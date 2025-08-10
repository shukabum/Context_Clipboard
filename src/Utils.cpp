#include "../include/Utils.h"
using namespace std;

string Utils::toLower(const string &str){
    string lower = str;
    transform(lower.begin(),lower.end(),lower.begin(),[](unsigned char c){return tolower(c);});
    return lower;
}

string Utils:: trim(const string & str){
    size_t first =str.find_first_not_of("\t\n\r");
    if(first  == string::npos) return "";
    size_t last = str.find_last_not_of("\t\n\r");

    return str.substr(first,(last-first+1));
}
