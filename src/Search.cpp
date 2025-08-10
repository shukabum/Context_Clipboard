#include "../include/Search.h"
#include <sqlite3.h>
#include <iostream>
#include "Utils.h"

using namespace std;


void Search::searchDB(const string& dbPath, const string& keyword, 
    const string& typeFilter, const string& afterDate) {
    sqlite3 * db;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        cerr << "ERROR OPENING DB\n";
        return;
    }

    string query = "SELECT id, content, type, timestamp FROM clipboard WHERE content LIKE ? COLLATE NOCASE";
    if (!typeFilter.empty()) query += " AND type = ?";
    if (!afterDate.empty()) query += " AND timestamp >= ?";
    query += " ORDER BY timestamp DESC;";

    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        int paramIndex = 1;
        string likePattern = "%" + keyword + "%";
        sqlite3_bind_text(stmt, paramIndex++, likePattern.c_str(), -1, SQLITE_STATIC);
        if (!typeFilter.empty()) sqlite3_bind_text(stmt, paramIndex++, typeFilter.c_str(), -1, SQLITE_STATIC);
        if (!afterDate.empty()) sqlite3_bind_text(stmt, paramIndex++, afterDate.c_str(), -1, SQLITE_STATIC);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* content = sqlite3_column_text(stmt, 1);
            const unsigned char* type = sqlite3_column_text(stmt, 2);
            const unsigned char* ts = sqlite3_column_text(stmt, 3);

            cout << "[" << id << "] (" << type << ") @ " << ts << "\n"
            << "   " << content << "\n\n";
        }

        sqlite3_finalize(stmt);
    } else {
        cerr << "SQL error: " << sqlite3_errmsg(db) << "\n";
    }
    sqlite3_close(db);
}
