def is_criticality_balanced(temperature, neutrons_emitted):
    cond1 = temperature < 800
    cond2 = neutrons_emitted > 500
    cond3 = temperature * neutrons_emitted < 500000
    if (cond1 and cond2 and cond3):
        return True
    return False


def reactor_efficiency(voltage, current, theoretical_max_power):
    generated_power = voltage * current
    percPower = (generated_power / theoretical_max_power)*100

    if percPower >= 80:
        return 'green'
    elif percPower >= 60:
        return 'orange'
    elif percPower >= 30:
        return 'red' 
    else:
        return 'black'


def fail_safe(temperature, neutrons_produced_per_second, threshold):
    val = temperature * neutrons_produced_per_second
    if val < threshold * 0.90:
        return 'LOW'
    elif threshold * 0.90 <= val <= threshold * 1.1:
        return 'NORMAL'
    return 'DANGER'

