def readfile(features, entry, entryList):

    try:
        file = open('resources/processList.txt', 'r')
    except:
        print("Não foi possível encontrar o arquivo.")
        return False

    # break settings
    if file:
        for line in file:
            line = line.replace('\n', '')
            features.append(line.split(' '))

    # adds processes already in the form of a structure
    strProcess = 'p'
    i = 0
    for process in features:
        i = i + 1
        entry.append(dict({'process': strProcess + str(i), 'arrival': int(process[0]), 'peak': int(process[1])}))
        entryList.append(dict({'process': strProcess + str(i), 'arrival': int(process[0]), 'peak': int(process[1])}))
    return True


def calculateMetrics(metricsValues, processName, entryList):

    # calculates values
    soma = 0
    metricsAverages = list()
    for items in metricsValues:
        for value in items:
            soma = soma + value
        metricsAverages.append(soma / len(entryList))
        soma = 0

    # shows on the screen
    print(f'{processName} ', end='')
    for average in metricsAverages:
        strValue = str(round(average, 1))
        print(f'{strValue.replace(".", ",")} ', end='')


def calculateExecution(execution):

    # reshapes arrival and output times
    previousItem = execution[0]
    for items in execution:
        if items['process'] != execution[0]['process']:
            items['begin'] = previousItem['end']
            items['end'] = items['end'] + items['begin']
        previousItem = items


# processIds:
# [[{'process': 'p1', 'begin': 0, 'end': 2}, {'process': 'p1', ...
# [{'process': {'process': 'p2', ' {'process': 'p3', 'begin': 22, 'end': 24}], ...
# [{'process': 'p4', 'begin': 8, 'end': 10}, {'process': 'p4', 'begin': 16, 'end': 18}.
def createExecutionList(entryList, processIDs, execution):

    # create a list for every process and put in a list
    for element in entryList:
        process = list()
        for j in range(0, 1):
            process.append(element)
            processIDs.append(process)

    # create a personalized list with every execution time feature
    for processList in processIDs:
        for value in execution:
            if processList[0]['process'] == value['process']:
                processList.append(value)

    # remove the aux default
    for processList in processIDs:
        processList.remove(processList[0])


def getWaitingTime(processIDs, timeWait):

    # calculating the waiting time in the ready queue
    auxBegin = list()
    auxEnd = list()
    processBegin = list()
    processEnd = list()

    # takes the start and end times of the process
    for index in processIDs:
        for element in index:
            auxBegin.append(element['begin'])
            auxEnd.append(element['end'])
        processBegin.append(auxBegin[:])
        processEnd.append(auxEnd[:])
        auxBegin.clear()
        auxEnd.clear()

    # calculates the waiting time with them(end and start times)
    soma = 0
    for process in range(0, len(processBegin)):
        for time in range(0, len(processBegin[process])):
            if time + 1 < len(processBegin[process]):
                soma = soma + (processBegin[process][time+1] - processEnd[process][time])
        timeWait.append(soma)
        soma = 0