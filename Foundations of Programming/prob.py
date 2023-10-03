# # # list= [1, 2, 3, 4, 5]

# # # for i in range(1,6):
# # #     print(list[:i])


# # import math

# def sum_num(a, b):
#     return a+b

# print(sum_num(1, 2))


def check_odd():
    x = int(input('PLease input an integer: '))
    if x % 2:
        print(x, 'is odd')
    else:
        print(x, 'is even')
        
check_odd()