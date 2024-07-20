# min_radio_stations.py   
# 
# The set covering problem using the example 
# of choosing minimum number of radio stations 
# to broadcast a program in the USA.
# 


def greedy_algorithm(states_needed, stations, final_stations):
    """ Own greedy algorithm for the task. """
    while states_needed:        
        # Search for a radio station broadcasting in the largest number of states.
        best_station = None
        states_covered = set()
        for station, states_for_station in stations.items():
            covered = states_needed & states_for_station        # Intersection of sets.
            if len(covered) > len(states_covered):
                best_station = station
                states_covered = covered

        # print(best_station)
        final_stations.add(best_station)
        states_needed -= states_covered


# Source data.

# Let's choose a small number of states (set), 8 pieces, to simplify the calculations.
states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

# Radio stations and their broadcasting states (hash table).
stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

# List of the resulting set of stations.
final_stations = set()


# Main code.
greedy_algorithm(states_needed=states_needed, 
        stations=stations, final_stations=final_stations)
print(final_stations)
