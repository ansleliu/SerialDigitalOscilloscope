#include "RecvDatabBase.h"

RecvDatabBase::RecvDatabBase(const QString &dbpath, const QString &connName) :
    MySQLite(dbpath, connName)
{
    if (!isTableExist("RecvDataBase"))	// 新建的数据库,创建表
    {
        createTable();
    }
}

bool RecvDatabBase::createTable()
{
    QSqlQuery query(*db);

    query.exec("CREATE TABLE [RecvDataBase] (\
               [id] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY AUTOINCREMENT, \
               [Data] TEXT NOT NULL ON CONFLICT FAIL);");
    db->commit();
    return true;
}

bool RecvDatabBase::addNewRecord(const double &recvdata)
{
    QString sql = QString("insert into RecvDataBase(Data) values('%1')")
        .arg(recvdata);
    return exec(sql);
}

double RecvDatabBase::getRecvData(const int &id)
{
    QSqlQuery query(QString("select Data from RecvDataBase where id = '%1'")
                    .arg(id), *db);
    query.next();
    return query.record().value(0).toDouble();
}

void RecvDatabBase::clearTable()
{
    //////////////////////////////////////////////////
    //清空表内容
    exec(QString("delete from %1").arg("RecvDataBase"));
    //////////////////////////////////////////////////
    //清空自增记录
    exec(QString("delete from sqlite_sequence where name = '%1'")
         .arg("RecvDataBase"));
}
