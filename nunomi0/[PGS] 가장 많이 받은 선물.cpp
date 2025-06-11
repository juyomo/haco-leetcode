#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string,int> m;
    int cnt[60][60]={}; // giver taker
    int gift_score[60]={};
    int nxt_gift[60]={};
    
    // name to idx
    for (int i = 0; i<friends.size(); i++){
        m[friends[i]]=i;
    }
    
    // 이번 달 선물 기록
    for (int i = 0; i<gifts.size(); i++){
        // gifts 문자열 파싱
        int giver, taker;
        for (int j = 0; j<gifts[i].size(); j++){
            if (gifts[i][j]==' ') {
                giver = m[gifts[i].substr(0,j)];
                taker = m[gifts[i].substr(j+1,gifts[i].size())];  
                break;
            }
        }
        
        // 개인별 선물 기록
        cnt[giver][taker]++;
    }
    
    // 선물 지수 계산
    for (int i = 0; i<friends.size(); i++){
        int give=0;
        int take=0;
        for (int j = 0; j<friends.size(); j++){
            give+=cnt[i][j];
            take+=cnt[j][i];            
        }
        gift_score[i]=give-take;
    }
        
    // 두 사람의 선물 기록 비교
    for (int i = 0; i<friends.size(); i++){
        for (int j = 0; j<friends.size(); j++){
            if (cnt[i][j]>cnt[j][i]){ // i가 j에게 준 선물이 더 많은 경우
                nxt_gift[i]++;
            }
            else if (cnt[i][j]==cnt[j][i]) { // 선물 주고 받은 수가 같은 경우
                // 선물 지수 비교
                if (gift_score[i]>gift_score[j]){
                    nxt_gift[i]++;
                }
            }
        }
    }
    
    // 최댓값 계산
    int mx = 0;
    for (int i = 0; i<friends.size(); i++){
        mx = max(mx, nxt_gift[i]);
    }
    return mx;
}
