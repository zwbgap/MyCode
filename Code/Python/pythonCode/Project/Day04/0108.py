
while(True):
    str1 = input("Please enter your number: ")
    a = len(str1)
    if a == 18 and (str1[a-1].isdigit() or str1[a-1] == 'X'):
        print("true")
    else:
        print("false")