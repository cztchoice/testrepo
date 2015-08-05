#!/usr/bin/python

import os
import sys
import argparse

def reencoding(s, f, t):
    uni_s = s.decode(f)
    return uni_s.encode(t)



def main():
    parser = argparse.ArgumentParser(description="convert file name from one encoding to another encoding")
    parser.add_argument("filename",  help="filename or dirname to be converted")

    parser.add_argument("-f", help="specify the encoding of filename from which should be converted")
    parser.add_argument("-t", help="specify the encoding of filename should be converted")
    parser.add_argument("-i", help="interactive mode(ask y/n for each action", action="store_true")
    parser.add_argument("-r", help="recursively go through directories", action="store_true")
    parser.add_argument("--list", help="list all encodings")

    args = parser.parse_args()

    encodings = ['gbk', 'utf-8']

    if args.f not in encodings:
        print("input encodings {} not supported".format(args.f))
        sys.exit(1)
    if args.t not in encodings:
        print("output encodings {} not supported".format(args.f))
        sys.exit(1)

    if not args.r:
        os.rename(args.filename, reencoding(args.filename, args.f, args.t))
    else:
        filenames = [os.path.realpath(args.filename)]
        while(len(filenames) != 0):
            filename = filenames.pop()
            dirname = os.path.dirname(filename)
            basename = os.path.basename(filename)
            new_basename =  reencoding(basename, args.f, args.t)
            new_filename = dirname + os.path.sep + new_basename
            os.rename(filename, new_filename)
            if os.path.isdir(filename):
                filenames.extend([os.path.realpath(new_filename) + os.path.sep + i for i in os.listdir(new_filename)])
            #print(filenames)


if __name__ == '__main__':
    main()
