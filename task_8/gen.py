#!/usr/bin/python3
import sys
import random

n = int(sys.argv[1])

for i in range(n):
    for j in range(n):
        print(random.random() * 2 - 1, end=" ")
    print()
