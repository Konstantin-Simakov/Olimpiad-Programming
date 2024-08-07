# knapsack.py
# Solve the rucksack problem using dynamic programming method.


def get_weights_costs(stuff):
    """Get the weight and cost lists of items."""
    # Start each list from zero to match the item index.
    weights = [0] + [stuff[item][0] for item in stuff.keys()]
    costs = [0] + [stuff[item][1] for item in stuff.keys()]

    return weights, costs


def get_memtable(stuff, max_weight=4):
    """Get memoization table based on weigth and cost lists."""
    weights, costs = get_weights_costs(stuff)
    items = len(costs)                  # Number of table lines.

    # Create the memoization table with oh costs.
    memtable = [[0 for j in range(max_weight+1)] for i in range(items)]
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


def get_selected_items(stuff, max_weight=4):
    """Make a list of your most valuable items with a rucksack weight limit."""
    memtable, weights, costs = get_memtable(stuff)
    print(weights)
    print(costs)
    items = len(costs)                          # Number of table lines.
    print_memtable(memtable, items, max_weight+1)

    weight = max_weight                         # Start from the maximum weight.
    needed_items = []                           # The list of items as pairs: weight and cost.

    res = memtable[items-1][max_weight]         # Start with the last element of the table.
    for i in range(items-1, 0, -1):             # The loop in reverse order through the list.
        if res <= 0:                            # The rucksack is packed to the maximum.
            break
        elif res != memtable[i-1][weight]:      # Take an item.
            needed_items.append((weights[i], costs[i]))
            res -= costs[i]
            weight -= weights[i]

    print(needed_items)

    items_list = []                             # Only strings, i.e. item names.
    # Search for keys of source dictionary, i.e. item names.
    for search in needed_items:
        for name, item in stuff.items():
            if search == item:
                items_list.append(name)

    return items_list


def print_memtable(memtable, rows, cols):
    for i in range(1, rows):
        for j in range(1, cols):
            print(memtable[i][j], end=" ")
        print()


# Here is a tuple where the first item means its weight
# and second item means its cost (in conventional monetary units).
stuff = {
        "guitar": (1, 1500),
        "recorder": (4, 3000),
        "notebook": (3, 2000)
}

items_list = get_selected_items(stuff)
print(items_list, "\n")

total_weight = sum([stuff[item][0] for item in items_list])
print("The total weight of the rucksack is", total_weight, "kg.")

total_cost = sum([stuff[item][1] for item in items_list])
print("The total cost of the rucksack is", total_cost, "rubles.")
