#include <iostream>
#include <string.h>
#include <list>
#include <iterator>
#include <thread>
#include <chrono>
#include <fstream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
using namespace std;

class OldestFolderSearcher
{
private:
	time_t oldestDirDate;
	string oldestDirName;
public:
	string find(string path)
	{
	  oldestDirDate=chrono::system_clock::to_time_t(chrono::system_clock::now());
		oldestDirName=path;
		for(const auto& dir : fs::recursive_directory_iterator(path))
		{
			if(fs::is_directory(dir))
			{
				auto dtime = fs::last_write_time(dir);
 				time_t dctime = decltype(dtime)::clock::to_time_t(dtime);
				if(dctime<oldestDirDate)
				{
					oldestDirDate=dctime;
					oldestDirName=fs::path(dir).filename();
				}
			}
		}
		return oldestDirName;
	}
};

class RepeatingFilesRemover
{
private:
	string getFileName(string path)
	{
		return fs::path(path).stem();
	}

	string getFileExt(string path)
	{
		return fs::path(path).extension();
	}

	bool fileExists(string path)
	{
		return fs::exists(path);
	}

	void removeFile(string path)
	{
		fs::remove(path);
	}
public:
	int remove(string path, string allowedExt)
	{
		list<string> allFiles;
		int removedCount = 0;
		for(const auto& dir : fs::recursive_directory_iterator(path))
		{
			if(!fs::is_directory(dir))
			{
				allFiles.push_front(fs::path(dir));
			}
		}
		for(list<string>::iterator it1=allFiles.begin(); it1!=allFiles.end(); ++it1)
		{
			for(list<string>::iterator it2=it1; it2!=allFiles.end(); ++it2)
			{
				string name1 = getFileName(*it1);
				string name2 = getFileName(*it2);
				string ext1 = getFileExt(*it1);
				string ext2 = getFileExt(*it2);
				if(name1==name2 && ext1!=ext2)
				{
					if(ext1!=allowedExt && fileExists(*it1))
					{
						removeFile(*it1);
						++removedCount;
						//cout<<"Remove1: "<<*it1<<endl;
					}
					if(ext2!=allowedExt && fileExists(*it2))
					{
						removeFile(*it2);
						++removedCount;
						//cout<<"Remove2: "<<*it2<<endl;
					}
				}
			}
		}
		return removedCount;
	}
};

void sleep()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1050));
}

void createFile(string fileName, string dir="test")
{
	ofstream file;
	file.open(dir + "/" + fileName);
	file.close();
}

bool fileExists(string fileName, string dir="test")
{
	return fs::exists(dir + "/" + fileName);
}

bool test1_1()
{
	bool testPassed=false;
	fs::create_directories("test/1/2/a");
	sleep();
  fs::create_directory("test/1/2/b");
	sleep();
	fs::create_directories("test/2/c");
	OldestFolderSearcher searcher;
	testPassed=(searcher.find("test")=="1")?true:false;
	fs::remove_all("test");
	return testPassed;
}

bool test1_2()
{
	bool testPassed=false;
	fs::create_directories("test/1/2");
	sleep();
	fs::create_directories("test/4/5");
	sleep();
	fs::create_directories("test/1/3");
	sleep();
	fs::create_directories("test/6/7");
	sleep();
	fs::create_directory("test/6/8");
	OldestFolderSearcher searcher;
	testPassed=(searcher.find("test")=="2")?true:false;
	fs::remove_all("test");
	return testPassed;
}

bool test1_3()
{
	bool testPassed=false;
	fs::create_directories("test/6/8");
	sleep();
	fs::create_directories("test/1/2");
	sleep();
	fs::create_directories("test/1/3");
	OldestFolderSearcher searcher;
	testPassed=(searcher.find("test")=="6")?true:false;
	fs::remove_all("test");
	return testPassed;
}

bool test2_1()
{
	bool testPassed=false;
	fs::create_directory("test");
	createFile("modest.cpp");
	createFile("modest.h");
	createFile("modest.txt");
	RepeatingFilesRemover remover;
	int removedCount = remover.remove("test", ".txt");
	testPassed = (!fileExists("modest.cpp") && !fileExists("modest.h") && removedCount==2)?true:false;
	fs::remove_all("test");
	return testPassed;
}

bool test2_2()
{
	bool testPassed=false;
	fs::create_directory("test");
	createFile("modest.cpp");
	createFile("modest.h");
	createFile("modest.txt");
	createFile("roman.cpp");
	createFile("roman.py");
	RepeatingFilesRemover remover;
	int removedCount = remover.remove("test", ".cpp");
	testPassed = (!fileExists("modest.h") && !fileExists("modest.txt") && !fileExists("roman.py") && removedCount==3)?true:false;
	fs::remove_all("test");
	return testPassed;
}

bool test2_3()
{
	bool testPassed=false;
	fs::create_directory("test");
	createFile("modest.cpp");
	createFile("modest.h");
	createFile("modest.txt");
	createFile("roman.cpp");
	createFile("roman.cp");
	createFile("roma.cpp");
	RepeatingFilesRemover remover;
	int removedCount = remover.remove("test", ".cpp");
	testPassed = (!fileExists("modest.h") && !fileExists("modest.txt") && !fileExists("roman.cp") && removedCount==3)?true:false;
	fs::remove_all("test");
	return testPassed;
}

int main(int argc, char* argv[])
{
	if((string)argv[1]=="--help")
	{
		cout<<"Usage: ./main [-t] [path] [ext] [--tests]"<<endl;
		cout<<"       [-t] - type, find-oldest-dir or delete-repeats"<<endl;
		cout<<"       [path] - path to the directory"<<endl;
		cout<<"       [ext] - extension of allowed files when delete-repeats"<<endl;
		cout<<"       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats"<<endl;
	}
	else if((string)argv[1]=="-t")
	{
		if((string)argv[2]=="find-oldest-dir")
		{
			string dirPath = (string)argv[3];
			OldestFolderSearcher searcher;
			cout<<"Oldest directory: "<<searcher.find(dirPath)<<endl;
		}
		else if((string)argv[2]=="delete-repeats")
		{
			string dirPath = (string)argv[3];
			string allowedExt = (string)argv[4];
			RepeatingFilesRemover remover;
			cout<<"Removed: "<<remover.remove(dirPath, allowedExt)<<" files"<<endl;
		}
	}
	else if((string)argv[1]=="--tests")
	{
		cout<<"Test 1.1: "<<((test1_1())?"passed":"failed")<<endl;
		cout<<"Test 1.2: "<<((test1_2())?"passed":"failed")<<endl;
		cout<<"Test 1.3: "<<((test1_3())?"passed":"failed")<<endl;
		cout<<"Test 2.1: "<<((test2_1())?"passed":"failed")<<endl;
		cout<<"Test 2.2: "<<((test2_2())?"passed":"failed")<<endl;
		cout<<"Test 2.3: "<<((test2_3())?"passed":"failed")<<endl;
	}
	return 0;
}
