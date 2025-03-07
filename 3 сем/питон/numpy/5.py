import numpy as np

while(True):
    n = int(input("n: ")) #str
    m = int(input("m: ")) #stb
    if (n>2 and m>2):
        break
    else: 
        print("try again:")
A = np.zeros((n, m))

#границы
for i in range(0, n):
    for j in range(0, m):
        if(i == 0 or i == n-1 or j == 0 or j == m-1):
            A[i,j]=1

print (A)

while(True):
    k = int(input("k: "))-1
    v = int(input("v: "))-1
    if (k>0 and v>0):
        break
    else: 
        print("try again:")

#заполнеие v k
for i in range(0, n):
    for j in range(0, m):
        if(i%k==0 or j%v==0):
            A[i,j]=1

print(A)