/*************************************************************************
	> File Name: main.cpp
	> Author: Pelhans
	> Mail: me@pelhans.com
	> Created Time: Tue 09 Mar 2021 12:52:15 AM CST
 ************************************************************************/
 #include <iostream>
 #include "src/norm.h"

 using namespace std;

int main(){
    string input = "今天是个好天气，好呀好h天气,是不。";
    string out_str = "";
    int status = TextProcess::remove_punc(input, out_str);
    cout << out_str << endl;
    return 0;
}
