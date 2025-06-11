#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

struct mission {
    string name;
    int start; // minute
    int playtime; // minute
};

bool comp(mission m1, mission m2){
    return m1.start < m2.start;
}

vector<string> solution(vector<vector<string>> plans) {
    
    // vector<string> -> mission
    vector<mission> missions;
    for (int i = 0; i<plans.size(); i++){
        mission m;
        
        // name
        m.name=plans[i][0];
        
        // start
        int start_hour = stoi(plans[i][1].substr(0,2));
        int start_minute = stoi(plans[i][1].substr(3,2));
        m.start = start_hour*60+start_minute;
        
        // playtime
        m.playtime=stoi(plans[i][2]);
        
        missions.push_back(m);
    }
    
    // 시작 시간 오름차순으로 정렬
    sort(missions.begin(),missions.end(),comp);
    
    // log
    for (int i = 0; i<missions.size(); i++){
        cout << missions[i].name << ' ';
        cout << missions[i].start << ' ';
        cout << missions[i].playtime << '\n';
    }
    
    // 과제 실행
    vector<string> answer;
    stack<mission> paused;
    int cur_time = missions[0].start;
    
    for (int i = 0; i<missions.size(); i++){
        int nxt_start = missions[i].start;
        
        // 멈춰둔 과제를 끝낼 수 있는 경우
        while (!paused.empty()){
            if (cur_time+paused.top().playtime<=nxt_start){ 
                cur_time+=paused.top().playtime;
                answer.push_back(paused.top().name);
                paused.pop();
            }
            else break;
        }
        
        // 새로운 과제를 하는 경우
        if (!paused.empty()){
            paused.top().playtime-=(nxt_start-cur_time);
        }
        cur_time=nxt_start;
        paused.push(missions[i]);
    }
    
    // 끝내지 못한 과제 처리
    while (!paused.empty()){
        answer.push_back(paused.top().name);
        paused.pop();
    }
    
    return answer;
}
