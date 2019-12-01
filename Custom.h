//
// Created by Jessica Wei on 11/28/19.
//
#include <string>
#include <vector>
#ifndef INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
#define INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
using namespace std;

class Custom {
protected:
    string type;
    string txt;
    int rpos;
    int cpos;
public:
    Custom();
    Custom(string type, string s, int r, int c);
    string getString();
    int getRowPos();
    int getColPos();
    string toString();
};

class TextCustom: public Custom{
public:
    TextCustom(string s, int r, int c){
        type = "Text";
        txt = s;
        rpos = r;
        cpos = c;
    };
};

class ButtonCustom: public Custom{
public:
    vector<string> functs;
    ButtonCustom(string s, int r, int c){
        type = "Button";
        txt = s;
        rpos = r;
        cpos = c;
    };
    // Functionalities
    // Change color of window
    //
};

#endif //INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
