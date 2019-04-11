#ifndef TESTS_H
#define TESTS_H

#include <QMessageBox>
#include <QDir>
#include "oldestfoldersearcher.h"
#include "repeatingfilesremover.h"

class Tests
{
private:
    DatabaseLogger* _logger;

    void createDir(QString path)
    {
        QDir dir;
        if (!dir.exists(path))
        {
            dir.mkpath(path);
        }
    }

    void removeDir(QString path)
    {
        QDir dir(path);
        dir.removeRecursively();
    }

    void createFile(QString path)
    {
        QFile newFile(path);
        newFile.open(QIODevice::WriteOnly);
    }

    bool test1_1()
    {
        createDir("./tests/");
        createDir("./tests/1/");
        createDir("./tests/2/");
        createDir("./tests/3/");
        QDir dir("./tests/");
        OldesttFolderSearcher searcher(&dir, _logger);
        auto result = searcher.findOldestDir();
        removeDir("./tests/");
        return result.getDirName().contains("/tests/1");
    }

    bool test1_2()
    {
        createDir("./tests/");
        createDir("./tests/2/");
        createDir("./tests/2/1/");
        createDir("./tests/3/");
        QDir dir("./tests/");
        OldesttFolderSearcher searcher(&dir, _logger);
        auto result = searcher.findOldestDir();
        removeDir("./tests/");
        return result.getDirName().contains("/tests/2");
    }

    bool test1_3()
    {
        createDir("./tests/");
        createDir("./tests/1/");
        createDir("./tests/1/2/");
        createDir("./tests/3/");
        createDir("./tests/3/4/");
        createDir("./tests/3/4/5/");
        QDir dir("./tests/");
        OldesttFolderSearcher searcher(&dir, _logger);
        auto result = searcher.findOldestDir();
        removeDir("./tests/");
        return result.getDirName().contains("/tests/1");
    }

    bool test2_1()
    {
        createDir("./tests/");
        createFile("./tests/modest.cpp");
        createFile("./tests/modest.h");
        createFile("./tests/modest.txt");
        createFile("./tests/roman.cpp");
        QDir dir("./tests/");
        RepeatingFilesRemover remover(&dir, _logger);
        int removed = remover.removeSimilar("cpp");
        removeDir("./tests/");
        return removed==2;
    }

    bool test2_2()
    {
        createDir("./tests/");
        createFile("./tests/modest.cpp");
        createFile("./tests/modest.txt");
        createFile("./tests/roman.cpp");
        QDir dir("./tests/");
        RepeatingFilesRemover remover(&dir, _logger);
        int removed = remover.removeSimilar("txt");
        removeDir("./tests/");
        return removed==1;
    }

    bool test2_3()
    {
        createDir("./tests/");
        createFile("./tests/modest.cpp");
        createFile("./tests/modest.h");
        createFile("./tests/modest.txt");
        createFile("./tests/roman.cpp");
        createFile("./tests/roman.h");
        createFile("./tests/roma.h");
        QDir dir("./tests/");
        RepeatingFilesRemover remover(&dir, _logger);
        int removed = remover.removeSimilar("cpp");
        removeDir("./tests/");
        return removed==3;
    }
public:
    Tests(DatabaseLogger* logger)
    {
        _logger = logger;
    }

    void runFirstTaskTests()
    {
        QMessageBox box;
        box.setText(QString("First tests runned\nTest1: ") +
                    QString(test1_1() ? "passed" : "failed") + QString("\nTest2: ") +
                    QString(test1_2() ? "passed" : "failed") + QString("\nTest3: ") +
                    QString(test1_3() ? "passed" : "failed"));
        box.exec();
    }

    void runSecondTaskTests()
    {
        QMessageBox box;
        box.setText(QString("Second tests runned\nTest1: ") +
                    QString(test2_1() ? "passed" : "failed") + QString("\nTest2: ") +
                    QString(test2_2() ? "passed" : "failed") + QString("\nTest3: ") +
                    QString(test2_3() ? "passed" : "failed"));
        box.exec();
    }
};

#endif // TESTS_H
