#!/usr/bin/python
import sys

f = open("test.txt")
for arg in sys.argv:
    print arg
print len(sys.argv)
count = 0
in_word = False
for i in f.read():
    if i != ' ' and i !='\n':
        if not in_word:
            in_word = True
            #print i
            count = count + 1;
    else:
        in_word = False
print count

f.close()
