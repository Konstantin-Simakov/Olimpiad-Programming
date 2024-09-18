# tourist_route.py
# The problem of tourist route optimization.

MAX_TIME = 2


def find_step_value(attractions):
    """Gets step using the attractions dictionary"""
    numbers = [attractions[item][0] for item in attractions.keys()]   # Initialize the list of numbers.

    # Find the maximum number of decimal places and сonvert numbers to integers.
    # Add 10 for correct calculation.
    decimal_digits = [10] + [int(str(number).split('.')[1]) for number in numbers]


    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a

    # Find GCD of integer numbers.
    result = decimal_digits[0]
    for i in range(1, len(decimal_digits)):
        result = gcd(result, decimal_digits[i])

    return result / 10 ** len(str(result))


def get_weights_costs(attractions):
    """Get the weight and cost lists of attractions."""
    weights = [0] + [attractions[item][0] for item in attractions.keys()]
    costs = [0] + [attractions[item][1] for item in attractions.keys()]
    return weights, costs


def get_memtable(attractions, max_time, step):
    """Get memoization table based on weight and cost lists."""
    weights, costs = get_weights_costs(attractions)
    attractions = len(costs)  # Number of table lines.
    # Create the memoization table with zero costs.
    memtable = [[0 for j in range(0, max_time + 1)] for i in range(attractions)]
    print_memtable(memtable, attractions, max_time + 1)

    for i in range(len(weights)):
        weights[i] = int(weights[i] // step)
    # Initialize it.
    for i in range(1, attractions):
        for j in range(1, max_time + 1):
            # If the item fits into the subtime, maximize the summarized cost.
            if weights[i] <= j:
                # print(j - weights[i])
                memtable[i][j] = max(costs[i] + memtable[i-1][j-weights[i]], memtable[i-1][j])
            # Else choose the previous attraction with max cost and the same weight.
            else:
                memtable[i][j] = memtable[i-1][j]

    return memtable, weights, costs


def get_selected_attractions(attractions, max_weight, step):
    """Make a list of your most valuable attractions with a time limit."""
    memtable, weights, costs = get_memtable(attractions, max_weight, step)

    items = len(costs)  # Number of table lines.
    print_memtable(memtable, items, max_weight + 1)

    j = max_weight  # Start from the maximum weight.
    rest_cost = memtable[items - 1][max_weight]  # Start with the last element of the table, its max cost.
    selected_attractions = []  # The list of selected attractions as pairs: weight and cost.

    # Logic to find which attractions were selected
    for i in range(items - 1, 0, -1):
        if 0 == rest_cost:
            break
        elif rest_cost != memtable[i - 1][j]:  # If the attraction was included
            selected_attractions.append((weights[i] * step, costs[i]))  # Append weight and cost
            j -= weights[i]  # Reduce the remaining weight
            rest_cost -= costs[i]  # Reduce the remaining cost
    print(selected_attractions)

    # Initialize new dictionary with convenient weights.
    # attractions_new = {}
    # for name in attractions.keys():
    #     attractions_new[name] = (int(attractions[name][0] // step), attractions[name][1])

    attractions_list = []
    for search in selected_attractions:
        for name, item in attractions.items():
            if search == item:
                attractions_list.append(name)

    return attractions_list


def print_memtable(memtable, rows, cols):
    for i in range(rows):
        for j in range(cols):
            print("%5d" % memtable[i][j], end=' ')
        print()
    print()


# Main code.
# A dictionary which contains attractions with couples where the first item means its weight
# and second item means its cost (in days).
attractions = {
    "Westminister abbey": (0.5, 7),
    "Globe the Theater": (0.5, 6),
    "National gallery": (1.0, 9),
    "British museum": (2.0, 9),
    "St. Paul's Cathedral": (0.5, 8)
}

STEP = find_step_value(attractions)
max_time = int(MAX_TIME//STEP)

attractions_list = get_selected_attractions(attractions, max_time, STEP)
print(', '.join(attractions_list), "\n")

print("The max time is", MAX_TIME, "days.")
total_weight = sum([attractions[item][0] for item in attractions_list])
print("The total duration of visiting all the attractions is", total_weight, "days.")

total_cost = sum([attractions[item][1] for item in attractions_list])
print("The total cost of attractions is", total_cost, "points.")

