from bubble import bubble
from selection import selection
from quicksort import quicksort
from insertion import insertion
import time

l = [4,3,2,6,5,4,9,8,7,5,4,3,1,10,7,2]

start = time.time()

print(insertion(l))

end = time.time()

print('Time taken: {0:.8f}'.format(end - start))