import os

os.system("as --32 boot.s -o obj/boot.o")


os.system("gcc -m32 -c kernel.c -o obj/kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -c utils.c -o obj/utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -c box.c -o obj/box.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -c str.c -o obj/str.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")



os.system("ld -m elf_i386 -T obj/linker.ld obj/boot.o obj/str.o obj/kernel.o obj/utils.o obj/box.o -o prebuild/Quarium.QOSE -nostdlib")

os.system("grub-file --is-x86-multiboot prebuild/Quarium.QOSE")

os.system("mkdir -p isodir/boot/grub")

os.system("cp prebuild/Quarium.QOSE isodir/boot/Quarium.os")

os.system("cp grub.cfg isodir/boot/grub/grub.cfg")

os.system("grub-mkrescue -o build/QuariumOS.iso isodir")

os.system("qemu-system-x86_64 -cdrom build/QuariumOS.iso")