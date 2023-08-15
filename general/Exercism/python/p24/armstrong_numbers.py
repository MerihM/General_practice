def is_armstrong_number(number):
    list_of_digits = [int(i) for i in str(number)]
    for i, digit in enumerate(list_of_digits):
        list_of_digits[i] = pow(digit, len(list_of_digits))
    return sum(list_of_digits) == number