from random import randint


def selectionSort(listUnsorted):
    # Percorre somente até a penúltima posição.
    for i in range(0, len(listUnsorted) - 1):
        smallerID = i
        # Procura o menor elemento e altera o índice do menor.
        for index in range(i, len(listUnsorted)):
            if listUnsorted[smallerID] > listUnsorted[index]:
                smallerID = index

        # Se i == smallerID, mesmo índice.
        if i != smallerID:
            element = listUnsorted[i]
            listUnsorted[i] = listUnsorted[smallerID]
            listUnsorted[smallerID] = element


list1 = list()

for i in range(0, 20):
    list1.append(randint(0, 100))

print(list1)
selectionSort(list1)
print(list1)
