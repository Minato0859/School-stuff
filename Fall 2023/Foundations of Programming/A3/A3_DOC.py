def is_outside_list(letter_list, index):
    """
    Check if a given index is outside the bounds of the list.
    
    Parameters:
    - letter_list (list): A list of letters
    - index (int): The index to be checked
    
    Returns:
    - bool: True if the index is outside the bounds of the list, else False
    
    Examples:
    >>> is_outside_list(['A', 'B', 'C', 'D'], 4)
    True
    >>> is_outside_list(['A', 'B', 'C', 'D'], 2)
    False
    """
    
    if index > (len(letter_list) - 1) or index < 0:
        return True
    return False


def letter_positions(letter_list, character):
    """
    Returns a list of indices where the given character is found in the letter_list.
    
    Parameters:
    - letter_list (list): A list of letters
    - character (str): A single character to search for
    
    Returns:
    - list: List of indices where the character appears in the letter_list

    Examples:
    >>> letter_positions(['A', 'B', 'C', 'D', 'C'], 'C')
    [2, 4]
    """
    
    list_of_indices = [i for i, letter in enumerate(letter_list) if letter == character]
    return list_of_indices


def valid_word_pos_direction(letter_list, word, index, direction):
    """
    Check if a word can be formed in the given position and direction.
    
    Parameters:
    - letter_list (list): A list of letters
    - word (str): Word to check
    - index (int): Starting position
    - direction (int): Direction to check (-1 for left, 1 for right)
    
    Returns:
    - bool: True if word can be formed, else False
    """
    
    for i in range(len(word)):
        if is_outside_list(letter_list, index) or letter_list[index] != word[i]:
            return False
        index += direction
    return True


def direction_word_given_position(letter_list, word, index):
    """
    Determines the direction(s) in which the word can be found given a starting index.
    
    Parameters:
    - letter_list (list): A list of letters
    - word (str): Word to check
    - index (int): Starting position
    
    Returns:
    - list: List of valid directions (-1 for left, 1 for right)
    """
    
    direction_list = []
    if valid_word_pos_direction(letter_list, word, index, -1):
        direction_list.append(-1)
    if valid_word_pos_direction(letter_list, word, index, 1):
        direction_list.append(1)
    return direction_list


def position_direction_word(letter_list, word):
    """
    Find all positions and directions in which the word can be formed.
    
    Parameters:
    - letter_list (list): A list of letters
    - word (str): Word to check
    
    Returns:
    - list: List of valid positions and directions
    """
    
    position_direction_list = []
    for position in letter_positions(letter_list, word[0]):
        for direction in direction_word_given_position(letter_list, word, position):
            position_direction_list.append([position, direction])
    return position_direction_list


def cross_word_position_direction(bool_letter_list, length_word, index, direction):
    """
    Mark positions covered by a word in a specific direction.
    
    Parameters:
    - bool_letter_list (list): A list representing positions covered by words
    - length_word (int): Length of the word
    - index (int): Starting position
    - direction (int): Direction (-1 for left, 1 for right)
    """
    
    for _ in range(length_word):
        bool_letter_list[index] = True
        index += direction


def cross_word_all_position_direction(bool_letter_list, length_word, list_position_direction):
    """
    Mark positions covered by a word in all valid positions and directions.
    
    Parameters:
    - bool_letter_list (list): A list representing positions covered by words
    - length_word (int): Length of the word
    - list_position_direction (list): List of valid positions and directions
    """
    
    for position, direction in list_position_direction:
        cross_word_position_direction(bool_letter_list, length_word, position, direction)


def find_magic_word(letter_list, bool_letter_list):
    """
    Find letters not covered by any word.
    
    Parameters:
    - letter_list (list): A list of letters
    - bool_letter_list (list): A list representing positions covered by words
    
    Returns:
    - str: Letters not covered by any word
    """
    
    if len(letter_list) != len(bool_letter_list):
        raise ValueError('Both lists should have the same size')
    
    return ''.join([letter for i, letter in enumerate(letter_list) if not bool_letter_list[i]])


def word_search(letter_list, word_list):
    """
    Perform a word search and find the magic word.
    
    Parameters:
    - letter_list (list): A list of letters
    - word_list (list): List of words to search for
    
    Returns:
    - str: The magic word
    """
    
    bool_letter_list = [False for _ in letter_list]
    
    for word in word_list:
        position_direction_list = position_direction_word(letter_list, word)
        cross_word_all_position_direction(bool_letter_list, len(word), position_direction_list)
    
    return find_magic_word(letter_list, bool_letter_list)


def word_search_main(letters, words):
    """
    Main function to perform the word search.
    
    Parameters:
    - letters (str): String of letters
    - words (str): String of words separated by '-'
    
    Returns:
    - str: The magic word
    """
    
    letter_list = [letter.upper() for letter in letters]
    word_list = words.split('-')
    word_list = [word.upper() for word in word_list]
    
    return word_search(letter_list, word_list)
