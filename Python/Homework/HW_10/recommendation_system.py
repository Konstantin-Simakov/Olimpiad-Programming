# recommendation_system.py
# This program is a movie recommendation system based on kNN algorithm.

import math


def knn_algorithm(source_data, test_example):
    
    LEN_SOURCE_DATA = len(source_data)

    # Calculate the number of neighbors (must be only odd value).
    neighbors = int(math.sqrt(LEN_SOURCE_DATA))
    neighbors = neighbors if neighbors & 1 else neighbors + 1

    distances = []
    for learnt_example in source_data:
        distance = calc_distances(learnt_example, test_example)
        distances.append(distance)

    source_data = list(source_data[:])
    sorted_source_data = sort_data(distances, source_data)
    sample = sorted_source_data[:neighbors]

    return sample


def calc_distances(learnt_example, test_example):
    """ 
    Calculate distance between learnt example and test example 
    using cosine distance. 
    """
    scalar_product, norm_learnt, norm_test = 0, 0, 0

    # Begin from 1 because 0 index is the element value.
    for i in range(1, len(learnt_example)):
        scalar_product += learnt_example[i] * test_example[i]
        norm_learnt += learnt_example[i] ** 2
        norm_test += test_example[i] ** 2

    norm_learnt = math.sqrt(norm_learnt)
    norm_test = math.sqrt(norm_test)

    return 1.0 - scalar_product / (norm_learnt * norm_test)


def sort_data(distances, source_data):
    """ Sort distances and source data by the common for distances condition. """
    # Sort with modified improved bubble sorting algorithm by ascending order (from min to max).
    LEN_DISTANCES = len(distances)
    did_swap = True
    while did_swap:
        did_swap = False
        for i in range(LEN_DISTANCES-1):
            if distances[i] > distances[i+1]:
                distances[i], distances[i+1] = distances[i+1], distances[i]
                source_data[i], source_data[i+1] = source_data[i+1], source_data[i]
                did_swap = True

    print(distances)
    print(source_data)

    return source_data


def print_sample(sample):
    for element in sample:
        print(element)
    print()


def main():
    """ Main code."""
    # Contains a user with their rate for each genre.
    SOURCE_DATA = (
        # User name, comedy, action, drama, horror, melodrama. 
        ("Alice",  1, 2, 3, 4, 5),
        ("Bob",    2, 3, 4, 2, 5),
        ("Claire", 3, 3, 4, 2, 4),
        ("Daniel", 4, 3, 3, 2, 2),
        ("Ethan",  5, 3, 2, 3, 4),
    )

    MOVIES = {
        "Alice":  ["Saw", "LaLaLand", "1 + 1"],
        "Bob":    ["Fight club", "Forrest Gump", "Tom & Jerry"],
        "Claire": ["The Truman Show", "Leon", "In time"],
        "Daniel": ["Terminal", "Jacob's ladder", "Taxi"],
        "Ethan":  ["The diamond hand", "Terminal", "It"]
    }

    test_example = ("Ivan", 3, 2, 5, 1, 3)
    nearest_neighbors = knn_algorithm(SOURCE_DATA, test_example)
    
    print("\nNearest neighbors:")
    for elem in nearest_neighbors:
        print(elem[0])

    # Create a set to store matching movies.
    matching_movies = set()

    # Add movies from nearest neighbors to the set.
    for neighbor in nearest_neighbors:
        user_name = neighbor[0]
        matching_movies.update(MOVIES[user_name])

    # Print the matching movies.
    print("\nMatching movies from nearest neighbors:")
    for movie in matching_movies:
        print(movie)


# Global scope.
if "__main__" == __name__:
    main()
    input("\nPress the <Enter> key to exit.")
