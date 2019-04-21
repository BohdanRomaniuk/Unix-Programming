package program;
import java.io.File;

public class OldestFolderSearcher 
{
	private String oldestDirName;
	private long oldestDirTime;
	
	public OldestFolderSearcher()
	{
		oldestDirName = "";
		oldestDirTime = Long.MAX_VALUE;
	}
	
	private void Search(File folder)
	{
		for (File fileEntry : folder.listFiles())
		{
	        if (fileEntry.isDirectory()) 
	        {
	        	if(fileEntry.lastModified() < oldestDirTime)
	        	{
	        		oldestDirName = fileEntry.getAbsolutePath();
	        		oldestDirTime = fileEntry.lastModified();
	        	}
	        	Search(fileEntry);
	        }
	    }
	}
	
	public String FindOldestDir(String path)
	{
		File folder = new File(path);
		Search(folder);
		return oldestDirName;
	}
}
