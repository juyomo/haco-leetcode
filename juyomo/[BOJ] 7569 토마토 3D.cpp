// Author: Juyoung Moon
// Solved on: Wed, May 28, 2025
// https://www.acmicpc.net/problem/7569
// 토마토 3D

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> Coordinate;
struct CoordHash {
    size_t operator()(const Coordinate& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
typedef unordered_set<Coordinate, CoordHash> CoordSet;

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int main() {
    int xlen, ylen, zlen;
    cin >> xlen >> ylen >> zlen;

    CoordSet ripe;
    int notRipeCount = 0;
    vector<vector<vector<int>>> m(xlen, vector<vector<int>>(ylen, vector<int>(zlen)));

    for (int zi = 0; zi < zlen; zi++) {
        for (int yi = 0; yi < ylen; yi++) {
            for (int xi = 0; xi < xlen; xi++) {
                int ripeness;
                cin >> ripeness;
                m[xi][yi][zi] = ripeness;

                if (ripeness == 1) {
                    ripe.insert({xi, yi, zi});
                } else if (ripeness == 0) {
                    notRipeCount++;
                }
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
            int xi = cell[0];
            int yi = cell[1];
            int zi = cell[2];

            for (int i = 0; i < 6; i++) {
                int nx = xi + dx[i];
                int ny = yi + dy[i];
                int nz = zi + dz[i];
                if (nx < 0 || ny < 0 || nz < 0 ||
                    nx >= xlen || ny >= ylen || nz >= zlen ||
                    m[nx][ny][nz] == -1) {
                    continue;
                } else if (m[nx][ny][nz] == 0) {
                    m[nx][ny][nz] = 1;
                    addedThisRound.insert({nx, ny, nz});
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
