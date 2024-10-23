
def main():
  a = []

  for i in range(10):
    j = 0
    
    def alt(): # Cmp to JavaScript
      nonlocal j # Try commenting out nonlocal / replace with global
      j = j+1
      print(j)
    
    e = lambda : print(j) # no multiple statments possible
    a.append(alt)

  for f in a:
    f()

main()


