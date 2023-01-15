#!/bin/bash

sudo apt-get update

sudo apt-get install                        \
    gcc-8                                   \
    python3 python3-pip                     \
    perl                                    \
    make gdb valgrind

# all py packages json os pathlib recordclass subprocess sys
sudo pip3 install                           \
    argparse                                \
    pathlib                                 \
    recordclass                             \
    python-sat
