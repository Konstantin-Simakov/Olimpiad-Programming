# The_longest_subsequence.py
# Algorithm which calculates the longest subsequence between given words.


def get_memtable(word1, word2):
    rows = len(word1)
    cols = len(word2)

    # Create the memoization table.
    memtable = [[0] * (cols + 1) for _ in range(rows + 1)]

    # Initialize it.
    for i in range(1, rows + 1):
        for j in range(1, cols + 1):
            if word1[i - 1] == word2[j - 1]:
                memtable[i][j] = memtable[i - 1][j - 1] + 1
            else:
                memtable[i][j] = max(memtable[i - 1][j], memtable[i][j - 1])

    # Display the table for check.
    for n in range(rows + 1):
        print(*memtable[n])
    print()

    return memtable

def get_string(source_word, word):
    word1 = source_word
    word2 = word
    memtable = get_memtable(word1, word2)

    str = ""
    i = len(word1)
    j = len(word2)
    while i > 0 and j > 0:                                      # Going in reverse order through the table,
        if word1[i - 1] == word2[j - 1]:                        # If letters in two words matches, add this letter to
            str += word1[i - 1]                                 # the resulting string.
            i -= 1
            j -= 1
        elif memtable[i - 1][j] > memtable[i][j - 1]:           # If they don't, and upper value's bigger than left one,
            i -= 1                                              # go upper.
        else:
            j -= 1                                              # Else, go to the left.

    return ''.join(reversed(str))


def get_max_subseq(source_word, words_tuple):                   # Returns the longest subsequence.
    longest_subseq = ""

    for word in words_tuple:
        current = get_string(source_word, word)
        print(current)
        if len(current) > len(longest_subseq):
            longest_subseq = current
            current_word = word

    return longest_subseq, current_word


"""Main code"""
source = "fosh"
words = ("fish", "fort")
longest_subseq, res_word = get_max_subseq(source, words)

print("The longest subsequence:", longest_subseq)
print("Its length is", len(longest_subseq))
print("Probably, the word was", res_word)
