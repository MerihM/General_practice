def create_inventory(items):
    ret_dict = {}
    for item in items:
        ret_dict[item] = items.count(item)
    return ret_dict


def add_items(inventory, items):
    for item in items:
        if item in inventory:
            inventory[item] += 1
        else:
            inventory[item] = 1
    return inventory
        


def decrement_items(inventory, items):
    for item in items:
        if inventory[item] == 0:
            continue
        inventory[item] -= 1
    return inventory


def remove_item(inventory, item):
    if item in inventory:
        inventory.pop(item)
    return inventory


def list_inventory(inventory):
    ret_arr = []
    for key, value in inventory.items():
        if value == 0:
            continue
        ret_arr.append((key, value))  
    return ret_arr
