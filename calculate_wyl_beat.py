#!/usr/bin/env python
# coding=utf-8

import os
import string
import random
from subprocess import Popen, PIPE

sourceA = "calculate_wyl.c"

def generateTestCase():
    a = random.randint(0, 2**2048)
    b = random.randint(0, 2**2048)
    a, b = max(a, b), min(a, b)
    return a, b

print "Compile", sourceA
os.system("gcc " + sourceA + " -o " + sourceA + ".out -Wall")

while True:
    print "Generate test case"
    testcase = generateTestCase()
    inputs = str(testcase[0]) + '\n' + str(testcase[1])
    print inputs

    answer = str(testcase[0] + testcase[1])

    print "Run sourceA"
    p = Popen(["./" + sourceA + ".out"], stdin=PIPE, stdout=PIPE)
    outputA, _ = p.communicate(inputs)
    

    print "Compare outputs"
    if outputA != answer:
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
        print '"' + answer.encode('string_escape') + '"'
        break
    else:
        print "PASS"
        print

