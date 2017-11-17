from bubble import bubble
import time

l = [4,3,2,6,5,4,9,8,7,5,4,3,1,10,7,2]

start = time.time()

print(bubble(l))

end = time.time()

print(f'Time taken: {end - start}')