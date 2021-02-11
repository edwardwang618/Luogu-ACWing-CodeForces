#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int l, int r) {
    if (l >= r) return;

    int m = a[l + (r - l >> 1)];
    int i = l, j = r;
    do{
        while(a[i] < m) i++;
        while(a[j] > m) j--; 
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while(i <= j); 

    quick_sort(l, j);
    quick_sort(i, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}