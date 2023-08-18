def to_rna(dna_strand):
    dna_rna_pairs = {
        'G':'C',
        'C':'G',
        'T':'A',
        'A':'U'
    }
    strand = ''
    for i in dna_strand:
        strand += dna_rna_pairs[i]
    return strand