#include <iostream>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;
const double eps = 1e-6;

int n, m;
char g[N][N];
PII q[N * N];

double get_dist(PII a, PII b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double get_hash(int size) {
    double sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            sum += get_dist(q[i], q[j]);
    return sum;
}

char get_id(double key) {
    static double hash[30];
    static int id = 0;
    for (int i = 0; i < id; i++) 
        if (fabs(hash[i] - key) < eps)
            return i + 'a';
    hash[id++] = key;
    return id - 1 + 'a';
}

void dfs(int x, int y, int& size) {
    q[size++] = {x, y};
    g[x][y] = '0';
    for (int a = x - 1; a <= x + 1; a++) 
        for (int b = y - 1; b <= y + 1; b++) {
            if (a == x && b == y) continue;
            if (0 <= a && a < m && 0 <= b && b < n && g[a][b] == '1')
                dfs(a, b, size);
        }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> g[i];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] == '1') {
                int size = 0;
                dfs(i, j, size);
                char c = get_id(get_hash(size));
                for (int k = 0; k < size; k++) 
                    g[q[k].x][q[k].y] = c;
            }

    for (int i = 0; i < m; i++) cout << g[i] << endl;

    return 0;
}