print("a = ")
a = float(input()) #вводимо довжину a

print("b = ")
b = float(input()) #вводимо довжину b

print("c = ")
c = float(input()) #вводимо довжину b

#знаходимо косинуси та визначаємо типи кутів за розрахованим значенням
cosa = (b*b+c*c-a*a)/(2*b*c)
if cosa < 0:
    print('кут A - тупий')
elif cosa > 0:
    print('кут A - гострий')
else:
    print('кут A - прямий')

cosb = (a*a+c*c-b*b)/(2*a*c)
if cosb < 0:
    print('кут B - тупий')
elif cosb > 0:
    print('кут B - гострий')
else:
    print('кут B - прямий')    

cosc = (b*b+a*a-c*c)/(2*a*b)
if cosc < 0:
    print('кут C - тупий')
elif cosc > 0:
    print('кут C - гострий')
else:
    print('кут C - прямий')

    