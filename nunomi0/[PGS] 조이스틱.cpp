#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int n = name.length();
    int answer = 0;

    // 상하 조작 횟수
    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    // 좌우 조작 최소 계산
    int move = n - 1;
    for (int i = 0; i < n; i++) {
        int next = i + 1;
        while (next < n && name[next] == 'A') next++;
        // i 까지 갔다가 → 0 으로 돌아가서 → 끝까지 가는 경로
        move = min(move, i*2 + n-next);
        // i 까지 갔다가 → 반대로 끝에서 돌아오는 경로
        move = min(move, i + (n - next)*2);
    }

    return answer + move;
}
