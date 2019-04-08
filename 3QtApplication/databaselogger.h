#ifndef DATABASELOGGER_H
#define DATABASELOGGER_H

#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

class SqlLiteConnection
{
private:
    QSqlDatabase db;
    QString _dbpath;

    void open()
    {
        if (!db.open())
        {
            throw "Failed to open connection to db!";
        }
    }

    void close()
    {
        db.close();
    }
public:
    SqlLiteConnection(QString dbpath):
        _dbpath(dbpath)
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(_dbpath);
    }

    void executeQuery(QString queryString)
    {
        open();
        QSqlQuery query;
        if (!query.exec(queryString))
        {
            throw "Error executing query";
        }
        close();
    }

    void ensureCreated()
    {
        open();
        QSqlQuery query;
        QString queryString = QString("CREATE TABLE IF NOT EXISTS logs(id integer PRIMARY KEY AUTOINCREMENT,") +
                QString("message varchar(512),") +
                QString("dt datetime DEFAULT current_timestamp)");

        if (!query.exec(queryString))
        {
            throw "Error executing query";
        }
        close();
    }
};

class DatabaseLogger
{
private:
    SqlLiteConnection* _sqlLiteConnection;
public:
    DatabaseLogger(QString dbpath)
    {
        _sqlLiteConnection = new SqlLiteConnection(dbpath);
        _sqlLiteConnection->ensureCreated();
    }

    ~DatabaseLogger()
    {
        delete _sqlLiteConnection;
    }

    void log(QString message)
    {
        QString queryString = "INSERT INTO logs(message) VALUES(\"" + message + "\")";
        _sqlLiteConnection->executeQuery(queryString);
    }
};

#endif // DATABASELOGGER_H
