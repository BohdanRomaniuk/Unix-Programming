#ifndef OLDESTFOLDERSEARCHER_H
#define OLDESTFOLDERSEARCHER_H

#include <QObject>
#include <QDir>
#include <QString>
#include <QDateTime>
#include <QFileInfo>
#include <databaselogger.h>
#include <searchresult.h>

class OldesttFolderSearcher
{
private:
    QDir* _sourceDir;
    QString _oldestDir;
    QDateTime _oldestDirDate;
    DatabaseLogger* _logger;

    QFileInfoList _getAllSubdirectories(QDir dir)
    {
        return dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    }
public:
    OldesttFolderSearcher(QDir* sourceDir, DatabaseLogger* logger)
    {
        _sourceDir = sourceDir;
        _oldestDir = sourceDir->absolutePath();
        QFileInfo dirInfo(sourceDir->absolutePath());
        _oldestDirDate = dirInfo.lastModified();
        _logger = logger;
    }

    SearchResult findOldestDir()
    {
        return findOldestDir(*_sourceDir);
    }

    SearchResult findOldestDir(QDir dir)
    {
        QFileInfo dirInfo(dir.absolutePath());
        _logger->log("Searching oldest dir:: Directory: " + dir.dirName() + " Create date:" + dirInfo.lastModified().toString());

        auto files = _getAllSubdirectories(dir);
        foreach(auto file, files)
        {
            QDir subDir(file.absoluteFilePath());
            QFileInfo subDirInfo(subDir.absolutePath());
            QDateTime dirCreateDate = subDirInfo.lastModified();
            if(dirCreateDate < _oldestDirDate)
            {
                _oldestDir = subDir.absolutePath();
                _oldestDirDate = dirCreateDate;
            }
            findOldestDir(subDir);
        }
        return SearchResult(_oldestDir, _oldestDirDate);
    }
};

#endif // OLDESTFOLDERSEARCHER_H
