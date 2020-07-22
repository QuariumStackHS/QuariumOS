import os
import sys
try:
    change=sys.argv[2]
except:
    change=input("what did you change?\n>")
os.system("git add -A")
os.system("git commit -m \""+change+"\"")
os.system("git push")