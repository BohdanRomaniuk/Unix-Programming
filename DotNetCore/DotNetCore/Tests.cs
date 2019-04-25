using System.IO;
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
		    Directory.CreateDirectory("./tests/");
		    Directory.CreateDirectory("./tests/1");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/2");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/3");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir("./tests/");

		    RemoveDirs("./tests/");
		    return result.Contains("/1");
	    }

	    public static bool Test1_2()
	    {
		    Directory.CreateDirectory("./tests/");
		    Directory.CreateDirectory("./tests/1");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/1/2");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/3");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir("./tests/");

		    RemoveDirs("./tests/");
		    return result.Contains("/1");
	    }

	    public static bool Test1_3()
	    {
		    Directory.CreateDirectory("./tests/");
		    Directory.CreateDirectory("./tests/3");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/3/2");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/4");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/1");
		    Sleep(1);
		    Directory.CreateDirectory("./tests/3/5");

		    OldestFolderSearcher searcher = new OldestFolderSearcher();
		    string result = searcher.FindOldestDir("./tests/");

		    RemoveDirs("./tests/");
		    return result.Contains("/3/2");
	    }

	    public static bool Test2_1()
	    {
		    Directory.CreateDirectory("./tests/");
		    CreateEmptyFile("./tests/modest.h");
		    CreateEmptyFile("./tests/modest.cpp");
		    CreateEmptyFile("./tests/modest.txt");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles("./tests/", ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");

		    RemoveDirs("./tests/");
		    return result == 2 && firstRemoved && thirdRemoved;
	    }

	    public static bool Test2_2()
	    {
		    Directory.CreateDirectory("./tests/");
		    CreateEmptyFile("./tests/modest.h");
		    CreateEmptyFile("./tests/modest.cpp");
		    CreateEmptyFile("./tests/modest.txt");
		    CreateEmptyFile("./tests/roman.h");
		    CreateEmptyFile("./tests/roman.cpp");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles("./tests/", ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");
		    bool fourthRemoved = !RepeatingFilesRemover.FileExist("./tests/roman.h");

		    RemoveDirs("./tests/");
		    return result == 3 && firstRemoved && thirdRemoved && fourthRemoved;
	    }

	    public static bool Test2_3()
	    {
		    Directory.CreateDirectory("./tests/");
		    CreateEmptyFile("./tests/modest.h");
		    CreateEmptyFile("./tests/modest.cpp");
		    CreateEmptyFile("./tests/modest.txt");
		    CreateEmptyFile("./tests/roman.h");
		    CreateEmptyFile("./tests/roman.cpp");
		    CreateEmptyFile("./tests/romn.cpp");
		    CreateEmptyFile("./tests/buchik.cpp");
		    CreateEmptyFile("./tests/buchk.cpp");

		    RepeatingFilesRemover remover = new RepeatingFilesRemover();
		    int result = remover.RemoveRepeatingFiles("./tests/", ".cpp");
		    bool firstRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.h");
		    bool thirdRemoved = !RepeatingFilesRemover.FileExist("./tests/modest.txt");
		    bool fourthRemoved = !RepeatingFilesRemover.FileExist("./tests/roman.h");

		    RemoveDirs("./tests/");
		    return result == 3 && firstRemoved && thirdRemoved && fourthRemoved;
	    }
    }
}