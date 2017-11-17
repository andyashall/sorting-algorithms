def selection(l):
  for n in range(len(l) - 1, 0, -1):
    larg = n
    for i in range(n):
      if l[i] > l[larg]:
        larg = i
    l[n], l[larg] = l[larg], l[n]
  return l