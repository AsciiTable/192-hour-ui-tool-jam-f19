//
// Created by Jessica Wei on 11/28/19.
//
#include <string>
#ifndef INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
#define INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
using namespace std;


class Custom {
private:
    string txt;
    int rpos;
    int cpos;
public:
    Custom(string s, int r, int c);
    string getString();
    int getRowPos();
    int getColPos();
};


#endif //INC_192_HOUR_UI_TOOL_JAM_CUSTOM_H
