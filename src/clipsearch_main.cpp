#include "../include/Search.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc,char* argv[]){
    if(argc<2){
        cout<<"If you want a specific clip then use <keyword>\n";
        Search::searchAllDB("../data/clipboard.db");
        return 0;
    }
    string keyword = argv[1];
    string type = (argc>2)?argv[2]:"";
    string date = (argc>3)?argv[3]:"";
    Search::searchDB("../data/clipboard.db", keyword,type,date);
    return 0; 
}