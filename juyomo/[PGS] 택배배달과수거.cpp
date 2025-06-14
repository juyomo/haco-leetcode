// Author: Juyoung Moon
// https://school.programmers.co.kr/learn/courses/30/lessons/150369
// Solved on Sat, June 14, 2025

#include <string>
#include <vector>
#include <iostream>

using namespace std;

void helper(int& farthest, vector<int>& data, int cap) {
    int done = 0;
    for (int i = farthest; i >= 0; i--) {
        if (done + data[i] <= cap) {
            done += data[i];
            data[i] = 0;
        } else {
            // over cap
            int delta = cap - done;
            data[i] -= delta;
            farthest = i;
            return;
        }
    }
    
    farthest = -1;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int farthestDelivery = -1;
    int farthestPickup = -1;
    
    for (int i = n-1; i >= 0; i--) {
        if (deliveries[i] != 0) {
            farthestDelivery = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (pickups[i] != 0) {
            farthestPickup = i;
            break;
        }
    }
    
    long long distance = 0;
    int nextTravelPoint = max(farthestDelivery, farthestPickup);
    while (nextTravelPoint >= 0) {
        helper(farthestDelivery, deliveries, cap);
        helper(farthestPickup, pickups, cap);
        
        distance += 2 * (nextTravelPoint + 1);
        nextTravelPoint = max(farthestDelivery, farthestPickup);
    }
    
    return distance;
}
