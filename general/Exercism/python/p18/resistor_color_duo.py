def value(colors):
    first = colors[0]
    second = colors[1]
    color = [
        'black',
        'brown',
        'red',
        'orange',
        'yellow',
        'green',
        'blue',
        'violet',
        'grey',
        'white'
    ]
    first = color.index(first) * 10
    second = color.index(second)
    return first+second