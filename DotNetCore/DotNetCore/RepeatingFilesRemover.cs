using System.IO;

namespace DotNetCore
{
    public class RepeatingFilesRemover
    {
        private int removedCount;
	
        public RepeatingFilesRemover()
        {
            removedCount = 0;
        }
	
        private string GetFileNameWithoutExtension(string fileName)
        {
            int dotPos = fileName.LastIndexOf(".");
            return (dotPos!=-1) ? fileName.Substring(0, dotPos) : fileName;
        }
	
        private string GetFileExtension(string fileName)
        {
            int dotPos = fileName.LastIndexOf(".");
            return (dotPos!=-1) ? fileName.Substring(dotPos) : fileName;
        }
	
        public static bool FileExist(string path)
        {
            FileInfo file = new FileInfo(path);
            return file.Exists;
        }
	
        public int RemoveRepeatingFiles(string path, string allowedExt)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(path);
            FileInfo[] files = dirInfo.GetFiles();
            for (int i=0; i<files.Length; ++i)
            {
                for(int j=i; j<files.Length; ++j)
                {
                    string fileName1 = GetFileNameWithoutExtension(files[i].Name);
                    string fileName2 = GetFileNameWithoutExtension(files[j].Name);
                    string ext1 = GetFileExtension(files[i].Name);
                    string ext2 = GetFileExtension(files[j].Name);
                    if (fileName1 == fileName2 && ext1 != ext2)
                    {
                        if (ext1 != allowedExt && FileExist(files[i].FullName))
                        {
                            files[i].Delete();
                            ++removedCount;
                        }
                        if (ext2 != allowedExt && FileExist(files[j].FullName))
                        {
                            files[j].Delete();
                            ++removedCount;
                        }
                    }
                }
            }
            return removedCount;
        }
    }
}