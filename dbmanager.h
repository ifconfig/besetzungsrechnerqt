#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QList>

#define TAB_COMRADS "Kameraden"
#define TAB_VEHICLES "Fahrzeuge"

class DBManager
{
public:
    DBManager(const QString& path);
    ~DBManager();
    QSqlTableModel* getComradTableModel();
    QSqlTableModel *getVehicleTableModel();
private:
    QSqlDatabase m_db;
    QSqlTableModel *m_comradModel;
    QSqlTableModel *m_vehicleModel;
};

#endif // DBMANAGER_H
