# biggest_1.py
# Search for the biggest item in the list with a loop.

import time


def biggest(arr):
	if [] == arr:		# Error case
		return None

	max = arr[0]
	for i in range(1, len(arr)):
		if arr[i] > max:
			max = arr[i]

	return max


start = time.time()
print(biggest([2, 4, 6, 8]))
end = time.time() - start
print(end * 1000)
