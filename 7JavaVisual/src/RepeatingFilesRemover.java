import java.io.File;

public class RepeatingFilesRemover
{
	private int removedCount;
	
	public RepeatingFilesRemover()
	{
		removedCount = 0;
	}
	
	private String GetFileNameWithoutExtension(String fileName)
	{
		int dotPos = fileName.lastIndexOf(".");
		return (dotPos!=-1) ? fileName.substring(0, dotPos) : fileName;
	}
	
	private String GetFileExtension(String fileName)
	{
		int dotPos = fileName.lastIndexOf(".");
		return (dotPos!=-1) ? fileName.substring(dotPos) : fileName;
	}
	
	public static boolean FileExist(String path)
	{
		File file = new File(path);
		return file.exists();
	}
	
	public int RemoveRepeatingFiles(String path, String allowedExt)
	{
		File folder = new File(path);
		File[] files = folder.listFiles();
		for (int i=0; i<files.length; ++i)
		{
			for(int j=i; j<files.length; ++j)
			{
				if (files[i].isFile() && files[j].isFile()) 
		        {
					String fileName1 = GetFileNameWithoutExtension(files[i].getName());
					String fileName2 = GetFileNameWithoutExtension(files[j].getName());
		        	String ext1 = GetFileExtension(files[i].getName());
		        	String ext2 = GetFileExtension(files[j].getName());
		        	if(fileName1.equals(fileName2) && !ext1.equals(ext2))
		        	{
		        		if(!ext1.equals(allowedExt) && FileExist(files[i].getAbsolutePath()))
		        		{
		        			files[i].delete();
		        			++removedCount;
		        		}
		        		if(!ext2.equals(allowedExt) && FileExist(files[j].getAbsolutePath()))
		        		{
		        			files[j].delete();
		        			++removedCount;
		        		}
		        	}
		        }
			}
	    }
		return removedCount;
	}
}
