#include"../include/Classifier.h"
#include<regex>
#include<algorithm>

using namespace std;
ContentType Classifier::classify(const string &content){
    regex urlRegex(R"(https?:\/\/[^\s]+)");
    regex emailRegex(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");
    regex pathRegex(R"(([A-Za-z]:\\|\/)[^\s]+)");

    if(regex_match(content,urlRegex)) return ContentType::URL;
    if(regex_match(content,emailRegex)) return ContentType::EMAIL;
    if(regex_match(content,pathRegex)) return ContentType::FILE_PATH;

    if(content.find("{")!=string::npos||content.find(";")!=string::npos) return ContentType::CODE;


    return ContentType::TEXT;
}

string Classifier::typeToString(ContentType type){
    switch (type){
        case ContentType::URL: return "URL";
        case ContentType::EMAIL :return "EMAIL";
        case ContentType::FILE_PATH :return "FILE_PATH";
        case ContentType::CODE :return "CODE";
        default: return "TEXT";
    }
}