# knn_regression.py
# 
# Simple implementation of k nearest neighbors (kNN) algorithm for regression.
# 
# Source data: days separated by signs and loaves of bread to bake in the corresponding day.
# Properties (3): weather level from 1 (awful) to 5 (excellent), integer; 
# is celebrating today or not: True (yes) or False (no),
# is competition today or not: True (yes) or False (no).
# Target value is a number of bread loaves to bake in the corresponding day.
# 
# This solution consists of simpler and more convenient code than some others, 
# since it doesn't contain a large number of external libraries.
# Also, it uses only function way without more difficult OOP.
# 

import math


def knn_regressor(source_data, test_example):
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

    # Choose 'neighbour' neighbors and calculate average of them.
    sample = source_data[:neighbors]
    element_value = calc_average(sample)

    return element_value


# def calc_distance(learnt_example, test_example):
#     """ Calculate distance between learnt example and test example. """
#     # Using Euclidean distance.
#     res = 0
#     # Begin from 1 because by 0 index is the element name.
#     for i in range(1, len(learnt_example)):
#         res += (learnt_example[i] - test_example[i]) ** 2
#     res = math.sqrt(res)

#     return res


def calc_distance(learnt_example, test_example):
    """ Calculate distance between learnt example and test example. """
    # Using proximity cosines.
    scalar_product, norm_learnt, norm_test = 0, 0, 0 

    # Begin from 1 because by 0 index is the element name.
    for i in range(1, len(learnt_example)):
        scalar_product += learnt_example[i] * test_example[i]
        norm_learnt += learnt_example[i] ** 2
        norm_test += test_example[i] ** 2

    scalar_product = math.sqrt(scalar_product)
    norm_learnt = math.sqrt(norm_learnt)
    norm_test = math.sqrt(norm_test)

    return scalar_product / (norm_learnt * norm_test)


def sort_data(distances, source_data):
    """ Sort distances and source data by the common for distances condition. """
    # Sort with modified and improved bubble sorting algorithm by ascending order (from min to max).
    LEN_DISTANCES = len(distances)
    did_swap = True
    while did_swap:
        did_swap = False
        for j in range(LEN_DISTANCES-1):
            if distances[j] > distances[j+1]:
                # Swap.
                distances[j], distances[j+1] = distances[j+1], distances[j]
                source_data[j], source_data[j+1] = source_data[j+1], source_data[j]
                did_swap = True
    
    # Check the calculations.
    print(distances)
    print(source_data)

    return distances, source_data


def calc_average(sample):
    """ Calculate an average value for the sample. """
    print_sample(sample)

    sum = 0
    for element in sample:
        sum += element[0]

    return sum / len(sample)


def print_sample(sample):
    for element in sample:
        print(element)
    print()


def main():
    """ Main code. """
    # Common view of one 'SOURCE_DATA' element:
    # (loaves_of_bread, weather, is_celebrating, is_competitions).
    # 1. 'loaves_of_bread' is the amount of bread to bake.
    # 2. 'weather' is measured from 1 to 5 by integers;
    # 3. 'is_celebrating' is measured by True or False;
    # 4. 'is_competition' is measured by True or False;
    SOURCE_DATA = (
        (300, 5, True, False),
        (225, 3, True, True),
        (75, 1, True, False),
        (200, 4, False, True),
        (150, 4, False, False),
        (50, 2, False, False), 
    )

    # Test kNN regressor.
    test_example = (None, 4, True, False)
    element_value = knn_regressor(SOURCE_DATA, test_example)
    element_value = math.ceil(element_value)
    test_example = (element_value,) + test_example[1:]
    
    # Display results.
    loaves_of_bread = test_example[0]
    print("The amount of bread loaves to bake equals ", loaves_of_bread, ".", sep="")


# Global scope.
if "__main__" == __name__:
    main()
input("\n\nPress the key <Enter> to exit.")
