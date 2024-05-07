# countdown.py
# Recursive countdown.

def countdown(num):
	print(num)
	if num <= 1:			# Basic case.
		return
	else:
		countdown(num - 1)	# Recursive case.


# Main code.
countdown(10)
