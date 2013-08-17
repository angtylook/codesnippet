import sys
import os

if len(sys.argv) < 2:
    print "less argv"
    sys.exit(0)

filename = sys.argv[1]

if os.path.exists(filename):
    print "file is exist"
    sys.exit(0)
else:
    fp = open(filename,"w")
    fp.close()


