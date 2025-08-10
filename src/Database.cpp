#include "../include/Database.h"
#include "../include/Classifier.h"
#include<sqlite3.h>
#include<iostream>
using namespace std;

Database:: Database(const string &dbPath){
    if(sqlite3_open(dbPath.c_str(),(sqlite3**)&db)!=SQLITE_OK){
        cerr<<"ERROR OPENING DB\n";
        db = nullptr;
    }else{
        const char* createTableSQL = "CREATE TABLE IF NOT EXISTS clipboard ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "content TEXT,"
            "type TEXT,"
            "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP"
            ");";
            char* errMsg = nullptr;
            sqlite3_exec((sqlite3*)db,createTableSQL,0,0,&errMsg);

            if(errMsg){
                cerr<<"SQL ERROR: "<<errMsg<<"\n";
                sqlite3_free(errMsg);
            }
    }
}
Database::~Database(){
    if(db) sqlite3_close((sqlite3*)db);
}

void Database::insertEntry(const string &content, ContentType type){
    if (!db) return;

    string sql = "INSERT INTO clipboard (content, type) VALUES (?, ?);";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2((sqlite3*)db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, content.c_str(), -1, SQLITE_STATIC);
        std::string typeStr = Classifier::typeToString(type);
        sqlite3_bind_text(stmt, 2, typeStr.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "Insert failed: " << sqlite3_errmsg((sqlite3*)db) << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        cerr << "Prepare failed: " << sqlite3_errmsg((sqlite3*)db) << "\n";
    }
}