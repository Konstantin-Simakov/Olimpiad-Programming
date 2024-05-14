# sum_1.py
# Sum the list of numbers with a loop.

def my_sum(arr):
	total = 0
	for x in arr:
		total += x

	return total


# Own code.
print(my_sum([2, 4, 6, 8]))
