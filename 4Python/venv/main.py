import os
import datetime

def fileExists(filePath):
    return os.path.exists(filePath)

def createDir(dirPath):
    os.makedirs(dirPath)

def findOldestDir(dirPath):
    oldestDir = dirPath;
    oldestDirDate = datetime.datetime(2029, 1, 6, 15, 8, 24, 78915).timestamp()
    for root, dirs, files in os.walk(dirPath):
        for _dir in dirs:
            curDirTime = os.stat(os.path.join(os.path.abspath(root), _dir)).st_ctime
            if  curDirTime < oldestDirDate:
                oldestDirDate = curDirTime
                oldestDir = os.path.join(os.path.abspath(root), _dir)
    return oldestDir

def removeSimilarFiles(dirPath, allowedExtension):
    removedCount=0;
    for root, dirs, files in os.walk(dirPath):
            for file1 in files:
                for file2 in files:
                    firstName = os.path.splitext(os.path.basename(file1))[0]
                    secondName = os.path.splitext(os.path.basename(file2))[0]
                    firstExt = os.path.splitext(os.path.basename(file1))[1]
                    secondExt = os.path.splitext(os.path.basename(file2))[1]
                    if firstName == secondName and firstExt != secondExt:
                        if firstExt!=allowedExtension and fileExists(os.path.join(os.path.abspath(dirPath), file1)):
                            os.remove(os.path.join(os.path.abspath(dirPath), file1))
                            ++removedCount
                        if secondExt!=allowedExtension and fileExists(os.path.join(os.path.abspath(dirPath),file2)):
                            os.remove(os.path.join(os.path.abspath(dirPath), file2))
                            ++removedCount
    return removedCount


def test1_1():
    return 0


print("First")
print(findOldestDir("/home/bohdan/first/"))
print("\nSecond")
print("Removed: "+removeSimilarFiles("/home/bohdan/second/", ".cpp"))