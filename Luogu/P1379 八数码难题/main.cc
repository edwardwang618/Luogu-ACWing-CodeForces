#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
using PIS = pair<int, string>;

string s, ed = "123804765";
int d[] = {-1, 0, 1, 0, -1};
int pos[9];
unordered_map<string, int> dist;
priority_queue<PIS, vector<PIS>, greater<>> heap;

int h(string &s) {
    int dis = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] == '0') continue;
        int x = i / 3, y = i % 3;
        int xx = pos[s[i] - '0'] / 3, yy = pos[s[i] - '0'] % 3;
        dis += abs(x - xx) + abs(y - yy);
    }

    return dis;
}

int Astar() {
    dist[s] = 0;
    heap.push({h(s), s});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        s = t.second;
        if (s == ed) return dist[s];

        int idx = 0;
        while (s[idx] != '0') idx++;
        int x = idx / 3, y = idx % 3;
        for (int i = 0; i < 4; i++) {
            string ss = s;
            int xx = x + d[i], yy = y + d[i + 1];
            if (0 <= xx && xx < 3 && 0 <= yy && yy < 3) {
                swap(ss[idx], ss[xx * 3 + yy]);
                if (!dist.count(ss) || dist[ss] > dist[s] + 1) {
                    dist[ss] = dist[s] + 1;
                    heap.push({dist[ss] + h(ss), ss});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> s;
    for (int i = 0; i < 9; i++) pos[ed[i] - '0'] = i;

    printf("%d\n", Astar());
    return 0;
}