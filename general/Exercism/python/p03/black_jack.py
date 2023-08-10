def value_of_card(card):
    if card == 'K' or card == 'Q' or card == 'J': #if card in ('JKQ') 
        return 10
    elif card == 'A':
        return 1
    else: 
        return int(card)


def higher_card(card_one, card_two):
    if value_of_card(card_one) == value_of_card(card_two):
        return (card_one, card_two)
    elif value_of_card(card_one) > value_of_card(card_two):
        return str(card_one)
    else:
        return str(card_two)


def value_of_ace(card_one, card_two):
    if card_one == 'A' or card_two == 'A':
        return 1
    elif value_of_card(card_one) + value_of_card(card_two) > 10:
        return 1
    else:
        return 11


def is_blackjack(card_one, card_two):
    s = 0
    if card_two == 'A':
        s = (11 + value_of_card(card_one))
    elif card_one == 'A':
        s = (11 + value_of_card(card_two))
    else:
        s = (value_of_card(card_one) + value_of_card(card_two))
    
    if s >= 21:
        return True
    return False


def can_split_pairs(card_one, card_two):
    return (value_of_card(card_one) == value_of_card(card_two))


def can_double_down(card_one, card_two):
    s = value_of_card(card_one) + value_of_card(card_two)
    if s >=9 and s <=11:
        return True 
    return False