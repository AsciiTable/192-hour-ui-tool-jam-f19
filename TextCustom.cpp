//
// Created by Jessica Wei on 11/27/19.
//

#include "TextCustom.h"

TextCustom::TextCustom(string s, int r, int c) {
    txt = s;
    rpos = r;
    cpos = c;
}

string TextCustom::getString(){
    return txt;
}

int TextCustom::getRowPos(){
    return rpos;
}

int TextCustom::getColPos(){
    return cpos;
}
