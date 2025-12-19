#include <iostream>
#include <queue>
#include <set>
using namespace std;

using PII = pair<int, int>;

#define x first
#define y second

// 总内存单元数
int n;
// 等待队列：{M, P}
queue<PII> wait_q;
// 已占用区：{start, len}，含左右哨兵 [-1,1] 和 [N,1]
set<PII> used;
// 释放事件小根堆：{end_time, start}
priority_queue<PII, vector<PII>, greater<PII>> rel;
// 输出：最后结束时刻、进入过等待队列的数量
int last_end = 0, wait_cnt = 0;

// 在时刻 t，尝试分配 M 并运行 P，成功则登记释放事件
bool alloc_try(int t, int M, int P) {
  // 相邻占用之间的空洞：[it_end, jt_start)
  // it_end = it->x + it->y
  for (auto it = used.begin(); it != used.end(); ++it) {
    auto jt = next(it);
    if (jt == used.end())
      break;
    int start = it->x + it->y;
    int gap = jt->x - start;
    if (gap >= M) {
      used.emplace(start, M);
      rel.emplace(t + P, start);
      return true;
    }
  }
  return false;
}

// 处理所有释放时间 <= t 的事件；每个释放时刻后尽力分配等待队头
void drain_release(int t) {
  while (rel.size() && rel.top().x <= t) {
    int f = rel.top().x;

    // 释放所有在时刻 f 结束的块
    while (rel.size() && rel.top().x == f) {
      int s = rel.top().y;
      rel.pop();
      auto it = used.lower_bound({s, 0});
      used.erase(it);
    }

    // 在时刻 f，队头可分配则一直分配，直到队头卡住
    while (wait_q.size()) {
      auto [M, P] = wait_q.front();
      if (alloc_try(f, M, P)) {
        wait_q.pop();
      } else
        break; // 队头优先，队头卡住则停止
    }

    last_end = f;
  }
}

int main() {
  scanf("%d", &n);
  used.emplace(-1, 1);
  used.emplace(n, 1);

  // T时刻，长M，运行时间P
  int T, M, P;
  while (scanf("%d%d%d", &T, &M, &P) == 3 && (T || M || P)) {
    // 先处理到达时刻 T 的所有释放
    drain_release(T);

    // 尝试直接分配；失败则入等待队列
    if (!alloc_try(T, M, P)) {
      wait_q.emplace(M, P);
      wait_cnt++;
    }
  }

  // 处理后续所有释放（把系统跑干净）
  drain_release(2e9);

  printf("%d\n%d\n", last_end, wait_cnt);
}