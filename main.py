from time import time
from random import random

from bubble import bubble
from selection import selection
from quicksort import quicksort
from insertion import insertion
from shell import shell
from merge import merge

l = [int(1000*random()) for i in range(10000)]

start = time()

print(quicksort(l))

end = time()

print('Time taken: {0:.8f}'.format(end - start))