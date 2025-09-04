import sympy as sp

# Definir la variable simbólica
x = sp.Symbol('x')

# Definir la función
f = (2/3) * x**3 - (7/4) * x**2 + (3/2) * x + 1

# Calcular la primera derivada
f_prime = sp.diff(f, x)

# Encontrar los puntos críticos (donde la primera derivada es cero)
critical_points = sp.solve(f_prime, x)

# Calcular la segunda derivada
f_double_prime = sp.diff(f_prime, x)

# Mostrar los puntos críticos
print("Puntos críticos:", critical_points)

# Evaluar la segunda derivada en los puntos críticos
for point in critical_points:
    second_derivative_value = f_double_prime.subs(x, point)
    if second_derivative_value > 0:
        print("El punto", point, "es un mínimo.")
    elif second_derivative_value < 0:
        print("El punto", point, "es un máximo.")
    else:
        print("No se puede determinar si el punto", point, "es un máximo o un mínimo.")
