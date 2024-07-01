# weighted_graph.py
# Demonstrates Dijkstra's algorithm working for weighted graphs.


# Infinity for a computer.
INFINITY = float("inf")


def dijkstra_algorithm(graph, nodes, start_node):
    """ Own Dijkstra's algorithm. """
    costs = {}
    parents = {}
    processed = []                                  # List of processed nodes.

    # Initial costs of all nodes.
    for node in nodes:
        costs[node] = INFINITY
    costs[start_node] = 0
    
    node = lowest_cost(costs, processed)            # Find the lowest cost node.
    while node is not None:

        cost = costs[node]                          # Get the cost of this node.
        neighbors = graph[node]                     # Get neighbors of this node as a dictionary.
        
        for neighbor in neighbors.keys():           # Get a list of neighbors of the node.
            new_cost = cost + neighbors[neighbor]   # Calculate new cost of its neighbors from the node.
            
            if new_cost < costs[neighbor]:          # If the new cost less than old cost
                costs[neighbor] = new_cost          # Update the old cost to new one
                parents[neighbor] = node            # And update the old parents to new one too.
        
        processed.append(node)                      # Mark the node as processed.
        node = lowest_cost(costs, processed)        # If there are no nodes, algorithm ends.

    return parents, costs


def lowest_cost(costs, processed):
    # Initial values.
    l_cost = INFINITY
    l_node = None

    # Own algorithm.
    for node in costs:
        cost = costs[node]
        # If the node has the lowest cost and hasn't been processed yet
        # Set the node as one with the lowest cost.
        if cost < l_cost and node not in processed:
            l_cost = cost
            l_node = node

    # The node with the lowest cost.
    return l_node


def display_results(parents, costs, start_node, finish_node):
    lowest_way = []
    node = finish_node
    while node != start_node:
        lowest_way.append(node)
        node = parents[node]
    lowest_way.append(start_node)

    print("The way with a lowest cost", costs[finish_node], 
            "is:")
    print(" -> ".join(reversed(lowest_way)))


# Main code and source data.

NODES = ("start", "a", "b", "finish")

graph = {}
for node in NODES:
    graph[node] = {}

graph["start"]["a"] = 6
graph["start"]["b"] = 2
graph["a"]["finish"] = 1
graph["b"]["a"] = 3
graph["b"]["finish"] = 5

parents, costs = dijkstra_algorithm(graph, NODES, start_node="start")
display_results(parents, costs, start_node="start", finish_node="finish")
