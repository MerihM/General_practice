def get_coordinate(record):
    return record[1]


def convert_coordinate(coordinate):
    return tuple(coordinate)


def compare_records(azara_record, rui_record):
    return azara_record[1] == rui_record[1][0] + rui_record[1][1]


def create_record(azara_record, rui_record):
    if compare_records(azara_record, rui_record):
        return azara_record + rui_record
    return 'not a match'


def clean_up(combined_record_group):
    cleaned_string = ''
    for record in combined_record_group:
        cleaned_string += str(record[:1] + record[2:]) + "\n"
    return cleaned_string
