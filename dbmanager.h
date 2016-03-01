#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QDebug>

class DBManager
{
public:
    DBManager(const QString& path);
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
