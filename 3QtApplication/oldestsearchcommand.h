#ifndef SEARCHOLDESTFOLDERCOMMAND_H
#define SEARCHOLDESTFOLDERCOMMAND_H

#include <QUndoCommand>
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include "oldestfoldersearcher.h"
#include "databaselogger.h"

class SearchOldestFolderCommand : public QUndoCommand
{
private:
    QString _oldFolderPath;
    QString _newFolderPath;

    QLineEdit* _selectedDirLine;
    QLineEdit* _oldestDirLine;
    QLineEdit* _oldestDateLine;

    DatabaseLogger* _logger;

    void search(QString path)
    {
        _selectedDirLine->setText(path);
        QDir dir(path);
        if(!dir.exists())
        {
            QMessageBox box;
            box.setText("Folder " + path + " doesn't exist");
            box.exec();
            return;
        }

        OldesttFolderSearcher searcher(&dir, _logger);
        SearchResult result = searcher.findOldestDir();

        _oldestDirLine->setText(result.getDirName());
        _oldestDateLine->setText(result.getDirCreateDate().toString());
    }
public:
    SearchOldestFolderCommand(QString oldFP, QString newFP, QLineEdit* selDL,
                              QLineEdit* oldDL, QLineEdit* oldDateL, DatabaseLogger* logger)
    {
        _oldFolderPath = oldFP;
        _newFolderPath = newFP;
        _selectedDirLine = selDL;
        _oldestDirLine = oldDL;
        _oldestDateLine = oldDateL;
        _logger = logger;
    }

    void undo() override
    {
        search(_oldFolderPath);
    }

    void redo() override
    {
        search(_newFolderPath);
    }
};

#endif // SEARCHOLDESTFOLDERCOMMAND_H
