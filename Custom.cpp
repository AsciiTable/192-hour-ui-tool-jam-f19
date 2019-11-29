//
// Created by Jessica Wei on 11/28/19.
//

#include "Custom.h"
Custom::Custom(){
    type = "";
    txt = "";
    rpos = 0;
    cpos = 0;
}

Custom::Custom(string type, string s, int r, int c) {
    type = "Custom";
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

string Custom::toString() {
    return type + ": " + txt + " @ " + to_string(rpos) + ", " + to_string(cpos);
}