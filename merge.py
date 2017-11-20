def merge(l):
  if len(l) > 1:
    split = len(l) // 2
    left = l[:split]
    right = l[split:]
    merge(left)
    merge(right)
    i, j, k = 0, 0, 0
    while i < len(left) and j < len(right):
      if left[i] < right[j]:
        l[k] = left[i]
        i+=1
      else:
        l[k] = right[j]
        j+=1
      k+=1
    while i < len(left):
      l[k]=left[i]
      i+=1
      k+=1
    while j < len(right):
      l[k]=right[j]
      j+=1
      k+=1
  return l

def split(l):
  if len(l) > 1:
    split = len(l) // 2
    left = l[0:split]
    right = l[split:len(l)]
    return left, right