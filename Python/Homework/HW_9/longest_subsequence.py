# The_longest_subsequence.py
# Algorithm which calculates the longest subsequence between given words.


def get_memtable(word_1, word_2):
    """ Construct and get the memoization table. """
    rows = len(word_1)
    cols = len(word_2)

    # Create the memoization table.
    memtable = [[0] * (cols+1) for _ in range(rows+1)]

    # Initialize it.
    for i in range(1, rows+1):
        for j in range(1, cols+1):
            if word_1[i-1] == word_2[j-1]:
                memtable[i][j] = memtable[i-1][j-1] + 1
            else:
                memtable[i][j] = max(memtable[i-1][j], memtable[i][j-1])

    # Display the table for check.
    print()
    for n in range(rows+1):
        print(*memtable[n])
    print()

    return memtable

def get_string(source_word, word):
    """ Get the subsequence for the 'word' and 'source_word' as a string. """
    word_1 = source_word
    word_2 = word
    memtable = get_memtable(word_1, word_2)

    str = ""
    i = len(word_1)
    j = len(word_2)
    while i > 0 and j > 0:                                      # Going in reverse order through the table,
        if word_1[i - 1] == word_2[j - 1]:                      # If letters in two words matches, add this letter to
            str += word_1[i - 1]                                # the resulting string.
            i -= 1
            j -= 1
        elif memtable[i - 1][j] > memtable[i][j - 1]:           # If they don't, and upper value's bigger than left one,
            i -= 1                                              # go upper.
        else:
            j -= 1                                              # Else, go to the left.

    return "".join(reversed(str))


def get_max_subseq(source_word, words_tuple):                   # Returns the longest subsequence.
    longest_subseq = ""

    for word in words_tuple:
        current = get_string(source_word, word)
        print(current)
        if len(current) > len(longest_subseq):
            longest_subseq = current
            current_word = word

    return longest_subseq, current_word


def main():
    WORDS = ("fish", "fort")
    source_word = "fosh"

    longest_subseq = ""
    for word in WORDS:
        current = get_string(source_word, word)
        print(current)
        if len(current) > len(longest_subseq):
            longest_subseq = current
            res_word = word

    print("\nThe longest subsequence: ", longest_subseq, ".", sep="")
    print("Its length is ", len(longest_subseq), ".", sep="")
    print("Probably, the word was ", res_word, ".", sep="")


# Main code.
if "__main__" == __name__:
    main()
