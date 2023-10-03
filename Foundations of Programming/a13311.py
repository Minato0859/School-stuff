print("Welcome to the DIY Tea & Juice Maker!")

proceed = True  # Variable to decide whether to continue to the next steps or not

drink_base = int(input('What kind of base do you want?'\
                        ' Please enter 1 for milk or 2 for fruit: '))

if drink_base == 1:
    is_lactose_intol = input("Do you have lactose intolerance?"\
                             " y for yes, n for no: ")
    
    if is_lactose_intol == 'y':
        milk_type = input("Do you want soy milk or oat milk?"\
                          " Please type in your choice [soy/oat]: ")
    else:
        milk_type = 'regular'
elif drink_base == 2:
    fruit = input('Which fruit do you want?'\
                  ' Please type in your choice [mango/strawberry]: ')
else:
    print("Invalid choice! End of the program")
    proceed = False  # Setting proceed to False will skip the rest of the code

if proceed:
    tea_type = input('''From the following tea types:
- No Tea
- Black Tea
- Green Tea
- Matcha
Please choose a tea type: ''')

    if tea_type == 'Matcha' and drink_base == 2:
        print('Invalid choice! End of the program')
        proceed = False  # Setting proceed to False will skip the rest of the code

if proceed:
    topping = input('''From the following toppings:
- No Topping
- Bobas
- Coconut Jelly
Please enter your choice for toppings: ''')
    cup_size = input('Please enter your desired size of cup'\
                     ' (Please enter s for small, m for medium, or l for large): ')
    beverage_temp = float(input('Please enter your desired'\
                                ' temperature of your beverage'\
                                ' (between 1 and 4 degrees): '))
    
    if 1 <= beverage_temp <= 4:
        valide = True
    elif 4 < beverage_temp <= 10:
        valide = True
        beverage_temp = 4  # Set to max allowed value
    else:
        print('Invalid choice! End of the program')
        valide = False  # Do not proceed with the rest


