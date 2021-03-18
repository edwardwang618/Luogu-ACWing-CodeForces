#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, string> PIS;

const int d[] = {1, 0, -1, 0, 1};
const char op[] = "dlur";
string ed = "12345678x";

int h(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) 
        if (s[i] != 'x') {
            int t = s[i] - '1';
            res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
        }

    return res;
}

string bfs(string st) {
    unordered_map<string, int> dist;
    unordered_map<string, pair<char, string> > prev;
    priority_queue<PIS, vector<PIS>, greater<PIS> > heap;

    dist[st] = 0;
    heap.push({h(st), st});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        string cur = t.y;
        if (cur == ed) break;

        int x, y;
        for (int i = 0; i < 9; i++)
            if (cur[i] == 'x') {
                x = i / 3, y = i % 3;
                break;
            }

        string orig = cur;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                cur = orig;
                swap(cur[3 * x + y], cur[3 * nx + ny]);
                if (!dist.count(cur) || dist[cur] > dist[orig] + 1) {
                    dist[cur] = dist[orig] + 1;
                    prev[cur] = {op[i], orig};
                    heap.push({dist[cur] + h(cur), cur});
                }
            }
        }
    }

    string res;
    while (ed != st) {
        res += prev[ed].x;
        ed = prev[ed].y;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string st, seq;
    char c;
    while (cin >> c) {
        st += c;
        if (c != 'x') seq += c;
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++)
            if (seq[i] > seq[j]) cnt++;

    if (cnt & 1) cout << "unsolvable" << endl;
    else cout << bfs(st) << endl;

    return 0;
}