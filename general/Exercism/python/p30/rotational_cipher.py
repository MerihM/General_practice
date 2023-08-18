import string
def rotate(text, key):
    letters = list(string.ascii_lowercase)
    length = len(letters)
    special_char = list(string.punctuation)
    special_char.append(' ')
    for i in range(10):
        special_char.append(str(i))
    rot_text = ''
    for i in text:
        if i in special_char:
            rot_text += i
            continue
        if i.isupper():
            index = letters.index(i.lower()) + key
            rot_text += letters[index % length].upper()
        else:
            index = letters.index(i) + key
            rot_text += letters[index % length]
    return rot_text