
from cs50 import get_int

height = get_int("Enter a height: ")

while (height <= 0 or height >= 9):
    height = get_int("Enter a height: ")


def prymid(num):
    for i in range(num):
        for j in range(i+1, num):
            print(' ', end='')
        for j in range(i+1):
            print('#', end='')
        print()


prymid(height)
