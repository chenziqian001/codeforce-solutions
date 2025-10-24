def calc(*nums):
    if not nums:
        return None, 0
    return max(nums), sum(nums)

mx, total = calc(3, 5, 7, 2, 9, 1)
print("最大值:", mx)
print("总和:", total)

def mysum(whatever,start=0):
    tt=start
    for i in whatever:
        tt+=i
    return tt

def my_sorted(iterable, reverse=False):
    arr = list(iterable)
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if (not reverse and arr[j] < arr[min_idx]) or (reverse and arr[j] > arr[min_idx]):
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def my_map(func, iterable):
    for item in iterable:
        yield func(item)  

