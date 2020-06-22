import os

os.system("git add -A")
os.system("git commit -m \""+input("what did you change?\n>")+"\"")
os.system("git push")