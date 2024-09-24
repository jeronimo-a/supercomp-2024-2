import random

VECTOR_SIZE = 10000000
MEAN_VALUE  = 0
STD_DEV     = 300

with open("vetor.txt", "w") as file:
    file.write(str(VECTOR_SIZE) + "\n")
    for i in range(VECTOR_SIZE):
        random_number = random.gauss(MEAN_VALUE, STD_DEV)
        file.write(str(random_number) + "\n")
    