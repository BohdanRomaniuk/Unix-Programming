use warnings;
use strict;
use File::Basename;

my $removedCount;

sub fileExist
{
	my $path = $_[0];
	return -e $path;
}

sub removeSimilar
{
	$removedCount = 0;
	my $currentDir = $_[0];
	my $allowedExt = $_[1];
        my @files;
	opendir(my $dh, $currentDir) || die ("Unable to open directory"); 
	while (my $fileName = readdir($dh))
	{
		if($fileName eq "." || $fileName eq "..") 
		{
			next;
		}
		push (@files, $fileName)
	}
        for(my $i=0; $i<scalar @files; $i++)
        {
            for(my $j=$i; $j<scalar @files; $j++)
            {
		my($fileName1,$dir1,$ext1) = fileparse($files[$i], qr/\.[^.]*/);
		my($fileName2,$dir2,$ext2) = fileparse($files[$j], qr/\.[^.]*/);
		if($fileName1 eq $fileName2 && $ext1 ne $ext2)
		{
			if($ext1 ne $allowedExt && fileExist($currentDir.''.$files[$i]))
			{
				unlink $currentDir.''.$files[$i];
				$removedCount++;
			}
			if($ext2 ne $allowedExt && fileExist($currentDir.''.$files[$j]))
			{
				unlink $currentDir.''.$files[$j];
				$removedCount++;
			}
		}
            }
        }
	closedir($dh);
	return ($removedCount);
}

1;
