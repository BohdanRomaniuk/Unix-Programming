using System.IO;
using System;
using System.Threading;

namespace DotNetCore
{
    public static class Tests
    {
	    private static void RemoveDirs(string root)
	    {
		    DirectoryInfo info = new DirectoryInfo(root);
		    foreach (var subDir in info.GetDirectories())
		    {
			    if (subDir.Exists)
			    {
				    RemoveDirs(subDir.FullName);
			    }
			    subDir.Delete();
		    }
	    }

	    private static void CreateEmptyFile(string path)
	    {
		    File.Create(path).Dispose();
	    }

	    private static void Sleep(int seconds)
	    {
		    Thread.Sleep(1000*seconds);
	    }

	    public static bool Test1_1()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    Directory.CreateDirectory(testPath + "1/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "2/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "3/");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir(testPath);
		    
		    RemoveDirs(testPath);
		    return result.Contains("/1");
	    }

	    public static bool Test1_2()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    Directory.CreateDirectory(testPath + "1/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "1/2/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "3/");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir(testPath);

		    RemoveDirs(testPath);
		    return result.Contains("/1");
	    }

	    public static bool Test1_3()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    Directory.CreateDirectory(testPath + "3/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "3/2/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "4/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "1/");
		    Sleep(1);
		    Directory.CreateDirectory(testPath + "3/5/");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir(testPath);

		    RemoveDirs(testPath);
		    return result.Contains("/3/2");
	    }

	    public static bool Test2_1()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    CreateEmptyFile(testPath + "modest.h");
		    CreateEmptyFile(testPath + "modest.cpp");
		    CreateEmptyFile(testPath + "modest.txt");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles(testPath, ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.txt");

		    RemoveDirs(testPath);
		    return result == 2 && firstRemoved && thirdRemoved;
	    }

	    public static bool Test2_2()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    CreateEmptyFile(testPath + "modest.h");
		    CreateEmptyFile(testPath + "modest.cpp");
		    CreateEmptyFile(testPath + "modest.txt");
		    CreateEmptyFile(testPath + "roman.h");
		    CreateEmptyFile(testPath + "roman.cpp");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles(testPath, ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.txt");
		    bool fourthRemoved = !RepeatingFilesRemover.FileExist(testPath + "roman.h");

		    RemoveDirs(testPath);
		    return result == 3 && firstRemoved && thirdRemoved && fourthRemoved;
	    }

	    public static bool Test2_3()
	    {
		    string tempDir = Path.GetTempPath();
		    string testPath = Path.Combine(tempDir, "tests/");
		    Directory.CreateDirectory(tempDir);
		    CreateEmptyFile(testPath + "modest.h");
		    CreateEmptyFile(testPath + "modest.cpp");
		    CreateEmptyFile(testPath + "modest.txt");
		    CreateEmptyFile(testPath + "roman.h");
		    CreateEmptyFile(testPath + "roman.cpp");
		    CreateEmptyFile(testPath + "romn.cpp");
		    CreateEmptyFile(testPath + "buchik.cpp");
		    CreateEmptyFile(testPath + "buchk.cpp");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles(testPath, ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist(testPath + "modest.txt");
		    bool fourthRemoved = !RepeatingFilesRemover.FileExist(testPath + "roman.h");

		    RemoveDirs(testPath);
		    return result == 3 && firstRemoved && thirdRemoved && fourthRemoved;
	    }
    }
}