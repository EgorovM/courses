import sys

digit_string = sys.argv[1]

print(sum(list(map(int, list(digit_string)))))
