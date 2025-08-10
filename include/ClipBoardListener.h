#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#pragma once
#include<string>
#include <windows.h>
#include<functional>
#include"Classifier.h"
using namespace std;

class ClipBoardListener{
    public:
    using ClipboardCallback = function<void(const string&)>;

    ClipBoardListener(ClipboardCallback cb);

    bool onClipboardChange(const string &newContent, ContentType type);
    void start();

    private:
    ClipboardCallback callback; 
    string getClipboardText();
};