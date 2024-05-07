# stack_of_calls.py
# Demonstrates stack data structure for function calls.


def greet(name):
	print("Hello, " + name + "!")
	greet2(name)

	print("Getting ready to say bye...")
	bye()


def greet2(name):
	print("How are you, " + name + "?")


def bye():
	print("OK, bye!")


# Own code.
greet("Ivan")
