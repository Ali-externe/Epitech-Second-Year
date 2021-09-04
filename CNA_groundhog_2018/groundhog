#!/usr/bin/env python3

import sys
import array
import numpy as np

if (sys.argv[1] == "-h"):
    print("SYNOPSIS\n    ./groundhog period\n\nDESCRIPTION\n    period        the number of days defining a period")
    sys.exit()
arg = int(sys.argv[1])
try:
    liste = []
    array = []
    switch = []
    a=0
    t = 0
    y = 0
    c = 0
    w = 0
    f = 0
    g="nan"
    r="nan"
    s="nan"
    switchstr=""
    switchnb = 0
    pourcent ='%'
    for line in sys.stdin:
        if (line == "STOP\n"):
            break
        if (line == "0\n"):
            line = "0.01"
        liste.insert(a, float(line))
        array.insert(a, float(line))
        a += 1
        if (a < arg):
            print("g=%s        r=%s%c        s=%s" %(g,r,pourcent,s))
        if (a == arg):
            s = np.std(array)
            s = round(s, 2)
            array.pop(0)
            print("g=%s        r=%s%c        s=%.2f" %(g,r,pourcent,s))

        if (a > arg):
            g = 0
            while (c < (arg + t)):
                w = float(liste[c + 1])-float(liste[c])
                if (w >= 0):
                    g += abs(liste[c]-liste[c + 1])
                if (w < 0):
                    g -= (liste[c + 1] - liste[c])
                c += 1
            c = t + 1
            g = abs(g / arg)
            if (g < 0):
                g = 0
            g = round(g, 2)
            s = np.std(array)
            s = round(s, 2)
            array.pop(0)
            res = float(liste[a - 1]) - float(liste[t])
            r = 100 * res / float(liste[t])
            r = round(r, 0)
            r = int(r)
            switch.insert(f, r)
            f += 1
            if (f == 2):
                f -= 1
                if (switch[0] < 0 and switch[1] > 0):
                    switchstr = "\ta switch occurs"
                    switchnb += 1
                elif (switch[0] > 0 and switch[1] < 0):
                    switchstr = "\ta switch occurs"
                    switchnb += 1
                else :
                    switchstr = ""
                switch.pop(0)
            print("g=%s        r=%s%c        s=%.2f%s" %(g,r,pourcent,s,switchstr))
            t += 1
            y += 1
    print("Global tendency switched", switchnb, "times")
    print("5 weirdest values are", liste)
except KeyboardInterrupt:
    sys.exit()
