def quicksort(l):
  return qs(l, 0, len(l)-1)

def qs(arr, left, right):
  if left < right:
    parti = partition(arr, left, right)
    qs(arr, left, parti - 1)
    qs(arr, parti + 1, right)
  return arr

def partition(arr, left, right):
  l = left+1
  r = right
  done = False
  while not done:
    while l <= r and arr[l] <= arr[left]:
      l = l + 1
    while arr[r] >= arr[left] and r >= l:
      r = r - 1
    if r < l:
      done = True
    else:
      swap(arr, l, r)
  swap(arr, left, r)
  return r

def swap(arr, i, j):
  arr[i], arr[j] = arr[j], arr[i]
  return arr