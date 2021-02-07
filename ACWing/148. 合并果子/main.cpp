#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int> > min_heap;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        min_heap.push(a);
    }

    int res = 0;
    while (min_heap.size() > 1) {
        int x = min_heap.top(); min_heap.pop();
        int y = min_heap.top(); min_heap.pop();
        res += x + y;
        min_heap.push(x + y);
    }

    cout << res << endl;

    return 0;
}