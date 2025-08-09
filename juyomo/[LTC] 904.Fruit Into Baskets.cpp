// Author: Juyoung Moon
// https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        unordered_map<int, int> counts;
        unordered_set<int> fruitTypes;
        int maxLen = 0;

        for (int r = 0; r < fruits.size(); r++) {
            int newlyAdded = fruits[r];
            fruitTypes.insert(newlyAdded);
            counts[newlyAdded]++;

            while (fruitTypes.size() > 2) {
                int toRemove = fruits[left];
                counts[toRemove]--;
                if (counts[toRemove] == 0) {
                    fruitTypes.erase(toRemove);
                }
                left++;
            }
            
            int currLen = r - left + 1;
            if (currLen > maxLen) {
                maxLen = currLen;
            }
        }

        return maxLen;
    }
};
