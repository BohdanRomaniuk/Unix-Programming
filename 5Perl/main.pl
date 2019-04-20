use warnings;
use strict;

require './findOldestDir.pl';
require './removeSimilar.pl';
require './tests.pl';

sub runFirstTaskTests
{
	print("Test 1.1 ".(test1_1() ? "passed" : "failed")."\n");
	print("Test 1.2 ".(test1_2() ? "passed" : "failed")."\n");
	print("Test 1.3 ".(test1_3() ? "passed" : "failed")."\n");
}

sub runSecondTaskTests
{
	print("\nTest 2.1 ".(test2_1() ? "passed" : "failed")."\n");
	print("Test 2.2 ".(test2_2() ? "passed" : "failed")."\n");
	print("Test 2.3 ".(test2_3() ? "passed" : "failed")."\n");
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
        		print("Oldest dir: ${oldestDir}\n");
		}
    		elsif($ARGV[1] eq 'delete-repeats' && $argsCount > 3)
		{
			my $directory = $ARGV[2];
			my $allowedExt = $ARGV[3];
			my ($removedCount) = removeSimilar($directory, $allowedExt);
			print("Removed: ${removedCount} files\n");
    		}
		else
		{
			print("Wrong parameter use --help\n");
		}
	}
}

main();
