#! python3

import os
import pathlib
import subprocess

for file in os.listdir(os.getcwd()):
    if file.endswith('.md'):
        cmd = ['pandoc.exe', '--latex-engine=xelatex']
        cmd.append(file)
        cmd.append('-o')
        cmd.append(str(pathlib.Path(file).with_suffix('.pdf')))
        ret = subprocess.run(cmd)
        if ret.returncode != 0:
            print(ret)
        

