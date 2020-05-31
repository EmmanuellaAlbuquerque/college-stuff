from random import randint


# del(), remove exatamente a posição.
# remove(), remove o 1° elemento igual que encontrar.

def insertionSort(listUnsorted):
    print(listUnsorted)
    for NormalIndex in range(1, len(listUnsorted)):  # Ex:. 1,2,3,4
        for DisorderedListIndex in range(0, NormalIndex):  # Ex:. 0 -> 0, 1 -> 0,1,2 -> 0,1,2,3...
            if listUnsorted[DisorderedListIndex] > listUnsorted[NormalIndex]:
                number = listUnsorted[NormalIndex]
                del(listUnsorted[NormalIndex])
                listUnsorted.insert(DisorderedListIndex, number)


list1 = list()

for i in range(0, 20):
    list1.append(randint(0, 100))

insertionSort(list1)
print(list1)
