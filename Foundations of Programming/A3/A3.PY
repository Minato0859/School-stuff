# 1. Please complete the following:
#   Your First name and Last Name: Syed Bilal Afzal
#   Your Student ID: 261166027

# 2. Write your program here: 

def is_outside_list(letter_list, index):
    
    if index > (len(letter_list) - 1) or index < 0:
        return True
    else:
        return False

def letter_positions(letter_list, character):

    list_of_indices = []
    
    for i in range(len(letter_list)):
        if letter_list[i] == character:
            list_of_indices.append(i)
        
    return list_of_indices
            
            


def valid_word_pos_direction(letter_list, word, index, direction):
       
    if not is_outside_list(letter_list, index):
        
        # if direction == 1:
            
            for i in range(len(word)):
                if  is_outside_list(letter_list, index) or letter_list[index] != word[i]:
                    return False
                index += direction
                
            return True  

    
def direction_word_given_position(letter_list, word, index):
    direction_list = []
    
    if word[0] == letter_list[index]:
        
        
        if valid_word_pos_direction(letter_list, word, index, -1):
            direction_list.append(-1)
        if valid_word_pos_direction(letter_list, word, index, 1):
            direction_list.append(1)
        
    
    return direction_list

def position_direction_word(letter_list, word):
    letter_position_list = letter_positions(letter_list, word[0])
    position_direction_list = []
    
    for i in letter_position_list:
       
        directions = direction_word_given_position(letter_list, word, i)
        
        if  directions != []:
            for j in directions:
                position_direction_list.append([i, j])
            
        
    return position_direction_list


def cross_word_position_direction(bool_letter_list, length_word, index, direction):
    
    for i in range(length_word):
        
        bool_letter_list[index] = True
        index += direction
        

def cross_word_all_position_direction(bool_letter_list, length_word, list_position_direction):
    
    for element in list_position_direction:
        
        cross_word_position_direction(bool_letter_list, length_word, element[0], element[1])
        
                        
                
def find_magic_word(letter_list, bool_letter_list):
    letters = []
    
    if len(letter_list) != len(bool_letter_list):
        raise ValueError('Both lists should have the same size')
    
    
    else:
        for i in range(len(bool_letter_list)):
            
            if bool_letter_list[i] == False:
                letters.append(letter_list[i])
            
    return ''.join(letters)


def word_search(letter_list, word_list):
    
    bool_letter_list = [False for i in letter_list]
    
    for word in word_list:
        length_word = len(word)
        
        position_direction_list = position_direction_word(letter_list, word)
        
        cross_word_all_position_direction(bool_letter_list, length_word, position_direction_list)
    
    magic_word = find_magic_word(letter_list, bool_letter_list)
    
    return magic_word
            
def word_search_main(letters, words):
    
    letter_list = [letter.upper() for letter in letters]
    word_list = words.split('-')
    
    for i in range(len(word_list)):
        word_list[i] = word_list[i].upper()
    
    magic_word = word_search(letter_list, word_list)
    
    return magic_word
    
            
    
           
    