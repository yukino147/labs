import numpy as np
n = 0
while(True):
    n = int(input())
    if (n>3):
        break
    else: 
        print("try again:")
m = np.zeros((n, n, n))

for a in range (n):
    m[a,a,a] = 1; 

print(m)