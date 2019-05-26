#这是CloudOS的MakeFILE

CC=gcc
asm=nasm
ld=ld
dd=dd

ld_flags=-s -m elf_i386 -Ttext 0x30400 
cc_flags= -I include/  -c -fno-builtin -o
bootflags=-I boot/include/ 
systemflgs=-I include/ -f elf -o
boot=build/loader.elf   build/boot.bin
target=build/system.elf
OBJS=system/system.o system/vga.o system/main.o system/printf.o lib/lib.o lib/string.o system/start.o system/i8259.o system/global.o lib/clib.o system/protect.o system/keyboard.o system/clock.o system/proc.o	system/syscall.o system/tty.o system/hd.o 

all : clean $(boot) $(OBJS) $(target)  makeimg clean_objs


clean: 
	rm -f $(boot) $(OBJS) $(target)
build/loader.elf : boot/loader.asm  boot/include/load.inc boot/include/fat12hdr.inc boot/include/pm.inc
	$(asm) $(bootflags)	-o $@ $<
build/boot.bin : boot/boot.asm  boot/include/load.inc boot/include/fat12hdr.inc
	$(asm) $(bootflags)  -o $@ $<
build/system.elf : system/system.o
	$(ld) $(ld_flags) -o $(target) $(OBJS)
system/system.o : system/system.asm 
	$(asm) $(systemflgs)  $@ $<
system/main.o : system/main.c
	$(CC) $(cc_flags) $@ $<
system/printf.o : system/printf.c
	$(CC) $(cc_flags) $@ $<
lib/string.o : lib/string.asm
	$(asm) $(systemflgs)  $@ $<
lib/lib.o : lib/lib.asm
	$(asm) $(systemflgs) $@ $<
system/start.o : system/start.c
	$(CC) $(cc_flags) $@ $<
system/i8259.o : system/i8259.c
	$(CC) $(cc_flags) $@ $<
system/global.o : system/global.c
	$(CC) $(cc_flags) $@ $<
lib/clib.o : lib/clib.c
	$(CC) $(cc_flags) $@ $<
system/protect.o : system/protect.c
	$(CC) $(cc_flags) $@ $<
system/keyboard.o : system/keyboard.c
	$(CC) $(cc_flags) $@ $<
	
system/clock.o : system/clock.c
	$(CC) $(cc_flags) $@ $<
system/proc.o : system/proc.c
	$(CC) $(cc_flags) $@ $<
system/syscall.o :system/syscall.asm
	$(asm) $(systemflgs)  $@ $<
system/tty.o : system/tty.c
	$(CC) $(cc_flags) $@ $<
system/hd.o : system/hd.c
	$(CC) $(cc_flags) $@ $<
system/vga.o : system/vga.c
	$(CC) $(cc_flags) $@ $<

makeimg:
	dd if=build/boot.bin of=image/floppy.img bs=512 count=1 conv=notrunc
hd : 
	dd if=build/boot.bin of=CloudOShd.vhd bs=512 count=1 conv=notrunc
run : 
	qemu-system-i386.exe -fda image/floppy.img -hda image/80m.img
iso:
	UltraISO.exe image/floppy.img
clean_objs : 
	rm -f $(OBJS)