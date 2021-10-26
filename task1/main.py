from quick_sort import quick_sort as qsort
from radix_sort import radix_sort as rsort
from merge_sort import merge_sort as msort
from timer import timer

import random
import time

def rnd_arr(len, min=-100, max=100, step = 1):
    arr = []
    for i in range(len):
        arr.append(random.randrange(min, max, step))
    return arr

def main():
    tmr = timer()

    size = 100

    for key in ["mid", "left", "right", "median"]:
        print("quick sort "+key+" key")
        arr1 = rnd_arr(size)
        tmr.set(arr1)
        print(arr1)
        t_start = time.monotonic_ns()
        s_arr1 = qsort(arr1, key, tmr)
        t_stop = time.monotonic_ns()
        print(s_arr1)
        tmr.get()
        print(str(t_stop - t_start) + " ns")

    print("radix sort")
    arr2 = rnd_arr(size, min=0, max = 128)
    tmr.set(arr2)
    print(arr2)
    t_start = time.monotonic_ns()
    rsort(arr2, 0, len(arr2)-1, 7, tmr)
    t_stop = time.monotonic_ns()
    print(arr2)
    tmr.get()
    print(str(t_stop - t_start) + " ns")

    print("merge sort")
    arr3 = rnd_arr(size)
    tmr.set(arr3)
    print(arr3)
    t_start = time.monotonic_ns()
    msort(arr3, 0, len(arr3), tmr)
    t_stop = time.monotonic_ns()
    print(arr3)
    tmr.get()
    print(str(t_stop - t_start) + " ns")


main()