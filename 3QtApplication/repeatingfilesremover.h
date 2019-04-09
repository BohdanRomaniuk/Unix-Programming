#ifndef REPEATINGFILESREMOVER_H
#define REPEATINGFILESREMOVER_H

#include <QString>
#include <QDir>
#include "databaselogger.h"

class RepeatingFilesRemover
{
private:
    QDir* _sourceDir;
    DatabaseLogger* _logger;

    bool fileExists(QString filePath)
    {
        QFileInfo check_file(filePath);
        return check_file.exists();
    }
public:
    RepeatingFilesRemover(QDir* sourceDir, DatabaseLogger* logger)
    {
        _sourceDir = sourceDir;
        _logger = logger;
    }

    int removeSimilar(QString allowedExt)
    {
        int removedCount = 0;
        QFileInfoList files = _sourceDir->entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        for(int i=0; i<files.size(); ++i)
        {
            for(int j=i; j<files.size(); ++j)
            {
                QString name1 = files[i].baseName();
                QString name2 = files[j].baseName();
                QString ext1 = files[i].suffix();
                QString ext2 = files[j].suffix();
                if(name1 == name2 && ext1 != ext2)
                {
                    if(ext1!=allowedExt && fileExists(files[i].absoluteFilePath()))
                    {
                        QFile file(files[i].absoluteFilePath());
                        file.remove();
                        ++removedCount;
                    }
                    if(ext2!=allowedExt && fileExists(files[j].absoluteFilePath()))
                    {
                        QFile file(files[j].absoluteFilePath());
                        file.remove();
                        ++removedCount;
                    }
                }
            }
        }
        return removedCount;
    }
};

#endif // REPEATINGFILESREMOVER_H
