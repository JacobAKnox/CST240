#!/bin/python3.11

# Jacob Knox CST 240 HW6 3/1/2023

def main():
    # Get the temperature to convert
    start_temp = input("Enter a temperature to convert (e.g. 45F, 10c, etc.): ")
    # Get the units
    units = start_temp[-1]

    # Convert the temperature to an integer
    temp = 0
    try:
      # eveyrthing but the last character should be the number
      temp = int(start_temp[:-1])
    except ValueError:
      # if the conversion fails, entered value is not a number
      print("Invalid temperature, please use a number followed by a unit.")
      exit()

    if units == "F" or units == "f":
        # Convert to Celsius and print
        celsius = (temp - 32) * 5/9
        print("The temperature is", celsius, "degrees Celsius.")
    elif units == "C" or units == "c":
        # Convert to Fahrenheit and print
        fahrenheit = (temp * 9/5) + 32
        print("The temperature is", fahrenheit, "degrees Fahrenheit.")
    else:
        # Invalid units
        print("Invalid units, please use C, c, F, or f.")
        exit()

# Run the program
if __name__ == "__main__":
    main()
