def round_scores(student_scores):
    for index, student in enumerate(student_scores):
        student_scores[index] = round(student)
    return student_scores


def count_failed_students(student_scores):
    ctr = 0
    for score in student_scores:
        if score <= 40:
            ctr += 1
    return ctr

def above_threshold(student_scores, threshold):
    best = []
    for score in student_scores:
        if score < threshold:
            continue
        best.append(score)
    return best


def letter_grades(highest):
    numDif = round((highest - 41)/4)
    thresholds = [41]
    while len(thresholds) < 4:
        thresholds.append(thresholds[len(thresholds)-1]+numDif)
    return thresholds



def student_ranking(student_scores, student_names):
    ranking = []
    for index, score in enumerate(student_scores):
        ranking.append(f"{index+1}. {student_names[index]}: {student_scores[index]}")
    return ranking


def perfect_score(student_info):
    for info in student_info:
        if (info[1] == 100):
            return info
    return []