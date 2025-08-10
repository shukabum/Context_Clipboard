#pragma once
#include<string>
#include "Classifier.h"
using namespace std;

class Database{
    public:
    Database(const string & dbPath);
    ~Database();
    void insertEntry(const string &content,ContentType type);
    
    private:
    void * db;

};