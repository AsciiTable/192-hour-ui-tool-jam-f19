//
// Created by Jessica Wei on 11/28/19.
//

#include "Custom.h"
Custom::Custom(string s, int r, int c) {
    txt = s;
    rpos = r;
    cpos = c;
}

string Custom::getString(){
    return txt;
}

int Custom::getRowPos(){
    return rpos;
}

int Custom::getColPos(){
    return cpos;
}