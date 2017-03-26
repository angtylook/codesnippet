#! /usr/local/bin/python3
import sys
import os
from PIL import Image
print(sys.version)

if __name__ == '__main__':
    if len(sys.argv) > 2:
        infile = sys.argv[1]
        outfile = sys.argv[2]
        if infile != outfile:
            try:
                Image.open(infile).save(outfile)
            except IOError:
                print('cannot convert', infile)
        else:
            print('input file is output file. done!')
    else:
        print('usage: convert infile outfile')
