def get_rounds(number):
    return [number, number+1, number+2]


def concatenate_rounds(rounds_1, rounds_2):
    return rounds_1 + rounds_2


def list_contains_round(rounds, number):
    return number in rounds


def card_average(hand):
    return sum(hand)/len(hand)


def approx_average_is_average(hand):
    cond1 = ((hand[0]+hand[-1])/2) == card_average(hand)
    cond2 = (hand[int(len(hand)/2)]) == card_average(hand)
    return cond1 or cond2


def average_even_is_average_odd(hand):
    cond1 = hand[0::2] 
    cond2 = hand[1::2]
    return card_average(cond1) == card_average(cond2)


def maybe_double_last(hand):
    if hand[-1] == 11:
        hand[-1] *=2
    return hand
