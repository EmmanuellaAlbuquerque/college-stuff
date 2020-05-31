class LRU:

    def __init__(self, sequence):
        self.sequence = sequence[1:]
        # Memory frames available in RAM
        self.memoryFrame = list()
        self.lruOnSequence = list()
        self.limitFrame = sequence[0]
        self.faultsPage = 0

    def setSequence(self, sequence):
        self.sequence = sequence

    def getSequence(self):
        return self.sequence

    def runsLru(self):

        for i in range(0, len(self.sequence)):
            # before filling the frame limit
            if len(self.memoryFrame) < self.limitFrame and self.sequence[i] not in self.memoryFrame:
                self.memoryFrame.append(self.sequence[i])
                self.lruOnSequence.insert(0, self.sequence[i])
                self.faultsPage += 1
            # after filling the frame limit
            else:
                # updates the recently used
                if self.sequence[i] in self.lruOnSequence:
                    self.lruOnSequence.remove(self.sequence[i])
                    self.lruOnSequence.insert(0, self.sequence[i])

                # adding a new ref that is not in memory
                if self.sequence[i] not in self.memoryFrame:

                    # make sure to remove references that are no longer in the frame
                    while self.lruOnSequence[-1] not in self.memoryFrame:
                        self.lruOnSequence.remove(self.lruOnSequence[-1])

                    # new sequence element is added in place of the least recently used
                    subsPosition = self.memoryFrame.index(self.lruOnSequence[-1])
                    self.memoryFrame[subsPosition] = self.sequence[i]
                    self.faultsPage += 1

                    # updates the LRU list with new elements of the sequence
                    if self.sequence[i] not in self.lruOnSequence:
                        self.lruOnSequence.insert(0, self.sequence[i])

        print(f'LRU {self.faultsPage}')
