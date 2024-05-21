# euclidean_algorithm.py
# Field 1680 x 640 divide by max number of squares.
# Recursive algorithm finds out the side of a square.


def euclidean(length, width):    # length must be bigger than width
    if length % width == 0:
        return width            # Basic case
    else:
        return euclidean(width, length % width)  # Recursive case


print(euclidean(1680, 640))
