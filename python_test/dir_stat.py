#!/usr/bin/python

import sys,os
import os.path
from operator import itemgetter

dir_name = os.curdir
reverse = False
print sys.argv[1]
if sys.argv:
    if os.path.isdir(sys.argv[1]):
        dir_name = sys.argv[1]
        print dir_name
    if len(sys.argv) > 2:
        reverse = True
        print reverse


file_sizes = []

os.chdir(dir_name)
for f in os.listdir(dir_name):
    #print f
    if os.path.isfile(f):
        file_sizes.append([os.path.basename(f), os.path.getsize(f)])

#print file_sizes
print sorted(file_sizes, key=itemgetter(1), reverse=reverse)
