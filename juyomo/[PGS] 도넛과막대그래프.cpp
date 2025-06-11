// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/258711

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

// 정점 number, donut, stick, 8

// midpoint is the only one that has 3 edges going out, no incoming
// donut: 1 in, 1 out
// stick: null, or one in/one out, or one in and one out
// 8: midpoint has 2 in 2 out, rest have 1 in 1 out
vector<int> solution(vector<vector<int>> edges) {
    unordered_map<int, vector<int>> incomingEdges;
    unordered_map<int, vector<int>> outgoingEdges;
    unordered_set<int> allNodes;
    for (int i = 0; i < edges.size(); i++) {
        int to = edges[i][1];
        int from = edges[i][0];
        incomingEdges[to].push_back(from);
        outgoingEdges[from].push_back(to);
        allNodes.insert(to);
        allNodes.insert(from);
    }
    
    //unordered_set<int> possibleMids;
    int mid;
    for (int node : allNodes) {
        if (incomingEdges.find(node) == incomingEdges.end() &&
            outgoingEdges[node].size() >= 2) {
            // a node with no incoming edges has a possibility of being a midpoint
            //possibleMids.insert(node);
            mid = node;
        }
    }
    
    vector<int> answer;
    answer.push_back(mid);
    
    int numStick = 0;
    int numDonut = 0;
    int numEight = 0;
    
    for (int n : outgoingEdges[mid]) {
        // traverse graph starting at n and figure out what type of graph it is
        int original = n;
        while (outgoingEdges[n].size() > 0) {
            if (outgoingEdges[n].size() == 2) {
                numEight++;
                break;
            }
            n = outgoingEdges[n][0];
            if (n == original) {
                numDonut++;
                break;
            }
        }
        // if no cycle, it's a stick
        if (outgoingEdges[n].size() == 0) {
            numStick++;
        }
    }
    
    answer.push_back(numDonut);
    answer.push_back(numStick);
    answer.push_back(numEight);
    return answer;
}
