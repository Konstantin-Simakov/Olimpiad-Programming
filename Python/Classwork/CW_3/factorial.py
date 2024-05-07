# factorial.py
# Recursive version of the factorial function.


def factorial(num):
	if 1 == num:
		return 1
	else:
		return num * factorial(num - 1)


# Own code.
print(factorial(-1))
