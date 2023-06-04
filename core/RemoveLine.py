lines = []
f = open("SUB.cpp")
for line in f:
    if not "#line" in line:
        lines.append(line)
f.close()

f = open("SUB.cpp","w")
for line in lines:
    f.write(line)
f.close()
