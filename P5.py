import numpy as np

def evalpolynomial(degree):
    coeffpolynomial = np.array([])
    for i in range(degree+1):
        coeff = float(input(f'Enter the coefficient of x^{i} : '))
        coeffpolynomial = np.append(coeffpolynomial , coeff)
    print("\nCoefficients : ",coeffpolynomial)
    x = float(input('\nEnter the value of the variable for which the value of the polynomial is to be found : '))
    value = 0
    for i in range(degree+1):
        value += coeffpolynomial[i]*(x**i)
    print(f'Value of the polynomial with coefficients {coeffpolynomial} at {x} : ',value)

#main
degree = int(input("Enter the highest degree of your polynomial : "))
print()
evalpolynomial(degree)
