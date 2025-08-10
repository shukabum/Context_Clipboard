#include "../include/ClipBoardListener.h"
#include<windows.h>
#include<thread>
#include<chrono>

using namespace std;

ClipBoardListener::ClipBoardListener(ClipboardCallback cb): callback(cb){}

string lastContent;

bool ClipBoardListener::onClipboardChange(const string &newContent, ContentType type) {
    if (newContent.empty() || newContent == lastContent) return true;
    lastContent = newContent;
    return false;
}

string ClipBoardListener::getClipboardText(){
    if(!OpenClipboard(nullptr)) return "";

    HANDLE hData = GetClipboardData(CF_TEXT);
    if(hData == nullptr){
        CloseClipboard();
        return "";
    }

    char* pszText = static_cast<char*> (GlobalLock(hData));
    if(pszText==nullptr){
        CloseClipboard();
        return "";
    }
    string text(pszText);
    GlobalUnlock(hData);
    CloseClipboard();

    return text;
}

void ClipBoardListener::start(){
    string lastText;
    while(true){
        string current = getClipboardText();
        if(!current.empty()&& current!=lastText){
            lastText = current;
            callback(current);
        }
        this_thread :: sleep_for(chrono::milliseconds(500));
    }
}