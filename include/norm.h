/*************************************************************************
	> File Name: norm.h
	> Author: Pelhans
	> Mail: me@pelhans.com
	> Created Time: Tue 09 Mar 2021 12:50:49 AM CST
 ************************************************************************/
#ifndef NORM_H
#define NORM_H

#include <set>
#include <string>
#include <vector>

class TextProcess{
    TextProcess();
    ~TextProcess();
    public:
        set<string> punc{"·", ",", ".", "。", "，", "!"};
        int remove_punc(const string &ori_str, string &out_str);
        int TextProcess::string2vec(const string &ori_str, vector<string> &vec)
};

#endif
