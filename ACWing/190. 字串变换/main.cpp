#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int N = 6;

int n;
string a[N], b[N];
int res;

bool extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[]) {
    string t = q.front();
    q.pop();

    for (int i = 0; i < t.size(); i++)
        for (int j = 0; j < n; j++)
            if (t.substr(i, a[j].size()) == a[j]) {
                string ne = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
                if (da.count(ne)) continue;
                da[ne] = da[t] + 1;

                if (db.count(ne)) {
                    res = da[ne] + db[ne];
                    return true;
                }

                q.push(ne);
            }

    return false;
}

int bfs(string A, string B) {
    unordered_map<string, int> da, db;
    da[A] = db[B] = 0;

    queue<string> qa, qb;
    qa.push(A), qb.push(B);

    while (qa.size() && qb.size()) {
        if (qa.size() <= qb.size()) {
            if (extend(qa, da, db, a, b)) return res;
        } else if (extend(qb, db, da, b, a)) return res;
    }

    return 11;
}

int main() {
    string A, B;
    cin >> A >> B;

    while (cin >> a[n] >> b[n]) n++;

    int res = bfs(A, B);
    if (res > 10) cout << "NO ANSWER!" << endl;
    else cout << res << endl;

    return 0;
}