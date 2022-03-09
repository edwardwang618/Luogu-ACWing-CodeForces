#include <iostream>  
#include <cstring>
using namespace std;

const int N = 2e7 + 10;
int n;
char a[N], b[N];
int p[N];
int res;

void init() {
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for (int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
}

void manacher() {
    int mr = 0, mid;
    for (int i = 1; i < n; i++) {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;

        while (b[i - p[i]] == b[i + p[i]]) p[i]++;

        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }

        res = max(res, p[i] - 1);
    }
}

int main() {
    scanf("%s", a);
    n = strlen(a);
    init();
    manacher();
    
    printf("%d\n", res);
    return 0;
}