//
// Created by Jessica Wei on 11/27/19.
//

#include <string>
#ifndef INC_192_HOUR_UI_TOOL_JAM_TEXTCUSTOM_H
#define INC_192_HOUR_UI_TOOL_JAM_TEXTCUSTOM_H
using namespace std;


class TextCustom {
private:
    string txt;
    int rpos;
    int cpos;
public:
    TextCustom(string s, int r, int c);
    string getString();
    int getRowPos();
    int getColPos();
};


#endif //INC_192_HOUR_UI_TOOL_JAM_TEXTCUSTOM_H
