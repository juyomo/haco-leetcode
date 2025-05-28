// Author: Juyoung Moon
// Solved on: Wed, May 28, 2025
// https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

typedef unordered_set<pair<int, int>, pair_hash> CoordSet;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main() {
    int cols, rows;
    cin >> cols >> rows;

    CoordSet ripe;
    int notRipeCount = 0;
    vector<vector<int>> m(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int ripeness; // -1 is a wall, 0 is not ripe, 1 is ripe
            cin >> ripeness;
            m[i][j] = ripeness;

            if (ripeness == 1) {
                ripe.insert(make_pair(i, j));
            } else if (ripeness == 0) {
                notRipeCount++;
            }
        }
    }

    // All tomatoes are ripe.
    if (notRipeCount == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Start the ripening process...
    int days = 0;
    
    while (notRipeCount > 0) {
        days++;
        
        CoordSet addedThisRound;
        for (const auto& cell : ripe) {
            // for each cell that is already ripe, add its neighbors
            int r = cell.first;
            int c = cell.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nc < 0 || nr < 0 || nr >= rows || nc >= cols || m[nr][nc] == -1) {
                    continue;
                } else if (m[nr][nc] == 0) {
                    m[nr][nc] = 1;
                    addedThisRound.insert(make_pair(nr, nc));
                }
            }
        }

        notRipeCount -= addedThisRound.size();

        // We are done! All tomatoes are ripe.
        if (notRipeCount == 0) {
            cout << days << endl;
            return 0;
        }

        // No new ripe tomatoes added. But if there are still tomatoes that are at 0, we can't reach them. Print -1. :'(
        if (addedThisRound.size() == 0) {
            cout << -1 << endl;
            return 0;
        }

        ripe = addedThisRound;
    }
}
