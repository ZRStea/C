#!/usr/bin/env python
# coding=utf-8

import os
import string
import random
from subprocess import Popen, PIPE

sourceA = "1006.c"
sourceB = "1006_wyl.c"

def generateTestCase():
    # generate a ISBN number
    a = random.randint(100000000, 999999999)
    b = str(a)
    checksum = sum([int(b[i])*(i+1) for i in range(len(b))]) % 11
    checksumChar = str(checksum) if checksum < 10 else 'X'
    ISBN = b[0] + '-' + b[1:4] + '-' + b[4:9] + '-' + checksumChar

    # generate a random checksum
    randomChecksum = random.choice(range(0, 10) + ['X'])
    
    # generate inputs
    inputs = ISBN
    inputs = inputs[:12] + str(randomChecksum)

    return inputs

print "Compile", sourceA
os.system("gcc " + sourceA + " -o " + sourceA + ".out -Wall")

print "Compile", sourceB
os.system("gcc " + sourceB + " -o " + sourceB + ".out -Wall")

while True:
    print "Generate test case"
    inputs = generateTestCase()
    print inputs

    print "Run sourceA"
    p = Popen(["./" + sourceA + ".out"], stdin=PIPE, stdout=PIPE)
    outputA, _ = p.communicate(inputs)

    print "Run sourceB"
    p = Popen(["./" + sourceB + ".out"], stdin=PIPE, stdout=PIPE)
    outputB, _ = p.communicate(inputs)
    
    print "Compare outputs"
    if outputA != outputB:
        print 
        print "STOP"
        print
        print "inputs"
        print '"' + inputs + '"'
        print
        print "outputA"
        print '"' + outputA.encode('string_escape')+ '"'
        print
        print "outputB"
        print '"' + outputB.encode('string_escape') + '"'
        break
    else:
        print "PASS"
        print

