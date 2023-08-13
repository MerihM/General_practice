def is_isogram(string):
    if len(string) == 0:
        return True
    contains = ''
    string = "".join(filter(str.isalpha, string)).lower()
    for l in string:
        if l in contains:
            return False
        contains += l
    return True
