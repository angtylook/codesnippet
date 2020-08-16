#!/usr/local/bin/python3
import os
import pathlib
import subprocess
import sys

def cvt(inputFile, outFile):
    print(inputFile, " -> ", outFile)
    cmdline = ["ffmpeg", "-i", inputFile, "-c:v", "libx265", outFile]
    print(cmdline)
    subprocess.call(cmdline)

if __name__ == "__main__":
    cnt = 0
    maxCnt = int(sys.argv[2])
    yid = os.walk(sys.argv[1])
    for rootDir, pathList, fileList in yid:
        for filePath in fileList:
            inputFile = pathlib.Path(rootDir).joinpath(filePath)
            if inputFile.suffix not in {".mp4", ".MP4", ".mkv", ".flv"}:
                continue
            stem = inputFile.stem
            if stem.endswith("x265") or stem.endswith("hevc_amf"):
                continue
            stem += "_x265.mp4"
            outFile = inputFile.with_name(stem)
            if outFile.exists():
                continue
            cvt(inputFile, outFile)
            cnt = cnt + 1
            if cnt == maxCnt:
                break