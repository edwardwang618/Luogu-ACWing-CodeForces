/*
 * @lc app=leetcode id=2590 lang=cpp
 *
 * [2590] Design a Todo List
 */

// @lc code=start
class TodoList {
  struct Task {
    string des;
    int due;
    vector<string> tags;
    bool operator<(const Task &other) const { return due < other.due; }
  };

  unordered_map<int, unordered_map<int, Task>>
      userTasks; // user -> (taskId -> task)

public:
  TodoList() {}
  int nextTaskId = 1;

  int addTask(int userId, const string &taskDescription, int dueDate,
              const vector<string> &tags) {
    userTasks[userId][nextTaskId] = {taskDescription, dueDate, tags};
    return nextTaskId++;
  }

  vector<string> getAllTasks(int userId) {
    vector<pair<Task, int>> tasks;
    for (auto &[id, task] : userTasks[userId])
      tasks.push_back({task, id});

    sort(tasks.begin(), tasks.end(),
         [](auto &a, auto &b) { return a.first < b.first; });

    vector<string> res;
    for (auto &[task, id] : tasks)
      res.push_back(task.des);
    return res;
  }

  vector<string> getTasksForTag(int userId, const string &tag) {
    vector<Task> tasks;
    for (auto &[id, task] : userTasks[userId]) {
      for (auto &t : task.tags) {
        if (t == tag) {
          tasks.push_back(task);
          break;
        }
      }
    }
    sort(tasks.begin(), tasks.end());

    vector<string> res;
    for (auto &task : tasks)
      res.push_back(task.des);
    return res;
  }

  void completeTask(int userId, int taskId) { userTasks[userId].erase(taskId); }
};

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList* obj = new TodoList();
 * int param_1 = obj->addTask(userId,taskDescription,dueDate,tags);
 * vector<string> param_2 = obj->getAllTasks(userId);
 * vector<string> param_3 = obj->getTasksForTag(userId,tag);
 * obj->completeTask(userId,taskId);
 */
// @lc code=end
