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


def selection_sort_2(arr):
	""" 2nd version of sorting without additional array. """
	for i in range(len(arr)):
		lowest_val_index = i
		for j in range(i+1, len(arr)):
			if arr[j] < arr[lowest_val_index]:
				lowest_val_index = j

		# It's allowed, e.g. 'a, a = 6, 6' and '6 == a' after it without problems.
		arr[i], arr[lowest_val_index] = arr[lowest_val_index], arr[i]

	return arr


# Own code.
start = time.time()					# Begin measure.
print(selection_sort_2([10, 5, 2, 3]))
end = time.time() - start			# End measure.
print(end * 1000)					# Output of results in ms.
