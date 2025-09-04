import math

def f_derivate(f, x, epsilon=1e-3):
    # Utilizando la definición de la derivada
    y_approx = (f(x + epsilon) - f(x)) / epsilon
    # Comparando con la derivada exacta

    return y_approx

# Definición de las funciones
def f1(x):
    return x**2 - 2*x + 1

def f1_prime(x):
    return 2*x - 2


# Pruebas de las funciones
print("\n*** Testing f_derivate ***\n")
x = 5
print("Test Case 1: f(x) = x**2 - 2x + 1, x = 5, epsilon=10^-6:", f1_prime(x), f_derivate(f1, x, 1e-10))
print()


def f2(x):
    return math.sin(x)**2

def f2_prime(x):
    return 2*math.sin(x)*math.cos(x)

x = 5
print("Test Case 2: f(x) = sin(x)^2, x = 5, epsilon=10^-6:", f2_prime(x), f_derivate(f2, x, 1e-10))
print()
