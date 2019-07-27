#!/usr/local/bin/env python3
# encoding=utf-8

import redis

def writeRedis(r):
    r.set('foo', 'bar')

def readRedis(r):
    print(r.get('foo'))


if __name__ == "__main__":
    r = redis.Redis(host='localhost', port=6379, db=0)
    writeRedis(r)
    readRedis(r)
