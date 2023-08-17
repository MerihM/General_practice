def convert(number):
    ret_string = ''
    if number%3 == 0:
        ret_string += 'Pling'
    if number%5 == 0:
        ret_string += 'Plang'
    if number%7 == 0:
        ret_string += 'Plong'
    if ret_string == '':
        ret_string = str(number)
    return ret_string