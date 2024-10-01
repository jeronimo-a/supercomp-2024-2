import random

AMOUNT  = 24

with open("numeros.txt", "w") as file:
    file.write(str(AMOUNT) + "\n")
    file.write("1\n")
    for i in range(AMOUNT):
        numero = int(random.uniform(2, 20))
        file.write(str(numero) + "\n")