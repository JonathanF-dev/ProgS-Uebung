
def Fibonacci():
  n = 1
  p1 = 0
  p2 = 0

  while True:
    curr = n
    p1 = n
    n = p1 + p2
    p2 = p1
    yield curr

cnt = 1

for i in Fibonacci():
  print(i)
  if cnt == 15:
    break
  cnt = cnt + 1
