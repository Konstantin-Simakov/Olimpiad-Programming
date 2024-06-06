# graph.py
# Demonstrates graphs uinsg.

from collections import deque


# BFS for graphs.
def bfs_search(graph, first_person):  
    search_queue = deque()                              # Create a new queue.
    search_queue += graph[first_person]                 # All neighbours are added in search queue.
    searched = []                                       # Already checked persons.
    
    while search_queue:                                 # While queue is not empty...
        person = search_queue.popleft()                 # First person is pop from the queue.
        if not person in searched:
            if is_seller(person):                       # Check if the person is mango seller.
                print(person, "is a mango seller!")     # Yes, it is a mango seller.
                return True                             # The mango seller is found.
            else:
                search_queue += graph[person]           # No, it isn't. All friends of this person 
                searched.append(person)                 # Now the person is checked.
                                                        # are added in search queue.
    return False                                        # If execution has reached this point, 
                                                        # then there is no mango seller in the queue.


def is_seller(name):
    return len(name) == 7


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
if not bfs_search(graph, "you"):
    print("There are no mango seller.")
