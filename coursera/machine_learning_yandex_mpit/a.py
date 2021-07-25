t = int(input())

for _ in range(t):
    l = input()

    ones = [0 for i in range(10)]

    val = 0

    for char in l:
        ones[ord(char) - ord('0')] += 1

        val = max(val, ones[ord(char) - ord('0')])

    for i in range(10):
        if ones[i] > val // 2:
            for j in range(10):
                if i != j and ones[j] > val // 2:
                    a = False
                    b = 0

                    for k in range(len(l)):
                        if a == False and ord(l[k]) - ord('0') == i:
                            a = True

                        if a and ord(l[k]) - ord('0') == j:
                            a = False
                            b += 2

                    val = max(val, b)

    print(len(l) - val)
