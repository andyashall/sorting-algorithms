def shell(l):
  split = len(l) // 2
  while split > 0:
    for start in range(split):
      gapInsertion(l, start, split)
    split = split // 2
  return l

def gapInsertion(l, s, e):
  for n in range(s+e, len(l), e):
    c = l[n]
    p = n
    while p >= e and l[p-e] > c:
      l[p] = l[p-e]
      p = p-e
    l[p] = c
  return l