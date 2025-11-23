/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
class FoodRatings {
 public:
  struct Food {
    int rating;
    string name;
    bool operator<(const Food& o) const {
      return rating > o.rating || (rating == o.rating && name < o.name);
    }
  };

  unordered_map<string, set<Food>> mp;
  unordered_map<string, string> c;
  unordered_map<string, int> r;

  FoodRatings(vector<string>& fs, vector<string>& cs, vector<int>& rs) {
    int n = fs.size();
    for (int i = 0; i < n; i++) {
      mp[cs[i]].insert({rs[i], fs[i]});
      c[fs[i]] = cs[i];
      r[fs[i]] = rs[i];
    }
  }

  void changeRating(string food, int newRating) {
    auto& cui = c[food];
    mp[cui].erase({r[food], food});
    mp[cui].insert({newRating, food});
    r[food] = newRating;
  }

  string highestRated(string cuisine) { return mp[cuisine].begin()->name; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end
