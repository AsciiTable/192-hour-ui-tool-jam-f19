//
// Created by Jessica Wei on 11/28/19.
//
#include <string>
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
    virtual string toString();
};

class TextCustom: public Custom{
public:
    TextCustom(string s, int r, int c){
        type = "Text";

    };

};

#endif //INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
