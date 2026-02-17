#include <bits/stdc++.h>
#include <limits.h>

// Fenwick Tree / BIT (1-indexed)
// 支持：point add,  prefix sum, range sum
template <class T> struct FenwickTree {
    int n;
    std::vector<T> tree;

    static int lowbit(int x) { return x & -x; }

    // 空树构造
    FenwickTree(int n = 0) : n(n), tree(n + 1, T{}) {}

    // 用数组直接构造（O(n) build），nums 是 0-based
    FenwickTree(const std::vector<T> &nums) {
        n = (int)nums.size();
        tree.assign(n + 1, T{});

        for (int i = 1; i <= n; i++) {
            tree[i] += nums[i - 1];
            int nxt = i + lowbit(i);
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // 单点加：在位置 i (1..n) 加 delta
    void add(int i, T delta) {
        while (i <= n) {
            tree[i] += delta;
            i += lowbit(i);
        }
    }

    // 前缀和：sum[1..i]
    T sumPrefix(int i) const {
        T s{};
        while (i > 0) {
            s += tree[i];
            i -= lowbit(i);
        }
        return s;
    }

    // 区间和：sum[l..r]
    T sumRange(int l, int r) const {
        if (l > r)
            return T{};
        return sumPrefix(r) - sumPrefix(l - 1);
    }

    T total() const { return sumPrefix(n); }
};