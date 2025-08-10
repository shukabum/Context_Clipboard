#include "../include/Search.h"
#include<iostream>
#include<string>

using namespace std;

int main(int argc,char* argv[]){
    if(argc<2){
        cout<<"Usage: clipsearch <keyword>\n";
        return 1;
    }

    string keyword = argv[1];

    Search::searchDB("../data/clipboard.db", keyword);

    return 0; 
}