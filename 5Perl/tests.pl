use warnings;
use strict;
use File::Path qw(make_path rmtree);
require 'searchEngine.pl';

sub test1{
	#arrange
	
	my $machinePath = "/home/mihailo1996";	
	
	make_path("$machinePath/Test");
	make_path("$machinePath/Test/1");
	make_path("$machinePath/Test/2");
	make_path("$machinePath/Test/3");
	make_path("$machinePath/Test/2/1");
	make_path("$machinePath/Test/2/2");
	make_path("$machinePath/Test/2/3");
	make_path("$machinePath/Test/2/4");
	make_path("$machinePath/Test/3/1");
	make_path("$machinePath/Test/2");

	#act
	
	my ($fold, $count) = search("$machinePath/Test");

	#assert
	
	if($count eq 4 && $fold eq "$machinePath/Test/2"){
		print "TEST PASSED.\n";	
	}
	else{
		print "TEST FAILED.\n";	
	}
	
	#cleanUp
	rmtree("$machinePath/Test");
}

sub run{
	test1();
}

run();

