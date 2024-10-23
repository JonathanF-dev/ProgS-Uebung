
class UnevenIterator:
  def __init__(self, a, b):
    self.nextValue = a
    self.maxValue = b

  def __iter__(self):
    return self

  def __next__(self):
    while self.nextValue <= self.maxValue:
      current = self.nextValue
      self.nextValue = self.nextValue + 1
      if current % 2 != 0:
        return current
    raise StopIteration

def UnevenIteratorWithGenerator(a,b):
  nextValue = a
  while nextValue <= b:
    if nextValue % 2 != 0:
      yield nextValue
    nextValue = nextValue + 1

for v in UnevenIterator(1,10):
  print(v)

print("****")

for v in UnevenIteratorWithGenerator(1,10):
  print(v)
