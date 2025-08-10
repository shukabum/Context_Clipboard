#include "../include/ClipBoardListener.h"
#include "../include/Classifier.h"
#include "../include/Database.h"
#include<iostream>
using namespace std;

int main(){
    Database db("../data/clipboard.db");
    string lastClipboardContent;
    ClipBoardListener listener([&](const string &text){
        if(lastClipboardContent == text) return;
        ContentType type = Classifier::classify(text);
        db.insertEntry(text,type);
        cout<<"[Capture] ("<<Classifier::typeToString(type)<<"): "<<text<<"\n";
    });

    listener.start();
    return 0;
}