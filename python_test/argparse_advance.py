import argparse

parser = argparse.ArgumentParser(description="calculate X to the power of Y")
#parser.add_argument("echo", help="echo the string you use here")
parser.add_argument("x", type=int, help="the base")
parser.add_argument("y", type=int, help="the exponent")
#parser.add_argument("-v", "--verbosity", action="count",  help="increase output verbosity")
group = parser.add_mutually_exclusive_group()
group.add_argument("-q", "--quiet", action="store_true")
group.add_argument("-v", "--verbose", action="store_true")

args=parser.parse_args()

answer = args.x**args.y

#if args.verbosity >= 2:
    ##print "{} to the power {} equals {}".format(args.x, args.y, answer)
    #print "Running '{}'".format(__file__)
#if args.verbosity >= 1:
    #print "{}^{} == {}".format(args.x, args.y,  answer)
#else:
    #print answer

if args.quiet:
    print answer
elif args.verbose:
    print "{} to the power {} equals {}".format(args.x, args.y, answer)
else:
    print "{}^{} == {}".format(args.x, args.y,  answer)
