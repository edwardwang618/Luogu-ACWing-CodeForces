#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 10010;
int n;
int p[N], cnt[N], cnt_house[N], area[N], min_id[N];

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void init(int x) {
  if (!~p[x]) p[x] = x;
}

void merge(int x, int y) {
  int px = find(x), py = find(y);
  if (px == py) return;
  p[px] = py;
  cnt[py] += cnt[px];
  cnt_house[py] += cnt_house[px];
  area[py] += area[px];
  min_id[py] = min(min_id[px], min_id[py]);
}

struct Info {
  int ID;
  int M;
  int TOT_CNT;
  int TOT_AREA;
};

int main() {
  for (int i = 0; i < N; i++) {
    p[i] = -1;
    cnt[i] = 1;
    min_id[i] = i;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int id, fa, mo, k;
    scanf("%d%d%d%d", &id, &fa, &mo, &k);
    init(id);
    if (~fa)
      init(fa), merge(id, fa);
    if (~mo)
      init(mo), merge(id, mo);
    for (int j = 1; j <= k; j++) {
      int ch;
      scanf("%d", &ch);
      init(ch);
      merge(id, ch);
    }
    int c, a;
    scanf("%d%d", &c, &a);
    int pid = find(id);
    cnt_house[pid] += c;
    area[pid] += a;
  }

  vector<Info> v;
  for (int i = 0; i < N; i++)
    if (p[i] == i) {
      Info info;
      info.ID = min_id[i];
      info.M = cnt[i];
      info.TOT_CNT = cnt_house[i];
      info.TOT_AREA = area[i];
      v.push_back(info);
    }

  sort(v.begin(), v.end(), [&](Info &x1, Info &x2) {
    if (x1.TOT_AREA * x2.M != x2.TOT_AREA * x1.M) {
      return x1.TOT_AREA * x2.M > x2.TOT_AREA * x1.M;
    }
    return x1.ID < x2.ID;
  });
  printf("%lu\n", v.size());
  for (auto &info : v) {
    printf("%04d %d %.3lf %.3lf\n", info.ID, info.M,
           (double)info.TOT_CNT / info.M, (double)info.TOT_AREA / info.M);
  }
}