# Trie



Trie中文叫字典树。Trie是个相当简单的数据结构，其是一个存储字符串信息的树结构，从根节点出发，每条边对应着某个字符，而从树根到节点的边所对应的字符连起来的单词，这个单词的信息可以存在那个节点里。看下图：

![C++ Trie Implementation](data:image/png;base64,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)

上面这个Trie里存的单词是，`a, at, ate, on, one, out, me, mud, my`，标黑的节点就表示从树根走到这个节点的单词在Trie里是存在的。

假设这个Trie只存英文小写字母所组成的单词，那么这个Trie的node的结构是：

```cpp
struct Node {
  Node *ne[26];
  bool is_word;
};
```



如果按照状态机的视角看Trie，它其实是这样的一个有限状态自动机：给定一个有穷的字符串集合$S$，这个自动机接受某个字符串$s$当且仅当$s\in S$。即，我们让每个节点成为一个状态，状态的转移就是边上的字母。如果字母符合，就跳转；否则跳转到一个死循环的状态。所有$S$中的单词能走到的状态即为接受的状态。那么这就是符合上述描述的状态机。



如果我们适当修改Node或者判断逻辑，那Trie可以做更多的事情，比如，Trie可以存每个单词出现的次数，也可以验证某个字符串$s$是否是Trie里某个字符串的前缀，等等。



## 一般问题

例题：https://blog.csdn.net/qq_46105170/article/details/113805415。在这道例题里，节点里要存其表示的单词出现的次数。代码如下：

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



## 最大异或对问题

这是个经典的用Trie解决的问题。例题：[https://blog.csdn.net/qq_46105170/article/details/113807387](https://blog.csdn.net/qq_46105170/article/details/113807387)给定一个数组，求异或值最大的数对。思路是，枚举第二个数$x$，然后在其前寻找与之异或最大的数。可以将前面的数视为二进制，然后存入Trie，从高位到低位存，接着拿$x$在Trie中进行询问，如果在某一位$u$在Trie中能找到$!u$的路径，那就说明$!u$这条路径存在数，而这些数与$x$进行异或的时候，可以保证这一位是$1$；由于数字是从高位到低位存的，所以走$!u$更优。如此这般，就能找到和$x$异或的最大数。

```cpp
#include <iostream>
using namespace std;

// Trie的节点数目可以开大一点
const int N = 100010, M = 31 * N;
int a[N], son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

// 询问与x异或最大的那个数是几
int query(int x) {
    int res = 0;
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        // 能走不同的边，就走之，反之只能走相同边
        if (son[p][!u]) {
            p = son[p][!u];
            res |= (!u) << i;
        } else {
            p = son[p][u];
            res |= u << i;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        insert(a[i]);
        res = max(res, query(a[i]) ^ a[i]);
    }

    cout << res << endl;

    return 0;
}
```

