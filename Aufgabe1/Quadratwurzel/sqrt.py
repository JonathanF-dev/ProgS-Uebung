import math

percision = 0.000001

def newton_sqrt(x):
    xn = 1.0
    while(abs(xn*xn - float(num)) > percision):
        xn = 0.5*(xn + x/xn)
    return xn

num = input("Bitte gib eine Zahl ein")
print ("Die Wurzel aus " + num + " ist " + str(newton_sqrt(float(num))))