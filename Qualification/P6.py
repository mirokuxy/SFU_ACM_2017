import sys, collections

is_first = True
for line in sys.stdin:
  stripped = line.strip()

  count = collections.defaultdict(int)
  for ch in stripped:
    count[ord(ch)] += 1
  
  tuples = []
  for ch, frequency in count.items():
    tuples.append((frequency, -ch))
  tuples.sort()

  if is_first:
    is_first = False
  else:
    print('')

  for (frequency, ch) in tuples:
    print(-ch, frequency)

