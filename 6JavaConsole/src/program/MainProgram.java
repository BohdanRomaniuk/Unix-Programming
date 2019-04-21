package program;

public class MainProgram 
{
	public static void RunFirstTaskTests()
	{
		System.out.println("Test 1.1: " + (Tests.Test1_1() ? "passed" : "failed"));
		System.out.println("Test 1.2: " + (Tests.Test1_2() ? "passed" : "failed"));
		System.out.println("Test 1.3: " + (Tests.Test1_3() ? "passed" : "failed"));
	}
	
	public static void RunSecondTaskTests()
	{
		System.out.println("\nTest 2.1: " + (Tests.Test2_1() ? "passed" : "failed"));
		System.out.println("Test 2.2: " + (Tests.Test2_2() ? "passed" : "failed"));
		System.out.println("Test 2.3: " + (Tests.Test2_3() ? "passed" : "failed"));
	}
	
	public static void main(String[] args)
	{
		if(args.length > 0 && args[0].equals("--help"))
		{
			System.out.println("Usage: java MainProgram [-t] [path] [ext] [--tests]");
			System.out.println("       [-t] - type, find-oldest-dir or delete-repeats");
			System.out.println("       [path] - path to the directory");
			System.out.println("       [ext] - extension of allowed files when delete-repeats");
			System.out.println("       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats");
		}
		else if(args.length > 0 && args[0].equals("--tests"))
		{
			RunFirstTaskTests();
			RunSecondTaskTests();
		}
		else if(args.length > 2 && args[0].equals("-t"))
		{
			if(args[1].equals("find-oldest-dir"))
			{
				String directory = args[2];
				OldestFolderSearcher searcher = new OldestFolderSearcher();
				String oldestDir = searcher.FindOldestDir(directory);
				System.out.println("Oldest dir: " + oldestDir);
			}
			else if(args[1].equals("delete-repeats") && args.length > 3)
			{
				String directory = args[2];
				String allowedExt = args[3];
				RepeatingFilesRemover remover = new RepeatingFilesRemover();
				int removedCount = remover.RemoveRepeatingFiles(directory, allowedExt);
				System.out.println("Removed: " + removedCount + " files\n");
	    	}
		}
		else
		{
			System.out.println("Wrong parameter use --help");
		}
    }
}
