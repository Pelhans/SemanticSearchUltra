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
        static int remove_punc(std::string &ori_str, std::string &out_str);
};

#endif
