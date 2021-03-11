#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

string st, ed;
unordered_map<string, int> dist;
unordered_map<string, pair<char, string> > pre;
queue<string> q;

vector<string> move(string cur) {
    vector<string> res;
    string m1 = cur.substr(4, 4);
    m1 += cur.substr(0, 4);

    string m2;
    m2 += cur[3] + cur.substr(0, 3);
    m2 += cur[7] + cur.substr(4, 3);

    string m3 = cur;
    m3[1] = cur[5], m3[2] = cur[1], m3[5] = cur[6], m3[6] = cur[2];

    res.push_back(m1);
    res.push_back(m2);
    res.push_back(m3);

    return res;
}

void bfs() {
    if (st == ed) return;

    q.push(st);
    dist[st] = 0;

    while (!q.empty()) {
        string t = q.front();
        q.pop();

        vector<string> nexts = move(t);
        for (int i = 0; i < 3; i++) {
            string s = nexts[i];
            if (dist.count(s)) continue;
            dist[s] = dist[t] + 1;
            pre[s] = {char(i + 'A'), t};

            if (s == ed) return;
            q.push(s);
        }
    }
}

int main() {
    int x;
    for (int i = 0; i < 8; i++) {
        cin >> x;
        ed += char(x + '0');
    }

    for (int i = 0; i < 8; i++) st += char(i + '1');
    reverse(st.begin() + 4, st.end());
    reverse(ed.begin() + 4, ed.end());

    bfs();

    cout << dist[ed] << endl;

    string res;
    while (ed != st) {
        res += pre[ed].first;
        ed = pre[ed].second;
    }

    reverse(res.begin(), res.end());
    if (!res.empty()) cout << res << endl;

    return 0;
}