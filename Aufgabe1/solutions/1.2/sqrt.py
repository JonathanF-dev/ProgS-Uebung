

def sqrt_newton(x):
  EPS = 0.000001
  MI  = 10000

  iter     = 0
  estimate = 1.0

  while (abs(estimate*estimate - x) > EPS and iter < MI):
    estimate = 0.5*(estimate + x/estimate)
    iter = iter + 1

  return estimate

x = input("Bitte geben Sie eine Zahl ein: ")
print("Die Wurzel aus " + x + " ist: " + str(sqrt_newton(float(x))))