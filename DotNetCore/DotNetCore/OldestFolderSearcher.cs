using System;
using System.IO;

namespace DotNetCore
{
    public class OldestFolderSearcher
    {
        private string oldestDirName;
        private DateTime oldestDirDate;

        public OldestFolderSearcher()
        {
            oldestDirName = string.Empty;
            oldestDirDate = DateTime.MaxValue;
        }

        private void Search(string path)
        {
            DirectoryInfo info = new DirectoryInfo(path);
            foreach (var subDir in info.GetDirectories())
            {
                if (subDir.CreationTime < oldestDirDate)
                {
                    oldestDirDate = subDir.CreationTime;
                    oldestDirName = subDir.FullName;
                }
                Search(subDir.FullName);
            } 
        }

        public string FindOldestDir(string path)
        {
            Search(path);
            return oldestDirName;
        }
    }
}