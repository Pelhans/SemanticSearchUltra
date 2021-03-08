/*************************************************************************
	> File Name: norm.cpp
	> Author: Pelhans
	> Mail: me@pelhans.com
	> Created Time: Tue 09 Mar 2021 12:50:30 AM CST
 ************************************************************************/
#include <iostream>
#include "../include/norm.h"
#include "../include/str_util.h"

using namespace std;

std::set<std::string> punc{"·", ",", ".", "。", "，", "!"};

int TextProcess::remove_punc(string &ori_str, string &out_str){
    vector<string> vec;
    string2vector(ori_str, vec);
    for (int i=0; i< vec.size(); i++){
        if (punc.find(vec[i]) == punc.end()){
            out_str += vec[i];
        }
    }
    return 1;
}

