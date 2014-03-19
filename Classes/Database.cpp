#include "Database.h"
#include "cocos2d.h"
#include "sqlite/sqlite3.h"
#include <string>

USING_NS_CC;
using namespace std;

int Database::sqliteOpen(sqlite3 **database)
{
    std::string fullpath = CCFileUtils::sharedFileUtils()->getWritablePath();
    fullpath += "sample.db";
    return sqlite3_open(fullpath.c_str(), database);
}

void Database::sqliteCreateTable()
{
    sqlite3* db = NULL;
    if (sqliteOpen(&db) == SQLITE_OK)
    {
        const char* sql_createtable = "CREATE TABLE test1(key TEXT, value TEXT)";
        sqlite3_stmt* stmt = NULL;
        if (sqlite3_prepare_v2(db, sql_createtable, -1, &stmt, NULL)== SQLITE_OK) {
                if (sqlite3_step(stmt) == SQLITE_DONE) {
                    CCLOG("create table done");
                }
                sqlite3_reset(stmt);
            }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}

const char* Database::sqliteGetValueForKey(const char* key)
{
    CCString* strValue = NULL;
    sqlite3* db = NULL;
    if (sqliteOpen(&db) == SQLITE_OK){
        const char* sql_select = "SELECT value FROM test1 WHERE key=?";
        sqlite3_stmt* stmt = NULL;
        if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, NULL) == SQLITE_OK)
        {
            sqlite3_bind_text(stmt, 1, key, -1, SQLITE_TRANSIENT);
            int ret = sqlite3_step(stmt);
            if (ret == SQLITE_DONE || ret == SQLITE_ROW){
                const char* val = (const char*)sqlite3_column_text(stmt, 0);
                strValue = CCString::create(val);
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    
    if (strValue != NULL) {
        return strValue->getCString();
    }
    return NULL;
}

void Database::sqliteSetValueForKey(const char* key, const char* value)
{
    std::string fullpath = CCFileUtils::sharedFileUtils()->getWritablePath();
    fullpath += "sample.db";
    sqlite3* db = NULL;
    if (sqlite3_open(fullpath.c_str(), &db) == SQLITE_OK) {
        const char* sql_select = "REPLACE INTO test1(key, value) VALUES (?,?)";
        sqlite3_stmt* stmt = NULL;
        if (sqlite3_prepare_v2(db, sql_select, -1, &stmt, NULL) == SQLITE_OK){
            sqlite3_bind_text(stmt, 1, key, -1, SQLITE_TRANSIENT);
            sqlite3_bind_text(stmt, 2, value, -1, SQLITE_TRANSIENT);
            if (sqlite3_step(stmt) == SQLITE_DONE) {
                CCLOG("replace key:%s value:%s", key, value);
            }
            sqlite3_reset(stmt);
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
}

void Database::manageData()
{
    sqliteCreateTable();
    
    // GET DIRECTORY WHICH DEFAULT MONSTER IS IN TEHN SET FOR SQLITE
    CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
    string DirectoryStr = userDefault->getStringForKey("userMonster");
    const char* DirectoryChar = DirectoryStr.c_str();
    sqliteSetValueForKey("userMonster", DirectoryChar);
    
    // BACKGROUND
    sqliteSetValueForKey("background", "default_grass.png");
    sqliteSetValueForKey("babyMonster", "baby_pon_front.png");
}