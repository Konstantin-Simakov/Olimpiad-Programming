# biggest_2.py
# Search for the biggest item in the list with a recursion.

import time


def biggest(arr):
	if [] == arr:					# Error case
		return None
	elif len(arr) == 1:				# Base case
		return arr[0]

	submax = biggest(arr[1:])		# Recursive case
	return arr[0] if arr[0] > submax else submax


start = time.time()
print(biggest([2, 4, 6, 8]))
end = time.time() - start
print(end * 1000)
