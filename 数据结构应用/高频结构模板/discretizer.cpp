#include <bits/stdc++.h>
using namespace std;

template <class T> struct Discretizer {
    vector<T> xs; // 排序去重后的值域（0-based）

    Discretizer() = default;
    Discretizer(const vector<T> &nums) { build(nums); }

    // 建表：排序 + 去重
    void build(const vector<T> &nums) {
        xs = nums;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }

    // 数值 x 排名（1-based），常用于 Fenwick / SegmentTree 下标
    int rank(const T &x) const {
        return int(lower_bound(xs.begin(), xs.end(), x) - xs.begin()) + 1;
    }

    // 数值 x 的排名（0-based）
    int rank0(const T &x) const {
        return int(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
    }

    // 反查：1-based rank -> 原值
    // 反查：0-based rank -> 原值
    const T &value(int r) const { return xs[r - 1]; }
    const T &value0(int r) const { return xs[r]; }

    int size() const { return (int)xs.size(); }

    // 把数组 nums 映射变为 1-based ranks（常用）
    vector<int> compress(const vector<T> &nums) const {
        vector<int> r;
        r.reserve(nums.size());
        for (auto &v : nums)
            r.push_back(rank(v));
        return r;
    }
};
