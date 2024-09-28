# quick_sort.py
# Realization of quick sort.

import time


def quick_sort(arr):
	if len(arr) < 2:		# Base case: arrays with 0 and 1 element
		return arr			# have already "sorted".
	else:
		pivot = arr[0]		# Recursive case: pivot element is the first.

		# Subarray of all remaining elements which less or equal to pivot.
		less = [x for x in arr[1:] if x <= pivot]
		# Subarray of all remaining elements which greater than pivot.
		greater = [x for x in arr[1:] if x > pivot]

		return quick_sort(less) + [pivot] + quick_sort(greater)


start = time.time()
print(quick_sort([4, 5, 2, 3]))
end = time.time() - start
print(end * 1000)
