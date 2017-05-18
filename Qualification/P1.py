import sys

for line in sys.stdin:
  stripped = line.strip()
  if not stripped: break

  inputs = list(map(int, stripped.split()))
  a = inputs[0]
  b = inputs[1]
  c = a if a > b else b
  print(c)
