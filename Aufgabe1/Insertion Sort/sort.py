x = [4,30,2,3,6,99,8,11,23]
def insertion_sort (x):
    for i in range(1, len(x)) :
        k = x[i]
        j = i - 1
        while(j >= 0 and x[j] > k):
            x[j+1] = x [j]
            j  -= 1
        x[j+1] = k
print(x)
insertion_sort (x)
print(x)
