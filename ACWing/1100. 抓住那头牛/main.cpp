#include <iostream>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
int n, k;
queue<int> q;
bool st[N];

int bfs(int n, int k) {
    if (n == k) return 0;
    
    int res = 0;
    q.push(n);
    st[n] = true;
    while (!q.empty()) {
        res++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int t = q.front();
            q.pop();
            if (t == k) return res;

            if (!st[t - 1] && t - 1 >= 0) {
                if (t - 1 == k) return res;
                q.push(t - 1); 
                st[t - 1] = true;
            }

            if (t < k) {
                if (!st[t + 1]) {
                    if (t + 1 == k) return res;
                    q.push(t + 1);
                    st[t + 1] = true;
                }
                if (!st[t * 2]) {
                    if (t * 2 == k) return res;
                    q.push(t * 2);
                    st[t * 2] = true;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> k;
    cout << bfs(n, k) << endl;

    return 0;
}