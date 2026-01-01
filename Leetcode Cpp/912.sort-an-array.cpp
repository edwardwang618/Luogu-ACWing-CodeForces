/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
  // vector<int> sortArray(vector<int> &a) {
  //   int n = a.size();
  //   auto quick_sort = [&](this auto &&quick_sort, int l, int r) -> void {
  //     if (l >= r) return;
  //     int i = l, j = r, piv = a[l + r >> 1];
  //     while (i <= j) {
  //       while (a[i] < piv) i++;
  //       while (a[j] > piv) j--;
  //       if (i <= j) swap(a[i++], a[j--]);
  //     }
  //     quick_sort(l, j), quick_sort(i, r);
  //   };
  //   quick_sort(0, n - 1);
  //   return a;
  // }

  // vector<int> sortArray(vector<int> &a) {
  //   int n = a.size();
  //   vector<int> tmp(n);
  //   auto merge_sort = [&](this auto &&merge_sort, int l, int r) -> void {
  //     if (l >= r) return;
  //     int mid = l + r >> 1;
  //     merge_sort(l, mid), merge_sort(mid + 1, r);
  //     int i = l, j = mid + 1, k = l;
  //     while (i <= mid && j <= r) {
  //       if (a[i] <= a[j]) tmp[k++] = a[i++];
  //       else tmp[k++] = a[j++];
  //     }
  //     while (i <= mid) tmp[k++] = a[i++];
  //     while (j <= r) tmp[k++] = a[j++];
  //     for (k = l; k <= r; k++) a[k] = tmp[k];
  //   };
  //   merge_sort(0, n - 1);
  //   return a;
  // }

  // vector<int> sortArray(vector<int> &a) {
  //   int n = a.size();
  //   vector<int> tmp(n);
  //   auto merge_sort = [&](int l, int r) -> void {
  //     for (int s = 1; s < n; s <<= 1) 
  //       for (int l = 0; l + s < n; l += s * 2) {
  //         int mid = l + s - 1;
  //         int r = min(l + 2 * s - 1, n - 1);
  //         int i = l, j = mid + 1, k = l;
  //         while (i <= mid && j <= r) {
  //           if (a[i] <= a[j]) tmp[k++] = a[i++];
  //           else tmp[k++] = a[j++];
  //         }
  //         while (i <= mid) tmp[k++] = a[i++];
  //         while (j <= r) tmp[k++] = a[j++];
  //         for (k = l; k <= r; k++) a[k] = tmp[k];
  //       }
  //   };
  //   merge_sort(0, n - 1);
  //   return a;
  // }
  
  vector<int> sortArray(vector<int> &a) {
    int n = a.size();
    vector<int> tmp(n);
    auto merge_sort = [&](int l, int r) -> void {
      for (int s = 1; s < n; s <<= 1) {
        for (int l = 0; l < n; l += s * 2) {
          int mid = min(l + s - 1, n - 1);
          int r = min(l + 2 * s - 1, n - 1);
          int i = l, j = mid + 1, k = l;
          if (mid < r) {
            while (i <= mid && j <= r) {
              if (a[i] <= a[j]) tmp[k++] = a[i++];
              else tmp[k++] = a[j++];
            }
          }
          while (i <= mid) tmp[k++] = a[i++];
          while (j <= r) tmp[k++] = a[j++];
        }
        swap(a, tmp);
      }
    };
    merge_sort(0, n - 1);
    return a;
  }

  // vector<int> sortArray(vector<int> &a) {
  //   int n = a.size();
  //   auto insertion_sort = [&](int l, int r) {
  //     for (int i = l + 1; i <= r; i++) {
  //       int x = a[i], j = i - 1;
  //       while (j >= l && a[j] > x) {
  //         a[j + 1] = a[j];
  //         j--;
  //       }
  //       a[j + 1] = x;
  //     }
  //   };
  //   vector<int> tmp(n);
  //   auto merge_sort = [&](int l, int r) -> void {
  //     for (int s = 1; s < n; s <<= 1) 
  //       for (int l = 0; l + s < n; l += s * 2) {
  //         int mid = l + s - 1;
  //         int r = min(l + 2 * s - 1, n - 1);
  //         if (r - l + 1 <= 32) {
  //           insertion_sort(l, r);
  //           continue;
  //         }
  //         int i = l, j = mid + 1, k = l;
  //         while (i <= mid && j <= r) {
  //           if (a[i] <= a[j]) tmp[k++] = a[i++];
  //           else tmp[k++] = a[j++];
  //         }
  //         while (i <= mid) tmp[k++] = a[i++];
  //         while (j <= r) tmp[k++] = a[j++];
  //         for (k = l; k <= r; k++) a[k] = tmp[k];
  //       }
  //   };
  //   merge_sort(0, n - 1);
  //   return a;
  // }
  
  // vector<int> sortArray(vector<int> &a) {
  //   int n = a.size();
  //   auto heapify = [&](int i, int sz) {
  //     while (true) {
  //       int largest_i = i;
  //       int l = 2 * i + 1, r = 2 * i + 2;
  //       if (l < sz && a[l] > a[largest_i]) largest_i = l;
  //       if (r < sz && a[r] > a[largest_i]) largest_i = r;
  //       if (largest_i == i) break;
  //       swap(a[i], a[largest_i]);
  //       i = largest_i;
  //     }
  //   };
  //   for (int i = n / 2 - 1; i >= 0; i--) heapify(i, n);
  //   for (int i = n - 1; i > 0; i--) {
  //     swap(a[0], a[i]);
  //     heapify(0, i);
  //   }
  //   return a;
  // }
};
// @lc code=end
