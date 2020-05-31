from math import inf


class OTM:

    def __init__(self, sequence):
        self.sequence = sequence[1:]
        # Memory frames available in RAM
        self.memoryFrame = list()
        self.limitFrame = sequence[0]
        self.faultsPage = 0

    def setSequence(self, sequence):
        self.sequence = sequence

    def getSequence(self):
        return self.sequence

    def runsOtm(self):
        position = [inf]*self.limitFrame
        for i in range(0, len(self.sequence)):
            # before filling the frame limit
            if len(self.memoryFrame) < self.limitFrame and self.sequence[i] not in self.memoryFrame:
                self.memoryFrame.append(self.sequence[i])
                self.faultsPage += 1
            # after filling the frame limit
            else:
                pos = 0
                if self.sequence[i] not in self.memoryFrame:

                    foundValue = list()
                    while pos < self.limitFrame:
                        for index in range(i + 1, len(self.sequence)):

                            if self.memoryFrame[pos] == self.sequence[index]:
                                position[pos] = index
                                foundValue.append(pos)
                                break

                        # counter for memoryFrame
                        pos += 1

                    # with the required number of positions you can
                    # take the value that will take the longest to enter the memory
                    maxPos = max(position)
                    refPos = position.index(maxPos)
                    posMemoryFrame = refPos
                    self.memoryFrame[posMemoryFrame] = self.sequence[i]

                    # Page fault for big distance
                    self.faultsPage += 1
                    position = [inf]*self.limitFrame

        print(f'OTM {self.faultsPage}')
