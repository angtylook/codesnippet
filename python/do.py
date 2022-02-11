#!/usr/local/bin/python3
# encoding=utf-8

import json
import csv
import argparse
from optparse import Option
import pathlib
import tempfile
import sys
from timeit import repeat
from urllib import request

if __name__ == "__main__":
    tp = open("out.txt",  mode="w+t", encoding="utf-8")
    csvfile = open(sys.argv[1], encoding="utf-8")
    lis = []
    repeated = {}
    for line in csvfile:
        if not line.startswith("Thor.HyYearServer.log"):
            continue
        idx = line.find("{")
        line = line[idx:]
        tp.write(line)
        js = json.loads(line)
        #print(js["sourceId"])
        lis.append(js["sourceId"])
        if js["sourceId"] in repeated:
            print(js["sourceId"])
        else:
            repeated[js["sourceId"]] = 1
    csvfile.close()
    tp.close()
    lis.sort()
    print(lis)
