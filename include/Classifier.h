#pragma once
#include<string>
using namespace std;


enum class ContentType{
   URL,
   EMAIL,
   FILE_PATH,
   CODE,
   TEXT
};


class Classifier{
    public:
    static ContentType classify(const string &content);
    static string typeToString(ContentType type);
};