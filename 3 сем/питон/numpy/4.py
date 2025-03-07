import numpy as np
import random
# n = size matrix

values= input()
n, dtp = values.split()
n = int(n)

if(n>0 and (dtp == "int" or dtp == "bool" or dtp == "float")):
    A = np.array([], dtype = dtp)
    A.resize(n)
    if(dtp == "int"):
        for i in range(n):
            A[i] = random.randint(-100, 100)
    if(dtp == "bool"):
        for i in range(n):
            A[i] = random.randint(0, 1)
    if(dtp == "float"):
        for i in range(n):
            A[i] = random.random()
    print(A, A.dtype)

elif(n < (-2) and (dtp == "int" or dtp == "bool" or dtp == "float")):
    n = abs(n)
    A = np.array([], dtype = dtp)
    A.resize(n, n)
    for i in range(n):
        for j in range(n):
            if (i==0 or i == (n-1) or j==0 or j==(n-1)):
                if(dtp == "int"):
                    A[i, j] = random.randint(-100, 100)
                if(dtp == "bool"):
                    A[i, j] = random.randint(0, 1)
                if(dtp == "float"):
                    A[i, j] = random.random()
    print(A, A.dtype)

else:
    print("Error")