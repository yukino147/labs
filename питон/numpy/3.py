import numpy as np
"""
n = 0
while(True):
    n = int(input("n: "))
    m = int(input("m: "))
    if (n>2 and m>2):
        break
    else: 
        print("try again:")
"""
n=3 
m=3     

#a_m array
a_m = np.array(int)
a_m = np.resize(a_m, (n,m))
a_m.fill(3)

#a_m array
b_m = np.array(int)
b_m = np.resize(b_m, (m+3,n)) # <------ 
b_m.fill(3)

multiply_ab = np.dot(a_m, b_m)

print(multiply_ab) 

# НЕ возможно т.к. количество столбцов матрицы А не равно количеству строк матрицы В
# ValueError: shapes (3,3) and (6,3) not aligned: 3 (dim 1) != 6 (dim 0)