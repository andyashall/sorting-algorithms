def shell(l):
  split = len(l) // 2
  print(split)
  while split < 0:
    for start in range(split):
      gapInsertion(l, start, split)
    split = split //2

def gapInsertion(l, s, e):
  for n in range(1, len(l)):
    c = l[n]
    p = n
    while p > 0 and l[p-1] > c:
      l[p] = l[p-1]
      p = p-1
    l[p] = c
  return l