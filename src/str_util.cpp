/*************************************************************************
	> File Name: str_util.cpp
	> Author: Pelhans
	> Mail: me@pelhans.com
	> Created Time: Tue 09 Mar 2021 12:51:23 AM CST
 ************************************************************************/
#include "../include/str_util.h"

using namespace std;

int string2vector(const string &text, vector<string> &v){
    for (size_t i=0; i<text.length();){
        size_t cplen = 1;
        if ((text[i] & 0xf8) == 0xf0) cplen = 4;
        else if ((text[i] & 0xf0) == 0xe0) cplen = 3;
        else if (text[i] & 0xe0 == 0xc0) cplen = 2;
        if ((i + cplen) > text.length()) cplen = 1;

        v.push_back(text.substr(i, cplen));
        i += cplen;
    }
    return 0;
}
