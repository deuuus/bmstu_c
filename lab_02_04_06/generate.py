from random import randint

N = 10000

a = []
a.append(str(N))

file = open("test.txt", "w")

for i in range(N):
    a.append(str(randint(0, 10000)))

file.write(" ".join(a))
file.close()
