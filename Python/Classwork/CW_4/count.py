# count.py
# Count a list length with recursion.

import time


def count(arr):
	if not arr:
		return 0
	else:
		return 1 + count(arr[1:])


# Own code.
start = time.time()
print(count([2, 4, 6, 8, 10]))
end = time.time() - start
print(end * 1000)

start = time.time()
print(len([2, 4, 6, 8, 10]))
end = time.time() - start
print(end * 1000)
