#include <iostream>
using namespace std;

const int N = 100010;

// head存头指针下标，
// e表示节点i的值，
// ne表示节点i的下一个节点的下标，
// idx表示下一次分配节点可以用的位置
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

// 将x插到开头
void add_to_head(int x) {
    e[idx] = x; 
    ne[idx] = head; 
    head = idx;
    idx++;
}

// 将x插到下标是k的点后面
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx; 
    idx++;
}

// 删掉下标是k的点后面的那个点
void remove(int k) {
    if (k == -1) head = ne[head];
    else ne[k] = ne[ne[k]];
}

int main() {
    int n;
    cin >> n;

    init();
    while (n--) {
        char op;
        int k, x;

        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'I') {
            cin >> k >> x;
            add(k - 1, x);
        } else if (op == 'D') {
            cin >> k;
            remove(k - 1);
        }
    }

    while (head != -1) {
        cout << e[head] << ' ';
        head = ne[head];
    }

    return 0;
}