/*
 * @lc app=leetcode id=3408 lang=cpp
 *
 * [3408] Design Task Manager
 */

// @lc code=start
class TaskManager {
public:
  struct Task {
    int priority;
    int taskId;
    int userId;
  };

  static constexpr auto cmp = [](const auto &t1, const auto &t2) {
    if (t1.priority != t2.priority)
      return t1.priority > t2.priority;
    return t1.taskId > t2.taskId;
  };
  set<Task, decltype(cmp)> tasks;

  using PII = pair<int, int>;
  unordered_map<int, PII> info;

  TaskManager(vector<vector<int>> &tasks) {
    for (auto &t : tasks)
      add(t[0], t[1], t[2]);
  }

  void add(int userId, int taskId, int priority) {
    tasks.emplace(priority, taskId, userId);
    info[taskId] = {userId, priority};
  }

  void edit(int taskId, int newPriority) {
    auto [userId, oldPriority] = info[taskId];
    auto node = tasks.extract({oldPriority, taskId, userId});
    node.value().priority = newPriority;
    tasks.insert(move(node));
    info[taskId] = {userId, newPriority};
  }

  void rmv(int taskId) {
    auto [userId, priority] = info[taskId];
    tasks.extract({priority, taskId, userId});
    info.erase(taskId);
  }

  int execTop() {
    if (tasks.empty())
      return -1;
    auto node = tasks.extract(tasks.begin());
    auto [priority, taskId, userId] = node.value();
    info.erase(taskId);
    return userId;
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
// @lc code=end
