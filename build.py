import os
import threading
import glob
#os.system("as --32 GAS/boot.s -o output/obj/boot.o")
#os.system("as --32 GAS/kernel.s -o output/obj/kernel.o")


import os
import zipfile

def zipdir(path, ziph):
    # ziph is zipfile handle
    for root, dirs, files in os.walk(path):
        for file in files:
            if not file.endswith(".iso"):
                ziph.write(os.path.join(root, file))


def run(c):
    print(c)
    os.system(c)

objlist=[]
C=glob.glob("C/*/*.c")
for i in C:
    j=i.split("/")[-1].split(".")[0]
    objlist.append(f"output/obj/C-{j}.o")
    stri=f"gcc -m32 -IGAS -IHeader -c {i} -o output/obj/C-{j}.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra"
    x=threading.Thread(target=run,args=(stri,))
    x.start()
C=glob.glob("GAS/*.s")
for i in C:
    j=i.split("/")[-1].split(".")[0]
    objlist.append(f"output/obj/GAS-{j}.o")
    stri=f"as --32 {i} -o output/obj/GAS-{j}.o"
    x=threading.Thread(target=run,args=(stri,))
    x.start()
"""C=glob.glob("NASM/*.asm")
for i in C:
    j=i.split("/")[-1].split(".")[0]
    objlist.append(f"output/obj/NASM-{j}.o")
    stri=f"nasm {i} -f elf -o output/obj/NASM-{j}.o"
    x=threading.Thread(target=run,args=(stri,))
    x.start()"""


x.join()
while threading.activeCount()>1: pass
ldstr=""
for i in objlist:
    ldstr+=f"{i} "
os.system(f"ld -m elf_i386 -T output/obj/linker.ld {ldstr}-o output/prebuild/Quarium.QOSE -nostdlib")
print("all obj:")
for i in ldstr.split(" "):
    print("\t"+i.replace("output/obj/",""))
import time
#zipf = zipfile.ZipFile(f'/media/slow/backups/backups/QuariumOS-{time.time()}.zip', 'w', zipfile.ZIP_DEFLATED)
#zipdir('.', zipf)
#zipf.close()
#os.system("ld -m elf_i386 -T output/obj/linker.ld output/obj/kernel.o -o output/prebuild/Quarium.QOSE -nostdlib")

os.system("grub2-file --is-x86-multiboot output/prebuild/Quarium.QOSE")

os.system("mkdir -p output/isodir/boot/grub")

os.system("cp output/prebuild/Quarium.QOSE output/isodir/boot/Q-DOS.os")

os.system("cp grub.cfg output/isodir/boot/grub/grub.cfg")

os.system("grub2-mkrescue -o output/build/Q-DOS.iso output/isodir")

os.system("qemu-system-x86_64 -cdrom output/build/Q-DOS.iso")
print(255**2)