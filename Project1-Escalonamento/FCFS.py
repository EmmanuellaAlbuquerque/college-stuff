from resources import utils
import sys


def executeFCFS(entry, execution):
    """
    First to Enter, First to be Served.
    Get the first and add to a execution list
    of process.
    :param entry: input processes
    :param execution: processes in exec
    :return: none
    """
    entryProcess = entry[0]
    smallerArrival = entry[0]['arrival']

    while len(entry) > 0:

        # get the smallerArrival and put in order
        for items in entry:
            if smallerArrival > items['arrival']:
                smallerArrival = items['arrival']
                entryProcess = items

        # add on execution
        element = dict({'process': entryProcess['process'],
                        'begin': entryProcess['arrival'],
                        'end': entryProcess['peak']})
        execution.append(element)
        entry.remove(entryProcess)

        # resets to find again the smallest
        if len(entry) != 0:
            entryProcess = entry[0]


# -------------------------------------------------- MAIN --------------------------------------------------------
entry = list()
entryList = list()
features = list()
execution = list()

# read the file with the process information
if not utils.readfile(features, entry, entryList):
    sys.exit()

# run FCFS
executeFCFS(entry, execution)

# calculates the beginning and end of the processes to be executed
utils.calculateExecution(execution)

# calculating the metrics
metricsValues = list()
timeAnswer = list()
timeReturn = list()
timeWait = list()

# calculates the Answer and Return times.
i = 0
for items in execution:
    resultAnswer = items['begin'] - entryList[i]['arrival']
    resultReturn = items['end'] - entryList[i]['arrival']
    i = i + 1
    timeAnswer.append(resultAnswer)
    timeReturn.append(resultReturn)

# FCFS peculiarity
timeWait = timeAnswer

# given the values, calculated metrics
metricsValues.append(timeReturn)
metricsValues.append(timeAnswer)
metricsValues.append(timeWait)

utils.calculateMetrics(metricsValues, 'FCFS', entryList)
