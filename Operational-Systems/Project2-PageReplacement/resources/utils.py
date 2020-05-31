def readSequence():
    try:
        file = open('resources/sequence.txt', 'r')
    except:
        print("Não foi possível encontrar o arquivo!")
        return False

    sequenceList = list()
    # break settings
    if file:
        for line in file:
            line = line.replace('\n', '')

            try:
                line = int(line)
            except ValueError:
                print(f'Erro de valor! Adicione um valor válido!')
                return False

            sequenceList.append(line)
    return sequenceList
