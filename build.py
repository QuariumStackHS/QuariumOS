import os

os.system("as --32 GAS/boot.s -o output/obj/boot.o")


os.system("gcc -m32 -IHeader -c C/Kernel/kernel.c -o output/obj/kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -IHeader -c C/utils/utils.c -o output/obj/utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -IHeader -c C/box/box.c -o output/obj/box.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")


os.system("gcc -m32 -IHeader -c C/str/str.c -o output/obj/str.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra")



os.system("ld -m elf_i386 -T output/obj/linker.ld output/obj/boot.o output/obj/str.o output/obj/kernel.o output/obj/utils.o output/obj/box.o -o output/prebuild/Quarium.QOSE -nostdlib")

os.system("grub-file --is-x86-multiboot output/prebuild/Quarium.QOSE")

os.system("mkdir -p output/isodir/boot/grub")

os.system("cp output/prebuild/Quarium.QOSE output/isodir/boot/Quarium.os")

os.system("cp grub.cfg output/isodir/boot/grub/grub.cfg")

os.system("grub-mkrescue -o output/build/QuariumOS.iso isodir")

os.system("qemu-system-x86_64 -cdrom output/build/QuariumOS.iso")