# longest_common_substring.py
# Finding the longest common substring.


def get_table(words):
    """ Construct and get the memoization table. """
    rows = len(words[0]) + 1                                            # For correct construction of the memoization table.
    cols = len(words[1]) + 1                                            # For correct construction of the memoization table.

    table = [[0 for j in range(cols)] for i in range(rows)]             # Initialize table with zeros.
    print_table(table, rows, cols)                                      # Then display it.

    # Initialize it.
    for row in range(rows-1):
        for col in range(cols-1):
            if words[0][row] == words[1][col]:                          # If letters in words match, update the current
                table[row+1][col+1] = table[row][col] + 1               # length of substring.

    print_table(table, rows, cols)                                      # Then display the table again.
    return table


def get_longest_substring(words, table):
    """ 
    Calculate the max character index and 
    construct the finding longest substring with it. 
    """
    # Find the max character index.
    character_index = 0
    length = 0
    for i in range(len(table)):                                         # Get the maximal substring length and its index
        for j in range(len(table[i])):                                  # in word from the table.
            if table[i][j] > length:
                length = table[i][j]
                character_index = j

    # Construct the max substring.
    substring = ""
    while length > 0:                                                   # Going in reverse order through the table,
        substring += words[1][character_index - 1]                      # adding matching characters to the resulting string,
        length -= 1                                                     # until length is equal to 0.
        character_index -= 1
                                        
    return "".join(reversed(substring))                                 # Reverse and join the resulting substring.


def print_table(table, rows, cols):
    for i in range(rows):
        for j in range(cols):
            print("%5d" % table[i][j], end=' ')                         # Display the table.
        print()
    print()


def main():
    WORDS = ("fish", "vista")                                           # The source collection of words.
    source_word = "hish"

    result = 0
    words = [source_word]                                               # The list will consist of two elements only.
    for word in WORDS:
        words.append(word)
        for word in words:
            print(word, end=" ")
        print()

        table = get_table(words)

        # Compare the source word with every word from the WORDS
        # and find the max substring among them. 
        substr = get_longest_substring(words, table)
        len_substr = len(substr)
        if len_substr > result:
            result = len_substr
            max_substr = substr
            target_word = word

        words.remove(word)

    print("The longest substring is \'", max_substr, "\'.", sep="")
    print("Its length is ", result, ".", sep="")
    print("Maybe you meant \"", target_word, "\".", sep="")


# Main code.
if "__main__" == __name__:
    main()
