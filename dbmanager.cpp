#include "dbmanager.h"

DBManager::DBManager(const QString& path)
{
    if(!QSqlDatabase::connectionNames().isEmpty())
    {
        m_db.close();
        m_db.removeDatabase(QSqlDatabase::connectionNames().first());
    }
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(path);

   if (!m_db.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }

   m_comradModel = new QSqlTableModel(0, m_db);
   m_vehicleModel = new QSqlTableModel(0, m_db);

}

DBManager::~DBManager()
{
    m_db.close();
    m_db.removeDatabase(QSqlDatabase::connectionNames().first());
}

QSqlTableModel *DBManager::getComradTableModel()
{
    m_comradModel->setTable(TAB_COMRADS);
    m_comradModel->select();
    return m_comradModel;
}

QSqlTableModel *DBManager::getVehicleTableModel()
{
    m_vehicleModel->setTable(TAB_VEHICLES);
    m_vehicleModel->select();
    return m_vehicleModel;
}

