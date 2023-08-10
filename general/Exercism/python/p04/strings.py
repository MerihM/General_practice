def add_prefix_un(word):
    return "un" + word


def make_word_groups(vocab_words):
    new = vocab_words[1:]
    for index, word in enumerate(new):
        new[index] = vocab_words[0] + word

    new.insert(0, vocab_words[0])
    return " :: ".join(new)


def remove_suffix_ness(word):
    new = word.split('ness')[0]
    if new[-1] == 'i':
        new = new[:-1] + 'y'
    return new


def adjective_to_verb(sentence, index):
    if sentence.split()[index][-1] == '.':
        return sentence.split()[index][:-1] + 'en'
    return sentence.split()[index] + 'en'
