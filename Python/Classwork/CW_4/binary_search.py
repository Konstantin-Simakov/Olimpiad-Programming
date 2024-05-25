# binary_search.py
# Recursive version of binary search algorithm.


# Own exception.
class Catapult(Exception):
    pass


# List must be sorted.
def binary_search(arr, val):
    mid = len(arr) // 2
    guess = arr[mid]       

    if len(arr) == 1:           # Base case.
        if guess == val:
            return 0
        else:
            raise Catapult
    else:                       # Recursive case.
        if guess > val:
            return binary_search(arr[:len(arr)//2], val)  # 1st recursive case.
        else:
            return (len(arr) // 2) + binary_search(arr[len(arr)//2:], val)  # 2nd recursive case.


# Main code.
try:
    print(binary_search([1, 2, 3, 6, 7, 9, 10, 46, 54], 55))
except Catapult:
    print(None)
