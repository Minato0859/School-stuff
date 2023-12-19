# 1. Please complete the following:
#   Your First name and Last Name: Syed Bilal Afzal
#   Your Student ID: 261166027

# 2. Write your program here: 

import pickle

def read_text(text_path):
    try:
        file_object  = open(text_path, 'r')
        text_list = []
        
        for line in file_object:
            text_list.append(line.split(',')[1])
            
        file_object.close()

        return text_list
      
    except FileNotFoundError:
        print('File does not exist')    
        
            
  

def read_pickle(path_to_pkl):
    
    pkl_obj = open(path_to_pkl, 'rb')
    
    pkl_dict = pickle.load(pkl_obj)
    
    pkl_obj.close()
    
    return pkl_dict



def sentiment_frequencies(text, dictionary_word):
    
    word_list = text.split()
    
    dict_frequency = dict.fromkeys(dictionary_word, 0)
    
    for word in word_list:
        for key in dictionary_word:
            if word in dictionary_word[key]:
                dict_frequency[key] += 1
                
    for key in dict_frequency:
        dict_frequency[key] = round(dict_frequency[key] / len(word_list), 2)
        
        
    return dict_frequency


def compute_polarity(dict_frequency):
    
    max_freq = -1
    
    list_frequency = dict_frequency.items()

    for key, freq in list_frequency:
        
        if freq > max_freq:
            max_freq = freq
            polarity = key
        
    return polarity


def analyse_text(text_path, dict_path):
    
    text_list = read_text(text_path)
    sentiment_dict = read_pickle(dict_path)
    list_polarity = []
    
    stop_words = ['!','.','?',';','\n']
    
    for line in text_list:
        
        for char in stop_words:
            line.replace(char, '')
        
        line = line.lower()
        
        dict_frequency = sentiment_frequencies(line, sentiment_dict)
        polarity = compute_polarity(dict_frequency)
        
        list_polarity.append(polarity)
    
    return list_polarity
         