class FIFO:

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

    def runsFifo(self):
        firstIn = 0
        for ref in self.sequence:
            # before filling the frame limit
            if len(self.memoryFrame) < self.limitFrame and ref not in self.memoryFrame:
                self.memoryFrame.append(ref)
                self.faultsPage += 1
            # after filling the frame limit
            else:
                if ref not in self.memoryFrame:
                    # Update after removing all F.I.
                    if firstIn == self.limitFrame:
                        firstIn = 0

                    # Performs the replacement
                    self.memoryFrame[firstIn] = ref
                    firstIn += 1
                    self.faultsPage += 1

        print(f'FIFO {self.faultsPage}')
