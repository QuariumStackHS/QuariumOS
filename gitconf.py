import os

email=input("enter your email adresse of your github account\n>")
name=input("enter your username for github\n>")

os.system("git config user.name \""+name+"\"")
os.system("git config user.email \""+email+"\"")
print("config finish")