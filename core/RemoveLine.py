import sys

def main(filename):
    lines = []
    f = open(filename)
    for line in f:
        if not "#line" in line:
            lines.append(line)
    f.close()
    
    f = open(filename,"w")
    for line in lines:
        f.write(line)
    f.close()

if __name__ == '__main__':
    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        filename = "SUB.cpp"
    main()
