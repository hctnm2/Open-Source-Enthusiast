import numpy as np
from math import sin, cos

#Making an empty list with 3 elements
n = 3
x = np.zeros(n)

#Setting x[0] to the value 3.14
x[0] = 3.14

#Printing out x[0]
print (f"The value for x(0) = {x[0]}")

#Defining the function f(x)=sin(x)
def f(x):
    return (sin(x))

#Defining the derivative for f(x) which is f'(x) = cos(x)
def derivative_f(x):
    return (cos(x))

#Calculating the values for x(1) and x(2) using previous values as well as Newtons method
for i in range(1,n):
    x[i]= (x[i-1]) - ((f(x[i-1]))/(derivative_f(x[i-1])))
    print (f"The value for x({i}) = {round(x[i], 13)}")
    
#Printing out numpy.pi with 13 decimals to compare with x(2)
print (f"The value of np.pi = {round(np.pi, 13)}")
