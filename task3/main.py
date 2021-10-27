from linear_search import linear_search
from quick_linear_search import quick_linear_search
from binary_search import binary_search
from block_search import block_search

from timer import timer
import random

def rnd_arr(len, min=-100, max=100, step=1):
    arr = []
    for i in range(len):
        arr.append(random.randrange(min, max, step))
    return arr

def srt_arr(min=1, max=100, step=1):
    arr = []
    for i in range(min, max+1, step):
        arr.append(i)
    return arr

def main():
    tmr = timer()

    arr_len = 500

    no_sort_arr = rnd_arr(len=arr_len, min=1, max=9)
    print("random arr")
    print(no_sort_arr)
    
    print("linear search")
    tmr.set(no_sort_arr)
    indxs = linear_search(no_sort_arr, 6, tmr)
    print(indxs)
    tmr.get()

    print("quick linear search(random array)")
    tmr.set(no_sort_arr)
    indxs = quick_linear_search(no_sort_arr, 6, tmr)
    print(indxs)
    tmr.get()
    
    sort_arr = srt_arr(max=arr_len)
    print("sort arr")
    print(sort_arr)

    print("quick linear search(sorted array)")
    tmr.set(sort_arr)
    indxs = quick_linear_search(sort_arr, 6, tmr)
    print(indxs)
    tmr.get()

    print("binary search")
    tmr.set(sort_arr)
    indxs = binary_search(sort_arr, 6, tmr)
    print(indxs)
    tmr.get()

    print("block search")
    tmr.set(sort_arr)
    indxs = block_search(sort_arr, 6, tmr)
    print(indxs)
    tmr.get()

main()