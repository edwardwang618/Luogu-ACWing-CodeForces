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
int q[M], tt;

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
  str[1] = '>';
  insert(1);
  move(1);
  char op[10];
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