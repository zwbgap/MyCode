import turtle as tu
import math
print("Please enter the three sides of the triangle:")
a = float(input("one: "))
b = float(input("two: "))
c = float(input("three: "))

if a*b*c > 0:
    if a+b>c and b+c>a and a+c>b:
        h = (a + b + c) / 2.0
        C = a + b + c
        S = math.sqrt(h*(h-a)*(h-b)*(h-c))
        print(f'The three sides of the triangle are:\na = {a}, b = {b}, c = {c}')
        print(f'The perimeter of the triangle is: {C}')
        print('The area of triangle is: {:.2f}'.format(S))
        A = math.degrees(math.acos((a*a-b*b-c*c)/(-2*b*c)))  #求角A
        B = math.degrees(math.acos((b*b-a*a-c*c)/(-2*a*c)))  #求角B
        C = math.degrees(math.acos((c*c-a*a-b*b)/(-2*a*b)))  #求角C
        tu.hideturtle()
        tu.color('red')
        tu.begin_fill()
        tu.write('A')     
        tu.fd(a * 20)
        tu.left(180-C)
        tu.write('B')
        tu.fd(b * 20)
        tu.left(180-A)
        tu.write('C')
        tu.fd(c * 20)
        tu.end_fill()
        tu.left(B+90)
        tu.rt(90)
        tu.pu()
        tu.fd(30)
        tu.color('black')
        tu.write('The area of triangle is: {:.2f}'.format(S),False,'left',18)
        tu.done()

    else:
        tu.hideturtle()
        tu.color('black')
        tu.write("can not form a triangle with these numbers\n\t(不能构成三角形)",False,'center',18)
        tu.done()
        print("can not form a triangle with these numbers")
       
else:
    tu.hideturtle()
    tu.color('black')
    tu.write("can not form a triangle with these numbers\n\t(不能构成三角形)",False,'center',18)
    tu.done()
    print("can not form a triangle with these numbers")
