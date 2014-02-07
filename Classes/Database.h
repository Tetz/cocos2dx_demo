#ifndef __DATABASE_H__
#define __DATABASE_H__

#include "cocos2d.h"
#include "sqlite/sqlite3.h"

class Database
{
public:
    int sqliteOpen(sqlite3 **database);
    virtual void sqliteCreateTable();
    const char* sqliteGetValueForKey(const char* key);
    virtual void sqliteSetValueForKey(const char* key, const char* value);
    virtual void manageData();
};

#endif /* __DATABASE_H__ */
