#!/usr/bin/env python3

import argparse
import re

parser = argparse.ArgumentParser(description='Configures the hal_conf-header.')
parser.add_argument('--input', '-i', type=argparse.FileType('r'))
parser.add_argument('--output', '-o', type=argparse.FileType('w'))
parser.add_argument('--enable', '-e', nargs='+', action='store')

args = parser.parse_args()

for line in args.input:

    m = re.search('^#define HAL_([a-zA-Z0-9]+)_MODULE_ENABLED', line)
    if m and m.group(1).lower() not in args.enable:
        line = '/* ' + line.strip('\n') + ' */\n'

    args.output.write(line)


