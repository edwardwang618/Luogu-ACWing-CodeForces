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
#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int l, int r) {
  if (l >= r) return;

  int piv = a[l + (r - l >> 1)];
  int i = l, j = r;
  while (i <= j) {
    while (a[i] < piv) i++;
    while (a[j] > piv) j--;
    if (i <= j) swap(a[i++], a[j--]);
  }

  quick_sort(l, j), quick_sort(i, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  quick_sort(0, n - 1);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
```

归并排序

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], tmp[N];

void merge_sort(int l, int r) {
  if (l >= r) return;

  int m = l + (r - l >> 1);
  merge_sort(l, m), merge_sort(m + 1, r);

  int k = l, i = l, j = m + 1;
  while (i <= m && j <= r) {
    if (a[i] <= a[j]) tmp[k++] = a[i++];
    else tmp[k++] = a[j++];
  }

  while (i <= m) tmp[k++] = a[i++];
  while (j <= r) tmp[k++] = a[j++];

  for (i = l; i <= r; i++) a[i] = tmp[i];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  merge_sort(0, n - 1);
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
```

堆排序

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void sift_down(int i, int n) {
  int x = a[i];
  while (i << 1 <= n) {
    int j = i << 1;
    if (j + 1 <= n && a[j + 1] > a[j]) j++;
    if (a[j] <= x) break;
    a[i] = a[j];
    i = j;
  }

  a[i] = x;
}

void heapify(int n) {
  for (int i = n >> 1; i; i--) sift_down(i, n);
}

void heap_sort(int n) {
  heapify(n);
  for (int i = n; i; i--) {
    swap(a[1], a[i]);
    sift_down(1, i - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  heap_sort(n);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
```

堆排序，在$n$个数里从小到大输出前$m$小的数

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int h[N], &sz = h[0];

void sift_down(int u) {
  int x = h[u];
  while (u << 1 <= sz) {
    int t = u << 1;
    if (t + 1 <= sz && h[t + 1] < h[t]) t++;
    if (x < h[t]) break;
    h[u] = h[t];
    u = t;
  }
  h[u] = x;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> h[i];
  sz = n;

  for (int i = n / 2; i; i--) sift_down(i);

  while (m--) {
    cout << h[1] << ' ';
    h[1] = h[sz--];
    sift_down(1);
  }
}
```

基数排序

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int tmp[N], cnt[15];

int max_num() {
  int M = 0;
  for (int i = 1; i <= n; i++) M = max(M, a[i]);
  return M;
}

void radix_sort(int M) {
  for (int rad = 1; rad <= M; rad *= 10) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[a[i] / rad % 10]++;
    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i; i--) tmp[cnt[a[i] / rad % 10]--] = a[i];
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  radix_sort(max_num());
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
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



## 双指针

Q：给定两个升序数组$A$和$B$，给定一个数$x$，要求两个下标$i,j$使得$A[i]+B[j]=x$。题目保证解唯一。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int n, m, x;
int a[N], b[N];

int main() {
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);

  for (int i = 0, j = m - 1; i < n; i++) {
    while (j >= 0 && a[i] + b[j] > x) j--;
    if (a[i] + b[j] == x) {
      printf("%d %d\n", i, j);
      break;
    }
  }
}
```

Q：给定一个长$n$数组，找到最长的不含重复数字的子数组，输出其长度。

A：

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int n, a[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int res = 0;
  unordered_map<int, int> map;
  for (int i = 0, j = 0; i < n; i++) {
    map[a[i]]++;
    while (j < i && map[a[i]] > 1) map[a[j++]]--;
    res = max(res, i - j + 1);
  }

  cout << res << endl;
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

Q：给定数组$A$，要求返回数组$B$，其中$B[i]$是$A[i]$左边最远的比它小的数的下标，若不存在则令$B[i]=-1$。

A：单调栈 + 二分

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
    if (get_h(i - len + 1, i) == get_rh(i, i + len - 1)) 
      return true;
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

  printf("%d\n", l / 2);
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

#### 询问子串位置

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
      break;
    }
  }
}
```

#### 最短周期

Q：给定一个非空字符串$s$，问其是否由其某个真子串重复若干次而得。如果是，返回最短周期长度；如果不是，返回$-1$。

A：

```cpp
bool repeatedSubstringPattern(string s) {
  int n = s.size();
  s = ' ' + s;
  int ne[n + 1];
  ne[1] = 0;
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && s[i] != s[j + 1]) j = ne[j];
    if (s[i] == s[j + 1]) j++;
    ne[i] = j;
  }

  if (ne[n] && n % (n - ne[n]) == 0) return ne[n];
  else return -1;
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

### 查找

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

### 插入

```cpp
TreeNode* insert(TreeNode *root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insert(root->left, key);
    else if (key > root->val) root->right = insert(root->right, key);

    return root;
}
```

### 删除

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

### 分裂

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

### 合并

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



## 字典树

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
}
```

A：动态链表写法：

```cpp
class Trie {
 public:
  struct Node {
	Node* ne[26];
	int cnt;
	Node() : cnt(0) {
	  fill(ne, ne + 26, nullptr);
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

	cur->cnt++;
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

## 二叉堆

Q：实现一个数据结构，可以做如下操作：

1. 插入一个数$x$；
2. 输出最小的数；
3. 删除最小的数，如果最小的数有多个，则只删除$1$个。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int h[N], sz;

void sift_up(int k) {
  while (k > 1 && h[k] < h[k >> 1]) {
    swap(h[k], h[k >> 1]);
    k >>= 1;
  }
}

void sift_down(int k) {
  while (k * 2 <= sz) {
    int t = k;
    if (h[k * 2] < h[t]) t = k * 2;
    if (k * 2 + 1 <= sz && h[k * 2 + 1] < h[t]) t = k * 2 + 1;
    if (t == k) return;
    swap(h[k], h[t]);
    k = t;
  }
}

void push(int x) {
  h[++sz] = x;
  sift_up(sz);
}

void pop() {
  h[1] = h[sz--];
  sift_down(1);
}

#define top() h[1]

int main() {
  scanf("%d", &n);
  while (n--) {
    int op, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      push(x);
    } else if (op == 2) printf("%d\n", top());
    else pop();
  }
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



## 哈夫曼树

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

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A$的第$i$个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：区间查询、单点修改

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

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A[l:r]$里的每个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：区间查询、区间修改

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

Q：给定一个长$n$的数组$A$，要求应答三种询问，第一种询问是将$A[l:r]$里的每个元素乘以$x$，第二种询问是将$A[l:r]$里的每个元素加上$x$，第三种询问是求子数组$A[l:r]$的和。要求输出所有第三种询问的答案。

A：双懒标记

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
long p, a[N];
struct Node {
  int l, r;
  long sum;
  long mul, add;
} tr[N << 2];

void pushup(int u) {
  tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void update(Node &u, long mul, long add) {
  u.mul = (u.mul * mul) % p;
  u.add = (u.add * mul + add) % p;
  u.sum = (u.sum * mul + add * (u.r - u.l + 1)) % p;
}

void pushdown(int u) {
  update(tr[u << 1], tr[u].mul, tr[u].add);
  update(tr[u << 1 | 1], tr[u].mul, tr[u].add);
  tr[u].mul = 1, tr[u].add = 0;
}

void build(int u, int l, int r) {
  tr[u] = {l, r, 0, 1, 0};
  if (l == r) {
    tr[u].sum = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void modify(int u, int l, int r, long mul, long add) {
  if (l <= tr[u].l && tr[u].r <= r) {
    update(tr[u], mul, add);
    return;
  }

  pushdown(u);
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) modify(u << 1, l, r, mul, add);
  if (r > mid) modify(u << 1 | 1, l, r, mul, add);
  pushup(u);
}

long query(int u, int l, int r) {
  if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

  pushdown(u);
  long res = 0;
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) res = (res + query(u << 1, l, r)) % p;
  if (r > mid) res = (res + query(u << 1 | 1, l, r)) % p;
  return res;
}

int main() {
  scanf("%d%d%ld", &n, &m, &p);
  for (int i = 1; i <= n; i++) scanf("%ld", &a[i]);
  build(1, 1, n);
  while (m--) {
    int op, l, r;
    long x;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%ld", &x);
      modify(1, l, r, x, 0);
    } else if (op == 2) {
      scanf("%ld", &x);
      modify(1, l, r, 1, x);
    } else printf("%ld\n", query(1, l, r));
  }
}
```

Q：给定直角坐标系中的若干个矩形，求其合并的面积。重合部分只算一次。

A：扫描线

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;
int n;
struct Segment {
  double x, y1, y2;
  int k;
  bool operator<(const Segment &t) const { return x < t.x; }
} seg[N * 2];
struct Node {
  int l, r;
  int cnt;
  double len;
} tr[N * 8];
vector<double> ys;

int find(double y) { 
  return lower_bound(ys.begin(), ys.end(), y) - ys.begin(); 
}

void pushup(int u) {
  if (tr[u].cnt)
    tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
  else {
    if (tr[u].l != tr[u].r)
      tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    else
      tr[u].len = 0;
  }
}

void build(int u, int l, int r) {
  tr[u] = {l, r};
  if (l == r) return;
  int mid = l + r >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int k) {
  if (tr[u].l >= l && tr[u].r <= r) {
    tr[u].cnt += k;
  } else {
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, k);
    if (r > mid) modify(u << 1 | 1, l, r, k);
  }

  pushup(u);
}

int main() {
  int T = 1;
  while (cin >> n, n) {
    ys.clear();
    for (int i = 0, j = 0; i < n; i++) {
      double x1, y1, x2, y2;
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      seg[j++] = {x1, y1, y2, 1};
      seg[j++] = {x2, y1, y2, -1};
      ys.push_back(y1), ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    build(1, 0, ys.size() - 2);

    sort(seg, seg + n * 2);

    double res = 0;
    for (int i = 0; i < n * 2; i++) {
      if (i) res += tr[1].len * (seg[i].x - seg[i - 1].x);
      modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
    }

    printf("Test case #%d\n", T++);
    printf("Total explored area: %.2lf\n\n", res);
  }
}
```



## 树状数组

### 区间查询、单点修改

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

### 区间修改、单点查询

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

### 用树状数组实现平衡树

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

## 可持久化数据结构

### 主席树（可持久化线段树）

Q：给定一个整数数组$A$，初始版本为版本$0$。接下来做若干次操作：

1、将版本$i$的数组的第$k$个位置修改为数值$v$，并产生新的版本（新版本的编号为当前最新版本的编号加$1$）；

2、询问版本$i$的数组的第$k$个位置的数值是多少，并产生新的版本。

对询问$2$进行输出。

A：

```cpp
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int a[N];
struct Node {
  int l, r, v;
} tr[(N << 2) + N * 20];
int root[N], idx;

int build(int l, int r) {
  int p = ++idx;
  if (l == r) tr[p].v = a[l];
  else {
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
  }
  return p;
}

int update(int p, int l, int r, int k, int v) {
  int q = ++idx;
  tr[q] = tr[p];

  if (l == r) tr[q].v = v;
  else {
    int mid = l + r >> 1;
    if (k <= mid) tr[q].l = update(tr[q].l, l, mid, k, v);
    else tr[q].r = update(tr[q].r, mid + 1, r, k, v);
  }
  
  return q;
}

int query(int p, int l, int r, int k) {
  if (l == r) return tr[p].v;
  int mid = l + r >> 1;
  if (k <= mid) return query(tr[p].l, l, mid, k);
  else return query(tr[p].r, mid + 1, r, k);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  root[0] = build(1, n);
  for (int i = 1; i <= m; i++) {
    int vi, op, loc, val;
    scanf("%d%d%d", &vi, &op, &loc);
    if (op == 1) {
      scanf("%d", &val);
      root[i] = update(root[vi], 1, n, loc, val);
    } else {
      printf("%d\n", query(root[vi], 1, n, loc));
      root[i] = root[vi];
    }
  }
}
```

### 可持久化平衡树

Q：设计一个数据结构，可以实现：

1、插入$x$；

2、删除$x$（若有多个相同的数，应只删除一个，如果没有请忽略该操作）

3、查询$x$的排名（排名定义为比当前数小的数的个数$+1$）

4、查询排名为$x$的数

5、求$x$的前驱（前驱定义为小于$x$，且最大的数，如不存在输出$-2^{31}+1$）

6、求$x$的后继（后继定义为大于$x$，且最小的数，如不存在输出$2^{31}-1$）

和原本平衡树不同的一点是，每一次的任何操作都是基于某一个历史版本，同时生成一个新的版本。操作$3$，$4$，$5$，$6$即保持原版本无变化。每个版本的编号即为操作的序号（版本$0$即为初始状态，空树）

A：

```cpp
#include <iostream>
#include <climits>
using namespace std;

const int N = 5e5 + 10;
int n, root[N], idx;
int x, y, z;
struct Node {
  int l, r;
  int key, val;
  int sz;
} tr[N * 50];

int newnode(int v) {
  int p = ++idx;
  tr[p].key = v;
  tr[p].val = rand();
  tr[p].sz = 1;
  return p;
}

#define pushup(u) tr[u].sz = tr[tr[u].l].sz + tr[tr[u].r].sz + 1

void split(int p, int v, int &x, int &y) {
  if (!p) {
    x = y = 0;
    return;
  }

  if (tr[p].key <= v) {
    x = ++idx;
    tr[x] = tr[p];
    split(tr[x].r, v, tr[x].r, y);
    pushup(x);
  } else {
    y = ++idx;
    tr[y] = tr[p];
    split(tr[y].l, v, x, tr[y].l);
    pushup(y);
  }
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (tr[x].val < tr[y].val) {
    tr[x].r = merge(tr[x].r, y);
    pushup(x);
    return x;
  } else {
    tr[y].l = merge(x, tr[y].l);
    pushup(y);
    return y;
  }
}

void insert(int &root, int v) {
  split(root, v, x, y);
  z = newnode(v);
  root = merge(merge(x, z), y);
}

void remove(int &root, int v) {
  split(root, v, x, z);
  split(x, v - 1, x, y);
  y = merge(tr[y].l, tr[y].r);
  root = merge(merge(x, y), z);
}

int get_rank(int &root, int v) {
  split(root, v - 1, x, y);
  int res = tr[x].sz + 1;
  root = merge(x, y);
  return res;
}

int get_key(int root, int rk) {
  if (rk <= tr[tr[root].l].sz) return get_key(tr[root].l, rk);
  else if (rk > tr[tr[root].l].sz + 1)
    return get_key(tr[root].r, rk - tr[tr[root].l].sz - 1);
  else return tr[root].key;
}

int get_prev(int &root, int v) {
  split(root, v - 1, x, y);
  if (!x) return INT_MIN;
  int res = get_key(x, tr[x].sz);
  root = merge(x, y);
  return res;
}

int get_next(int &root, int v) {
  split(root, v, x, y);
  if (!y) return INT_MAX;
  int res = get_key(y, 1);
  root = merge(x, y);
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int vi, op, x;
    scanf("%d%d%d", &vi, &op, &x);
    root[i] = root[vi];
    if (op == 1) insert(root[i], x);
    else if (op == 2) remove(root[i], x);
    else if (op == 3) printf("%d\n", get_rank(root[i], x));
    else if (op == 4) printf("%d\n", get_key(root[i], x));
    else if (op == 5) printf("%d\n", get_prev(root[i], x));
    else printf("%d\n", get_next(root[i], x));
  }
}
```



## 分块

Q：给定一个长$n$的数组$A$，要求应答两种询问，第一种询问是将$A[l:r]$里的每个元素增加$x$，第二种询问是求子数组$A[l:r]$的和。

A：

```cpp
#include <iostream>
#include <cmath>
using namespace std;

const int N = 100010, M = 350;
int n, m, len;
long add[M], sum[M];
int w[N];
int bel[N];

void modify(int l, int r, int d) {
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) w[i] += d, sum[bel[i]] += d;
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) w[i++] += d, sum[bel[l]] += d;
    while (bel[j] == bel[r]) w[j--] += d, sum[bel[r]] += d;
    for (int k = bel[i]; k <= bel[j]; k++) sum[k] += len * d, add[k] += d;
  }
}

long query(int l, int r) {
  long res = 0;
  if (bel[l] == bel[r]) for (int i = l; i <= r; i++) res += w[i] + add[bel[i]];
  else {
    int i = l, j = r;
    while (bel[i] == bel[l]) res += w[i++] + add[bel[l]];
    while (bel[j] == bel[r]) res += w[j--] + add[bel[r]];
    for (int k = bel[i]; k <= bel[j]; k++) res += sum[k];
  }

  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  len = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    bel[i] = i / len;
    sum[bel[i]] += w[i];
  }

  char op[2];
  int l, r, d;
  while (m--) {
    scanf("%s%d%d", op, &l, &r);
    if (op[0] == 'C') {
      scanf("%d", &d);
      modify(l, r, d);
    } else printf("%ld\n", query(l, r));
  }
}
```



## 块状链表

Q：实现一个文本编辑器，可以做如下操作：

1、将光标移到第$k$个字符之后。如果$k=0$，则移到文本开头；

2、在光标处插入长度为$n$的字符串，光标位置不变；

3、删除光标后$n$个字符，光标位置不变；

4、输出光标后$n$个字符，光标位置不变；

5、光标前移一个字符；

6、光标后移一个字符。

题目保证每次操作都合法。插入的时候，插入字符串可能包含空格，可以忽略之，只考虑ASCII码位于$[32, 126]$的字符。

对于每条指令$4$输出答案。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2000, M = 2010;
int n, x, y;
struct Node {
    char s[N + 1];
    int c, l, r;
} p[M];
char str[2000010];
// 内存复用
int q[M], tt;

// 0号Node是边界Node，其实起始位置是0号点的下一个节点
void move(int k) {
  x = p[0].r;
  while (k > p[x].c) k -= p[x].c, x = p[x].r;
  y = k;
}

void add(int x, int u) {
  p[u].r = p[x].r, p[p[u].r].l = u;
  p[x].r = u, p[u].l = x;
}

void del(int u) {
  p[p[u].l].r = p[u].r;
  p[p[u].r].l = p[u].l;
  p[u].l = p[u].r = p[u].c = 0;
  q[tt++] = u;
}

void insert(int k) {
  if (y < p[x].c) {
    int u = q[--tt];
    for (int i = y + 1; i <= p[x].c; i++)
      p[u].s[++p[u].c] = p[x].s[i];
    p[x].c = y;
    add(x, u);
  }
  int cur = x;
  for (int i = 1; i <= k; ) {
    int u = q[--tt];
    while (p[u].c < N && i <= k)
      p[u].s[++p[u].c] = str[i++];
    add(cur, u);
    cur = u;
  }
}

void remove(int k) {
  if (p[x].c - y >= k) {
    for (int i = y + k + 1, j = y + 1; i <= p[x].c; )
      p[x].s[j++] = p[x].s[i++];
    p[x].c -= k;
  } else {
    k -= p[x].c - y;
    p[x].c = y;
    while (p[x].r && k >= p[p[x].r].c) {
      int u = p[x].r;
      k -= p[u].c;
      del(u);
    }
    int u = p[x].r;
    for (int i = 1, j = k + 1; j <= p[u].c; ) p[u].s[i++] = p[u].s[j++];
    p[u].c -= k;
  }
}

void get(int k) {
  if (p[x].c - y >= k)
    for (int i = y + 1; i <= y + k; i++) putchar(p[x].s[i]);
  else {
    for (int i = y + 1; i <= p[x].c; i++) putchar(p[x].s[i]);
    k -= p[x].c - y;
    int cur = x;
    while (p[cur].r && k >= p[p[x].r].c) {
      int u = p[cur].r;
      for (int i = 1; i <= p[u].c; i++) putchar(p[u].s[i]);
      k -= p[u].c;
      cur = u;
    }
    int u = p[cur].r;
    for (int i = 1; i <= k; i++) putchar(p[u].s[i]);
  }
  puts("");
}

void prev() {
  if (y > 1) y--;
  else {
    x = p[x].l;
    y = p[x].c;
  }
}

void next() {
  if (y < p[x].c) y++;
  else {
    x = p[x].r;
    y = 1;
  }
}

void merge() {
  for (int i = p[0].r; i; i = p[i].r) {
    while (p[i].r && p[i].c + p[p[i].r].c <= N) {
      int r = p[i].r;
      for (int j = p[i].c + 1, k = 1; k <= p[r].c; )
        p[i].s[j++] = p[r].s[k++];
      if (x == r) x = i, y += p[i].c;
      p[i].c += p[r].c;
      del(r);
    }
  }
}

int main() {
  for (int i = 1; i < M; i++) q[tt++] = i;
  scanf("%d", &n);
  char op[10];
  // 哨兵
  str[1] = '>';
  insert(1);
  move(1);
  while (n--) {
    int a;
    scanf("%s", op);
    if (!strcmp(op, "Move")) {
      scanf("%d", &a);
      move(a + 1);
    } else if (!strcmp(op, "Insert")) {
      scanf("%d", &a);
      int i = 1, k = a;
      while (a) {
        str[i] = getchar();
        if (32 <= str[i] && str[i] <= 126) i++, a--;
      }
      insert(k);
      merge();
    } else if (!strcmp(op, "Delete")) {
      scanf("%d", &a);
      remove(a);
      merge();
    } else if (!strcmp(op, "Get")) {
      scanf("%d", &a);
      get(a);
    } else if (!strcmp(op, "Prev")) prev();
    else next();
  }
}
```



## 莫队

### 基础莫队

Q：给定一个正整数数组，要求应答若干次询问，每次询问问区间$[l,r]$中有多少个不同的数。输出询问结果。

A：

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 50010, M = 200010, S = 1000010;
int n, m, len;
int w[N], res[M], ans;
int cnt[S];
struct Query {
  int id, l, r;
} q[M];

void add(int x) {
  if (!cnt[x]) ans++;
  cnt[x]++;
}

void del(int x) {
  cnt[x]--;
  if (!cnt[x]) ans--;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  scanf("%d", &m);
  len = sqrt(double(n) * n / m) + 1;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  
  sort(q, q + m, [&](Query &a, Query &b) {
    int i = a.l / len, j = b.l / len;
    if (i != j) return i < j;
    if (i & 1) return a.r < b.r;
    else return a.r > b.r;
  });

  for (int k = 0, i = 0, j = 1; k < m; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r;
    while (i < r) add(w[++i]);
    while (i > r) del(w[i--]);
    while (j < l) del(w[j++]);
    while (j > l) add(w[--j]);
    res[id] = ans;
  }

  for (int i = 0; i < m; i++) printf("%d\n", res[i]);
}
```

### 带修改莫队

Q：给定一个正整数数组，要求应答若干次询问，每次询问或者问区间$[l,r]$中有多少个不同的数，或者要求将某个位置的数修改为另一个数。输出每次询问结果。

A：

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e4 + 10, S = 1e6 + 10;
int n, m, len, mc, mq;
int w[N], cnt[S], res[N], ans;
struct Query {
  int id, l, r, t;
} q[N];
struct Modify {
  int p, c;
} c[N];

void add(int x) {
  if (!cnt[x]) ans++;
  cnt[x]++;
}

void del(int x) {
  cnt[x]--;
  if (!cnt[x]) ans--;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  for (int i = 0; i < m; i++) {
    char op[2];
    int a, b;
    scanf("%s%d%d", op, &a, &b);
    if (*op == 'Q') mq++, q[mq] = {mq, a, b, mc};
    else c[++mc] = {a, b};
  }
  len = sqrt(n);
  sort(q + 1, q + 1 + mq, [&](Query& a, Query& b) {
    int al = a.l / len, bl = b.l / len;
    if (al != bl) return al < bl;
    int ar = a.r / len, br = b.r / len;
    if (ar != br) if (al & 1) return ar < br; else return ar > br;
    return a.t < b.t;
  });

  for (int k = 1, i = 0, j = 1, t = 0; k <= mq; k++) {
    int id = q[k].id, l = q[k].l, r = q[k].r, tm = q[k].t;
    while (i < r) add(w[++i]);
    while (i > r) del(w[i--]);
    while (j < l) del(w[j++]);
    while (j > l) add(w[--j]);

    while (t < tm) {
      t++;
      if (l <= c[t].p && c[t].p <= r) {
        del(w[c[t].p]);
        add(c[t].c);
      }
      swap(w[c[t].p], c[t].c);
    }
    while (t > tm) {
      if (l <= c[t].p && c[t].p <= r) {
        del(w[c[t].p]);
        add(c[t].c);
      }
      swap(w[c[t].p], c[t].c);
      t--;
    }

    res[id] = ans;
  }

  for (int i = 1; i <= mq; i++) printf("%d\n", res[i]);
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

例题1

Q：一开始一共$n$个数，编号$1\sim n$，每个数各自在一个集合中。现在要进行$m$个操作，每次操作是下面三种之一：

1、将$a$和$b$所在集合合并；

2、问$a$和$b$是否在同一个集合中；

3、问$a$所在集合的点的个数。

A：询问连通性 + 集合点个数

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int p[N], sz[N];

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  int px = find(x), py = find(y);
  if (px == py) return;
  p[px] = py;
  sz[py] += sz[px];
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
    } else if (op[0] == 'Q') {
      if (op[1] == '1') {
        // 问是否在同一集合中
        cin >> x >> y;
        find(x) == find(y) ? puts("Yes") : puts("No");
      } else if (op[1] == '2') {
        // 问x所在集合的大小
        cin >> x;
        printf("%d\n", sz[find(x)]);
      }
    }
  }
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



## 左偏树

Q：一开始有$n$个小根堆，每个堆包含且仅包含一个数。接下来需要支持两种操作：
1、`1 x y`：将第$x$个数和第$y$个数所在的小根堆合并（若第$x$或第$y$个数已经被删除或第$x$和第$y$个数在用一个堆内，则无视此操作）。
2、`2 x`：输出第$x$个数所在的堆最小数，并将这个最小数删除（若有多个最小数，优先删除先输入的；若第$x$个数已经被删除，则输出$-1$并无视删除操作）。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int v[N], d[N], l[N], r[N];
int p[N];

bool cmp(int x, int y) {
  if (v[x] != v[y]) return v[x] < v[y];
  return x < y;
}

int find(int x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int merge(int x, int y) {
  if (!x || !y) return x ^ y;
  if (!cmp(x, y)) swap(x, y);
  r[x] = merge(r[x], y);
  if (d[r[x]] > d[l[x]]) swap(l[x], r[x]);
  d[x] = d[r[x]] + 1;
  return x;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    d[i] = 1;
    scanf("%d", &v[i]);
  }

  while (m--) {
    int t, x, y;
    scanf("%d%d", &t, &x);
    if (t == 1) {
      scanf("%d", &y);
      if (!d[x] || !d[y]) continue;
      x = find(x), y = find(y);
      if (x == y) continue;
      if (!cmp(x, y)) swap(x, y);
      p[y] = x;
      merge(x, y);
    } else {
      if (!d[x]) {
        puts("-1");
        continue;
      }
      x = find(x);
      printf("%d\n", v[x]);
      d[x] = 0;
      if (r[x] && !cmp(l[x], r[x])) swap(l[x], r[x]);
      p[x] = p[l[x]] = l[x];
      merge(l[x], r[x]);
    }
  }
}
```



## 搜索

### 深度优先搜索

#### 排列组合

Q：求$1\sim n$的所有组合，每个组合占一行，数字从小到大排列。

A：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
bool vis[20];

void dfs(int u) {
    for (int i = 0; i < a.size(); i++)
        printf("%d ", a[i]);
    puts("");
    
    for (int i = u; i <= n; i++) {
        a.push_back(i);
        dfs(i + 1);
        a.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    
    return 0;
}
```

Q：在$1\sim n$中任意选$m$个数，求所有方案。每个方案占一行，数字从小到大排列。方案之间按字典序排列。题目保证$m\le n$。

A：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> a;

void dfs(int u, int cnt) {
    if (cnt == m) {
        for (int x : a) printf("%d ", x);
        puts("");
        return;
    }
    
    if (u == n + 1) return;
    
    a.push_back(u);
    dfs(u + 1, cnt + 1);
    a.pop_back();
    dfs(u + 1, cnt);
}

int main() {
    scanf("%d%d", &n, &m);
    dfs(1, 0);
    return 0;
}
```

Q：求$1\sim n$的所有排列，每个排列占一行。排列之间按字典序排列。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 10;
int n;
int a[N];
bool st[N];

void dfs(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;

        a[idx] = i;
        st[i] = true;
        dfs(idx + 1);
        st[i] = false;
    }
}

int main() {
    cin >> n;
    dfs(0);

    return 0;
}
```

Q：（带重复排列）



#### 树的重心

Q：给定一棵$n$个节点的树，求其重心。

A：

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = 2 * N;
int n;
int h[N], e[M], ne[M], idx;
int res;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int from) {
  int cnt = 1, ms = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v != from) {
      int s = dfs(v, u);
      if (!s) return 0;
      ms = max(ms, s);
      cnt += s;
    }
  }

  ms = max(ms, n - cnt);
  if (ms <= n / 2) {
    res = ms;
    return 0;
  }

  return cnt;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1, -1);
  printf("%d\n", res);
}
```

#### 剪枝

Q：有一组等长的木棒，将它们随机地砍断，使得每一节木棍的长度都不超过$50$。想把这些木棍恢复到为裁截前的状态，但忘记了初始时有多少木棒以及木棒的初始长度。求木棒的可能最小长度。每一节木棍的长度都用大于零的整数表示。
A：法1

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 70;
int n;
int a[N], len, sum;
bool st[N];

// dfs的定义是，正在放第u组，第u组已经放了l的长度，从start开始枚举，问能否放完
// u是当前在放第几组，从0开始
// l是第u组已经放了多长，start是第u组在枚举哪个木棒的时候从哪个木棒开始枚举，那个木棒的下标
bool dfs(int u, int l, int start) {
  if (u * len == sum) return true;
  if (l == len) return dfs(u + 1, 0, 0);

  // 组合型枚举
  for (int i = start; i < n; i++) {
    if (st[i]) continue;
    if (l + a[i] > len) continue;
    if (i > start && !st[i - 1] && a[i] == a[i - 1]) continue;

    st[i] = true;
    if (dfs(u, l + a[i], i + 1)) return true;
    st[i] = false;

    if (!l || l + a[i] == len) return false;
  }

  return false;
}

int main() {
  while (cin >> n, n) {
    sum = len = 0;
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    sort(a, a + n, greater<int>());
    for (len = a[0]; len <= sum; len++)
      if (sum % len == 0 && dfs(0, 0, 0)) {
        printf("%d\n", len);
        break;
      }
  }

  return 0;
}
```

A：法2

```cpp
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 70;
int n;
int a[N], len, sum;
// s[i]是第i组已经拼出的长度，g[i]是下标为i的小木棍放在了的组的下标
int s[N], g[N];

// u是当前枚举到了的小木棍的下标，cnt是已经有多少个非空组
bool dfs(int u, int cnt) {
  // 如果枚举完了，看一下cnt是否是sum / len，
  // 如果是，说明得出了一个解，返回true
  if (u == n) {
    return cnt * len == sum;
  }

  // 如果开的组数过大，说明无解，返回false
  if (cnt > sum / len) return false;

  int start = 0;
  // 如果当前小木棍和上一个小木棍等长，则其从上一个小木棍所在组及其之后开始枚举
  if (u && a[u] == a[u - 1]) start = g[u - 1];

  for (int i = start; i <= cnt; i++) {
    if (s[i] + a[u] > len) continue;

    s[i] += a[u];
    g[u] = i;
    if (dfs(u + 1, cnt + (i == cnt ? 1 : 0))) return true;
    s[i] -= a[u];

    // 如果a[u]放在首尾无解，则该分支无解
    if (!s[i] || s[i] + a[u] == len) return false;
  }

  return false;
}

int main() {
  while (cin >> n, n) {
    sum = len = 0;
    memset(s, 0, sizeof s);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    sort(a, a + n, greater<int>());
    for (len = a[0]; len <= sum; len++)
      if (sum % len == 0 && dfs(0, 0)) {
        printf("%d\n", len);
        break;
      }
  }

  return 0;
}
```

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

A：朴素版Dijkstra，稠密图

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
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

  return dist[n] == INF ? -1 : dist[n];
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
}
```

A：堆优化版Dijkstra，稀疏图

```cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 150010, INF = 0x3f3f3f3f;
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
    auto t = heap.top(); heap.pop();
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

  return dist[n] == INF ? -1 : dist[n];
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  cout << dijkstra() << endl;
}
```

#### 分层图最短路

Q：给定一个非负权无向图，顶点个数$n$，边的个数$m$。从$1$出发走到$n$，总共有$k$次机会，每一步可以使用一次机会，让走的边的长度缩短到一半。问最短距离有多长。题目保证边长都是偶数，图连通。$k$次机会可以不用完。

A：

```cpp
#include <iostream>
#include <cstring>
#include <queue>
#define x first
#define y second
using namespace std;
using PLII = pair<long, pair<int, int>>;

const int N = 55, M = 2010;
int n, m, K;
int h[N], e[M], ne[M], w[M], idx;
long dist[N][N];
bool vis[N][N];

void add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

long dijkstra() {
  memset(dist, 0x3f, sizeof dist);
  memset(vis, 0, sizeof vis);
  dist[1][K] = 0;
  priority_queue<PLII, vector<PLII>, greater<PLII>> heap;
  heap.push({0, {1, K}});
  while (heap.size()) {
    auto t = heap.top(); heap.pop();
    int u = t.y.x, k = t.y.y;
    if (u == n) return t.x;
    if (vis[u][k]) continue;
    vis[u][k] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      if (!vis[v][k] && dist[v][k] > dist[u][k] + w[i]) {
        dist[v][k] = dist[u][k] + w[i];
        heap.push({dist[v][k], {v, k}});
      }
      if (k && !vis[v][k - 1] && dist[v][k - 1] > dist[u][k] + w[i] / 2) {
        dist[v][k - 1] = dist[u][k] + w[i] / 2;
        heap.push({dist[v][k - 1], {v, k - 1}});
      }
    }
  }

  return -1;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &m, &K);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  printf("%ld\n", dijkstra());
}
```

#### 有边数限制的最短路

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，可能存在负环。求$1$号点到$n$号点的最多经过$k$条边的最短距离。如果不存在这样的路径则输出`impossible`。

A：Bellman-Ford算法

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;
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

  if (dist[k & 1][n] > INF / 2) return INF;
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

  res == INF ? puts("impossible") : printf("%d\n", res);
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
  res == 0x3f3f3f3f ? puts("impossible") : printf("%d\n", res);
}
```

#### 负环

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，不存在负环。求$1$号点到$n$号点的最多经过$k$条边的最短距离。如果不存在这样的路径则输出`impossible`。

A：SPFA

```cpp
#include <cstring>
#include <iostream>
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
  memset(h, -1, sizeof h);
  cin >> n >> m;

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  spfa() ? puts("Yes") : puts("No");
}
```

#### 多点对最短路

Q：给定有$n$个点$m$条边的有向图，可能存在重边和自环，边权可能为负，不存在负环。给定$k$次询问，每次询问问点$x$到$y$的最短路长度。如果路径不存在，则输出`impossible`。

A：Floyd

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

A：倍增

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
}
```

A：树链剖分

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10, M = N << 1;
int n, qu;
int h[N], e[M], ne[M], idx;
int dep[N], son[N], top[N], sz[N], fa[N];
int root;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(int u, int from, int depth) {
  dep[u] = depth, sz[u] = 1, fa[u] = from;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == from) continue;
    dfs1(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[son[u]] < sz[v]) son[u] = v;
  }
}

void dfs2(int u, int from, int t) {
  top[u] = t;
  if (!son[u]) return;
  dfs2(son[u], u, t);
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (v == son[u] || v == from) continue;
    dfs2(v, u, v);
  }
}

int lca(int u, int v) {
  while (top[u] != top[v]) {
    // 谁的重链头深度深，谁就向上跳
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return dep[u] < dep[v] ? u : v;
}

int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d%d", &n, &qu, &root);
  for (int i = 1; i <= n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs1(root, -1, 0);
  dfs2(root, -1, root);

  for (int i = 0; i < qu; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", lca(a, b));
  }
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
// id[v]表示点v在第几个强连通分量里，scc_cnt表示已经找到了多少个强连通分量，sz[v]表示点v所在的缩点的点个数
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
            sz[scc_cnt]++;
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
        if (!dfn[i]) tarjan(i);
    
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

Q：给定一个正整数$n$，问小于等于$n$有多少个质数。

A：

埃拉托斯特尼筛

```cpp
#include <iostream>
using namespace std;

const int N = 1000010;
int primes[N], res;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[res++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_primes(n);

    cout << res << endl;

    return 0;
}
```

欧拉筛

```cpp
#include <iostream>
using namespace std;

const int N = 1000010;
int primes[N], res;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[res++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_primes(n);

    cout << res << endl;

    return 0;
}
```

### 约数

#### 求所有约数

Q：给定一个正整数$n$，求其所有约数，要求从小到大打印出来。

A：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> get_divisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; i++) 
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        vector<int> res = get_divisors(x);
        for (int i : res) cout << i << ' ';
        cout << endl;
    }

    return 0;
}
```

#### 约数个数

Q：给定一个正整数$n$，求其所有正约数的个数，答案模$10^9+7$。

A：

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
unordered_map<int, int> map;

void divide(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                c++;
                n /= i;
            }
            
            map[i] += c;
        }
    }

    if (n >= 2) map[n]++;
}

int main() {
    int x;
    cin >> x;

    divide(x);

    long res = 1;
    for (auto p : map) res = res * (p.second + 1) % MOD;
    cout << res << endl;

    return 0;
}
```

#### 约数之和

Q：给定一个正整数$n$，求其所有正约数的和，答案模$10^9+7$。

A：

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
unordered_map<int, int> map;

void divide(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                c++;
                n /= i;
            }
            
            map[i] += c;
        }
    }

    if (n >= 2) map[n]++;
}

int main() {
    int x;
    cin >> x;

    divide(x);

    long res = 1;
    for (auto pa : map) {
        int p = pa.first, a = pa.second;
        long t = 1;
        while (a--) t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }

    cout << res << endl;

    return 0;
}
```

### 欧拉函数

#### 欧拉函数

公式：设$n$为正整数，欧拉函数$\phi(n)=|\{1\le k\le n:(k,n)=1\}|$，设$n$的质因子分解为$n=p_{1}^{k_1}p_{2}^{k_2}...p_{s}^{k_s}$有公式：$\phi(n)=n\prod_{i=1}^s (1-\frac{1}{p_i})$。若素数$p|n$，则$\phi(pn)=p\phi(n)$；否则$\phi(pn)=(p-1)\phi(n)$。

Q：给定正整数$n$，求$\phi(n)$。

A：

```cpp
#include <iostream>
using namespace std;

int euler(int x) {
  int res = x;
  for (int i = 2; i <= x / i; i++) {
    if (x % i == 0) {
      res = res / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  }

  if (x >= 2) res = res / x * (x - 1);
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << euler(n) << endl;
}
```

Q：给定正整数$n$，求$\sum_{i=1}^n\phi(i)$。

A：欧拉筛法

```cpp
#include <iostream>
using namespace std;

const int N = 1000010;
int n;
int primes[N], cnt;
int phi[N];
bool st[N];

long get_eulers(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!st[i]) {
      primes[cnt++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; primes[j] <= n / i; j++) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        phi[i * primes[j]] = phi[i] * primes[j];
        break;
      }
      phi[i * primes[j]] = phi[i] * (primes[j] - 1);
    }
  }

  long res = 0;
  for (int i = 1; i <= n; i++) res += phi[i];
  return res;
}

int main() {
  cin >> n;
  cout << get_eulers(n) << endl;
}
```

#### 欧拉定理、费马小定理

定理：设$(a,n)=1$，$a,n$都是正整数，则$a^{\phi(n)}\equiv 1(\mod n)$。特殊地，设$p$为素数且$p$不整除$a$，则$a^{p-1}\equiv 1(\mod p)$。

定理：设$b\ge \phi(n)$，则$a^b\equiv a^{b \mod \phi(n)+\phi(n)}(\mod n)$。

Q：给定正整数$a,b,m$，求$a^b\mod m$。

A：

```cpp
#include <iostream>
using namespace std;

long a, b, m;

long fast_pow() {
  long res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    b >>= 1L;
    a = a * a % m;
  }
  return res;
}

int main() {
  scanf("%ld%ld", &a, &m);
  long phi = m, tmp = m;
  for (int i = 2; i <= tmp / i; i++) {
    if (tmp % i == 0) {
      phi = phi / i * (i - 1);
      while (tmp % i == 0) tmp /= i;
    }
  }

  if (tmp > 1) phi = phi / tmp * (tmp - 1);

  char ch;
  bool flag = false;
  while (!isdigit(ch = getchar()));
  for (; isdigit(ch); ch = getchar()) {
    b = b * 10 + ch - '0';
    if (b >= phi) {
      flag = true;
      b %= phi;
    }
  }
  if (flag) b += phi;
  printf("%ld\n", fast_pow());
}
```

### 最大公约数

#### 最大公约数

Q：给定两个整数$a$和$b$，求其最大公约数。

A：欧几里得算法

```cpp
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a; 
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}
```

#### 裴蜀定理

Q：给定两个整数$a$和$b$，求一组解$(x,y)$使得$ax+by=\gcd(a,b)$。

A：扩展欧几里得算法

```cpp
#include <iostream>
using namespace std;

void exgcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }

  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);

    printf("%d %d\n", x, y);
  }
}
```

#### 线性同余方程

Q：给定正整数$a,b,m$，求一个解$x$使得$ax\equiv b(\mod m)$。

A：

```cpp
#include <iostream>
using namespace std;

int exgcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }

  int d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  int a, b, m;
  scanf("%d%d%d", &a, &b, &m);
  int x, y;
  int d = exgcd(a, m, x, y);

  if (b % d == 0) printf("%d\n", (long)x * (b / d) % m);
  else puts("impossible");
}
```

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

Q：求$a^k$对$p$取模的值，其中$1\le a, k, p\le 10^9$。

A：快速幂

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

Q：设$p$为素数，给定一个正整数$a$，求$a$在模$p$意义下的逆元。若不存在逆元则输出`impossible`。

A：快速幂求逆元

```cpp
#include <iostream>
using namespace std;

int fast_pow(int a, int k, int p) {
    long res = 1;
    while (k) {
        if (k & 1) res = res * a % p;
        
        k >>= 1;
        a = (long) a * a % p;
    }

    return (int) res;
}

int main() {
    int a, p;
    scanf("%d%d", &a, &p);
        
    if (a % p == 0) printf("impossible\n");
    else {
    	int res = fast_pow(a, p - 2, p);
	    printf("%d\n", res);
    }
    return 0;
}
```

Q：求$a\times b \bmod p$，其中$1\le a, b, p\le 10^{18}$。

A：龟速乘

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

### 组合数学

#### 容斥原理

公式：$|S_1\cup S_2\cup...\cup S_n|=\sum_i |S_i|-\sum_{i_1<i_2}|S_{i_1}\cap S_{i_2}|+\sum_{i_1<i_2<i_3}|S_{i_1}\cap S_{i_2}\cap S_{i_3}|-...\\ +(-1)^{n-1}|S_1\cup S_2\cup...\cup S_n|$

Q：给定一个正整数$n$和$m$个不同的素数$p_1,...,p_m$，求$1\sim n$中能被这些素数其一整除的整数有多少个。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 20;
int n, m;
int p[N];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> p[i];

  int res = 0;
  for (int i = 1; i < 1 << m; i++) {
    int prod = 1, cnt = 0;
    for (int j = 0; j < m; j++)
      if (i >> j & 1) {
        cnt++;
        if ((long)prod * p[j] > n) {
          prod = -1;
          break;
        }
        prod *= p[j];
      }

    if (prod != -1)
      if (cnt % 2)
        res += n / prod;
      else
        res -= n / prod;
  }

  cout << res << endl;
}
```

#### 错排问题

Q：某人写了$n$封信和$n$个信封，如果所有的信都装错了信封，求所有信都装错信封共有多少种不同情况。

A：

```cpp
#include <iostream>
using namespace std;
const int N = 30;
int n;
long f[N];

int main() {
  scanf("%d", &n);
  f[1] = 0, f[2] = 1;
  for (int i = 3; i <= n; i++)
    f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
  printf("%ld\n", f[n]);
}
```

Q：某人写了$n$封信和$n$个信封，如果恰好有$m$封信装对了信封，求所有信都装错信封共有多少种不同情况。答案模$10^9+7$后返回。

A：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10, P = 1e9 + 7;
long fac[N], f[N], inv[N];
int n, m;

long fast_pow(long x, int p) {
  long res = 1;
  while (p) {
    if (p & 1) res = res * x % P;
    x = x * x % P;
    p >>= 1;
  }
  return res;
}

long inverse(int i) {
  if (~inv[i]) return inv[i];
  return inv[i] = fast_pow(fac[i], P - 2);
}

long comb(int n, int m) {
  return fac[n] * inverse(m) % P * inverse(n - m) % P;
}

int main() {
  memset(inv, -1, sizeof inv);
  f[0] = 1, f[1] = 0;
  fac[0] = fac[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % P;
    fac[i] = fac[i - 1] * i % P;
  }

  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    printf("%ld\n", comb(n, m) * f[n - m] % P);
  }
}
```

### 博弈论

#### Nim游戏

Q：甲乙两个人玩取石子游戏，有$n$堆石子，两人轮流取，每次取的人可以在任一堆石子里取任意个石子扔掉，可以一次取完，但不能不取。问先取者是否有必胜策略。

A：

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int res = 0;
  while (n--) {
    int x;
    scanf("%d", &x);
    res ^= x;
  }
  res ? puts("Yes") : puts("No");
}
```

#### SG函数

Q：甲乙两个人玩取石子游戏，有$n$堆石子和一个数字构成的集合$S$，两人轮流取，每次取的人可以在任一堆石子里取$S$中的数个石子扔掉，不能不取。问先取者是否有必胜策略。

A：

```cpp
#include <cstring>
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 110, M = 10010;
int k, n;
int s[N], f[M];

int sg(int x) {
  if (f[x] != -1) return f[x];

  unordered_set<int> set;
  for (int i = 0; i < k; i++)
    if (x >= s[i]) set.insert(sg(x - s[i]));

  for (int i = 0;; i++)
    if (!set.count(i)) return f[x] = i;
}

int main() {
  cin >> k;
  for (int i = 0; i < k; i++) cin >> s[i];
  cin >> n;

  memset(f, -1, sizeof f);

  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    res ^= sg(x);
  }

  res ? puts("Yes") : puts("No");
}
```

### 计算几何

#### 基础知识

公式及常用代码：

```cpp
#include <cmath>
double pi = acos(-1);

const double eps = 1e-8;
int sign(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}
int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}
```

设三角形三条边长为$a,b,c$，对应的角为$A,B, C$，则：

余弦定理：$a^2=b^2+c^2-2bc\cos A$。

正弦定理：$\frac{a}{\sin A}=\frac{b}{\sin B}=\frac{c}{\sin C}$

$\vec{a}=(x_1,y_1), \vec{b}=(x_2,y_2)$

点积：$\vec{a}\cdot \vec{b}=|\vec{a}||\vec{b}|\cos \theta=x_1x_2+y_1y_2$

叉积：$|\vec{a}\times \vec{b}|=|\vec{a}||\vec{b}||\sin \theta|=|x_1y_2-x_2y_1|$

```cpp
Point operator-(Point &a, Point &b) {
  return {a.x - b.x, a.y - b.y};
}

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}
double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
double get_length(Point a) {
    return sqrt(dot(a, a));
}
double get_angle(Point a, Point b) {
    return acos(dot(a, b) / get_length(a) / get_length(b));
}
double area(Point a, Point b, Point c) {
    return cross(b - a, c - a);
}
```

将$\vec{a}$逆时针旋转$\theta$，得：

$$\vec{b} = \vec{a}\begin{pmatrix} \cos\theta & \sin\theta \\-\sin\theta & \cos\theta \end{pmatrix}=(x_1,y_1)\begin{pmatrix} \cos\theta & \sin\theta \\-\sin\theta & \cos\theta \end{pmatrix}=(x_1\cos\theta-y_1\sin\theta, x_1\sin\theta+y_1\cos\theta)$$

```cpp
Point rotate(Point a, double theta) {
    return {a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)};
}
```

直线的表示：

一般式：$ax+by+c=0$

点向式：$\vec{p}+t\vec{v}$

斜截式：$y=kx+b$

判断点在直线上：验证$(\vec{a}-\vec{p})\times \vec{v}=\vec{0}$

求两条直线的交点：

```cpp
using Vector = Point;
Vector operator*(double t, Vector& v) {
    return {t * v.x, t * v.y};
}
Vector operator*(Vector& v, double t) {
    return t * v;
}
bool operator==(Point a, Point b) {
    return !cmp(a.x, b.x) && !cmp(a.y, b.y);
}
Point get_line_intersection(Point p, Vector v, Point q, Vector w) {
    auto u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + t * v;
}
// p到直线a->b的距离
double distance_to_line(Point p, Point a, Point b) {
    Vector v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2) / get_length(v1));
}
double distance_to_segment(Point p, Point a, Point b) {
    if (a == b) return get_length(p - a);
    Vector v1 = b - a, v2 = p - a, v3 = p - b;
    if (sign(dot(v1, v2)) < 0) return get_length(v2);
    if (sign(dot(v1, v3)) > 0) return get_length(v3);
    return distance_to_line(p, a, b);
}
Point get_line_projection(Point p, Point a, Point b) {
    Vector v = b - a;
    return a + v * (dot(v, p - a)) / dot(v, v));
}
bool on_segment(Point p, Point a, Point b) {
    return !sign(cross(p - a, p - b)) && sign(dot(p - a, p - b)) == -1;
}
bool segment_intersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a2 - b1), c4 = cross(b2 - b1, a1 - b1);
    return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
}
```

求凸多边形面积，其点按逆时针方向排列

```cpp
double polygon_area(Point p[], int n) {
    double s = 0;
    for (int i = 1; i + 1 < n; i++)
        s += cross(p[i] - p[0], p[i + 1] - p[i]);
   	return s / 2;
}
```

判断一个点是否在一个多边形内：

射线法：从该点任意做一条和所有边都不平行的射线，若交点个数为奇数，则在内，否则在外。

判断一个点是否在一个凸多边形内：

设每个点（边）逆时针排列，则只需要判断该点在每条边的左侧即可。

皮克定理：

设某个多边形的每个点都是整点，则其面积$s=a+\frac{b}{2}-1$，$a$为多边形内的整点个数，$b$是多边形边上的整点个数。

#### 凸包

Q：给定若干点，求其凸包的周长。

A：

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#define x first
#define y second
using namespace std;
using PDD = pair<double, double>;

const int N = 10010;
int n;
PDD q[N];
int stk[N];
bool used[N];

double get_dist(PDD a, PDD b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

PDD operator-(PDD &a, PDD &b) {
  return {a.x - b.x, a.y - b.y};
}

double cross(PDD a, PDD b) {
  return a.x * b.y - a.y * b.x;
}

double area(PDD a, PDD b, PDD c) {
  return cross(b - a, c - a);
}

double andrew() {
  int top = 0;
  for (int i = 0; i < n; i++) {
    while (top >= 2 && area(q[stk[top - 2]], q[stk[top - 1]], q[i]) >= 0)
      used[stk[--top]] = false;
    stk[top++] = i;
    used[i] = true;
  }

  used[0] = false;
  for (int i = n - 1; i >= 0; i--) {
    if (used[i]) continue;
    while (top >= 2 && area(q[stk[top - 2]], q[stk[top - 1]], q[i]) >= 0)
      top--;
    stk[top++] = i;
  }

  double res = 0;
  for (int i = 1; i < top; i++)
    res += get_dist(q[stk[i - 1]], q[stk[i]]);

  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf%lf", &q[i].x, &q[i].y);
  sort(q, q + n);
  int idx = 1;
  for (int i = 1; i < n; i++) if (q[i] != q[idx - 1]) q[idx++] = q[i];
  n = idx;
  printf("%.2lf\n", andrew());
}
```



## 动态规划

### 线性动态规划

Q：给定一个数组$a$，求其最长严格上升子序列长度。

A：动态规划

```cpp
#include <iostream>
using namespace std;

const int N = 1010;
int a[N], f[N];
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  int res = 0;
  for (int i = 1; i <= n; i++) {
	f[i] = 1;
	for (int j = 1; j < i; j++)
	  if (a[j] < a[i]) 
		f[i] = max(f[i], f[j] + 1);

    res = max(res, f[i]);
  }

  cout << res << endl;
}
```

A：偏序集分解定理

```cpp
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int a[N], f[N];

int binary_search(int r, int t) {
  if (r < 0) return -1;

  int l = 0;
  while (l < r) {
      int m = l + (r - l >> 1);
      if (f[m] >= t) r = m;
      else l = m + 1;
  }

  return f[l] >= t ? l : -1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int idx = 0;
  for (int i = 0; i < n; i++) {
    int pos = binary_search(idx - 1, a[i]);
    if (pos == -1) f[idx++] = a[i];
    else f[pos] = a[i];
  }

  cout << idx << endl;
}
```

Q：给定两个字符串$s$和$t$，求它们的最长公共子序列长度。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 1010;
string s, t;
int n, m;
int f[N][N];

int main() {
  cin >> n >> m;
  cin >> s >> t;

  s = ' ' + s;
  t = ' ' + t;

  for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
	  if (s[i] == t[j]) f[i][j] = 1 + f[i - 1][j - 1];
	  else f[i][j] = max(f[i - 1][j], f[i][j - 1]);

  cout << f[n][m] << endl;
}
```

### 区间动态规划

Q：$N$堆石子排成一排，编号$1\sim N$，第$i$堆石子的质量是$a[i]$，每次可以合并相邻的两堆，合并的代价为两堆石子质量之和。问最后要合并成一堆所需要的最小代价。

A：

```cpp
#include <iostream>
using namespace std;

const int N = 310;
int n;
int s[N];
int f[N][N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];

  for (int i = 1; i <= n; i++) s[i] += s[i - 1];

  for (int len = 2; len <= n; len++)
    for (int i = 1; i + len - 1 <= n; i++) {
      int l = i, r = i + len - 1;
      f[l][r] = 1e9;
      for (int k = l; k < r; k++)
        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
    }

  cout << f[1][n] << endl;
}
```

### 背包模型

Q：有$N$件物品和一个容量是$V$的背包。每件物品只能使用一次。第$i$件物品的体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：0-1背包

```cpp
#include <iostream>
using namespace std;

const int N = 1010, V = 1010;
int v[N], w[N];
int f[V];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= v[i]; j--) 
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  cout << f[m] << endl;
}
```

Q：有$N$件物品和一个容量是$V$的背包。每件物品使用次数不限。第$i$件物品的体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：完全背包

```cpp
#include <iostream>
using namespace std;

const int N = 1010, V = 1010;
int v[N], w[N];
int f[V];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

  for (int i = 1; i <= n; i++)
    for (int j = v[i]; j <= m; j++) 
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  cout << f[m] << endl;
}
```

Q：有$N$件物品和一个容量是$V$的背包。第$i$种物品最多用$s_i$次，体积是$v_i$，价值是$w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。

A：多重背包，未优化

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
}
```

A：多重背包，二进制优化

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
}
```

Q：有$N$组物品和一个容量是$V$的背包。每组物品有若干个，同一组内的物品最多只能选一个。每件物品的体积是$v_{ij}$，价值是$w_{ij}$，其中$i$是组号，$j$是组内编号。求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。输出最大价值。

A：分组背包

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
    for (int j = 1; j <= s[i]; j++) cin >> w[i][j] >> v[i][j];
  }

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      for (int k = 1; k <= s[i]; k++)
        if (j >= w[i][k]) f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);

  cout << f[m] << endl;
}
```

### 状态压缩

Q：给定一个$n$阶带权无向图，顶点从$0\sim n-1$标号，求从起点$0$到终点$n-1$的Hamilton路径的最短长度。两个顶点之间路径的长度$w[i][j]$由一个对称方阵给出。

A：最短哈密顿路径

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

