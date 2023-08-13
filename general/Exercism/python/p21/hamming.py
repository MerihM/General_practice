def distance(strand_a, strand_b):
    if len(strand_a) != len(strand_b):
        raise ValueError("Strands must be of equal length.")
    if strand_b == strand_a:
        return 0
    ctr = 0
    for i in range(len(strand_a)):
        if strand_a[i] != strand_b[i]:
            ctr += 1
    return ctr
