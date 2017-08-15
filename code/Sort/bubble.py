#Implementing Bubble Sort in Python

def bubbleSort(vetor):

    for i in range(len(vetor)-1,0,-1):
        for j in range(0,i):
            if vetor[j] > vetor[j+1]:
                aux = vetor[j]
                vetor[j] = vetor[j+1]
                vetor[j+1] = aux

    return vetor

v = [2,3,1,0,9,5]
v = bubbleSort(v)
print v
