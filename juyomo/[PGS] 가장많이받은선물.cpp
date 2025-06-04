// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/258712
// Solved on Wed, June 4, 2025

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    unordered_map<string, int> giftScores;
    unordered_map<string, int> pairScores;
    unordered_map<string, int> giftCount;
    
    for (const string& s : gifts) { 
        int spaceIdx = s.find(" ");
        string from = s.substr(0, spaceIdx);
        string to = s.substr(spaceIdx + 1);
        
        giftScores[from]++;
        giftScores[to]--;
        
        pairScores[from + "," + to]++;
    }
    
    
    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            string me = friends[i];
            string you = friends[j];
            int given = pairScores[me + "," + you];
            int received = pairScores[you + "," + me];
            if (given > received) 
                giftCount[me]++;
            } else if (given < received) {
                giftCount[you]++;
            } else if (giftScores[you] < giftScores[me]) {
                giftCount[me]++;
            } else if (giftScores[you] > giftScores[me]) {
                giftCount[you]++;
            }
        }
    }
    
    int maxGifts = 0;
    string personWhoReceivesMost = "";
    
    for (const auto& p : giftCount) {
        const string& name = p.first;
        int num = p.second;
        if (num > maxGifts) {
            maxGifts = num;
            personWhoReceivesMost = name;
        }
    }
    
    return maxGifts;
}
