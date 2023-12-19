print("Welcome to the DIY Tea and Juice Maker!")
drink_base = int(input('What kind of base do you want?'\
    ' Please enter 1 for milk and 2 for fruit: '))

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
    
    
tea_type = input('''From the following tea types:
                 - No Tea
                 - Black Tea
                 - Green Tea
                 - Matcha
                 Please choose a tea type: ''')

if tea_type == 'Matcha' and drink_base == 2:
    print('Invalid choice! End of the program')
else:
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
    
    valid = True
    
    if beverage_temp <= 10 and beverage_temp > 4:
        beverage_temp = 4
        valid = True #introducing variable to check weather or not to continue
    elif beverage_temp >= 1 and beverage_temp <= 4:
        valid = True
    else:
        valid = False
        print('Invalid choice! End of the program')
        

if valid:
    if cup_size == 's':
        cup_grams = 355
    elif cup_size == 'm':
        cup_grams = 473
    else:
        cup_grams = 621
    
    # Difference of initial and desired temperature of the drink
    delta_temp_drink = 25 - beverage_temp 
    # Heat capacity of water
    c_drink = 4.184 
    # Difference between desired temperature and ice temperature
    delta_temp_ice = beverage_temp
    # Heat of fusion for water at 0 degrees
    h_fusion = 334
    

    ice_grams = ((cup_grams * c_drink * delta_temp_drink) 
                 / ((c_drink * delta_temp_ice) + h_fusion))
    
    num_cubes = ice_grams / 5

    if drink_base == 1:
        print('Your drink is a', milk_type, 'and', tea_type, 
              'with', topping, '.')
        print('The temperature of your beverage will be', beverage_temp, 
              'Celcius degree after all', intnum_cubes, 'ice cubes melted.')
        print('Have a nice day!')
    elif drink_base == 2:
        print('Your drink is a', fruit, 'juice and', tea_type, 
              'with', topping, '.')
        print('The temperature of your beverage will be', beverage_temp, 
              'Celcius degree after all', int(num_cubes), 'ice cubes melted.')
        print('Have a nice day!')        
        
    
     
    
    
    
    