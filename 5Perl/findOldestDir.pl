use warnings;
use strict;

my $maxFolder;
my $maxCount;

sub listDir{	
	my $currentDir = $_[0];
	my $currentDirSubCount = 0;
		
	opendir(my $dh, $currentDir) || die ("Unable to open directory"); 
	while (my $filename = readdir($dh)) {
		if($filename eq "." || $filename eq "..") {
			next;
		}
		
		my $path = $currentDir.'/'.$filename;		
		if(-d $path){
			++$currentDirSubCount;
			listDir($path);
		}
	}
	
	closedir($dh);

	if($currentDirSubCount > $maxCount){
		$maxFolder = $currentDir;
		$maxCount = $currentDirSubCount;	
	}
}

sub search{
	$maxFolder = "";
	$maxCount = -1;

	listDir($_[0]);
	return ($maxFolder, $maxCount);
}

1;
