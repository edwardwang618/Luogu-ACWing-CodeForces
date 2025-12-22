/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
// class MyHashMap {
//   using ll = long long;
//   using ull = unsigned long long;
//   using sll = signed long long;
//   enum State : uint8_t { EMPTY = 0, FILLED = 1, ERASED = 2 };

//   struct Slot {
//     int key = 0;
//     int val = 0;
//     State st = EMPTY;
//   };

//   ull m;          // table size (prime)
//   ull filled = 0; // number of FILLED slots
//   vector<Slot> t;

//   ull hash(int key) const {
//     // simplest: modulo a prime-sized table
//     // handle negative keys if they ever appear
//     ll k = key;
//     ll r = k % (ll)m;
//     if (r < 0) r += (ll)m;
//     return (ull)r;
//   }

//   void rehash(ull new_m) {
//     vector<Slot> old = move(t);
//     t.assign(new_m, {});
//     m = new_m;
//     filled = 0;
//     for (auto &s : old)
//       if (s.st == FILLED)
//         put(s.key, s.val);
//   }

//   static bool isPrime(ull x) {
//     if (x < 2) return false;
//     if (x % 2 == 0) return x == 2;
//     for (ull d = 3; d <= x / d; d += 2)
//       if (x % d == 0) return false;
//     return true;
//   }
//   static ull nextPrime(ull x) {
//     if (x <= 2) return 2;
//     if (!(x & 1)) x++;
//     while (!isPrime(x)) x += 2;
//     return x;
//   }

//   void ensure_capacity() {
//     // keep load factor < ~0.7
//     if ((filled + 1) * 10 >= m * 7) {
//       ull new_m = nextPrime(max(8ull, m * 2));
//       rehash(new_m);
//     }
//   }

// public:
//   MyHashMap(ull initial = 1009) { // start with a small prime
//     m = nextPrime(initial);
//     t.assign(m, {});
//   }

//   void put(int key, int value) {
//     ensure_capacity();
//     ull i0 = hash(key);
//     sll firstErased = -1;
//     for (ull n = 0; n < m; n++) {
//       ull p = (i0 + n) % m;
//       Slot &s = t[p];
//       if (s.st == EMPTY) {
//         ull use = ~firstErased ? (ull)firstErased : p;
//         Slot &u = t[use];
//         filled++;
//         u.key = key;
//         u.val = value;
//         u.st = FILLED;
//         return;
//       } else if (s.st == ERASED) {
//         if (!~firstErased) firstErased = (sll)p;
//       } else { // FILLED
//         if (s.key == key) {
//           s.val = value;
//           return;
//         }
//       }
//     }
//   }

//   int get(int key) const {
//     ull i0 = hash(key);
//     for (ull n = 0; n < m; n++) {
//       ull p = (i0 + n) % m;
//       const Slot &s = t[p];
//       if (s.st == EMPTY) return -1;
//       if (s.st == FILLED && s.key == key) return s.val;
//     }
//     return -1;
//   }

//   void remove(int key) {
//     ull i0 = hash(key);
//     for (ull n = 0; n < m; n++) {
//       ull p = (i0 + n) % m;
//       Slot &s = t[p];
//       if (s.st == EMPTY) return;
//       if (s.st == FILLED && s.key == key) {
//         s.st = ERASED;
//         filled--;
//         return;
//       }
//     }
//   }
// };

class MyHashMap {
  using ll  = long long;
  using ull = unsigned long long;

  struct KV {
    int key;
    int val;
  };
  using Slot = vector<KV>;

  ull m;          // table size (prime)
  ull filled = 0; // number of elements
  vector<Slot> t;

  static bool isPrime(ull x) {
    if (x < 2) return false;
    if ((x & 1ULL) == 0ULL) return x == 2;
    for (ull d = 3; d <= x / d; d += 2)
      if (x % d == 0) return false;
    return true;
  }
  static ull nextPrime(ull x) {
    if (x <= 2) return 2;
    if ((x & 1) == 0) x++;
    while (!isPrime(x)) x += 2;
    return x;
  }

  // Modulo a prime, branchless adjust for negatives.
  // If keys are known non-negative, you can simplify to: return (ull)((unsigned)key % m);
  ull hash(int key) {
    ll r = (ll)key % (ll)m;
    if (r < 0) r += (ll)m;
    return (ull)r;
  }

  void ensure_capacity() {
    // keep load factor < 0.7
    if ((filled + 1) * 10 >= m * 7) {
      rehash(nextPrime(max(8ull, m * 2)));
    }
  }

  void rehash(ull new_m) {
    vector<Slot> old = move(t);
    t.assign(new_m, {});
    m = new_m;

    for (auto& slot : old) {
      for (auto& kv : slot) {
        ull i0 = hash(kv.key); // uses updated m
        auto& dst = t[i0];
        if (dst.empty()) dst.reserve(2);
        dst.push_back(kv);
      }
    }
  }

public:
  MyHashMap(ull initial = 1009) {
    m = nextPrime(initial);
    t.assign(m, {});
  }

  void put(int key, int value) {
    ensure_capacity();
    const ull i0 = hash(key);
    auto& slot = t[i0];

    for (auto& kv : slot)
      if (kv.key == key) { kv.val = value; return; }

    if (slot.empty()) slot.reserve(2);
    slot.push_back({key, value});
    filled++;
  }

  int get(int key) {
    ull i0 = hash(key);
    auto& slot = t[i0];
    for (auto& kv : slot)
      if (kv.key == key) return kv.val;
    return -1;
  }

  void remove(int key) {
    ull i0 = hash(key);
    auto& slot = t[i0];
    for (size_t i = 0, n = slot.size(); i < n; i++) {
      if (slot[i].key == key) {
        slot[i] = slot.back();
        slot.pop_back();
        filled++;
        return;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
