# biggest_3.py
# Search for the biggest item in the list with a recursion.

import time


def biggest(arr):
	len_arr = len(arr)
	if len_arr < 2:					# Error case
		return None
	elif 2 == len_arr:				# Base case
		return arr[0] if arr[0] > arr[1] else arr[1]
	
	submax = biggest(arr[1:])		# Recursive case
	return arr[0] if arr[0] > submax else submax


start = time.time()
print(biggest([2, 4, 6, 8]))
end = time.time() - start
print(end * 1000)
