// Author: Juyoung Moon
// Solved on Wed, June 11, 2025 as part of Hoco-LeetCode study
// https://school.programmers.co.kr/learn/courses/30/lessons/72410

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void removeLastDot(string& str) {
    int idx = -1;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != '.') {
            idx = i;
            break;
        }
    }
    if (idx >= 0) {
        str = str.substr(0, idx + 1);
    }
}

string solution(string new_id) {
    string ans = "";
    
    // STEP 1 & 2.
    for (int i = 0; i < new_id.size(); i++) {
        char c = new_id[i];
        if (isalpha(c) || isdigit(c) || c == '-' || c == '_' || c == '.') {
            ans += tolower(c);
        }
    }
    
    // STEP 3 & 4a.
    bool firstNonPeriod = false;
    string ans2 = "";
    for (int i = 0; i < ans.size(); i++) {
        char c = ans[i];
        if (c != '.') {
            firstNonPeriod = true;
        }
        if (c == '.' && !firstNonPeriod) {
            continue;
        }
        if (c == '.' && c > 0 && ans[i-1] == '.') {
            continue;
        }
        ans2 += c;
    }
    
    string ans3 = ans2;
    
    // STEP 4b. Need to remove last .s
    removeLastDot(ans3);
    
    // STEP 5.
    if (ans3.empty()) {
        ans3 = "a";
    }
    
    // STEP 6.
    if (ans3.size() >= 16) {
        ans3.resize(15);
    }
    
    // STEP 6a. Remove last .
    removeLastDot(ans3);
    
    // STEP 7.
    if (ans3.size() <= 2) {
        char lastChar = ans3[ans3.size() - 1];
        while (ans3.size() < 3) {
            ans3 += lastChar;
        }
    }
    
    return ans3;
}

/* Mine is long. Somebody solved it like this really nicely:

#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}
*/
