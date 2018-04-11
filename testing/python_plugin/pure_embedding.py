import sys
print('\n'.join(sys.path))

def multiply(a,b):
    print("Will compute", a, "times", b)
    c = 0
    for i in range(0, a):
        c = c + b
    return c

def main():
    pass

if __name__ == '__main__':
    main()