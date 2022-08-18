#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1010;
int a[N], n;

int get_unique_count(int a[], int n) {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    
    return s.size();
}

int main() {
    cin >> n; 
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << get_unique_count(a, n) << endl;

    return 0;
}