# sum_2.py
# Sum the list of numbers with recursion.

import time


def my_sum(arr):
	if [] == arr:
		return 0
	else:
		return arr[0] + my_sum(arr[1:])


def my_sum2(arr):
	total = 0
	for x in arr:
		total += x

	return total


# Own code.
start = time.time()
print(my_sum([2, 4, 6, 8, 10]))
end = time.time() - start
print(end * 1000)

start = time.time()
print(my_sum2([2, 4, 6, 8, 10]))
end = time.time() - start
print(end * 1000)

start = time.time()
print(sum([2, 4, 6, 8, 10]))
end = time.time() - start
print(end * 1000)
