#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QString>
#include <QDateTime>

class SearchResult
{
private:
    QString _dirName;
    QDateTime _dirCreateDate;
public:
    SearchResult(QString dirName, QDateTime dirCreateDate)
    {
        _dirName = dirName;
        _dirCreateDate = dirCreateDate;
    }

    QString getDirName()
    {
        return _dirName;
    }

    QDateTime getDirCreateDate()
    {
        return _dirCreateDate;
    }
};

#endif // SEARCHRESULT_H
