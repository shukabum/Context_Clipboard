#pragma once
#include<string>
using namespace std;

class Search{
    public:
    static void searchDB(const string &dbPath, 
        const string &keyword,
        const string &typeFilter = "",
        const string &afterDate = "");
};