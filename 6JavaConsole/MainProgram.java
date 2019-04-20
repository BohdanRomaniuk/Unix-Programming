public class MainProgram 
{
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
			System.out.println("Running tests");
		}
		else if(args.length > 2 && args[0].equals("-t"))
		{
			if(args[1].equals("find-oldest-dir"))
			{
				String directory = args[2];
				System.out.println("Oldest dir: " + directory);
			}
			else if(args[1].equals("delete-repeats") && args.length > 3)
			{
				//String directory = args[2];
				//String allowedExt = args[3];
				int removedCount = 0;
				System.out.println("Removed: " + removedCount + " files\n");
	    	}
		}
		else
		{
			System.out.println("Wrong parameter use --help");
		}
    }
}