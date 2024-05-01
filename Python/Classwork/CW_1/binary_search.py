# binary_search.py
# Binary search algorithm.

import time


def binary_search(seq, item):
	""" The algorithm. """
	low = 0
	high = len(seq) - 1

	while low <= high:
		mid = low + high // 2
		guess = seq[mid]

		if guess == item:
			return mid
		elif guess > item:
			high = mid - 1
		else:
			low = mid + 1

	return None


# Own code.
start = time.time()

# Let's test the function!
# my_list = [1, 3, 5, 7, 9]			# The list must be sorted.

search_element = binary_search([1, 3, 5, 7, 9], 1)	# => 0

end = time.time() - start

print(search_element)
print(end * 1000)
# print(binary_search(my_list, 2))	# => None
