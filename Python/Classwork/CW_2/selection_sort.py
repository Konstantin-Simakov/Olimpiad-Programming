# selection_sort.py
# Simple sorting algorithm.

import time


def find_smallest(arr):
	smallest = arr[0]		# Save smallest value.
	smallest_index = 0		# Save index of smallest value.

	for i in range(1, len(arr)):
		if arr[i] < smallest:
			smallest = arr[i]
			smallest_index = i

	return smallest_index


def selection_sort(arr):
	""" Sort an array. """	
	new_arr = []

	for i in range(len(arr)):
		smallest_i = find_smallest(arr)		# Find the smallest element.
		new_arr.append(arr.pop(smallest_i))

	return new_arr


# Own code.
start = time.time()				# Begin measure.

print(selection_sort([5, 3, 6, 2, 10]))

end = time.time() - start		# End measure.
print(end * 1000)				# Output of results.
# print(arr)
