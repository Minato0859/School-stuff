import math
import random

MIN_LAT = -90
MAX_LAT = 90
MIN_LONG = -180
MAX_LONG = 180
EARTH_RADIUS = 6371

def meter_to_feet(meters):
    """
    Convert meters to feet.

    Parameters:
    meters : float
        Measurement in meters.

    Returns:
    float
        Equivalent measurement in feet, rounded to 2 decimal places.
    """
    feet = meters * 3.28
    return round(feet, 2)


def degrees_to_radians(degrees):
    """
    Convert degrees to radians.

    Parameters:
    degrees : float
        Angle in degrees.

    Returns:
    float
        Equivalent angle in radians, rounded to 2 decimal places.
    """
    radians = degrees * math.pi / 180
    return round(radians, 2)


def get_vessel_dimensions():
    """
    Prompt user for vessel dimensions in meters and return in feet.

    Returns:
    tuple
        Vessel length and width in feet.
    """
    length_m = float(input('Enter the vessel length (in meter): '))
    width_m = float(input('Enter the vessel width (in meter): '))
    length_f = meter_to_feet(length_m)
    width_f = meter_to_feet(width_m)
    return length_f, width_f


def get_valid_coordinate(val_name, min_float, max_float):
    """
    Prompt user for a valid coordinate value within a specified range.

    Parameters:
    val_name : str
        Name of the coordinate (e.g., 'latitude' or 'longitude').
    min_float : float
        Minimum valid value.
    max_float : float
        Maximum valid value.

    Returns:
    float
        Valid coordinate value.
    """
    in_range = False
    while not in_range:
        val = float(input('What is your ' + val_name + ' ?'))
        if val <= min_float or val >= max_float:
            print('Invalid', val_name)
        else:
            in_range = True
    return val


def get_gps_location():
    """
    Prompt user for valid GPS latitude and longitude coordinates.

    Returns:
    tuple
        Valid latitude and longitude coordinates.
    """
    latitude = get_valid_coordinate('latitude', -90, 90)
    longitude = get_valid_coordinate('longitude', -180, 180)
    return latitude, longitude


def distance_two_points(lat_1, long_1, lat_2, long_2):
    """
    Calculate the distance between two points on Earth's surface.

    Parameters:
    lat_1, long_1 : float
        Latitude and longitude of the first point.
    lat_2, long_2 : float
        Latitude and longitude of the second point.

    Returns:
    float
        Distance between the two points in kilometers, rounded to 2 decimal places.
    """
    lat_1, long_1 = degrees_to_radians(lat_1), degrees_to_radians(long_1) 
    lat_2, long_2 = degrees_to_radians(lat_2), degrees_to_radians(long_2)
    lat_dif = lat_1 - lat_2
    long_dif = long_1 - long_2
    a = math.sin(lat_dif / 2) ** 2 + math.cos(lat_1) * math.cos(lat_2) * math.sin(long_dif / 2) ** 2
    c = 2 * math.atan2(a ** (1/2), (1-a) ** (1/2))
    distance = EARTH_RADIUS * c
    return round(distance, 2)


def check_safety(latitude, longitude):
    """
    Check safety based on the provided latitude and longitude.

    Parameters:
    latitude, longitude : float
        Current latitude and longitude of the vessel.

    Prints:
    str
        Safety status message.
    """
    restricted_dist = distance_two_points(latitude, longitude, 25, -71)
    
    if restricted_dist <= 400:
        print('Error: Restricted zone!')
    elif (latitude >= 40 and latitude <= 41) and (longitude >= -71 and longitude <= 70):
        print('Warning: Hazardous area! Navigate with caution.') 
    else:
        print('Safe navigation.')


def get_max_capacity(length, width):
    """
    Calculate the maximum passenger capacity of a vessel based on its dimensions.

    Parameters:
    length, width : float
        Vessel dimensions in feet.

    Returns:
    int
        Maximum passenger capacity.
    """
    if length <= 26:
        capacity = length * width / 15
    else: 
        capacity = (length * width / 15) + (length - 26) * 3
    return int(capacity)


def passengers_on_boat(length, width, passengers):
    """
    Check if the number of passengers can fit on a vessel based on its dimensions.

    Parameters:
    length, width : float
        Vessel dimensions in feet.
    passengers : int
        Number of passengers.

    Returns:
    bool
        True if passengers can fit, False otherwise.
    """
    true_passengers = get_max_capacity(length, width)
    return passengers <= true_passengers and passengers % 4 == 0


def update_coordinate(position, min_float, max_float):
    """
    Update a GPS coordinate value within a valid range using a random value.

    Parameters:
    position : float
        Current coordinate value.
    min_float : float
        Minimum valid value.
    max_float : float
        Maximum valid value.

    Returns:
    float
        Updated coordinate value.
    """
    updated = False
    random.seed(123)
    while not updated:
        random_num = random.uniform(-10, 10)
        new_position = position + random_num
        if (new_position > min_float) and (new_position < max_float):
            updated = True
    return round(new_position, 2)


def wave_hit_vessel(latitude, longitude):
    """
    Simulate the effect of a wave hit on a vessel, updating its position.

    Parameters:
    latitude, longitude : float
        Current latitude and longitude of the vessel.

    Returns:
    tuple
        Updated latitude and longitude after the wave hit.
    """
    new_lat = update_coordinate(latitude, MIN_LAT, MAX_LAT)
    new_long = update_coordinate(longitude, MIN_LONG, MAX_LONG)
    
    check_safety(new_lat, new_long)  # This line will directly print the safety message
    
    return new_lat, new_long

def vessel_menu():
    """
    Display and manage a vessel menu for various operations.

    This function interacts with the user through inputs and outputs, guiding them through various options related to vessel safety, capacity, and positioning.
    """
    print('Welcome to the boat menu!')
    latitude, longitude = get_gps_location()
    print('Your current position is at latitude', latitude, 'and longitude', longitude)
    length_f, width_f = get_vessel_dimensions()
    print('Your boat measures ' + str(length_f) + ' feet by ' + str(width_f) + ' feet')
    num = 0
    while num != 4:
        print("Please select an option below: ")
        print("1. Check the safety of your boat")
        print("2. Check the maximum number of people that can fit on the boat")
        print("3. Update the position of your boat")
        print("4. Exit boat menu")
        num = int(input("Your selection: "))
        if num == 1:
            print(check_safety(latitude, longitude))
        elif num == 2:
            adults = int(input('How many adults go on the boat? '))
            can_fit = passengers_on_boat(length_f, width_f, adults)
            if can_fit:
                print('Your boat can hold ' + str(adults) + ' adults')
            else:
                print('Your boat cannot hold that many adults.')
        elif num == 3:
            latitude, longitude = wave_hit_vessel(latitude, longitude)
            print('Your new position is latitude of ' + str(latitude) + 
                  ' and longitude of ' + str(longitude))
    print('End of boat menu.')
