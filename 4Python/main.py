import os
import sys
import time
import shutil
import datetime

def fileExists(filePath):
    return os.path.exists(filePath)

def createDir(dirPath):
    os.mkdir(dirPath)

def createFile(filePath):
    os.mknod(filePath)

def removeDir(dirPath):
    shutil.rmtree(dirPath)

def findOldestDir(dirPath):
    oldestDir = dirPath
    oldestDirDate = datetime.datetime(2029, 1, 6, 15, 8, 24, 78915).timestamp()
    for root, dirs, files in os.walk(dirPath):
        for _dir in dirs:
            curDirTime = os.stat(os.path.join(os.path.abspath(root), _dir)).st_ctime
            if  curDirTime < oldestDirDate:
                oldestDirDate = curDirTime
                oldestDir = os.path.join(os.path.abspath(root), _dir)
    return oldestDir

def removeSimilarFiles(dirPath, allowedExtension):
    removedCount=0
    for root, dirs, files in os.walk(dirPath):
            for file1 in files:
                for file2 in files:
                    firstName = os.path.splitext(os.path.basename(file1))[0]
                    secondName = os.path.splitext(os.path.basename(file2))[0]
                    firstExt = os.path.splitext(os.path.basename(file1))[1]
                    secondExt = os.path.splitext(os.path.basename(file2))[1]
                    if firstName == secondName and firstExt != secondExt:
                        if firstExt != allowedExtension and fileExists(os.path.join(os.path.abspath(dirPath), file1)):
                            os.remove(os.path.join(os.path.abspath(dirPath), file1))
                            removedCount += 1
                        if secondExt != allowedExtension and fileExists(os.path.join(os.path.abspath(dirPath),file2)):
                            os.remove(os.path.join(os.path.abspath(dirPath), file2))
                            removedCount += 1
    return removedCount


def test1_1():
    createDir("./tests/")
    createDir("./tests/1/")
    time.sleep(1)
    createDir("./tests/2/")
    time.sleep(1)
    createDir("./tests/3/")
    result = findOldestDir("./tests/")
    removeDir("./tests/")
    return "/tests/1" in result

def test1_2():
    createDir("./tests/")
    createDir("./tests/3/")
    time.sleep(1)
    createDir("./tests/1/")
    time.sleep(1)
    createDir("./tests/1/2")
    result = findOldestDir("./tests/")
    removeDir("./tests/")
    return "/tests/3" in result

def test1_3():
    createDir("./tests/")
    createDir("./tests/1/")
    time.sleep(1)
    createDir("./tests/1/2")
    time.sleep(1)
    createDir("./tests/4/")
    time.sleep(1)
    createDir("./tests/1/2/3")
    result = findOldestDir("./tests/")
    removeDir("./tests/")
    return "/tests/1" in result

def test2_1():
    createDir("./tests/")
    createFile("./tests/modest.cpp")
    createFile("./tests/modest.h")
    createFile("./tests/modest.txt")
    result = removeSimilarFiles("./tests/", ".cpp")
    removeDir("./tests/")
    return result == 2

def test2_2():
    createDir("./tests/")
    createFile("./tests/modest.cpp")
    createFile("./tests/modest.h")
    createFile("./tests/modest.txt")
    createFile("./tests/roman.h")
    createFile("./tests/roman.cpp")
    result = removeSimilarFiles("./tests/", ".cpp")
    removeDir("./tests/")
    return result == 3

def test2_3():
    createDir("./tests/")
    createFile("./tests/modest.cpp")
    createFile("./tests/modest.h")
    createFile("./tests/modest.txt")
    createFile("./tests/roman.h")
    createFile("./tests/roman.cpp")
    createFile("./tests/roma.h")
    createFile("./tests/buchik.cpp")
    result = removeSimilarFiles("./tests/", ".cpp")
    removeDir("./tests/")
    return result == 3

def runFirstTests():
    print("Test 1.1: " + ("passed" if test1_1() else "failed"))
    print("Test 1.2: " + ("passed" if test1_2() else "failed"))
    print("Test 1.3: " + ("passed" if test1_3() else "failed"))

def runSecondTests():
    print("Test 2.1: " + ("passed" if test2_1() else "failed"))
    print("Test 2.2: " + ("passed" if test2_2() else "failed"))
    print("Test 2.3: " + ("passed" if test2_3() else "failed"))

if len(sys.argv)>1 and sys.argv[1] == "--help":
    print("Usage: python3 main.py [-t] [path] [ext] [--tests]")
    print("       [-t] - type, find-oldest-dir or delete-repeats")
    print("       [path] - path to the directory")
    print("       [ext] - extension of allowed files when delete-repeats")
    print("       [--tests] - run tests for both functionalities find-oldest-dir and delete-repeats")
if len(sys.argv)>1 and sys.argv[1] == "--tests":
    runFirstTests()
    runSecondTests()
if len(sys.argv)>3 and sys.argv[1] == "-t":
    if sys.argv[2]=="find-oldest-dir":
        print("Oldest dir: " + findOldestDir(sys.argv[3]))
    elif sys.argv[2]=="delete-repeats" and len(sys.argv)>4:
        print("Removed: " + str(removeSimilarFiles(sys.argv[3], sys.argv[4])) + " files")
    else:
        print("Wrong parameter use --help")