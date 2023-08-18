def classify(number):
    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")
    divisors = []
    for i in range(1, number):
        if number % i == 0:
            divisors.append(i)
    if sum(divisors) == number:
        return 'perfect'
    if sum(divisors) > number:
        return 'abundant'
    return 'deficient'