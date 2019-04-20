use warnings;
use strict;

my $oldestDirName;
my $oldestDirTime;

sub search
{	
	my $currentDir = $_[0];	
	opendir(my $dh, $currentDir) || die ("Unable to open directory"); 
	while (my $subDir = readdir($dh))
	{	
		if($subDir eq "." || $subDir eq "..") 
		{
			next;
		}
		my $path = $currentDir.''.$subDir.'/';		
		if(-d $path)
		{
			my @stats = stat $path;
			my $modifiedTime = $stats[9];
			if($modifiedTime < $oldestDirTime)
			{
				$oldestDirTime = $modifiedTime;
				$oldestDirName = $path;
			}
			search($path);
		}
	}
	closedir($dh);
}

sub findOldestDir
{
	$oldestDirName = "";
	$oldestDirTime = time() + 24*60*60;
	search($_[0]);
	return ($oldestDirName);
}

1;
