def is_valid(isbn):
    clear_str = ''.join(filter(str.isalnum, isbn)).lower()
    if len(clear_str) < 10 or len(clear_str) > 10:
        return False
    valid_identifiers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    result = 0
    ctr = 10
    for i in range(0, len(clear_str)-1):
        if clear_str[i] not in valid_identifiers:
            return False
        result += int(clear_str[i]) * ctr
        ctr -=1
    valid_identifiers.append('x')
    if clear_str[-1] not in valid_identifiers:
        return False
    else:
        if clear_str[-1] == 'x':
            result += 10 * ctr
        else:
            result += int(clear_str[-1]) * ctr
    return result % 11 == 0

    pass

is_valid('3-598-21508-8')