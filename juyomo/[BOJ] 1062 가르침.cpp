#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool debug = false;

//
int howManyCanILearn(const vector<unordered_set<char>>& words,
                     const vector<int>& charList) {
    int num = 0;
    for (const unordered_set<char>& st : words) {
        bool canUse = true;
        for (char c : st) {
            int charIdx = c - 'a';
            if (charList[charIdx] != 1) {
                canUse = false;
                break;
            }
        }
        if (canUse) {
            num++;
        }
    }
    return num;
}

//
void backtrack(const vector<unordered_set<char>>& words,
               const vector<int>& inputList,
               int index,
               int remaining,
               vector<int>& currChoices,
               int& maxSoFar) {
    if (remaining < 0) {
        return;
    }

    if (remaining == 0 || index >= inputList.size()) {
        int currMax = howManyCanILearn(words, currChoices);
        if (currMax > maxSoFar) {
            maxSoFar = currMax;
        }
        return;
    }

    
    backtrack(words, inputList, index + 1, remaining, currChoices, maxSoFar);
    if (inputList[index] == 0) {
        currChoices[index] = 1;
        backtrack(words, inputList, index + 1, remaining - 1, currChoices, maxSoFar);
        currChoices[index] = 0;
    }
}

//
int countPossibleWords(const vector<unordered_set<char>>& words,
                  int lettersICanLearn,
                  const vector<int>& charList) {
    if (lettersICanLearn < 0) {
        return 0;
    }

    vector<int> currChoices(charList.size(), 0);
    int maxSoFar = 0;
    backtrack(words, charList, 0, lettersICanLearn, currChoices, maxSoFar);

    return maxSoFar;
}

//
int main() {
    int numWords, numLettersICanLearn;
    cin >> numWords >> numLettersICanLearn;
    
    numLettersICanLearn -= 5;

    // PROCESS DATA
    vector<unordered_set<char>> charsPerWord(numWords);
    vector<int> charList(26, -1);
    // -1 doesn't exist
    // 0 exists
    // 1 learned

    for (int i = 0; i < numWords; i++) {
        string s;
        cin >> s;
        // anta rc tica
        // antic <- 5 chars need to learn
        // remove all antic chars from s
        unordered_set<char>& chars = charsPerWord[i];
        for (char c : s) {
            if (c != 'a' && c != 'n' && c != 't' && c != 'i' && c != 'c') {
                chars.insert(c);
                charList[c - 'a'] = 0; // mark char as existing
            }
        }
    }
    
    if (debug) {
        for (const auto& st : charsPerWord) {
            for (const auto& c : st) {
                cout << c << " ";
            }
            cout << endl;
        }
    }

    int numCharsThatExist = 0;
    for (int flag : charList) {
        if (flag == 0) {
            numCharsThatExist++;
        }
    }
    if (numLettersICanLearn >= numCharsThatExist) {
        cout << numWords << endl;
        return 0;
    }

    cout << countPossibleWords(charsPerWord, numLettersICanLearn, charList) << endl;
}
