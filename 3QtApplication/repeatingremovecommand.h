#ifndef REPEATINGREMOVECOMMAND_H
#define REPEATINGREMOVECOMMAND_H

#include <QUndoCommand>
#include <QTableView>
#include <QMessageBox>
#include <QStandardItem>
#include "databaselogger.h"
#include "repeatingfilesremover.h"

class RepeatingRemoveCommand : public QUndoCommand
{
private:
    QFileInfoList* _oldFiles;
    QFileInfoList* _newFiles;

    QString _dirPath;
    QString _allowedExt;

    QTableView* _table;
    DatabaseLogger* _logger;

    void showFilesInTable(QFileInfoList files)
    {
        QStandardItemModel* model = new QStandardItemModel();
        QStandardItem* item;
        QStringList cells;
        cells.append("Path");
        cells.append("Filename");
        cells.append("Ext");
        cells.append("Create date");

        model->setHorizontalHeaderLabels(cells);

        int i=0;
        foreach(QFileInfo file, files)
        {
            item = new QStandardItem(QString(file.absoluteFilePath()));
            model->setItem(i,0,item);
            item = new QStandardItem(QString(file.fileName()));
            model->setItem(i,1,item);
            item = new QStandardItem(QString(file.suffix()));
            model->setItem(i,2,item);
            item = new QStandardItem(QString(file.lastModified().toString()));
            model->setItem(i,3,item);
            ++i;
        }

        _table->setModel(model);
        _table->resizeColumnsToContents();
    }

    bool fileExists(QString filePath)
    {
        QFileInfo check_file(filePath);
        return check_file.exists();
    }
public:
    RepeatingRemoveCommand(QString dirPath, QString allowedExt, QTableView* table, DatabaseLogger* logger)
    {
        _dirPath = dirPath;
        _allowedExt = allowedExt;
        _table = table;
        _logger = logger;
    }

    void undo() override
    {
        foreach(QFileInfo file, *_oldFiles)
        {
            if(!fileExists(file.absoluteFilePath()))
            {
                QFile newFile(file.absoluteFilePath());
                newFile.open(QIODevice::WriteOnly);
            }
        }
        QDir dir(_dirPath);
        QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        showFilesInTable(files);
    }

    void redo() override
    {
        QDir dir(_dirPath);
        if(!dir.exists())
        {
            QMessageBox box;
            box.setText("Folder " + _dirPath + " doesn't exist");
            box.exec();
            return;
        }

        QFileInfoList files1 = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        _oldFiles = new QFileInfoList(files1);

        RepeatingFilesRemover remover(&dir, _logger);
        int removed = remover.removeSimilar(_allowedExt);

        QMessageBox box;
        box.setText("Removed " + QString::number(removed) + "  files");
        box.exec();

        QFileInfoList files2 = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        _newFiles = new QFileInfoList(files2);

        showFilesInTable(files2);
    }
};

#endif // REPEATINGREMOVECOMMAND_H
