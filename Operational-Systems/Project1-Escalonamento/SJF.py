from resources import utils
import sys


def executeSJF(entry, selection, execution):
    """
    Smallest Job first.
    :param entry: input processes
    :param selection: process with same arrival time
    :param execution: processes in exec
    :return: none
    """
    smallerProcess = entry[0]
    smallerArrival = entry[0]['arrival']

    # get the smallest arrival
    for items in entry:
        if smallerArrival > items['arrival']:
            smallerArrival = items['arrival']
            smallerProcess = items
    selection.append(smallerProcess)

    # get entry with same arrival, but different process.
    for item in entry:
        if smallerArrival == item['arrival'] and smallerProcess['process'] != item['process']:
            selection.append(item)

    # resets the smaller.
    smallerProcess = selection[0]
    smallerPeak = selection[0]['peak']

    while len(selection) != 0:

        # get the smallest peak and put it on the the execution list.
        for item in selection:
            if smallerPeak > item['peak']:
                smallerPeak = item['peak']
                smallerProcess = item
        element = dict({'process': smallerProcess['process'],
                        'begin': smallerProcess['arrival'],
                        'end': smallerProcess['peak']})
        execution.append(element)

        # remove because it has already been placed on the execution list.
        selection.remove(smallerProcess)
        entry.remove(smallerProcess)

        execTime = execution[len(execution) - 1]['end']
        # adds new processes given the new run time(current)
        for item in entry:
            if item['arrival'] <= execTime:
                selection.append(item)

        # list comprehension: remove duplicates
        selection = [i for n, i in enumerate(selection) if i not in selection[n + 1:]]

        # resets the values
        if len(selection) != 0:
            smallerProcess = selection[0]
            smallerPeak = selection[0]['peak']


# -------------------------------------------------- MAIN --------------------------------------------------------
entry = list()
entryList = list()
features = list()
execution = list()
selection = list()

# read the file with the process information
if not utils.readfile(features, entry, entryList):
    sys.exit()

# run SJF
executeSJF(entry, selection, execution)

# calculates the beginning and end of the processes to be executed
utils.calculateExecution(execution)

# calculating the metrics
metricsValues = list()
timeAnswer = list()
timeReturn = list()
timeWait = list()

arrivalTime = 0
for items in execution:
    # based on the order of execution, catch each process's arrival time.
    for element in entryList:
        if items['process'] == element['process']:
            arrivalTime = element['arrival']
            break

    # calculates the results for each process
    resultAnswer = items['begin'] - arrivalTime
    resultReturn = items['end'] - arrivalTime
    timeAnswer.append(resultAnswer)
    timeReturn.append(resultReturn)

processIDs = list()

# for calculating the waiting time
utils.createExecutionList(entryList, processIDs, execution)

# calculating the waiting time in the ready queue
utils.getWaitingTime(processIDs, timeWait)

# zip allows to join / merge two iterables
timeWait = [elemA + elemB for elemA, elemB in zip(timeWait, timeAnswer)]

# given the values, calculated metrics
metricsValues.append(timeReturn)
metricsValues.append(timeAnswer)
metricsValues.append(timeWait)

utils.calculateMetrics(metricsValues, 'SJF', entryList)
