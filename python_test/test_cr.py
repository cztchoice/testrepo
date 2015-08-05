#!env python3
import time
s = "\r"
for i in range(1, 20):
    s += "#"
    time.sleep(0.4)
    print(s, end = "")

print()
