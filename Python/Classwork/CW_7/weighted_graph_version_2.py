# weighted_graph.py
# Demonstrates Dijkstra's algorithm working for weighted graphs.


# Infinity for a computer.
INFINITY = float("inf")


def dijkstra_algorithm(graph, nodes, start_node):
    """ Own Dijkstra's algorithm. """
    costs = {}
    parents = {}
    unvisited_nodes = list(nodes[:])                # Get the copy of all nodes as a list for save working.

    # Initial costs of all nodes.
    for node in unvisited_nodes:
        costs[node] = INFINITY
    costs[start_node] = 0

    while unvisited_nodes:
        node = lowest_cost(unvisited_nodes, costs)  # Find the lowest cost node.
        cost = costs[node]                          # Get the cost of this node.
        neighbors = graph[node]                     # Get neighbors of this node as a dictionary.
        
        for neighbor in neighbors.keys():           # Get a list of neighbors of the node.
            new_cost = cost + neighbors[neighbor]   # Calculate new cost of its neighbors from the node.
            
            if new_cost < costs[neighbor]:          # If the new cost less than old cost
                costs[neighbor] = new_cost          # Update the old cost to new one
                parents[neighbor] = node            # And update the old parents to new one too.
        
        unvisited_nodes.remove(node)                # Mark the node as processed.

    return parents, costs


def lowest_cost(unvisited_nodes, costs):
    # Initial values.
    # l_cost = INFINITY
    l_node = None
    for node in unvisited_nodes:
        if l_node == None:
            l_node = node
        elif costs[node] < costs[l_node]:
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

parents, costs = dijkstra_algorithm(graph, NODES, "start")
display_results(parents, costs, "start", "finish")
