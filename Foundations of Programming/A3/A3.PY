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
            
            
            # valid_word_pos_direction(['A', 'B', 'C', 'D', 'C', 'M'],BCD,1,1) == True; 
# Got: False

def valid_word_pos_direction(letter_list, word, index, direction):
       
    if not is_outside_list(letter_list, index):
        
        # if direction == 1:
            
            for i in range(len(word)):
                if letter_list[index] != word[i] or is_outside_list(letter_list, index):
                    return False
                index += direction
                
            return True  
        # if direction == -1:
            
        #     for i in range(len(word)):
        #         if letter_list[index] != word[i] or is_outside_list(letter_list, index):
        #             return False
        #         index -= 1

                
        # return True                    
    
# Expected: direction_word_given_position(['A', 'B', 'C', 'D', 'C', 'M'],BCD,1) == [1]; 
# Got: [1, -1]
    
    
def direction_word_given_position(letter_list, word, index):
    
    if word[0] == letter_list[index]:
        direction_list = []
        
        if valid_word_pos_direction(letter_list, word, index, -1):
            direction_list.append(-1)
        if valid_word_pos_direction(letter_list, word, index, 1):
            direction_list.append(1)
        
    
    return direction_list

def position_direction_word(letter_list, word):
    letter_position_list = letter_positions(letter_list, word[0])
    position_direction_list = []
    
    for i in letter_position_list:
        # direction_list.append(direction_word_given_position(
        #     letter_list, word, i))
        directions = direction_word_given_position(letter_list, word, i)
        
        if  directions == []:
            letter_position_list.pop(i)
        
        else:
            for j in directions:
                position_direction_list.append([i, j])
            
        
    return position_direction_list


def cross_word_position_direction(bool_letter_list, length_word, index, direction):
    
    for i in range(length_word):
        
        bool_letter_list[index] = True
        index += direction
                        
                
        
    
           
    
    