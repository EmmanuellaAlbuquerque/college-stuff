from resources import utils

quantum = 2


def executeRR(queue, execution, entry):
    """
    Round Robin.
    :param queue: queue of process
    :param execution: processes in exec
    :param entry: input processes
    :return: none
    """
    while len(queue) != 0:

        # adds process queue elements
        element = dict({'process': queue[0]['process'],
                        'begin': execution[len(execution) - 1]['end'],
                        'end': execution[len(execution) - 1]['end'] + quantum})
        execution.append(element)

        processQueue = queue[0]
        queue.remove(queue[0])
        elementsToRemove = list()

        execTime = execution[len(execution) - 1]['end']
        # adds new processes given the new run time(current)
        for item in entry:
            if item['arrival'] <= execTime:
                queue.append(item)
                elementsToRemove.append(item)

        # add a process in quantum size
        processQueue['peak'] = processQueue['peak'] - quantum
        if processQueue['peak'] > 0:
            queue.append(processQueue)

        # removes the add elements from the main list.
        for element in elementsToRemove:
            entry.remove(element)


def getSmaller(entry, queue, smallerArrival, smallerProcess):
    # get the smallest arrival and put it on the the queue.
    for items in entry:
        if smallerArrival > items['arrival']:
            smallerArrival = items['arrival']
            smallerProcess = items
    queue.append(smallerProcess)


def getSameEntry(entry, queue, smallerArrival, smallerProcess):
    # get entry with same arrival, but different process.
    for item in entry:
        if smallerArrival == item['arrival'] and smallerProcess['process'] != item['process']:
            queue.append(item)
            entry.remove(item)
    entry.remove(smallerProcess)


def addFirst(execution, queue, smallerProcess):

    element = dict({'process': smallerProcess['process'],
                    'begin': smallerProcess['arrival'],
                    'end': smallerProcess['arrival'] + quantum})
    execution.append(element)

    # Decrease the peak size and re-add it to the queue.
    queue.remove(smallerProcess)
    smallerProcess['peak'] = smallerProcess['peak'] - quantum
    queue.append(smallerProcess)


def rindex(lst, val):
    start = len(lst)-1
    # Scroll the list backwards if it is the same stop.
    for count in range(start, -1, -1):
        if lst[count] == val:
            return count


def labelsForMetrics(entryList, execution, arrivalTimes, firstCpuTime, finalizationTime):

    stringProcess = list()

    # calculates the results for each process
    for item in entryList:
        for value in execution:
            # add only the first time that appeared on the execution list
            if item['process'] == value['process']:
                arrivalTimes.append(item['arrival'])
                firstCpuTime.append(value['begin'])
                break

    # list of processes in order that have been executed
    for item in execution:
        stringProcess.append(item['process'])

    # Collects data to know(the time) when a process has finished running
    for element in entryList:
        lastOne = rindex(stringProcess, element['process'])
        finalizationTime.append(execution[lastOne]['end'])


# -------------------------------------------------- MAIN --------------------------------------------------------
entry = list()
entryList = list()
features = list()

# read the file with the process information
utils.readfile(features, entry, entryList)

smallerProcess = entry[0]
smallerArrival = entry[0]['arrival']
execution = list()
queue = list()

# add to queue
getSmaller(entry, queue, smallerArrival, smallerProcess)

# add same arrival or less
getSameEntry(entry, queue, smallerArrival, smallerProcess)

# First element
addFirst(execution, queue, smallerProcess)

# run RR
executeRR(queue, execution, entry)

# calculating the metrics
metricsValues = list()
timeAnswer = list()
timeReturn = list()
timeWait = list()
arrivalTimes = list()
firstCpuTime = list()
finalizationTime = list()

# time to calculate metrics
labelsForMetrics(entryList, execution,
                 arrivalTimes, firstCpuTime,
                 finalizationTime)

# calculating the answer and return time
i = 0
for element in arrivalTimes:
    timeAnswer.append(firstCpuTime[i] - element)
    timeReturn.append(finalizationTime[i] - element)
    i = i + 1

processIDs = list()

# for calculating the waiting time
utils.createExecutionList(entryList, processIDs, execution)

# calculating the waiting time in the ready queue
utils.getWaitingTime(processIDs, timeWait)

# zip allows to join / merge two iterables
timeWait = [elemA + elemB for elemA, elemB in zip(timeWait, timeAnswer)]

metricsValues.append(timeReturn)
metricsValues.append(timeAnswer)
metricsValues.append(timeWait)

utils.calculateMetrics(metricsValues, 'RR', entryList)

