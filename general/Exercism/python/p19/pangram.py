def is_pangram(sentence):
    if len(sentence) == 0:
        return False
    contains = ''
    sentence = "".join(filter(str.isalpha, sentence)).lower()
    for l in sentence:
        if l not in contains:
            contains +=  l
    return len(contains) == 26
