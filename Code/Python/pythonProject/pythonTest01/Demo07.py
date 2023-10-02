import math

day_up_365 = math.pow((1 + 0.01), 365)


def day_up(df):
    dayup = 1.0
    for i in range(365):
        j = i % 7
        if j in range(1, 6):
            dayup *= (1 + df)
        else:
            dayup *= (1 - 0.01)
    return dayup


dayfactor = 0.01
while day_up(dayfactor) < day_up_365:
    dayfactor += 0.001
print("每天的努力参数应为：{:.3f}".format(dayfactor))

