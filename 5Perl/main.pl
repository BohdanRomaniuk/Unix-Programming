use warnings;
use strict;

require './findOldestDir.pl';

sub runFirstTaskTests
{
	print("FiRST\n");
}

sub runSecondTaskTests
{
	print("SECOND\n");
}

sub main
{	
	my $argsCount = $#ARGV + 1;
	if($argsCount > 0 && $ARGV[0] eq '--help')
	{
		print("Usage: perl main.pl [-t] [path] [ext] [--tests]\n");
    		print("       [-t] - type, find-oldest-dir or delete-repeats\n");
    		print("       [path] - path to the directory\n");
    		print("       [ext] - extension of allowed files when delete-repeats\n");
    		print("       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats");
		exit();
	}
	elsif($argsCount > 0 && $ARGV[0] eq '--tests')
	{
		runFirstTaskTests();
		runSecondTaskTests();
	}
	elsif($argsCount > 2 && $ARGV[0] eq '-t')
	{
		if($ARGV[1] eq 'find-oldest-dir')
		{
			my ($oldestDir) = findOldestDir($ARGV[2]);
        		print("Oldest dir: ${oldestDir}");
		}
    		elsif($ARGV[1] eq 'delete-repeats' && $argsCount > 3)
		{
			my $directory = $ARGV[2];
			my $allowedExt = $ARGV[3];
			my $removedCount = 0;
			print("Removed: ${removedCount} files");
    		}
		else
		{
			print("Wrong parameter use --help");
		}
	}
}

main();
