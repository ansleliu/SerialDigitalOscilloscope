#ifndef RECVDATABBASE_H
#define RECVDATABBASE_H
#include "MySQLite.h"

class RecvDatabBase : public MySQLite
{
public:
    explicit RecvDatabBase(const QString &dbpath, const QString &connName);
    
protected:
    bool createTable();	// ´´½¨±í

public:
    bool addNewRecord(const double &recvdata);
    double getRecvData(const int &id);
    void clearTable();
    
};

#endif // RECVDATABBASE_H
