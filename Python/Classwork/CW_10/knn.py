# knn.py
# 
# Simple implementation of k nearest neighbors (kNN) algorithm.
# Source data: oranges and grapefruits.
# Properties (2): size, color (on a conventional scale from 1 to 10).
# This solution consists of simpler and more convenient code, 
# since it doesn't contain a large number of external libraries.
# Also, it doesn't use OOP; only functions for more convinience.
# 

import math


def knn_classifier(source_data, test_example):
    """
    Determines whether a test sample belongs to 
    a particular class of trained samples.
    """
    LEN_SOURCE_DATA = len(source_data)

    # Calculate the number of neighbors more exactly (must be only odd value).
    neighbors = int(math.sqrt(LEN_SOURCE_DATA))
    neighbors = neighbors if neighbors & 1 else neighbors + 1

    # Calculate distances from the test example to every learnt example.
    distances = []
    for learnt_example in source_data:
        distance = calc_distance(learnt_example, test_example)
        distances.append(distance)

    # Calculate neighbors.
    source_data = list(source_data[:])
    distances, source_data = sort_data(distances, source_data)

    # Choose 'neighbour' neighbors and calculate mode of them.
    sample = source_data[:neighbors]
    element_name = calc_mode(sample)

    return element_name


def calc_distance(learnt_example, test_example):
    """ Calculate distance between learnt example and test example. """
    # Using Euclidean distance.
    res = 0
    # Begin from 1 because by 0 index is the element name name.
    for i in range(1, len(learnt_example)):
        res += (learnt_example[i] - test_example[i]) ** 2
        # print(res)
    res = math.sqrt(res)


    return res


def sort_data(distances, source_data):
    """ Sort distances and source data by the common for distances condition. """
    # Sort with modified bubble sorting algorithm by ascending order (from min to max).
    LEN_DISTANCES = len(distances)
    for i in range(LEN_DISTANCES-1):
        for j in range(LEN_DISTANCES-1):
            if distances[i] < distances[j]:
                # Swap.
                distances[i], distances[j] = distances[j], distances[i]
                source_data[i], source_data[j] = source_data[j], source_data[i]

    print(distances)
    print(source_data)

    return distances, source_data


def calc_mode(sample):
    """ 
    Calculate mode (as element name) of neighbors in the sample considering that 
    the sample has already sorted by ascending (from min to max) order.
    """
    print_sample(sample)

    max_frequency = 0
    count = 1
    element_name = sample[0][0]
    for i in range(1, len(sample)):
        if sample[i-1][0] == sample[i][0]:      # Compare element names.
            count += 1
        else:
            if max_frequency < count:           # Suppose that there is only one mode.
                max_frequency = count
                element_name = sample[i-1][0]   # Update a frequently occurring element name.
            count = 1

    return element_name


def print_sample(sample):
    for element in sample:
        print(element)
    print()


def main():
    """ Main code. """
    # From 1 to 5 by size and color -- orange,
    # from 6 to 10 by size and color -- grapefruit.
    SOURCE_DATA = (
        # Fruit name, size, color.
        ("O", 1, 1),                    # Oranges.
        ("O", 2, 2),
        ("O", 3, 3),
        ("O", 4, 4),
        ("O", 5, 5),
        ("G", 6, 6),                    # Grapefruits.
        ("G", 7, 7),
        ("G", 8, 8),
        ("G", 9, 9),
        ("G", 10, 10),
    )

    # Test kNN classifier.
    test_example = (None, 6, 7)
    element_name = knn_classifier(SOURCE_DATA, test_example)
    test_example = (element_name,) + test_example[1:]
    
    # Display results.
    fruit_name = "orange" if "O" == element_name else "grapefruit"
    print("The test example is ", fruit_name, ".", sep="")


# Global scope.
if __name__ == '__main__':
    main()
input("\n\nPress the key <Enter> to exit.")
