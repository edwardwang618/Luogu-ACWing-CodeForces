# 算法与数据结构模板



## 前缀和

### 询问区间和

Q：给定数组$A$，要求应答询问，每次询问问$A[l:r]$的和。

A：

```cpp
vector<int> pre_sum;

void init(vector<int> &A) {
  	int n = A.size();
  	pre_sum = vector<int>(n + 1, 0);
  	for (int i = 0; i < n; i++) pre_sum[i + 1] = pre_sum[i] + A[i];
}

int query(vector<int> &A, int l, int r) {
  	init(A);
  	return pre_sum[r + 1] - pre_sum[l];
}
```

### 询问子矩阵和

Q：给定二维数组$A$，要求应答询问，每次询问问$A[x_1:x_2,y_1:y_2]$的和。

A：

```cpp
vector<vector<int>> pre_sum;

void init(vector<vector<int>> &A) {
  	int m = A.size(), n = A[0].size();
  	pre_sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
  	for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++)
        	pre_sum[i + 1][j + 1] = A[i][j] + pre_sum[i + 1][j] + pre_sum[i][j + 1] - pre_sum[i][j];
}

int query(vector<vector<int>> &A, int x1, int y1, int x2, int y2) {
  	init(A);
  	return pre_sum[x2 + 1][y2 + 1] - pre_sum[x2 + 1][y1] - pre_sum[x1][y2 + 1] + pre_sum[x1][y1];
}
```



## 差分

### 区间加数

Q：给定数组$A$，要求应答询问，每次询问要将$A[l:r]$中每个数都加上某个数$x$，最后返回最终的数组。

A：

```cpp
vector<int> diff;

void init(vector<int> &A) {
    int n = A.size();
    diff = vector<int>(n, 0);
    diff[0] = A[0];
    for (int i = 1; i < n; i++) diff[i] = A[i] - A[i - 1];
}

void query(int l, int r, int x) {
    diff[l] += x;
    if (r + 1 < diff.size()) diff[r + 1] -= x;
}

vector<int> restore() {
    for (int i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];
    return diff;
}
```

### 子矩阵加数

Q：给定二维数组$A$，要求应答询问，每次询问将$A[x_1:x_2,y_1:y_2]$的每个数都加上某个数$x$，最后返回最终的数组。

A：

```cpp
vector<vector<int>> diff;

void query(int x1, int y1, int x2, int y2, int c) {
    int m = diff.size(), n = diff[0].size();
    diff[x1][y1] += c;
    if (x2 + 1 < m) diff[x2 + 1][y1] -= c;
    if (y2 + 1 < n) diff[x1][y2 + 1] -= c;
    if (x2 + 1 < m && y2 + 1 < n) diff[x2 + 1][y2 + 1] += c;
}

void init(vector<vector<int>> &A) {
    int m = A.size(), n = A[0].size();
    diff = vector<vector<int>>(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            query(i, j, i, j, A[i][j]);
}

vector<vector<int>> restore() {
    int m = diff.size(), n = diff[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i) diff[i][j] += diff[i - 1][j];
            if (j) diff[i][j] += diff[i][j - 1];
            if (i && j) diff[i][j] -= diff[i - 1][j - 1];
        }

    return diff;
}
```



## 排序

### 排序算法

Q：给定数组$A$，要求将其从小到大排序。

A：

快速排序

```cpp
void quick_sort(vector<int> &A, int l, int r) {
    if (l == r) return;
    int i = l, j = r, piv = A[l + (r - l >> 1)];
    while (i <= j) {
        while (A[i] < piv) i++;
        while (A[j] > piv) j--;
        if (i <= j) swap(A[i++], A[j--]);
    }

    quick_sort(A, l, j);
    quick_sort(A, i, r);
}

void quick_sort(vector<int> &A) {
    int n = A.size();
    quick_sort(A, 0, n - 1);
}
```

归并排序

```cpp
vector<int> tmp;

void merge_sort(vector<int> &A, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l >> 1);
    merge_sort(A, l, mid);
    merge_sort(A, mid + 1, r);
    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) tmp[idx++] = A[i++];
        else tmp[idx++] = A[j++];
    }

    while (i <= mid) tmp[idx++] = A[i++];
    while (j <= r) tmp[idx++] = A[j++];
    for (int k = l; k <= r; k++) A[k] = tmp[k];
}

void merge_sort(vector<int> &A) {
    int n = A.size();
    tmp = vector<int>(n, 0);
    merge_sort(A, 0, n - 1);
}
```

堆排序

```cpp
void sift_down(vector<int> &A, int idx, int n) {
    int x = A[idx];
    while (idx * 2 + 1 < n) {
        int s = idx * 2 + 1;
        if (s + 1 < n && A[s + 1] > A[s]) s++;
        if (A[s] > x) A[idx] = A[s];
        else break;
        
        idx = s;
    }

    A[idx] = x;
}

void heapify(vector<int> &A) {
    int n = A.size();
    for (int i = n - 2 >> 1; i >= 0; i--) sift_down(A, i, n);
}

void heap_sort(vector<int> &A) {
    heapify(A);
    int n = A.size();
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        sift_down(A, 0, i);
    }
}
```

### 快速选择

Q：给定数组$A$，要求返回其从小到大排序后的下标为$k$的数。

A：

```cpp
int quick_select(vector<int> &A, int l, int r, int k) {
    if (l == r) return A[l];
    int i = l, j = r, piv = A[l + (r - l >> 1)];
    while (i <= j) {
        while (A[i] < piv) i++;
        while (A[j] > piv) j--;
        if (i <= j) swap(A[i++], A[j--]);
    }

    if (k <= j) return quick_select(A, l, j, k);
    if (k >= i) return quick_select(A, i, r, k);
    return A[k];
}

int quick_select(vector<int> &A, int k) {
    int n = A.size();
    return quick_select(A, 0, n - 1, k);
}
```

### 逆序对个数

Q：给定数组$A$，求其逆序对个数。

A：

```cpp
vector<int> tmp;

int merge_sort(vector<int> &A, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l >> 1);
    int res = merge_sort(A, l, mid) + merge_sort(A, mid + 1, r);
    int i = l, j = mid + 1, idx = l;
    while (i <= mid && j <= r) {
        if (A[i] <= A[j]) tmp[idx++] = A[i++];
        else {
            res += mid - i + 1;
            tmp[idx++] = A[j++];
        }
    }

    while (i <= mid) tmp[idx++] = A[i++];
    while (j <= r) tmp[idx++] = A[j++];
    for (int k = l; k <= r; k++) A[k] = tmp[k];
    return res;
}

int count_inversion_pairs(vector<int> &A) {
    int n = A.size();
    tmp = vector<int>(n, 0);
    return merge_sort(A, 0, n - 1);
}
```



## 二分

Q：给定一个升序数组$A$，求$x$最左和最右出现的下标。如果没出现，则返回$-1$。

A：

```cpp
int get_first_pos(vector<int> &A, int x) {
    int n = A.size();
    int l = 0, r = n - 1;
    if (l > r) return -1;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (A[mid] >= x) r = mid;
        else l = mid + 1;
    }
    
    return A[l] == x ? l : -1;
}

int get_last_pos(vector<int> &A, int x) {
    int n = A.size();
    int l = 0, r = n - 1;
    if (l > r) return -1;
    while (l < r) {
        int mid = l + (r - l + 1 >> 1);
        if (A[mid] <= x) l = mid;
        else r = mid - 1;
    }
    
    return A[l] == x ? l : -1;
}
```



## 位运算

### 二进制1的个数

Q：求$32$位整数$x$的二进制表示里$1$的个数。

A：lowbit

```cpp
int lowbit(int x) {
    return x & -x;
}

int count(int x) {
    int res = 0;
    while (x) {
        x -= lowbit(x);
        res++;
    }
    
    return res;
}
```

A：倍增法

```cpp
int count(int x){
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);
    x = (x & 0x33333333) + (x >> 2 & 0x33333333);
    x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
    x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);
    return x;
}
```

### 异或运算的阿贝尔群性质

Q：给定一个数组$A$，除了某个数$x$只出现了$1$次之外，其余数都恰好出现了$2$次。求$x$。

A：

```cpp
int solve(vector<int> &A) {
    int res = 0;
    for (int x : A) res ^= x;
    return res;
}
```



## 高精度计算

### 高精度加法

Q：给定两个非负整数$a$和$b$，都没有前导$0$，计算它们的和。

A：

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    puts("");
    
    return 0;
}
```

### 高精度减法

Q：给定两个非负整数$a$和$b$，都没有前导$0$，计算它们的差。差可能为负。

A：

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool bigger(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--) 
        if (A[i] != B[i]) return A[i] > B[i];
    
    return true;
}

vector<int> subtract(vector<int> &A, vector<int> &B, bool &neg) {
    if (!bigger(A, B)) {
        swap(A, B);
        neg = true;
    }
    
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
        t = t < 0 ? -1 : 0;
    }
    
    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    bool neg = false;
    auto C = subtract(A, B, neg);
    
    if (neg) printf("-");
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    puts("");
    
    return 0;
}
```

### 高精度乘法

Q：给定两个非负整数$a$和$b$，都没有前导$0$，计算它们的乘积。其中$b\le 10000$。

A：

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> mult(vector<int> &A, int b) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || t; i++) {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    
    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    auto C = mult(A, b);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    puts("");
    
    return 0;
}
```

### 高精度除法

Q：给定两个非负整数$a$和$b$，都没有前导$0$，计算它们的商。其中$1\le b\le 10000$。

A：

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && !C.back()) C.pop_back();
    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    int r;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    printf("\n%d\n", r);
    
    return 0;
}
```



## 链表

链表节点定义

```cpp
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int val) : val(val) {}
}
```

### 求中点

Q：给定一个单链表，求其中点。若其长度为偶数，则返回靠左的中点。

A：

```cpp
ListNode* solve(ListNode *head) {
    if (!head) return nullptr;
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
```

### 翻转链表

Q：给定一个单链表，要求将其反转，返回新的头结点。

A：

```cpp
ListNode* reverse(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *res = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return res;
}

ListNode* reverse(ListNode *head) {
    LIstNode *prev = nullptr, *tmp;
    while (head) {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    
    return prev;
}
```

### 合并有序链表

Q：给定两个升序的单链表，要求将它们合并为一个升序的单链表，返回新链表表头

A：

```cpp
ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(0), *prev = dummy;
    while (l1 || l2) {
        if (!l1) {
            prev->next = l2;
            break;
        }
        if (!l2) {
            prev->next = l1;
            break;
        }
        
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        
        prev = prev->next;
    }
    
    return dummy->next;
}
```

### 链表排序

Q：给定一个单链表，要求将其从小到大排序，返回新链表表头。

A：

```cpp
ListNode* sort(ListNode *head) {
    if (!head || !head->next) return head;
    
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy, *fast = dummy;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode *l1 = head, *l2 = slow->next;
    slow->next = nullptr;
    
    l1 = sort(l1);
    l2 = sort(l2);
    ListNode *prev = dummy;
    while (l1 || l2) {
        if (!l1) {
            prev->next = l2;
            break;
        }
        if (!l2) {
            prev->next = l1;
            break;
        }
        
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        
        prev = prev->next;
    }
    
    return dummy->next;
}
```

### 静态链表

Q：实现静态链表，实现在表头插入、删除，和遍历链表的功能。

A：

```cpp
const int N = 1e5 + 10;
int h, e[N], ne[N], idx;

void init() {
    idx = 0, h = -1;
    memset(e, 0, sizeof e);
    memset(ne, 0, sizeof ne);
}

void insert_head(int x) {
    e[idx] = x, ne[idx] = h, h = idx++;
}

void remove_head() {
    h = ne[h];
}

void traverse() {
    for (int i = h; ~i; i = ne[i]) printf("%d ", e[i]);
    puts("");
}
```



## 栈

### 单调栈

Q：给定数组$A$，要求返回数组$B$，其中$B[i]$是$A[i]$左边最近的比它小的数的下标，若不存在则令$B[i]=-1$。

A：

版本1

```cpp
vector<int> solve(vector<int> &A) {
    int n = A.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && A[stk.top()] >= A[i]) stk.pop();
        res[i] = stk.size() ? stk.top() : -1;
        stk.push(i);
    }

    return res;
}
```

版本2

```cpp
vector<int> solve(vector<int> &A) {
    int n = A.size();
    vector<int> res(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && A[stk.top()] >= A[i]) {
            int top = stk.top(); stk.pop();
            res[top] = stk.size() ? stk.top() : -1;
        }

        stk.push(i);
    }

    while (stk.size()) {
        int top = stk.top(); stk.pop();
        res[top] = stk.size() ? stk.top() : -1;
    }

    return res;
}
```

### 单调栈+二分

Q：给定数组$A$，要求返回数组$B$，其中$B[i]$是$A[i]$左边最远的比它小的数的下标，若不存在则令$B[i]=-1$。

A：

```cpp
int bin_search(vector<int> &stk, int r, int x, vector<int> &A) {
    int l = 0;
    if (l > r) return -1;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (A[stk[mid]] < x) r = mid;
        else l = mid + 1;
    }

    return A[stk[l]] < x ? stk[l] : -1;
}

vector<int> solve(vector<int> &A) {
    int n = A.size();
    vector<int> res(n, 0), stk(n, 0);
    int top = 0;

    for (int i = 0; i < n; i++) {
        res[i] = bin_search(stk, top - 1, A[i], A);
        if (!top || A[stk[top - 1]] > A[i]) stk[top++] = i;
    }

    return res;
}
```

### 表达式解析

Q：给定一个只含数字、空格和加减乘除的后缀表达式，求其值。

A：

```cpp
void calc(stack<int> &stk, char op) {
    int b = stk.top();
    stk.pop();
    int a = stk.top();
    stk.pop();
    switch (op) {
        case '+': stk.push(a + b); break;
        case '-': stk.push(a - b); break;
        case '*': stk.push(a * b); break;
        case '/': stk.push(a / b); break;
    }
}

int solve(string s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == ' ') continue;
        else if (isdigit(ch)) {
            int j = i;
            while (j < s.size() && isdigit(s[j])) j++;
            int x = stoi(s.substr(i, j - i));
            stk.push(x);
            i = j - 1;
        } else calc(stk, ch);
    }

    return stk.top();
}
```

Q：给定一个只含数字、空格、左右小括号和加减乘除的中缀表达式，求其值。

A：

```cpp
void calc(stack<int> &stk, stack<char> &ops) {
    int b = stk.top();
    stk.pop();
    int a = stk.top();
    stk.pop();
    switch (ops.top()) {
        case '+': stk.push(a + b); break;
        case '-': stk.push(a - b); break;
        case '*': stk.push(a * b); break;
        case '/': stk.push(a / b); break;
    }

    ops.pop();
}

int solve(string s) {
    stack<int> stk;
    stack<char> ops;
    unordered_map<char, int> mp = {{'(', 0}, {'+', 1}, {'-', 1},
                                   {'*', 2}, {'/', 2}};

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (ch == ' ') continue;
        else if (ch == '(') ops.push(ch);
        else if (isdigit(ch)) {
            int j = i;
            while (j < s.size() && isdigit(s[j])) j++;
            stk.push(stoi(s.substr(i, j - i)));
            i = j - 1;
        } else if (mp.count(ch)) {
            while (ops.size() && mp[ops.top()] >= mp[ch]) calc(stk, ops);
            ops.push(ch);
        } else if (ch == ')') {
            while (ops.top() != '(') calc(stk, ops);
            ops.pop();
        }
    }

    while (ops.size()) {
        calc(stk, ops);
    }

    return stk.top();
}
```



## 队列

### 单调队列

Q：给定数组$A$，和正整数$k$，要求返回数组$B$，其中$B[i]$是$A[i:i+k-1]$的最小值。题目保证$k$不大于$A$的长度。

A：

```cpp
vector<int> solve(vector<int> &A, int k) {
    int n = A.size();
    vector<int> res(n - k + 1, 0);

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (dq.size() && dq.front() <= i - k) dq.pop_front();
        while (dq.size() && A[dq.back()] > A[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res[i - k + 1] = A[dq.front()];
    }

    return res;
}
```



## 字符串

### 字符串哈希

#### 询问子串是否相等

Q：给定两个等长字符串$s$和$t$， 要求应答若干询问，每次询问问$s[l:r]=t[l:r]$是否成立。

A：

```cpp
using UL = unsigned long;
vector<UL> hash_s, hash_t, pow;
UL P = 131;

vector<UL> get_hash(string &s) {
    int n = s.size();
    vector<UL> hash(n + 1, 0);
    for (int i = 0; i < n; i++) hash[i + 1] = hash[i] * P + s[i];
    return hash;
}

void init(string &s, string &t) {
    int n = s.size();
    hash_s = get_hash(s);
    hash_t = get_hash(t);
    pow = vector<UL>(n + 1, 0);
    pow[0] = 1;
    for (int i = 0; i < n; i++) pow[i + 1] = pow[i] * P;
}

UL hashcode(vector<UL> &hash_string, int l, int r) {
    return hash_string[r + 1] - hash_string[l] * pow[r - l + 1];
}

bool query(string &s, string &t, int l, int r) {
    init(s, t);
    return hashcode(hash_s, l, r) == hashcode(hash_t, l, r);
}
```

#### Rabin-Karp

Q：给定两个字符串$s$和$p$， 问$p$是否是$s$的子串，如果是，返回$p$在$s$中第一次出现的位置；如果不是，返回$-1$。

A：

```cpp
using UL = unsigned long;

int query(string s, string p) {
    int n = s.size(), m = p.size();
    if (m > n) return -1;
  	
    UL P = 131, hash_s = 0, hash_p = 0, pow = 1;
    for (int i = 0; i < m; i++) {
        hash_s = hash_s * P + s[i];
        hash_p = hash_p * P + p[i];
        pow = pow * P;
    }

    if (hash_s == hash_p) return 0;

    for (int i = m; i < n; i++) {
        hash_s = hash_s * P + s[i];
        hash_s -= s[i - m] * pow;
        if (hash_s == hash_p) return i - m + 1;
    }

    return -1;
}
```

#### 询问回文串

Q：给定字符串$s$， 要求应答若干询问，每次询问问$s[l:r]$是否是回文串。

A：

```cpp
using UL = unsigned long;
UL P = 131L;
vector<UL> hash_l, hash_r, pow;

void init(string s) {
	int n = s.size();
    hash_l = vector<UL>(n + 1, 0);
    hash_r = vector<UL>(n + 1, 0);
    pow = vector<UL>(n + 1, 1);

    for (int i = 0; i < n; i++) {
        hash_l[i + 1] = hash_l[i] * P + s[i];
        hash_r[n - 1 - i] = hash_r[n - i] * P + s[n - 1 - i];
        pow[i + 1] = pow[i] * P;
    }
}

UL hash_left(int l, int r) {
    return hash_l[r + 1] - hash_l[l] * pow[r - l + 1];
}

UL hash_right(int l, int r) {
    return hash_r[l] - hash_r[r + 1] * pow[r - l + 1];
}

bool query(int l, int r) {
    int rad = r - l + 1 >> 1;
	return hash_left(l, l + rad - 1) == hash_right(r - rad + 1, r);
}
```

#### 最长回文子串

Q：给定字符串$s$， 求其最长回文子串的长度。

A：二分 + 哈希

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e6 + 10, P = 131;
char s[N], t[N];
int n, h[N], rh[N], pow[N];

void init() {
  pow[0] = 1;
  h[0] = 0, rh[n + 1] = 0;
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] * P + s[i], pow[i] = pow[i - 1] * P;
  for (int i = n; i; i--) rh[i] = rh[i + 1] * P + s[i];
}

int get_h(int l, int r) {
  return h[r] - h[l - 1] * pow[r - l + 1];
}

int get_rh(int l, int r) {
  return rh[l] - rh[r + 1] * pow[r - l + 1];
}

bool check(int len) {
  len = len / 2 + 1;
  for (int i = len; i + len - 1 <= n; i++)
    if (get_h(i - len + 1, i) == get_rh(i, i + len - 1)) return true;
  return false;
}

int main() {
  scanf("%s", t + 1);
  s[++n] = '$';
  for (int i = 1; t[i]; i++) s[++n] = t[i], s[++n] = '$';
  init();
  int l = 1, r = n;
  while (l < r) {
    int mid = l + (r - l + 1 >> 1);
    if (check(mid)) l = mid;
      else r = mid - 1;
  }

  printf("%d\n"l / 2);
}
```



### 序列自动机

Q：给定一个字符串$s$，要求应答若干次询问，每次询问问某个字符串$p$是否是$s$的子序列。题目保证只含英文小写字母。

A：

```cpp
vector<vector<int>> dfa;

void init(string &s) {
    int n = s.size();
    dfa = vector<vector<int>>(n + 1, vector<int>(26, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; k < 26; k++) 
            dfa[i][k] = dfa[i + 1][k];
        dfa[i][s[i] - 'a'] = i + 1;
    }
}

bool query(string s, string p) {
  	if (p.size() > s.size()) return false;
  
    init(s);
    for (int i = 0, pos = 0; i < p.size(); i++) {
        if (!dfa[pos][p[i] - 'a']) 
            return false;
        pos = dfa[pos][p[i] - 'a'];
    }

    return true;
}
```

### KMP

Q：给定两个字符串$s$和$p$， 问$p$是否是$s$的子串，如果是，返回$p$在$s$中所有出现的位置。字符串下标从$1$开始。

A：朴素版KMP

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
char p[N], s[N];
int ne[N];

void build_ne() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
  }
}

int main() {
  cin >> m >> p + 1 >> n >> s + 1;

  build_ne();

  for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) {
      printf("%d ", i - m + 1);
      j = ne[j];
    }
  }
}
```

Q：给定两个字符串$s$和$p$， 问$p$是否是$s$的子串，如果是，返回$p$在$s$中第一次出现的位置。字符串下标从$1$开始。

A：优化版KMP

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
char p[N], s[N];
int ne[N];

void build_ne() {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = i < m && p[i + 1] != p[j + 1] ? j : ne[j];
  }
}

int main() {
  cin >> m >> p + 1 >> n >> s + 1;

  build_ne();

  for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) {
      printf("%d ", i - m + 1);
      j = ne[j];
    }
  }
}
```

### 后缀数组

Q：给定一个字符串$s$，求其后缀数组、名次数组和高度数组。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
int n, m;
char s[N];
int sa[N], rk[N], y[N], c[N], he[N];

void get_sa() {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  for (int k = 1;; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[rk[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
    swap(rk, y);
    rk[sa[1]] = num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? num : ++num;
    if (num == n) break;
    m = num;
  }
}

void get_height() {
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
	if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

int main() {
  scanf("%s", s + 1);
  
  n = strlen(s + 1), m = 'z';
  get_sa();
  get_height();

  for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
  puts("");
  for (int i = 1; i <= n; i++) printf("%d ", he[i]);
  puts("");

  return 0;
}
```

Q：给定字符串$s$， 求其最长回文子串的长度。

A：

```cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 2e6 + 10, M = 23;
int n, m;
char s[N];
int sa[N], rk[N], y[N], c[N], he[N];
int f[N][M];

void get_sa() {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  for (int k = 1;; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[rk[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
    swap(rk, y);
    rk[sa[1]] = num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? num : ++num;
    if (num == n) break;
    m = num;
  }
}

void get_height() {
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

void init() {
  for (int i = 1; i <= n; i++) f[i][0] = he[i];
  for (int j = 1; j <= log2(n); j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(int l, int r) {
  if (l > r) swap(l, r);
  l++;
  int j = log2(r - l + 1);
  return min(f[l][j], f[r - (1 << j) + 1][j]);
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), m = 'z';
  s[n + 1] = '$';
  for (int i = 1; i <= n; i++) s[n + 1 + i] = s[n - i + 1];
  n = n * 2 + 1;
  s[n + 1] = 0;

  get_sa();
  get_height();

  init();

  int res = 0;
  for (int i = 1; i <= n / 2; i++) {
    res = max(res, query(rk[i], rk[n - i + 1]) * 2 - 1);
    if (i > 1) res = max(res, query(rk[i], rk[n - i + 2]) * 2);
  }

  printf("%d\n", res);
}
```

### 最小表示法

Q：给定一个长$n$数组$A$，求其所有循环同构里字典序最小的那个。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 6e5 + 10;
int n;
int a[N];

int get() {
  int i = 0, j = 1, k;
  while (i < n && j < n) {
    k = 0;
    while (i + k < n && j + k < n && a[i + k] == a[j + k]) k++;
    if (k == n) break;
    a[i + k] > a[j + k] ? i += k + 1 : j += k + 1;
    if (i == j) j++;
  }

  return min(i, j);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  memcpy(a + n, a, (n - 1) * sizeof(int));
  int idx = get();
  for (int i = idx; i < idx + n; i++) printf("%d ", a[i]);
}
```

### AC自动机（Trie图）

Q：给定一个文本串$s$和若干模式串，问每个模式串在$s$中出现的次数。模式串非空，但可能有相同。”一次出现“定义为在$s$的某个位置可以发生匹配。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 2e5 + 10, M = 2e6 + 10;
int n;
char s[M];
int tr[N][26], ne[N], f[N], idx;
int id[N];
int q[N];

void insert(int k) {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    int c = s[i] - 'a';
    if (!tr[p][c]) tr[p][c] = ++idx;
    p = tr[p][c];
  }
  id[k] = p;
}

void build() {
  int hh = 0, tt = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i])
      q[tt++] = tr[0][i];

  while (hh < tt) {
    int t = q[hh++];
    for (int i = 0; i < 26; i++) {
      int &p = tr[t][i];
      if (p) ne[p] = tr[ne[t]][i], q[tt++] = p;
      else p = tr[ne[t]][i];
    }
  }
}

void query() {
  int p = 0;
  for (int i = 0; s[i]; i++) {
    p = tr[p][s[i] - 'a'];
    f[p]++;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    insert(i);
  }
  build();
  scanf("%s", s);

  query();

  for (int i = idx - 1; i >= 0; i--) f[ne[q[i]]] += f[q[i]];
  for (int i = 1; i <= n; i++) printf("%d\n", f[id[i]]);
}
```



## RMQ

Q：给定一个数组$A$，要求应答若干次询问，每次询问问$A[l:r]$的最小值是多少。

A：

```cpp
vector<vector<int>> f;

void init(vector<int> &A) {
    int n = A.size();
    f = vector<vector<int>>(n, vector<int>(log2(n) + 1, 0));
    for (int i = 0; i < n; i++) f[i][0] = A[i];

    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i + (1 << j) - 1 < n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int query(vector<int> &A, int l, int r) {
    init(A);
    int k = log2(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}
```



## 二叉树

二叉树树节点的定义

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
}
```

### 前序遍历

```cpp
void preorder_recursion(TreeNode *root, vector<int> &res) {
    if (!root) return;
    res.push_back(root->val);
    preorder_recursion(root->left, res);
    preorder_recursion(root->right, res);
}

vector<int> preorder_nonrecursion(TreeNode *root) {
  	vector<int> res;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (stk.size() || cur) {
        while (cur) {
            res.push_back(cur->val);
            if (cur->right) stk.push(cur->right);
            cur = cur->left;
        }

        if (stk.size()) {
            cur = stk.top();
            stk.pop();
        }
    }
  
  	return res;
}
```

### 中序遍历

```cpp
void inorder_recursion(TreeNode *root, vector<int> &res) {
    if (!root) return;
    inorder_recursion(root->left, res);
    res.push_back(root->val);
    inorder_recursion(root->right, res);
}

vector<int> inorder_nonrecursion(TreeNode *root) {
  	vector<int> res;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (stk.size() || cur) {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
  
  	return res;
}
```

### 后序遍历

```cpp
void postorder_recursion(TreeNode *root, vector<int> &res) {
    if (!root) return;
    postorder_recursion(root->left, res);
    postorder_recursion(root->right, res);
    res.push_back(root->val);
}

vector<int> postorder_nonrecursion(TreeNode *root) {
  	vector<int> res;
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (stk.size() || cur) {
        while (cur) {
            stk.push(cur);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }

        cur = stk.top();
        stk.pop();
        res.push_back(cur->val);
        if (stk.size() && cur == stk.top()->left) cur = stk.top()->right;
        else cur = nullptr;
    }
  
  	return res;
}
```

### 层序遍历

```cpp
vector<vector<int>> level_order(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q;
    if (root) q.push(root);
    while (q.size()) {
        vector<int> v;
        for (int i = q.size(); i; i--) {
            TreeNode *cur = q.front();
            q.pop();
            v.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        res.push_back(v);
    }

    return res;
}
```

### Morris遍历

#### 前序

```cpp
vector<int> morris_preorder(TreeNode *root) {
    vector<int> res;
    TreeNode *cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
            continue;
        }

        TreeNode *left = cur->left;
        while (left->right && left->right != cur) left = left->right;
        if (!left->right) {
            left->right = cur;
            res.push_back(cur->val);
            cur = cur->left;
        } else {
            left->right = nullptr;
            cur = cur->right;
        }
    }

    return res;
}
```

#### 中序

```cpp
vector<int> morris_inorder(TreeNode *root) {
    vector<int> res;
    TreeNode *cur = root;
    while (cur) {
        if (!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
            continue;
        }

        TreeNode *left = cur->left;
        while (left->right && left->right != cur) left = left->right;
        if (!left->right) {
            left->right = cur;
            cur = cur->left;
        } else {
            left->right = nullptr;
            res.push_back(cur->val);
            cur = cur->right;
        }
    }

    return res;
}
```

#### 后序

```cpp
TreeNode* reverse(TreeNode *cur) {
    TreeNode *prev = nullptr;
    while (cur) {
        TreeNode *tmp = cur->right;
        cur->right = prev;
        prev = cur;
        cur = tmp;
    }

    return prev;
}

void reverse_add(TreeNode *cur, vector<int> &res) {
    cur = reverse(cur);
    TreeNode *tail = cur;
    while (cur) {
        res.push_back(cur->val);
        cur = cur->right;
    }

    reverse(tail);
}

vector<int> morris_postorder(TreeNode *root) {
    vector<int> res;
    TreeNode *cur = root;
    while (cur) {
        if (!cur->left) {
            cur = cur->right;
            continue;
        }

        TreeNode *left = cur->left;
        while (left->right && left->right != cur) left = left->right;
        if (!left->right) {
            left->right = cur;
            cur = cur->left;
        } else {
            left->right = nullptr;
            reverse_add(cur->left, res);
            cur = cur->right;
        }
    }

    reverse_add(root, res);
    return res;
}
```

## 二叉搜索树

#### 查找

```cpp
TreeNode* search(TreeNode *root, int key) {
    while (root) {
        if (key < root->val) root = root->left;
        else if (key > root->val) root = root->right;
        else break;
    }

    return root;
}

TreeNode* search(TreeNode *root, int key) {
    if (!root) return nullptr;

    if (key < root->val) return search(root->left, key);
    else if (key > root->val) return search(root->right, key);
    else return root;
}
```

#### 插入

```cpp
TreeNode* insert(TreeNode *root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);

    return root;
}
```

#### 删除

版本1（以前驱覆盖）

```cpp
TreeNode* remove(TreeNode *root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = remove(root->left, key);
    else if (key > root->val) root->right = remove(root->right, key);
    else {
        if (!root->left) root = root->right;
        else {
            TreeNode *left = root->left;
            if (!left->right) {
                root->val = left->val;
                root->left = left->left;
            } else {
                TreeNode *prev = left;
                left = left->right;
                while (left->right) {
                    left = left->right;
                    prev = prev->right;
                }

                root->val = left->val;
                prev->right = left->left;
            }
        }
    }

    return root;
}
```

版本2（利用旋转）

```cpp
// 右旋
void zig(TreeNode* &root) {
    TreeNode *left = root->left;
    root->left = left->right;
    left->right = root;
    root = left;
}

// 左旋
void zag(TreeNode* &root) {
    TreeNode *right = root->right;
    root->right = right->left;
    right->left = root;
    root = right;
}

TreeNode* remove(TreeNode *root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = remove(root->left, key);
    else if (key > root->val) root->right = remove(root->right, key);
    else {
        if (!root->left && !root->right) return nullptr;
        if (root->left) {
            zig(root);
            root->right = remove(root->right, key);
        } else {
            zag(root);
            root->left = remove(root->left, key);
        }
    }

    return root;
}
```

版本3（利用合并）

```cpp
TreeNode* merge(TreeNode *x, TreeNode *y) {
    if (!x) return y;
    if (!y) return x;

    if ((x->val ^ y->val) & 1) {
        x->right = merge(x->right, y);
        return x;
    } else {
        y->left = merge(x, y->left);
        return y;
    }
}

TreeNode* remove(TreeNode *root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = remove(root->left, key);
    else if (key > root->val) root->right = remove(root->right, key);
    else root = merge(root->left, root->right);

    return root;
}
```

#### 分裂

将二叉搜索树分裂为小于等于$key$和大于$key$的两棵树。

```cpp
vector<TreeNode *> split(TreeNode *root, int key) {
    if (!root) return {nullptr, nullptr};
    if (key < root->val) {
        vector<TreeNode *> vec = split(root->left, key);
        root->left = vec[1];
        return {vec[0], root};
    } else {
        vector<TreeNode *> vec = split(root->right, key);
        root->right = vec[0];
        return {root, vec[1]};
    }
}
```

#### 合并

假设两棵二叉搜索树$x$和$y$满足$x$的最大值小于等于$y$的最小值，求它们的合并之后的二叉搜索树。

```cpp
TreeNode* merge(TreeNode *x, TreeNode *y) {
    if (!x) return y;
    if (!y) return x;

    if ((x->val ^ y->val) & 1) {
        x->right = merge(x->right, y);
        return x;
    } else {
        y->left = merge(x, y->left);
        return y;
    }
}
```



## N叉树

N叉树树节点的定义

```cpp
struct Node {
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
```

### 前序遍历

```cpp
vector<int> preorder(Node* root) {
    vector<int> res;
    stack<Node *> stk;
    Node *cur = root;
    while (stk.size() || cur) {
        while (cur) {
            res.push_back(cur->val);
            auto v = cur->children;
            for (int i = v.size() - 1; i >= 1; i--) 
                stk.push(v[i]);

            cur = v.size() ? v[0] : nullptr;
        }

        if (stk.size()) {
            cur = stk.top(); 
            stk.pop();
        }
    }

    return res;
}
```

### 后序遍历

```cpp
vector<int> postorder(Node* root) {
    vector<int> res;
    stack<pair<Node *, int>> stk;
    Node *cur = root;
    int idx = 0;
    while (stk.size() || cur) {
        if (cur) {
            stk.push({cur, idx});
            while (cur->children.size()) {
                cur = cur->children[0];
                stk.push({cur, 0});
            }
        }

        auto p = stk.top(); 
        stk.pop();
        res.push_back(p.first->val);
        cur = p.first;
        idx = p.second;
        if (stk.size() && cur != stk.top().first->children.back()) 
            cur = stk.top().first->children[++idx];
        else cur = nullptr;
    }

    return res;
}
```



## 字典树（Trie）

例题1

Q：要求设计一个数据结构，可以执行：

1、插入字符串$s$；

2、询问某个字符串$s$在该数据结构里有多少个。

题目保证字符串只含英文小写字母。

A：静态链表写法：

```cpp
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char op;
        string s;
        cin >> op;
        cin >> s;

        if (op == 'I') insert(s);
        else if (op == 'Q') cout << query(s) << endl;
    }

    return 0;
}
```

A：动态链表写法：

```cpp
class Trie {
public:

    struct Node {
        vector<Node*> ne;
        int cnt;
        Node() {
            ne = vector<Node*>(26, nullptr);
            cnt = 0;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* cur = root;
        for (char ch : s) {
            int u = ch - 'a';
            if (!cur->ne[u]) cur->ne[u] = new Node();
            cur = cur->ne[u];
        }

		cnt++;
    }
    
    int query(string s) {
        Node* cur = root;
        for (char ch : s) {
            int u = ch - 'a';
            if (!cur->ne[u]) return 0;
            cur = cur->ne[u];
        }

        return cur->cnt;
    }
};
```

例题2

Q：给定$n$个数，求$\max_{i\ne j} A[i]\land A[j]$。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 31e5 + 10;
int n;
int son[N][2];
int idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            p = son[p][!u];
            res |= 1 << i;
        } else p = son[p][u];
    }
    
    return res;
}

int main() {
    scanf("%d", &n);
    int res = -1;
    while (n--) {
        int x;
        scanf("%d", &x);
        res = max(res, query(x));
        insert(x);
    }
    
    printf("%d\n", res);
    
    return 0;
}
```



## 平衡树

### 树堆（Treap）

例题

Q：要求实现一个数据结构，可以进行如下操作：

1、插入一个数$x$；

2、删除一个数$x$；

3、给定一个数$x$，问其在已经存储的数据里的排名，如果该数出现了多次，则返回最小排名，询问保证该数存在；

4、问排名为$k$的数是几，题目保证$k$大于等于$1$，小于已经存的数字个数；

5、给定一个数$x$，求小于它的最大数，如果不存在则返回$-\infty$；

6、给定一个数$x$，求大于它的最小数，如果不存在则返回$\infty$。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, INF = 1e8;
int n;
// 注意tr[0]空着不用，视为null节点，其cnt和size都是0
struct Node {
	// 左右孩子的下标
    int l, r;
    // key是BST的权值，val是最大堆的权值
    int key, val;
    // cnt是本key有多少个，size表示以本node为树根的子树的节点总个数
    int cnt, size;
} tr[N];
int root, idx;

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

// 右旋
void zig(int &p) {
    int q = tr[p].l;
    tr[p].l = tr[q].r, tr[q].r = p, p = q;
    pushup(tr[p].r);
}

// 左旋
void zag(int &p) {
    int q = tr[p].r;
    tr[p].r = tr[q].l, tr[q].l = p, p = q;
    pushup(tr[p].l);
}

// 创建新节点并返回其下标
int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

// 注意要传引用，因为我们要真实修改p为新的Treap的树根
void insert(int &p, int key) {
	// 如果树空，则new出新节点作为树根
    if (!p) p = get_node(key);
    else if (tr[p].key > key) {
    	// 如果key小于树根，则要向左子树里插入
        insert(tr[p].l, key);
        // 左子树完成插入后，看一下左子树的val是否与当前节点
        // 的val满足堆的关系，如果不满足，则将左子树右旋上来
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else if (tr[p].key < key) {
    	// 如果key大于当前树根，则要向右子树插入
        insert(tr[p].r, key);
        // 右子树完成插入后，看一下右子树的val是否与当前节点
        // 的val满足堆的关系，如果不满足，则将右子树左旋上来
        if (tr[tr[p].r].val > tr[p].val) zag(p);
        // 否则说明当前节点的key就等于输入key，则计数加1
    } else tr[p].cnt++;
	
	// 插入完成后还需要更新当前节点
    pushup(p);
}

void remove(int &p, int key) {
	// 如果树空，那就不用删了，直接返回
    if (!p) return;
    // 如果key大于树根，则去右子树里删
    if (tr[p].key > key) remove(tr[p].l, key);
    // 如果key小于树根，则去左子树里删
    else if (tr[p].key < key) remove(tr[p].r, key);
    // 否则说明key等于树根
    else {
    	// 如果key之前的次数大于1，那么不用删节点，只需要删cnt
        if (tr[p].cnt > 1) tr[p].cnt--;
        // 否则说明要删当前节点了
        else if (tr[p].l || tr[p].r) {
        	// 如果右子树空，或者左子树不空且v值大于右孩子v值，则需要右旋，否则左旋
            if (!tr[p].r || (!tr[p].l && tr[tr[p].l].val > tr[tr[p].r].val)) {
                zig(p);
                remove(tr[p].r, key);
            } else {
                zag(p);
                remove(tr[p].l, key);
            }
            // 如果当前节点是叶子，那直接将其变成空节点null就行了，null的下标是0
        } else p = 0;
    }

	// 删除完成后还需要更新当前节点
    pushup(p);
}

int get_rank_by_key(int p, int key) {
    if (!p) return 0;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    else if (tr[p].key < key) return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);
    else return tr[tr[p].l].size + 1;
}

int get_key_by_rank(int p, int rank) {
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    else if (tr[tr[p].l].size + tr[p].cnt < rank) return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
    else return tr[p].key;
}

int get_prev(int p, int key) {
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}

int get_next(int p, int key) {
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main() {
    scanf("%d", &n);
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(root, x));
        else if (opt == 4) printf("%d\n", get_key_by_rank(root, x));
        else if (opt == 5) printf("%d\n", get_prev(root, x));
        else if (opt == 6) printf("%d\n", get_next(root, x));
    }

    return 0;
}
```

### 范浩强Treap（FHQ Treap）

例题1

Q：要求实现一个数据结构，可以进行如下操作：

1、插入一个数$x$；

2、删除一个数$x$；

3、给定一个数$x$，问其在已经存储的数据里的排名，如果该数出现了多次，则返回最小排名，询问保证该数存在；

4、问排名为$k$的数是几，题目保证$k$大于等于$1$，小于已经存的数字个数；

5、给定一个数$x$，求小于它的最大数，如果不存在则返回$-\infty$；

6、给定一个数$x$，求大于它的最小数，如果不存在则返回$\infty$。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m;
struct Node {
    int l, r;
    int v, rnd;
    int sz, cnt;
} tr[N];
int root, idx;
int x, y, z;

int get_node(int v) {
    tr[++idx].v = v;
    tr[idx].l = tr[idx].r = 0;
    tr[idx].sz = tr[idx].cnt = 1;
    tr[idx].rnd = rand();
    return idx;
}

void pushup(int u) {
    tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + tr[u].cnt;
}

void split_key(int u, int key, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (tr[u].v <= key) {
            x = u;
            split_key(tr[u].r, key, tr[u].r, y);
            pushup(x);
        } else {
            y = u;
            split_key(tr[u].l, key, x, tr[u].l);
            pushup(y);
        }
    }
}

void split_sz(int u, int sz, int &x, int &y) {
    if (!u) x = y = 0;
    else {
        if (sz > tr[tr[u].l].sz) {
            x = u;
            split_sz(tr[u].r, sz - tr[tr[u].l].sz - tr[u].cnt, tr[u].r, y);
            pushup(x);
        } else {
            y = u;
            split_sz(tr[u].l, sz, x, tr[u].l);
            pushup(y);
        }
    }
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (tr[x].rnd > tr[y].rnd) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

int merge(int x, int y, int z) {
    return merge(merge(x, y), z);
}

void insert(int c) {
    split_key(root, c, y, z);
    split_key(y, c - 1, x, y);
    if (!y) y = get_node(c);
    else {
        tr[y].cnt++;
        tr[y].sz++;
    }

    root = merge(x, y, z);
}

void remove(int c) {
    split_key(root, c, y, z);
    split_key(y, c - 1, x, y);
    tr[y].cnt--;
    tr[y].sz--;
    if (!tr[y].cnt) y = 0;
    root = merge(x, y, z);
}

int get_rank_by_key(int c) {
    split_key(root, c - 1, x, y);
    int rk = tr[x].sz + 1;
    root = merge(x, y);
    return rk;
}

int get_key_by_rank(int rk) {
    split_sz(root, rk, x, y);
    int u = x, key;
    while (u) key = tr[u].v, u = tr[u].r;
    root = merge(x, y);
    return key;
}

int get_prev(int c) {
    split_key(root, c - 1, x, y);
    int u = x, key;
    while (u) key = tr[u].v, u = tr[u].r;
    root = merge(x, y);
    return key;
}

int get_next(int c) {
    split_key(root, c, x, y);
    int u = y, key;
    while (u) key = tr[u].v, u = tr[u].l;
    root = merge(x, y);
    return key;
}

int main() {
    scanf("%d", &m);

    while (m--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1) insert(x);
        else if (opt == 2) remove(x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(x));
        else if (opt == 4) printf("%d\n", get_key_by_rank(x));
        else if (opt == 5) printf("%d\n", get_prev(x));
        else if (opt == 6) printf("%d\n", get_next(x));
    }

    return 0;
}
```

例题2

Q：要求设计一个数据结构，维护一个序列$A$，并且应答若干询问，每次询问要将$A[l:r]$翻转。求最后的序列$A$。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
struct Node {
    int l, r;
    int key, val;
    int size;
    bool reverse;
} tr[N];

int n, m;
int root, idx;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].size = 1;
    return idx;
}

void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
}

void pushdown(int p) {
    swap(tr[p].l, tr[p].r);
    tr[tr[p].l].reverse ^= 1;
    tr[tr[p].r].reverse ^= 1;
    // 懒标记下传完毕，清除当前节点懒标记
    tr[p].reverse = false;
}

void split(int p, int sz, int &x, int &y) {
    if (!p) x = y = 0;
    else {
    	// 要分裂p了，先下传懒标记
        if (tr[p].reverse) pushdown(p);
        if (tr[tr[p].l].size < sz) {
            x = p;
            split(tr[p].r, sz - tr[tr[p].l].size - 1, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, sz, x, tr[p].l);
        }
		
		// 分裂完之后pushup。注意，这个pushup操作必须写在else里，
		// 否则会pushup 0节点，size会错
        pushup(p);
    }
}

// 合并，并维护大顶堆性质
int merge(int x, int y) {
    if (!x || !y) return x ^ y;
    if (tr[x].val > tr[y].val) {
    	// 要将x右子树与y合并，合并之前下传x的懒标记
        if (tr[x].reverse) pushdown(x);
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        // x是新树根
        return x;
    } else {
        if (tr[y].reverse) pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

void reverse(int l, int r) {
    int x, y, z;
    split(root, l - 1, x, y);
    split(y, r - l + 1, y, z);
    tr[y].reverse ^= 1;
    root = merge(merge(x, y), z);
}

// 中序遍历打印答案
void dfs(int p) {
    if (!p) return;
    if (tr[p].reverse) pushdown(p);
    dfs(tr[p].l);
    printf("%d ", tr[p].key);
    dfs(tr[p].r);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        root = merge(root, get_node(i));

    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        reverse(l, r);
    }

    dfs(root);

    return 0;
}
```



## 哈夫曼树（Huffman Tree）

例题

Q：给定一个数组$A$，每次允许挑出两个数字$x$和$y$，将它们合并为$x+y$放回数组，合并的代价就是$x+y$，问最后合并只剩下一个数字的时候，最小的总代价是多少。

A：最小堆

```cpp
int solve(vector<int> &A) {
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (const auto &x : A) min_heap.push(x);
    
    while (min_heap.size() >= 2) {
        int x = min_heap.top();
        min_heap.pop();
        int y = min_heap.top();
        min_heap.pop();
        res += x + y;
        min_heap.push(x + y);
    }

    return res;
}
```

A：双队列 + 快读

```cpp
#include <iostream>
using namespace std;

const int M = 1e5 + 10, N = 1e7 + 10;
int n, a[M];
long res;
long q1[N], q2[N];
int hh1, tt1, hh2, tt2;

void read(int &x) {
  int si = 1;
  x = 0;
  char c = getchar();
  if (c == '-') si = -1, c = getchar();
  for (; '0' <= c && c <= '9'; c = getchar())
    x = x * 10 + c - '0';
  x *= si;
}

long find_min() {
  long x;
  if (hh2 == tt2 || hh1 < tt1 && q1[hh1] < q2[hh2]) x = q1[hh1++];
  else x = q2[hh2++];
  return x;
}

int main() {
  read(n);
  for (int i = 1, x; i <= n; i++) {
    read(x);
    a[x]++;
  }

  for (int i = 1; i < M; i++) while (a[i]) a[i]--, q1[tt1++] = i;
  for (int i = 1; i < n; i++) {
    long x = find_min(), y = find_min();
    res += x + y;
    q2[tt2++] = x + y;
  }

  printf("%ld\n", res);
}
```



## 线段树

例题1（区间查询、单点修改）

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A$的第$i$个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
struct Node {
    int l, r;
    int sum;
} tr[N << 2];
// n个数，m次询问
int n, m;
int A[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = A[l];
        return;
    }

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    int mid = tr[u].l + tr[u].r >> 1, sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

void add(int u, int i, int x) {
    if (tr[u].l == tr[u].r) {
        tr[u].sum += x;
        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;
    if (i <= mid) add(u << 1, i, x);
    else add(u << 1 | 1, i, x);
    pushup(u);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    build(1, 1, n);

    while (m--) {
        // op = 0代表求第a到第b个数的和；op = 1代表将第a个数加上b
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) add(1, a, b);
        else printf("%d\n", query(1, a, b));
    }

    return 0;
}
```

例题2（区间查询、区间修改）

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A[l:r]$里的每个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
struct Node {
    int l, r;
    long sum, add;
} tr[N << 2];
int n, m;
int A[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (tr[u].add) {
        Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        left.add += root.add;
        left.sum += (long) (left.r - left.l + 1) * root.add;
        right.add += root.add;
        right.sum += (long) (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].sum = A[l];
        return;
    }

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

long query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    long sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int l, int r, long x) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += (long) (tr[u].r - tr[u].l + 1) * x;
        tr[u].add += x;
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);
    pushup(u);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    build(1, 1, n);

    while (m--) {
        char op[2];
        scanf("%s", op);
        // C代表增加数的操作；Q代表询问操作
        if (*op == 'C') {
            int l, r;
            long x;
            scanf("%d%d%ld", &l, &r, &x);
            modify(1, l, r, x);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%ld\n", query(1, l, r));
        }
    }

    return 0;
}
```



## 树状数组

例题1（区间查询、单点修改）

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A$的第$i$个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        tr[i] += x;
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }

    while (m--) {
        char op[2];
        scanf("%s", op);

        if (*op == 'Q') {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", sum(r) - sum(l - 1));
        } else {
            int i, x;
            scanf("%d%d", &i, &x);
            add(i, x);
        }
    }

    return 0;
}
```

例题2（区间修改、单点查询）

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A[l:r]$的每个数增加$x$，第二种询问是求$A[i]$。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m, tr[N], a[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int x = a[i] - a[i - 1];
        tr[i] += x;
        int j = i + lowbit(i);
        if (j <= n) tr[j] += tr[i];
    }
    
    while (m--) {
        char op[2];
        scanf("%s", op);

        if (*op == 'Q') {
            int i;
            scanf("%d", &i);
            printf("%d\n", sum(i);
        } else {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            add(l, x);
            add(r + 1, -x);
        }
    }

    return 0;
}
```

例题3（用树状数组实现平衡树）

Q：要求实现一个数据结构，可以进行如下操作：

1、插入一个数$x$；

2、删除一个数$x$；

3、给定一个数$x$，问其在已经存储的数据里的排名，如果该数出现了多次，则返回最小排名，询问保证该数存在；

4、问排名为$k$的数是几，题目保证$k$大于等于$1$，小于已经存的数字个数；

5、给定一个数$x$，求小于它的最大数，如果不存在则返回$-\infty$；

6、给定一个数$x$，求大于它的最小数，如果不存在则返回$\infty$。

A：

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int tr[N], op[N], v[N], a[N];
int sz, idx;

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

// 求x离散化之后的值是多少
int get(int x) {
    return lower_bound(a + 1, a + 1 + idx, x) - a;
}

void insert(int x) {
    add(x, 1);
}

void remove(int x) {
    add(x, -1);
}

int get_rank_by_key(int x) {
    return sum(x - 1) + 1;
}

int get_key_by_rank(int rk) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (sum(mid) >= rk) r = mid;
        else l = mid + 1;
    }
	// 这里的l是离散化之后的答案，还需要还原回来才是正确答案
    return a[l];
}

int get_prev(int x) {
    return get_key_by_rank(sum(x - 1));
}

int get_next(int x) {
    return get_key_by_rank(sum(x) + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &op[i], &v[i]);
        if (op[i] != 4) a[++idx] = v[i];
    }

	// 排序完去重
    sort(a + 1, a + 1 + idx);
    sz = unique(a + 1, a + 1 + idx) - (a + 1);

    for (int i = 1; i <= n; i++) {
        int opt = op[i], x = v[i];
        // 如果不是第4个操作，则求一下x离散化之后的值
        if (opt != 4) x = get(v[i]);

        if (opt == 1) insert(x);
        else if (opt == 2) remove(x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(x));
        else if (opt == 4) printf("%d\n", get_key_by_rank(x));
        else if (opt == 5) printf("%d\n", get_prev(x));
        else if (opt == 6) printf("%d\n", get_next(x));
    }

    return 0;
}
```



## 块状数组（分块）

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A[l:r]$里的每个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 10, M = sqrt(N);
int n, m, len;
long A[N];
long sum[N / M + 1], add[N / M + 1];

int get(int i) {
    return i / len;
}

long query(int l, int r) {
    long res = 0;
    if (get(l) == get(r)) for (int i = l; i <= r; i++) res += A[i] + add[get(l)];
    else {
        int i = l, j = r;
        while (get(i) == get(l)) res += A[i++] + add[get(l)];
        while (get(j) == get(r)) res += A[j--] + add[get(r)];
        for (int k = get(i); k <= get(j); k++) res += sum[k];
    }
    
    return res;
}

void modify(int l, int r, long x) {
    if (get(l) == get(r)) for (int i = l; i <= r; i++) A[i] += x, sum[get(i)] += x;
    else {
        int i = l, j = r;
        while (get(i) == get(l)) A[i++] += x, sum[get(l)] += x;
        while (get(j) == get(r)) A[j--] += x, sum[get(r)] += x;
        for (int k = get(i); k <= get(j); k++) add[k] += x, sum[k] += len * x;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%ld", &A[i]);
        sum[get(i)] += A[i];
    }

    while (m--) {
        char op[2];
        scanf("%s", op);
        if (*op == 'Q') {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%ld\n", query(l, r));
        } else {
            int l, r;
            long x;
            scanf("%d%d%ld", &l, &r, &x);
            modify(l, r, x);
        }
    }

    return 0;
}
```



## 树链剖分

Q：给定一棵树，树中包含$n$个节点（编号$1∼n$），其中第$i$个节点的权值为$a_i$。初始时，$1$号节点为树的根节点。现在要对该树进行$m$次操作，操作分为以下$4$种类型：
1、 `u v k`，修改路径上节点权值，将节点$u$和节点$v$之间路径上的所有节点（包括这两个节点）的权值增加$k$。
2、`u k`，修改子树上节点权值，将以节点$u$为根的子树上的所有节点的权值增加$k$。
3、`u v`，询问路径，询问节点$u$和节点$v$之间路径上的所有节点（包括这两个节点）的权值和。
4、`u`，询问子树，询问以节点$u$为根的子树上的所有节点的权值和。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = N * 2;
int n, m;
int h[N], w[N], e[M], ne[M], idx;
int id[N], nw[N], cnt;
int dep[N], sz[N], top[N], fa[N], son[N];
struct Tree {
    int l, r;
    long sum, add;
} tr[N << 2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int from, int depth) {
  dep[u] = depth, fa[u] = from, sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs1(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
}

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
  auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
  if (root.add) {
    left.sum += root.add * (left.r - left.l + 1);
    left.add += root.add;
    right.sum += root.add * (right.r - right.l + 1);
    right.add += root.add;
    root.add = 0;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, nw[l], 0};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void update(int u, int l, int r, int k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].add += k;
    tr[u].sum += k * (tr[u].r - tr[u].l + 1);
    return;
  }
  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) update(u << 1, l, r, k);
  if (r > mid) update(u << 1 | 1, l, r, k);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum;
  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}

void update_path(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    update(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  update(1, id[v], id[u], k);
}

long query_path(int u, int v) {
  long res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += query(1, id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res += query(1, id[v], id[u]);
  return res;
}

void update_tree(int u, int k) {
  update(1, id[u], id[u] + sz[u] - 1, k);
}

long query_tree(int u) {
  return query(1, id[u], id[u] + sz[u] - 1);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(1, 1, 0);
  dfs2(1, 1);

  build(1, 1, n);
  
  scanf("%d", &m);
  while (m--) {
    int t, u, v, k;
    scanf("%d%d", &t, &u);
    if (t == 1) {
      scanf("%d%d", &v, &k);
      update_path(u, v, k);
    } else if (t == 2) {
      scanf("%d", &k);
      update_tree(u, k);
    } else if (t == 3) {
      scanf("%d", &v);
      printf("%ld\n", query_path(u, v));
    } else printf("%ld\n", query_tree(u));
  }
}
```

Q：给定一棵树，树中包含$n$个节点（编号$1∼n$），其中第$i$个节点的权值为$a_i$。初始时，$1$号节点为树的根节点。现在要对该树进行$m$次操作，操作分为以下$5$种类型：
1、`u`，将$u$设为新树根。

2、 `u v k`，修改路径上节点权值，将节点$u$和节点$v$之间路径上的所有节点（包括这两个节点）的权值增加$k$。
3、`u k`，修改子树上节点权值，将以节点$u$为根的子树上的所有节点的权值增加$k$。
4、`u v`，询问路径，询问节点$u$和节点$v$之间路径上的所有节点（包括这两个节点）的权值和。
5、`u`，询问子树，询问以节点$u$为根的子树上的所有节点的权值和。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx, w[N];
int id[N], nw[N], cnt;
int dep[N], son[N], top[N], sz[N], fa[N];
int root;
struct Tree {
  int l, r;
  long sum, add;
} tr[N << 2];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int depth) {
  dep[u] = depth, sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    dfs1(v, depth + 1);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int t) {
  id[u] = ++cnt, nw[cnt] = w[u], top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == son[u]) continue;
    dfs2(v, v);
  }
}

void pushup(int u) {
  tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
  auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
  if (root.add) {
    l.sum += root.add * (l.r - l.l + 1);
    l.add += root.add;
    r.sum += root.add * (r.r - r.l + 1);
    r.add += root.add;
    root.add = 0;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r, nw[l], 0};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int l, int r, long k) {
  if (l <= tr[u].l && tr[u].r <= r) {
    tr[u].add += k;
    tr[u].sum += k * (tr[u].r - tr[u].l + 1);
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r, k);
  if (r > mid) modify(u << 1 | 1, l, r, k);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  long res = 0;
  if (l <= mid) res += query(u << 1, l, r);
  if (r > mid) res += query(u << 1 | 1, l, r);
  return res;
}

void add_path(int u, int v, int k) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    modify(1, id[top[u]], id[u], k);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  modify(1, id[v], id[u], k);
}

long query_path(int u, int v) {
  long res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += query(1, id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res += query(1, id[v], id[u]);
  return res;
}

int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}

int get_son(int u, int v) {
  while (top[u] != top[v]) {
    if (fa[top[u]] == v) return top[u];
    u = fa[top[u]];
  }
  return son[v];
}

void add_sub(int u, int k) {
  modify(1, id[u], id[u] + sz[u] - 1, k);
}

void add_tree(int u, int k) {
  if (u == root) modify(1, 1, n, k);
  else if (lca(u, root) != u) modify(1, id[u], id[u] + sz[u] - 1, k);
  else {
    int x = get_son(root, u);
    modify(1, 1, n, k);
    modify(1, id[x], id[x] + sz[x] - 1, -k);
  }
}

long query_tree(int u) {
  if (u == root) return query(1, 1, n);
  if (lca(u, root) != u) return query(1, id[u], id[u] + sz[u] - 1);
  int x = get_son(root, u);
  return query(1, 1, n) - query(1, id[x], id[x] + sz[x] - 1);
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%ld", &w[i]);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    add(p, i);
    fa[i] = p;
  }

  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);

  scanf("%d", &m);
  while (m--) {
    int op, u, v;
    long k;
    scanf("%d%d", &op, &u);
    if (op == 1) {
      root = u;
    } else if (op == 2) {
      scanf("%d%ld", &v, &k);
      add_path(u, v, k);
    } else if (op == 3) {
      scanf("%ld", &k);
      add_tree(u, k);
    } else if (op == 4) {
      scanf("%d", &v);
      printf("%ld\n", query_path(u, v));
    } else printf("%ld\n", query_tree(u));
  }
}
```



## 并查集

例题1（询问连通性 + 集合点个数）

Q：一开始一共$n$个数，编号$1\sim n$，每个数各自在一个集合中。现在要进行$m$个操作，每次操作是下面三种之一：

1、将$a$和$b$所在集合合并；

2、问$a$和$b$是否在同一个集合中；

3、问$a$所在集合的点的个数。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int p[N], sz[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    
    while (m--) {
        char op[2];
        int x, y;
        cin >> op;
        if (op[0] == 'C') {
            cin >> x >> y;
            merge(x, y);
            int px = find(x), py = find(y);
    		if (px != py) {
    			p[px] = py;
    			sz[py] += sz[px];
            }
        } else if (op[0] == 'Q') {
            if (op[1] == '1') {
                // 问是否在同一个集合中
                cin >> x >> y;
                if (find(x) == find(y)) puts("Yes");
                else puts("No");
            } else if (op[1] == '2') {
                // 问所在集合的点个数
                cin >> x;
                printf("%d\n", sz[find(x)]);
            }
        }
    }

    return 0;
}
```

例题2（带权并查集）

Q：一开始有$n$个人，站在一排。要求应答如下询问：

1、将第$i$号人所在的那一列保持原有顺序，接在第$j$号人所在的那一列后面；

2、问第$i$号人和第$j$号人是否同属于一列，如果是，则输出他们之间有多少人，如果不是，输出$-1$。

```cpp
#include <iostream>
using namespace std;

const int N = 3e4 + 10;
int m;
int p[N], sz[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    
    return p[x];
}

int main() {
    scanf("%d", &m);
    for (int i = 1; i < N; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        char op[2];
        int a, b;
        // op是M代表操作1，是C代表操作2
        scanf("%s%d%d", op, &a, &b);
        int pa = find(a), pb = find(b);
        if (op[0] == 'M') {
            if (pa != pb) {
                p[pa] = pb;
                d[pa] = sz[pb];
                sz[pb] += sz[pa];
            }
        } else {
            if (pa != pb) puts("-1");
            else printf("%d\n", a != b ? abs(d[a] - d[b]) - 1 : 0);
        }
    }

    return 0;
}
```

例题3（带扩展域并查集）



## 搜索

### A*

例题1

Q：八数码问题。在$3×3$的棋盘上，摆有八个棋子，每个棋子上标有$1$至$8$的某一数字。棋盘中留有一个空格，空格用$0$来表示。空格周围的棋子可以移到空格中。要求解的问题是：给出一种初始布局（初始状态）和目标布局（为了使题目简单，设目标状态为`123804765`），找到一种最少步骤的移动方法，实现从初始布局到目标布局的转变。题目保证有解。

A：

```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
using PIS = pair<int, string>;

string s, ed = "123804765";
int d[] = {-1, 0, 1, 0, -1};
int pos[9];
unordered_map<string, int> dist;
priority_queue<PIS, vector<PIS>, greater<>> heap;

// 求s和ed的各个数字的曼哈顿距离之和
int h(string &s) {
    int dis = 0;
    for (int i = 0; i < 9; i++) {
        if (s[i] == '0') continue;
        int x = i / 3, y = i % 3;
        int xx = pos[s[i] - '0'] / 3, yy = pos[s[i] - '0'] % 3;
        dis += abs(x - xx) + abs(y - yy);
    }

    return dis;
}

int Astar() {
    dist[s] = 0;
    heap.push({h(s), s});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        s = t.second;
        if (s == ed) return dist[s];

        int idx = 0;
        while (s[idx] != '0') idx++;
        int x = idx / 3, y = idx % 3;
        for (int i = 0; i < 4; i++) {
            string ss = s;
            int xx = x + d[i], yy = y + d[i + 1];
            if (0 <= xx && xx < 3 && 0 <= yy && yy < 3) {
                swap(ss[idx], ss[xx * 3 + yy]);
                if (!dist.count(ss) || dist[ss] > dist[s] + 1) {
                    dist[ss] = dist[s] + 1;
                    heap.push({dist[ss] + h(ss), ss});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> s;
    for (int i = 0; i < 9; i++) pos[ed[i] - '0'] = i;

    printf("%d\n", Astar());
    return 0;
}
```



### IDA*

例题：

Q：八数码问题。对于每组数据，要求返回从初始状态到终止状态的最短操作序列，若路径不唯一，则返回操作序列字典序最小的那个序列。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10, INF = 2e9;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string op = "dlru";
int board[N], goal[N];
string path;
int next_depth;

int dis() {
    int dis = 0;
    for (int i = 0; i < 9; i++)
        if (board[i] != 9) {
            int x = i / 3, y = i % 3;
            int xx = goal[board[i]] / 3, yy = goal[board[i]] % 3;
            dis += abs(x - xx) + abs(y - yy);
        }

    return dis;
}

bool dfs(int idx, int depth, int pre, int max_depth) {
    int h = dis();
    if (depth + h > max_depth) {
        next_depth = min(next_depth, depth + h);
        return false;
    }

    if (!h) return true;

    int x = idx / 3, y = idx % 3;
    for (int i = 0; i < 4; i++) {
        if (i + pre == 3) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
            int nidx = nx * 3 + ny;
            swap(board[idx], board[nidx]);
            path += op[i];
            if (dfs(nx * 3 + ny, depth + 1, i, max_depth)) return true;
            swap(board[idx], board[nidx]);
            path.pop_back();
        }
    }

    return false;
}

int main() {
    int T;
    char str[10];
    scanf("%d", &T);
    for (int k = 1; k <= T; k++) {
        int idx;
        scanf("%s", str);
        for (int i = 0; i < 9; i++) {
            if (str[i] == 'X') board[i] = 9, idx = i;
            else board[i] = str[i] - '0';
        }

        scanf("%s", str);
        for (int i = 0; i < 9; i++) {
            if (str[i] == 'X') goal[9] = i;
            else goal[str[i] - '0'] = i;
        }

        path = "";
        for (int max_depth = dis();; max_depth = next_depth) {
            next_depth = INF;
            if (dfs(idx, 0, INF, max_depth)) break;
        }

        printf("Case %d: %d\n", k, path.size());
        cout << path << endl;
    }
}
```



## 点分治

Q：给定一棵$n$个顶点的无权树，问距离不超过$m$的点对个数是多少个。$(u,v)$和$(v,u)$视为同一个点对，并且$(u,u)$不视为一个点对。

A：

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10, M = N << 1;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int sz[N];
bool vis[N];
int p[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int get_sz(int u, int from) {
  if (vis[u]) return 0;
  sz[u] = 1;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) sz[u] += get_sz(v, u);
  }
  return sz[u];
}

bool get_wc(int u, int from, int tot, int &wc) {
  int ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from || vis[v]) continue;
    if (get_wc(v, u, tot, wc)) return true;
    ms = max(ms, sz[v]);
  }
  ms = max(ms, tot - sz[u]);
  if (ms <= tot / 2) {
    wc = u;
    return true;
  }
  return false;
}

int get_dist(int u, int from, int dist, int &pt) {
  if (vis[u]) return 0;
  int cnt = 1;
  p[pt++] = dist;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) cnt += get_dist(v, u, dist + w[i], pt);
  }

  return cnt;
}

int calc(int l, int r) {
  sort(p + l, p + r + 1);
  int res = 0;
  for (int i = l, j = r; i < j;)
    if (p[i] + p[j] <= m) res += j - i, i++;
    else j--;

  return res;
}

int dfs(int u) {
  if (vis[u]) return 0;
  get_wc(u, -1, get_sz(u, -1), u);
  vis[u] = true;

  int res = 0, pt = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    int cnt = get_dist(v, -1, w[i], pt);
    if (!cnt) continue;
    res -= calc(pt - cnt, pt - 1);
    int l = pt - cnt, r = pt - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (p[mid] <= m) l = mid;
      else r = mid - 1;
    }

    if (p[l] <= m) res += l - (pt - cnt) + 1;
  }
  res += calc(0, pt - 1);
  
  for (int i = h[u]; ~i; i = ne[i]) res += dfs(e[i]);
  return res;
}

int main() {
  memset(h, -1, sizeof h);
  for (int i = 1; i <= n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a++, b++;
    add(a, b, c), add(b, a, c);
  }
  printf("%d\n", dfs(1));
}
```



## 图论

### 最短路

#### 非负权图最短路

Q：给定一个$n$个点$m$条边的有向图，图中可能存在重边和自环，所有边权均非负。请你求出$1$号点到$n$号点的最短距离，如果无法从$1$号点走到$n$号点，则输出$−1$。

A：朴素版Dijkstra，如果图是稠密图

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) 
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        
        if (t == n) break;

        st[t] = true;
        for (int j = 1; j <= n; j++) 
            if (!st[j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main() {
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) g[a][b] = 0;
        else g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}
```

A：堆优化版Dijkstra，如果图是稀疏图

```cpp
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, dis = t.first;
        if (st[v]) continue;

        if (v == n) break;
        
        st[v] = true;
        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dist[j] > dis + w[i]) {
                dist[j] = dis + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}
```

#### 有边数限制的最短路

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，可能存在负环。求$1$号点到$n$号点的最多经过$k$条边的最短距离。如果不存在这样的路径则输出`impossible`。

A：Bellman-Ford算法

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
int n, m, k;
struct Edge {
  int u, v, w;
} e[M];
int dist[2][N];

int bellman_ford() {
  memset(dist, 0x3f, sizeof dist);
  dist[0][1] = dist[1][1] = 0;
    
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= m; j++) {
      int u = e[j].u, v = e[j].v, w = e[j].w;
      dist[i & 1][v] = min(dist[i & 1][v], dist[i - 1 & 1][u] + w);
    }
  
  if (dist[k & 1][n] > 0x3f3f3f3f / 2) return 0x3f3f3f3f;
  else return dist[k & 1][n];
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[i] = {u, v, w};
  }
  
  int res = bellman_ford();
  
  if (res == 0x3f3f3f3f) puts("impossible");
  else printf("%d\n", res);
  
  return 0;
}
```

#### 含负权边图最短路

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，不存在负环。求$1$号点到$n$号点的最多经过$k$条边的最短距离。如果不存在这样的路径则输出`impossible`。

A：SPFA

```cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], w[N], idx;
queue<int> q;
int dist[N];
bool vis[N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int spfa() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  q.push(1);
  vis[1] = true;
  while (q.size()) {
    int u = q.front(); q.pop();
    vis[u] = false;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[u] + w[i]) {
        dist[v] = dist[u] + w[i];
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  
  return dist[n];
}

int main() {
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c);
  }
  
  int res = spfa();
  if (res == 0x3f3f3f3f) puts("impossible");
  else printf("%d\n", res);
}
```

#### 负环

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，不存在负环。求$1$号点到$n$号点的最多经过$k$条边的最短距离。如果不存在这样的路径则输出`impossible`。

A：SPFA

```cpp
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 100010;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        stk.push(i);
        st[i] = true;
    }

    while (stk.size()) {
        int t = stk.top();
        stk.pop();

        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    stk.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << (spfa() ? "Yes" : "No") << endl;

    return 0;
}
```

#### 多点对最短路

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，不存在负环。给定$k$次询问，每次询问问点$x$到$y$的最短路长度。如果路径不存在，则输出`impossible`。

A：Floyd算法

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin >> n >> m >> Q;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w);
    }

    floyd();

    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > INF / 2) cout << "impossible" << endl;
        else cout << d[a][b] << endl;
    }

    return 0;
}
```

#### 最小环

Q：给定一个无向图，求图中至少含$3$个点的环，环上节点不重复，并且总边权最小。若无解则输出`No solution.`。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], d[N][N];

int floyd() {
  int res = INF;
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i < k; i++)
      for (int j = i + 1; j < k; j++)
        if (d[i][j] < INF && g[j][k] < INF && g[k][i] < INF)
          res = min(res, d[i][j] + g[j][k] + g[k][i]);
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
  }

  return res;
}

int main() {
  memset(g, 0x3f, sizeof g);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  memcpy(d, g, sizeof g);

  int res = floyd();
  res < INF ? printf("%d\n", res) : puts("No solution.");
}
```



### 拓扑排序

Q：给定一个有向图，点的编号是$1\sim n$，可能存在重边和自环。输出其拓扑序列。若不存在则输出$-1$。

A：

BFS

```cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
bool vis[N];
int res[N], cnt;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (!d[i]) q.push(i);

    while (!q.empty()) {
        int t = q.front(); q.pop();
        res[++cnt] = t;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j]) q.push(j);
        }
    }

    return cnt == n;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    if (!bfs()) puts("-1");
    else for (int i = 1; i <= n; i++) cout << res[i] << ' ';

    return 0;
}
```

DFS

```CPP
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int vis[N];
int res[N], cnt;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
    vis[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (vis[j] == -1 && !dfs(j)) return false;
        else if (!vis[j]) return false;
    }
    
    vis[u] = 1;
    res[++cnt] = u;
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    memset(vis, -1, sizeof vis);
    for (int i = 1; i <= n; i++)
        if (vis[i] == -1 && !dfs(i)) {
            puts("-1");
            return 0;
        }

    for (int i = n; i; i--) cout << res[i] << ' ';
    return 0;
}
```

### 欧拉路径

Q：给定一张图，其可能是无向图，也可能是有向图，求其欧拉回路。返回任意一组合法解即可。如果无解，则输出`NO`。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

// 要建反向边，所以边数要开两倍
const int N = 100100, M = 400100;
int h[N], e[M], ne[M], idx;
int res[M], cnt;
// 记录某条边是否被访问过（主要是应付无向图的反向边）
bool used[M];
// din[i]和dout[i]分别记录顶点i的入度和出度
int din[N], dout[N];
int n, m;
// 记录图的类型，1表示无向图，2表示有向图
int type;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 从顶点u开始DFS
void dfs(int u) {
	// 注意，这里不是i = ne[i]，而是i = h[u]，因为每次遍历完一条边就顺便删掉了
    for(int i = h[u]; ~i ;i = h[u]) {
    	// 删掉当前边
        h[u] = ne[i];
        // 如果i是已经用过的某条边的反向边，则直接略过
        if (used[i]) continue;
        
        // 标记这条边已使用。其实这句话可以省去不写，后面
        // 的代码可以看出这个循环结束后这条边就已经被删了
        // used[i] = true;
        
        // 如果是无向图，那么这条边的反向边也要标记使用过了
        if (type == 1) used[i ^ 1] = true;

        int t;
        // 注意边是从1开始计数的
        if (type == 1) {
            t = i / 2 + 1;
            // (0, 1) (2, 3) (4, 5)奇数编号是返回的边
            if (i & 1) t = -t;
        } else t = i + 1;
        
		// 删掉当前的边，并继续DFS
        dfs(e[i]);
        // 回溯之前存路径
        res[cnt++] = t;
    }
}

int main() {
    scanf("%d%d%d", &type, &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        // 无向边
        if (type == 1) add(b, a);
        din[b]++, dout[a]++;   
    }

    if (type == 1) {
        for (int i = 1; i <= n; i++)
            if (din[i] + dout[i] & 1) {
                //无向图含欧拉回路的充要条件是每个点的度都为偶数
                puts("NO");
                return 0;
            }
    } else {
        for (int i = 1; i <= n; i++)
            if (din[i] != dout[i]) {
                //有向图含欧拉回路的充要条件是每个点的入度等于出度
                puts("NO");
                return 0;
            }
    }

    for (int i = 1; i <= n; i++) 
        if (~h[i]) {
            dfs(i);
            break;
        }

    if (cnt < m) puts("NO");
    else {
		puts("YES");
        for (int i = cnt - 1; i >= 0; i--)
            printf("%d ", res[i]);
    }

    return 0;
}
```

Q：给定一个有向图，求其字典序最小的欧拉路径。如果无解，则输出`NO`。

A：

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int deg[N][2];
vector<int> G[N];
// del[x]是x的出边已经删了多少条，即走过多少条
int res[M], idx, del[N], cnt[3];

void dfs(int u) {
  // 按指向点的字典序遍历出边，略过已经删掉的边
  for (int i = del[u]; i < G[u].size(); i = del[u]) {
    del[u]++;
    dfs(G[u][i]);
  }

  res[idx++] = u;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    deg[a][1]++, deg[b][0]++;
  }

  int S = 1;
  for (int i = 1; i <= n; i++) {
    if (deg[i][0] != deg[i][1]) cnt[0]++;
    // 如果存在出度比入度多1的点，那么如果存在欧拉通路，则起点为这个点
    if (deg[i][1] - deg[i][0] == 1) cnt[1]++, S = i;
    if (deg[i][0] - deg[i][1] == 1) cnt[2]++;
  }
	
  // 如果cnt[0]不为0则不存在欧拉回路；如果入度比出度多1的点
  // 不为1或者出度比入度多1的点不为1，则不存在欧拉通路
  if (cnt[0] && (cnt[1] != 1 || cnt[2] != 1)) return !puts("No");

  for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
  dfs(S);
  for (int i = idx - 1; i >= 0; i--) printf("%d ", res[i]);
}
```

### 最近公共祖先

Q：给定一棵有根的多叉树，再给定若干次询问，每次询问$a$和$b$这两个点的最近公共祖先的节点编号。

A：

```cpp
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 5e5 + 10, M = N << 1;
int n, m, qu, root;
int h[N], e[M], ne[M], idx;
int dep[N], f[N][25];
int q[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs() {
    memset(dep, -1, sizeof dep);
    dep[root] = 0;
    int hh = 0, tt = 0;
    q[tt++] = root;
    while (hh < tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dep[v] == -1) {
                dep[v] = dep[t] + 1;
                q[tt++] = v;
                f[v][0] = t;
                for (int k = 1; 1 << k <= dep[v]; k++) 
                    f[v][k] = f[f[v][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 0, diff = dep[a] - dep[b]; 1 << k <= diff; k++)
        if (diff >> k & 1)
            a = f[a][k];

    if (a == b) return a;

    for (int k = log2(dep[a]); k >= 0; k--)
        if (f[a][k] != f[b][k])
            a = f[a][k], b = f[b][k];

    return f[a][0];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d%d", &n, &qu, &root);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 0; i < qu; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }

    return 0;
}
```

### 有向图的强连通分量

#### 缩点

Q：给定一个有向图，$n$个顶点，$m$条边，求其强连通分量，建出缩点后的图。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, M = 100010;
int n, m;
// hs存缩点后的图
int h[N], hs[N], e[M], ne[M], idx;
// dfn[v]存v的访问时间戳，low[v]存v能访问到的点的时间戳最小值，timestamp表示当前时间戳
int dfn[N], low[N], timestamp;
int stk[N], top;
// in_stk[v]表示v是否在栈里
bool in_stk[N];
// id[v]表示点v在第几个强连通分量里，scc_cnt表示已经找到了多少个强连通分量
int id[N], scc_cnt, sz[N];

void add(int a, int b, int h[]) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[top++] = u, in_stk[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) low[u] = min(low[u], dfn[j]);        
    }
    
    if (dfn[u] == low[u]) {
        scc_cnt++;
        int y;
        do {
            y = stk[--top];
            in_stk[y] = false;
            id[y] = scc_cnt;
        } while (y != u);
    }
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b, h);
    }

    for (int i = 1; i <= n; i++) 
        if (!dfn[i])
            tarjan(i);
    
    for (int i = 1; i <= n; i++)
        for (int j = h[i]; ~j; j = ne[j])
            if (id[i] != id[e[j]])
                add(id[i], id[e[j]], hs);

    return 0;
}
```

### 无向图的双连通分量

#### 割点

Q：给定一个无向图，求割点总数，并将所有割点按编号从小到大输出。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
bool cut[N];
int tot;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;
    int child = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) child++;
        } else if (v != from) low[u] = min(low[u], dfn[v]);
    }

    if (u == from && child >= 2 || u != from && child) {
        cut[u] = true;
        tot++;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);

    printf("%d\n", tot);
    for (int i = 1; i <= n; i++)
        if (cut[i])
            printf("%d ", i);
}
```

### 二分图

#### 二分图最大匹配

Q：给定一个二分图，其中左半部包含$n_1$个点（编号$1\sim n_1$），右半部包含$n_2$个点（编号$1\sim n_2$），二分图共包含$m$条边。数据保证任意一条边的两个端点都不可能在同一部分中。求该二分图的最大匹配，返回匹配数。

A：匈牙利算法

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
// match[i]存的是右边的点i与左边哪个点匹配的。match[i] = 0说明还未匹配
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回从v出发是否能找到一条增广路
bool dfs(int v) {
    for (int i = h[v]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            // 如果走到了非匹配点，那已经找到了一条增广路，将其与v匹配并返回true；
            // 如果走到了匹配点j，那就看从j的匹配点出发能不能走出一条增广路，如果能，
            // 也可以将v与j匹配并返回true；否则不做新匹配，匹配保持原样
            if (!match[j] || dfs(match[j])) {
                match[j] = v;
                return true;
            }
        }
    }
	
	// 否则说明从v出发找不到增广路，返回false
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, 0, sizeof st);
        // 如果从i能找到增广路，就能增加匹配数，将匹配数加1
        if (dfs(i)) res++;
    }

    cout << res << endl;
    return 0;
}
```



## 数学

### 分解质因数

Q：给定一个正整数$n$，求其质数分解，每行格式为$p_i\ i$，表示质因子$p_i$的指数为$i$。

A：

```cpp
#include <iostream>
using namespace std;

void divide(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0) {
      int c = 0;
      while (n % i == 0) {
        n /= i;
        c++;
      }

      printf("%d %d\n", i, c);
    }
  }

  if (n > 1) printf("%d %d\n", n, 1);
}

int main() {
  int x;
  cin >> x;

  divide(x);
}
```

### 筛质数



### 康托展开

Q：求$1\sim N$的一个给定全排列在所有$1 \sim N$全排列中的排名。结果对$998244353$取模。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
const long MOD = 998244353;
int n;
int a[N], tr[N];
long res, fact[N];

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int cnt = 0;
    for (int i = k; i; i -= lowbit(i)) cnt += tr[i];
    return cnt;
}

int main() {
    scanf("%d", &n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % MOD;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = n; i; i--) {
        res = (res + fact[n - i] * sum(a[i])) % MOD;
        add(a[i], 1);
    }

	// 变为从1开始计数的排名
    res = (res + 1) % MOD;
    printf("%ld\n", res);

    return 0;
}
```

### 快速幂

例题（快速幂）

Q：求$a^k$对$p$取模的值，其中$1\le a, k, p\le 10^9$。

A：

```cpp
#include <iostream>
using namespace std;

int a, k, p;

int fast_pow(int a, int k, int p) {
    // 这里主要防止p = 1并且k = 0的情况。但是本题中不会出现这个问题
    long res = 1 % p;
    while (k) {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = (long) a * a % p;
    }

    return (int) res;
}

int main() {
    scanf("%d%d%d", &a, &k, &p);
    printf("%d\n", fast_pow(a, k, p));
    return 0;
}
```

例题（龟速乘）

Q：求$a\times b \bmod p$，其中$1\le a, b, p\le 10^{18}$。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

long qadd(long a, long b, long p) {
    long res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }

    return res;
}

int main() {
    long a, b, p;
    scanf("%ld%ld%ld", &a, &b, &p);
    printf("%ld\n", qadd(a, b, p));

    return 0;
}
```

### 中位数

Q：给定$n$个数$a_0,a_1,...,a_{n-1}$，求一个数$x$使得$\sum_i |a_i-x|$最小，返回这个总距离。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int quick_select(int l, int r, int idx) {
	if (l == r) return a[l];
    int i = l, j = r;
    int m = a[l + (r - l >> 1)];
    while (i <= j) {
        while (a[i] < m) i++;
        while (a[j] > m) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    
    if (idx <= j) return quick_select(l, j, idx);
    if (idx >= i) return quick_select(i, r, idx);
    return a[idx];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    int x = quick_select(0, n - 1, n / 2);
    for (int i = 0; i < n; i++) res += abs(a[i] - x);

    cout << res << endl;
    return 0;
}
```



## 动态规划

### 背包模型

例题1（0-1背包）

Q：有$N$件物品和一个容量是$V$的背包。每件物品只能使用一次。第$i$件物品的体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1010, V = 1010;
int v[N], w[N];
int f[V];

int main() {
	// n是总个数，m是总体积
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) 
        for (int j = m; j >= v[i]; j--)
                f[j] = max(f[j],  f[j - v[i]] + w[i]);   

    cout << f[m] << endl;
    return 0;
}
```

例题2（完全背包）

Q：有$N$件物品和一个容量是$V$的背包。每件物品使用次数不限。第$i$件物品的体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1010, V = 1010;
int v[N], w[N];
int f[V];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++) 
        for (int j = v[i]; j <= m; j++)
                f[j] = max(f[j],  f[j - v[i]] + w[i]); 

    cout << f[m] << endl;
    return 0;
}
```

例题3（多重背包）

Q：有$N$件物品和一个容量是$V$的背包。第$i$种物品最多用$s_i$次，体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：未优化

```cpp
#include <iostream>
using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= m; j++) 
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

    cout << f[n][m] << endl;

    return 0;
}
```

A：二进制优化

```cpp
#include <iostream>
using namespace std;

const int N = 15000, M = 2010;
int n, m;
int v[N], w[N], cnt;
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        for (int k = 1; k <= s; k <<= 1) {
            v[++cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
        }

        if (s) {
            v[++cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}
```

例题4（分组背包）

Q：有$N$组物品和一个容量是$V$的背包。每组物品有若干个，同一组内的物品最多只能选一个。每件物品的体积是$v_{ij}$，价值是$w_{ij}$，其中$i$是组号，$j$是组内编号。求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。输出最大价值。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int n, m;
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++) 
            cin >> w[i][j] >> v[i][j];
    }
        
    for (int i = 1; i <= n; i++) 
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (j >= w[i][k])
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);

    cout << f[m] << endl;

    return 0;
}
```

### 状态压缩

例题（最短哈密顿路径）

Q：给定一个$n$阶带权无向图，顶点从$0\sim n-1$标号，求从起点$0$到终点$n-1$的Hamilton路径的最短长度。两个顶点之间路径的长度$w[i][j]$由一个对称方阵给出。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 21, M = 1 << N;
int n;
int w[N][N], f[M][N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);

    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++) 
        for (int j = 0; j < n; j++)
            // 停留在j
            if (i >> j & 1)
                // 枚举从哪里走过来
                for (int k = 0; k < n; k++)
                    if (k != j && i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    printf("%d\n", f[(1 << n) - 1][n - 1]);
    return 0;
}
```

