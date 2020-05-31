from random import randint


def bubbleSort(listUnsorted):
    for repetitiontime in range(0, len(listUnsorted)):
        # Ex.: if we have 5 elements: 5-> 4-> 3-> 2-> 1-> 0 repetitions of sorting.
        for index in range(0, len(listUnsorted) - repetitiontime):
            if (index+1) < len(listUnsorted) and listUnsorted[index] > listUnsorted[index+1]:
                element = listUnsorted[index]
                listUnsorted[index] = listUnsorted[index+1]
                listUnsorted[index+1] = element


list1 = list()

for i in range(0, 3):
    list1.append(randint(0, 100))

print(list1)
bubbleSort(list1)
print(list1)
