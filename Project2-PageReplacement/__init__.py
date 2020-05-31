from resources import utils
from FIFO import FIFO
from OTM import OTM
from LRU import LRU

# Obtains the sequence of memory references
memoryREF = utils.readSequence()

# Execute FIFO substitution
fifoSubstitution = FIFO(memoryREF)
fifoSubstitution.runsFifo()

# Execute OTM substitution
otmSubstitution = OTM(memoryREF)
otmSubstitution.runsOtm()

# Execute LRU substitution
lruSubstitution = LRU(memoryREF)
lruSubstitution.runsLru()
