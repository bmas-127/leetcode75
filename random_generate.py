import numpy as np
import os

if(os.path.exists("record.npy")):
    lst = np.load("record.npy")
else:
    lst = [i for i in range(0, 76)]
    lst[0] = 75
    
ridx = np.random.randint(1, lst[0] + 1)
print(f"new question is {lst[ridx]}")

lst[ridx] = lst[lst[0]]
lst[0] -= 1

np.save("record.npy", lst[0:-1])
np.save("record_backup.npy", lst[0:-1])
