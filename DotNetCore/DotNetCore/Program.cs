using System;

namespace DotNetCore
{
    class Program
    {
        static void RunFirstTaskTests()
        {
            Console.WriteLine("Test 1.1: " + (Tests.Test1_1() ? "passed" : "failed"));
            Console.WriteLine("Test 1.2: " + (Tests.Test1_2() ? "passed" : "failed"));
            Console.WriteLine("Test 1.3: " + (Tests.Test1_3() ? "passed" : "failed"));
        }
	
        static void RunSecondTaskTests()
        {
            Console.WriteLine("\nTest 2.1: " + (Tests.Test2_1() ? "passed" : "failed"));
            Console.WriteLine("Test 2.2: " + (Tests.Test2_2() ? "passed" : "failed"));
            Console.WriteLine("Test 2.3: " + (Tests.Test2_3() ? "passed" : "failed"));
        }
        
        static void Main(string[] args)
        {
            if(args.Length > 0 && args[0] == "--help")
            {
                Console.WriteLine("Usage: java MainProgram [-t] [path] [ext] [--tests]");
                Console.WriteLine("       [-t] - type, find-oldest-dir or delete-repeats");
                Console.WriteLine("       [path] - path to the directory");
                Console.WriteLine("       [ext] - extension of allowed files when delete-repeats");
                Console.WriteLine("       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats");
            }
            else if(args.Length > 0 && args[0] == "--tests")
            {
                RunFirstTaskTests();
                RunSecondTaskTests();
            }
            else if(args.Length > 2 && args[0] == "-t")
            {
                if(args[1] == "find-oldest-dir")
                {
                    string directory = args[2];
                    OldestFolderSearcher searcher = new OldestFolderSearcher();
                    string oldestDir = searcher.FindOldestDir(directory);
                    Console.WriteLine("Oldest dir: " + oldestDir);
                }
                else if(args[1] == "delete-repeats" && args.Length > 3)
                {
                    string directory = args[2];
                    string allowedExt = args[3];
                    RepeatingFilesRemover remover = new RepeatingFilesRemover();
                    int removedCount = remover.RemoveRepeatingFiles(directory, allowedExt);
                    Console.WriteLine("Removed: " + removedCount + " files\n");
                }
            }
            else
            {
                Console.WriteLine("Wrong parameter use --help");
            }
        }
    }
}