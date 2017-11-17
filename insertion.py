def insertion(l):
  for n in range(1, len(l)):
    c = l[n]
    p = n
    while p > 0 and l[p-1] > c:
      l[p] = l[p-1]
      p = p-1
    l[p] = c
  return l