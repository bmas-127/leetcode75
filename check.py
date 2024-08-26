import numpy as np

a = np.load("record.npy")

arr = a[1:a[0]+1]

s = np.sort(arr)

for i in s:
    print(i, end=" ")
print()


print(a[0])
print(np.average(s))