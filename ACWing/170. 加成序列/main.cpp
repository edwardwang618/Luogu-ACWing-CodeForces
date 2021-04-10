#include <iostream>
using namespace std;

const int N = 110;
int n;
int a[N];

bool dfs(int depth, int max_depth) {
    if (depth > max_depth) return false;

    if (a[depth - 1] == n) return true;

    bool st[N] = {0};
    for (int i = depth - 1; i >= 0; i--) 
        for (int j = i; j >= 0; j--) {
            int s = a[i] + a[j];
            if (s > n || s <= a[depth - 1] || st[s]) continue;

            st[s] = true;
            a[depth] = s;
            if (dfs(depth + 1, max_depth)) return true;
        }

    return false;
}

int main() {
    a[0] = 1;
    while (cin >> n, n) {
        int max_depth = 1;
        while (!dfs(1, max_depth)) 
            max_depth++;
        
        for (int i = 0; i < max_depth; i++) 
            cout << a[i] << ' ';
        
        cout << endl;
    }

    return 0;
}