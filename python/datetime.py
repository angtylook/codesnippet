#!/usr/local/bin/python3
#utf-8

from datetime import datetime
import time

if __name__ == "__main__":
    print(time.time())
    ts = datetime.now().timestamp()
    print(ts)
    nts = datetime.fromtimestamp(time.time() - 36000)
    print(nts)
