use warnings;
use strict;

require './findOldestDir.pl';

sub help
{
	if(scalar(@ARGV) > 0 && $ARGV[0] eq '--help')
	{
		print("Usage: perl main.pl [-t] [path] [ext] [--tests]\n");
    		print("       [-t] - type, find-oldest-dir or delete-repeats\n");
    		print("       [path] - path to the directory\n");
    		print("       [ext] - extension of allowed files when delete-repeats\n");
    		print("       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats");
		exit();
	}
}

sub main{
	
	help();
	my $num_args = $#ARGV + 1;
	if ($num_args != 1) {
	    print "Specify folder name.\n";
	    exit;
	}

	my $dir = $ARGV[0];

	unless(-d $dir){
		print $dir." is not a folder.\n";
		exit;	
	}

	my ($maxF, $maxC) = search($dir);

	print $maxF."\n";
	print $maxC."\n";
}

main();
