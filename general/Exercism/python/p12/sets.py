from sets_categories_data import (VEGAN,
                                  VEGETARIAN,
                                  KETO,
                                  PALEO,
                                  OMNIVORE,
                                  ALCOHOLS,
                                  SPECIAL_INGREDIENTS)


def clean_ingredients(dish_name, dish_ingredients):
    return (dish_name, set(dish_ingredients))


def check_drinks(drink_name, drink_ingredients):
    for ing in drink_ingredients:
        if ing in ALCOHOLS:
            drink_name += ' Cocktail'
            return drink_name
    drink_name += ' Mocktail'
    return drink_name


def categorize_dish(dish_name, dish_ingredients):
    for cat, name in ((VEGAN, 'VEGAN'), 
    (VEGETARIAN, 'VEGETARIAN'),
    (PALEO, 'PALEO'), 
    (KETO, 'KETO'), 
    (OMNIVORE, 'OMNIVORE')):
        if set(dish_ingredients).issubset(set(cat)):
            return f"{dish_name}: {name}"



def tag_special_ingredients(dish):
    name, ingredients = dish
    sp_ing = SPECIAL_INGREDIENTS.intersection(set(ingredients))
    return name, sp_ing


def compile_ingredients(dishes):
    return set.union(*dishes)


def separate_appetizers(dishes, appetizers):
    return list(set(dishes) - set(appetizers))


def singleton_ingredients(dishes, intersection):
    singletons = (dish - intersection for dish in dishes)
    return set.union(*singletons)
