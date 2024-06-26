# graph.py
# Demonstrates graphs uinsg.

from collections import deque


# With start vertice "you" (see below).
vertices = 1
edges = 0

# BFS for graphs.
def bfs_search(graph, first_person):  
    search_queue = deque()                              # Create a new queue.
    search_queue += graph[first_person]                 # All neighbours are added in search queue.
    searched = []                                       # Already checked persons.

    global vertices, edges
    while search_queue:                                 # While queue is not empty...
        person = search_queue.popleft()                 # First person is pop from the queue.
        edges += 1
        if not person in searched:
            vertices += 1
            if is_seller(person):                       # Check if the person is a mango seller.
                print(person, "is a mango seller!")     # Yes, it is a mango seller.
                return True                             # The mango seller is found.
            else:
                search_queue += graph[person]           # No, it isn't. All friends of this person 
                searched.append(person)                 # Now the person is checked.
                                                  
    print("There are no mango seller.")                 # If execution has reached this point, 
    return False                                        # then there is no mango seller in the queue.


def is_seller(name):
    return len(name) == 6


# Main code.
# Create special hash table.
graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["tom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["tom"] = []
graph["jonny"] = []

# Launch search.
bfs_search(graph, "you")
print("\nThere are", vertices, "vertices and", edges, "edges in the graph.")
