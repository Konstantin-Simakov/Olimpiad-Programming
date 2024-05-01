# fact.py
# Calculate factorial.

def factorial_1(num):
	res = 1
	while num > 1:
		res *= num
		num -= 1

	return res

def factorial_2(num):
	for i in range(2, num):
		num *= i

	return num


print(factorial_1(5))
print(factorial_2(5))
