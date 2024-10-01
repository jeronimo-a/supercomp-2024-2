import random

AMOUNT  = 100

with open("numeros.txt", "w") as file:
    file.write(str(AMOUNT) + "\n")
    file.write(str(int(random.uniform(10000, 100000000))) + "\n")
    for i in range(AMOUNT):
        numero = int(random.uniform(1, 10000))
        file.write(str(numero) + "\n")