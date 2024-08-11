# rucksack.py
# Solve the rucksack problem using dynamic programming method.

MAX_WEIGHT = 4      # The max capacity of the rucksack in kg, only integer!


def get_weights_costs(stuff):
    """Get the weight and cost lists of items."""
    # Start each list from zero to match the item index.
    weights = [0] + [stuff[item][0] for item in stuff.keys()]
    costs = [0] + [stuff[item][1] for item in stuff.keys()]

    return weights, costs


def get_memtable(stuff, max_weight=MAX_WEIGHT, step=1):
    """Get memoization table based on weigth and cost lists."""
    weights, costs = get_weights_costs(stuff)
    items = len(costs)                  # Number of table lines.

    # Create the memoization table with zero costs.
    memtable = [[0 for j in range(0, max_weight+1, step)] for i in range(items)]
    print_memtable(memtable, items, max_weight+1)
    
    # Initialize it.
    for i in range(1, items):
        for j in range(1, max_weight+1):
            # If the item fits into the rucksack,
            # maximize the summarize cost.
            if weights[i] <= j:
                memtable[i][j] = max(costs[i] + memtable[i-1][j-weights[i]], memtable[i-1][j])

            # Else choose the previous item with max cost and the same weight.
            else:
                memtable[i][j] = memtable[i-1][j]

            print(memtable[i][j], end=" ")
        print()

    return memtable, weights, costs


def get_selected_items(stuff, max_weight=MAX_WEIGHT):
    """Make a list of your most valuable items with a rucksack weight limit."""
    memtable, weights, costs = get_memtable(stuff)
    print(weights)
    print(costs)
    items = len(costs)                          # Number of table lines.
    print_memtable(memtable, items, max_weight+1)

    j = max_weight                              # Start from the maximum weight.
    rest_cost = memtable[items-1][max_weight]   # Start with the last element of the table, its max cost.
    needed_items = []                           # The list of items as pairs: weight and cost.

    for i in range(items-1, 0, -1):             # The loop in reverse order through the list.
        if 0 == rest_cost:                      # The rucksack is packed to the maximum.
            break
        elif rest_cost != memtable[i-1][j]:     # Take an item.
            needed_items.append((weights[i], costs[i]))
            rest_cost -= costs[i]
            j -= weights[i]                     # Transfer to the previous max cost of the rest capacity.

    print(needed_items)

    items_list = []                             # Only strings, i.e. item names.
    # Search for keys of source dictionary, i.e. item names.
    for search in needed_items:
        for name, item in stuff.items():
            if search == item:
                items_list.append(name)

    return items_list


def print_memtable(memtable, rows, cols):
    for i in range(0, rows):
        for j in range(0, cols):
            print("%5d" % memtable[i][j], end=" ")
        print()


# A dictionary with tuples where the first item means its weight
# and second item means its cost (in conventional monetary units).
stuff = {
        "guitar": (1, 1500),
        "recorder": (4, 3000),
        "notebook": (3, 2000)
}

items_list = get_selected_items(stuff)
print(items_list, "\n")

print("The total capacity of the rucksack is", MAX_WEIGHT, "kg.")
total_weight = sum([stuff[item][0] for item in items_list])
print("The total weight of items in the rucksack is", total_weight, "kg.")

total_cost = sum([stuff[item][1] for item in items_list])
print("The total cost of items in the rucksack is", total_cost, "rubles.")
