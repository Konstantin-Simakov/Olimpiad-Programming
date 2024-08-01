# traveling_salesman.py
# 
# A greedy algorithm for the traveling salesman problem.
# The algorithm is based on Dijkstra's algorithm.
# 

INFINITY = float("inf")


def lowest_cost(graph, node, processed):
    l_cost = INFINITY
    l_node = None

    # Get the couples of neighbors and their costs from the current node.
    for neighbor, cost in graph[node].items():
        if cost < l_cost and neighbor not in processed:     # Find the lowest cost of unprocessed node's neighbors.
            l_cost = cost
            l_node = neighbor

    return l_cost, l_node


def greedy_algorythm(start_node):
    processed = []
    total_cost = 0

    # For the first iteration set the start node as current node.
    node = start_node
    cost = 0
    while node is not None:                                 # While there are any nodes left unprocessed.
        processed.append(node)                              # Mark node as processed. 
        total_cost += cost
        
        cost, node = lowest_cost(graph, node, processed)    

    return total_cost, processed


def display_results(total_cost, processed):
    print("The total cost is", total_cost)
    print(" -> ".join(processed), "\n")


NODES = ("start", "a", "b", "c")
graph = {}
for node in NODES:
    graph[node] = {}

# Start node
graph["start"]["a"] = 5
graph["start"]["b"] = 20
graph["start"]["c"] = 15

# A node
graph["a"]["start"] = 5
graph["a"]["b"] = 15
graph["a"]["c"] = 13

# B node
graph["b"]["start"] = 20
graph["b"]["a"] = 15
graph["b"]["c"] = 10

# C node
graph["c"]["start"] = 15
graph["c"]["a"] = 13
graph["c"]["b"] = 10

total_cost, processed = greedy_algorythm(start_node="start")
display_results(total_cost, processed)


# Second example
NODES = ("start", "a", "b", "c", "d")
graph = {}
for node in NODES:
    graph[node] = {}

# Start node
graph["start"]["a"] = 10
graph["start"]["b"] = 27
graph["start"]["c"] = 12
graph["start"]["d"] = 11

# A node
graph["a"]["start"] = 10
graph["a"]["b"] = 5
graph["a"]["c"] = 13
graph["a"]["d"] = 9

# B node
graph["b"]["start"] = 7
graph["b"]["a"] = 5
graph["b"]["c"] = 6
graph["b"]["d"] = 8

# C node
graph["c"]["start"] = 12
graph["c"]["a"] = 13
graph["c"]["b"] = 6
graph["c"]["d"] = 10

# D node
graph["d"]["start"] = 11
graph["d"]["a"] = 9
graph["d"]["b"] = 8
graph["d"]["c"] = 10

total_cost, processed = greedy_algorythm(start_node="start")
display_results(total_cost, processed)
