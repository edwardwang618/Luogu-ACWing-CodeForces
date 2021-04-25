#include <iostream>
#include <queue>
using namespace std;

const int N = 700, M = 100010;
int n;
int h[N], e[M], w[M], ne[M], idx;
int cnt[N];
bool st[N];

void add(int a, int b, int c) {

}

int main() {
    char str[1010];
    while (scanf("%d", &n), n) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            int len = strlen(str);
            if (len >= 2) {
                int left = (str[0] - 'a') * 26 + str[1] - 'a';
                int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
                add(left, right, len);
            }
        }
    }


    return 0;
}