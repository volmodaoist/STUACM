from typing_extensions import Optional, Sequence


class FenwickTree:
    """
    Fenwick Tree / BIT (1-indexed)
    支持：单点加、前缀和、区间和、kth（频次树/非负权重时）
    """

    __slots__ = ["n", "tree"]

    def __init__(self, n: int = 0, nums: Optional[Sequence[int]] = None):
        self.n = n
        self.tree = [0] * (n + 1)
        if nums is not None:
            self.build(nums)

    @staticmethod
    def lowbit(x: int) -> int:
        return x & -x

    def build(self, nums: Sequence[int]) -> None:
        """O(n) build：nums 是 0-based，内部转成 1-based tree"""
        for i, x in enumerate(nums, start=1):
            self.tree[i] += x
            nxt = i + self.lowbit(i)
            if nxt <= self.n:
                self.tree[nxt] += self.tree[i]

    def add(self, i: int, delta: int) -> None:
        """在位置 i (1..n) 加 delta"""
        while i <= self.n:
            self.tree[i] += delta
            i += self.lowbit(i)

    def sum_prefix(self, i: int) -> int:
        """前缀和 sum[1..i]"""
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= self.lowbit(i)
        return s

    def sum_range(self, l: int, r: int) -> int:
        """区间和 sum[l..r]"""
        if l > r:
            return 0
        return self.sum_prefix(r) - self.sum_prefix(l - 1)

    def total(self) -> int:
        return self.sum_prefix(self.n)

    def kth(self, k: int) -> int:
        # 目前先不实现的我
        pass