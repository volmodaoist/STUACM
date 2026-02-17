from bisect import bisect_left
from typing_extensions import Generic, Optional, List, Sequence, TypeVar

T = TypeVar("T")


class Discretizer(Generic[T]):
    """
    离散化（坐标压缩）
    - xs: 排序去重后的值域（0-based 存）
    - rank(x): 1-based 排名（适配 Fenwick）
    - value(r): 1-based 反查
    """

    def __init__(self, nums: Sequence[T]):
        self.xs = sorted(set(nums))

    def rank(self, x: T) -> int:
        """1-based rank"""
        return bisect_left(self.xs, x) + 1

    def rank0(self, x: T) -> int:
        """0-based rank"""
        return bisect_left(self.xs, x)

    def value(self, r: int) -> T:
        """1-based rank -> value"""
        return self.xs[r - 1]

    def value0(self, r: int) -> T:
        """0-based rank -> value"""
        return self.xs[r]

    def size(self) -> int:
        return len(self.xs)

    def compress(self, nums: Sequence[T]) -> List[int]:
        """对于传入的 nums 映射为 1-based ranks"""
        return [self.rank(v) for v in nums]
