use warnings;
use strict;
use File::Path qw(make_path rmtree);
use File::Tempdir;

require './findOldestDir.pl';
require './removeSimilar.pl';

sub createEmptyFile
{
	my $path = $_[0];
	open OUTFILE, ">", $path or die $!; 
	close OUTFILE;
}

sub test1_1
{
	my $root = "./test";	
	
	make_path("$root/1");
	sleep 1;
	make_path("$root/2");
	sleep 1;
	make_path("$root/3");
	
	my ($oldestDir) = findOldestDir("$root/");
	rmtree($root);

	return index($oldestDir, "/1") != -1;
}

sub test1_2
{
	my $root = "./test";	
	
	make_path("$root/1");
	sleep 1;
	make_path("$root/1/2");
	sleep 1;
	make_path("$root/3");
	
	my ($oldestDir) = findOldestDir("$root/");
	rmtree($root);

	return index($oldestDir, "/1") != -1;
}

sub test1_3
{
	my $root = "./test";	
	
	make_path("$root/3");
	sleep 1;
	make_path("$root/3/2");
	sleep 1;
	make_path("$root/4");
	sleep 1;
	make_path("$root/1");
	sleep 1;
	make_path("$root/3/5");
	
	my ($oldestDir) = findOldestDir("$root/");
	rmtree($root);

	return index($oldestDir, "/3/2") != -1;
}

sub test2_1
{
	my $root = "./tests";
	make_path($root);
	createEmptyFile("$root/modest.h");
	createEmptyFile("$root/modest.cpp");
	createEmptyFile("$root/modest.txt");
	my ($removedCount) = removeSimilar($root."/", ".cpp");
	my $isFirstRemoved = !fileExist("$root/modest.h");
	my $isThirdRemoved = !fileExist("$root/modest.h");
	rmtree($root);
	return $removedCount == 2 && $isFirstRemoved && $isThirdRemoved;
}

sub test2_2
{
	my $root = "./tests";
	make_path($root);
	createEmptyFile("$root/modest.h");
	createEmptyFile("$root/modest.cpp");
	createEmptyFile("$root/modest.txt");
	createEmptyFile("$root/roman.h");
	createEmptyFile("$root/roman.cpp");
	my ($removedCount) = removeSimilar($root."/", ".cpp");
	my $isFirstRemoved = !fileExist("$root/modest.h");
	my $isThirdRemoved = !fileExist("$root/modest.h");
	my $isFourthRemoved = !fileExist("$root/roman.h");
	rmtree($root);
	return $removedCount == 3 && $isFirstRemoved && $isThirdRemoved && $isFourthRemoved;
}

sub test2_3
{
	my $root = "./tests";
	make_path($root);
	createEmptyFile("$root/modest.h");
	createEmptyFile("$root/modest.cpp");
	createEmptyFile("$root/modest.txt");
	createEmptyFile("$root/roman.h");
	createEmptyFile("$root/roman.cpp");
	createEmptyFile("$root/romn.cpp");
	createEmptyFile("$root/buchik.cpp");
	createEmptyFile("$root/buck.cpp");
	my ($removedCount) = removeSimilar($root."/", ".cpp");
	my $isFirstRemoved = !fileExist("$root/modest.h");
	my $isThirdRemoved = !fileExist("$root/modest.h");
	my $isFourthRemoved = !fileExist("$root/roman.h");
	rmtree($root);
	return $removedCount == 3 && $isFirstRemoved && $isThirdRemoved && $isFourthRemoved;
}

1;
