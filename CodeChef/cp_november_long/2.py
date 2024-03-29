import sys

sys.stdout = open("out.txt", "w")
sys.stdin = open("in.txt", "r")

# import os
# import math
# import numpy as np
# from collections import OrderedDict
# from memo import memo #@memo
# from collections import deque #list = deque()
# import random
# from queue import *

# from functools import lru_cache #@lru_cache
# from functools import lru_cache
# sys.setrecursionlimit(15000)
# @lru_cache(128)


def solver(n, arr):
    map_arr = [1] * n
    map_arr[n - 1] = 10 ** 4
    for i in range(n - 2, -1, -1):
        if arr[i] == i + 1:
            map_arr[i] = map_arr[i + 1] - 1
        else:
            map_arr[i] = map_arr[arr[i]-1]
    return map_arr


if __name__ == "__main__":
    for i in range(int(input())):
        n = int(sys.stdin.readline())
        arr = list(map(int, sys.stdin.readline().split()))
        print(solver(n, arr))


# def gcd(a, b):
# 	while b:
# 	a, b = b, a % b
# return a
# def lcm(a, b):
# 	w = a //gcd(ab)
# return w * b

# def insertionSortWithIndex(arr, m):
#    for i in range(1, len(arr)):
#        key = arr[i]
#        l = m[i]
#        j = i-1
#        while j >=0 and key < arr[j] :
#                arr[j+1] = arr[j]
#                m[j+1] = m[j]
#                j -= 1
#        m[j+1] = l
#        arr[j+1] = key
# insertionSortWithIndex(arr, indexstore)


# index = sorted(range(len(nums)), key = lambda x: nums[x])
