include ../../Makefile.cfg



all:
	
	mkdir -p cd_root
	$(CC) $(CCFLAGS)-O2 -DEXAMPLES_VMODE=VMODE_NTSC main.c system573_lib/ksys573_pad.c ksys573_dump.c ksys573_flash_check.c ksys573_rtc_util.c ksys573_sio_check.c ksys573_input_check.c system573_lib/ksys573_flash_mem.c ksys573_font.c system573_lib/ksys573_psx_gpu.c system573_lib/ksys573_nvram.c system573_lib/ksys573_sio.c -o PSX.elf
	elf2exe PSX.elf cd_root/PSX.exe -mark_jpn
	systemcnf PSX.exe > cd_root/system.cnf
	mkisofs -o PSX.hsf -V GAMEISO -sysid PLAYSTATION cd_root
	mkpsxiso PSX.hsf PSX.bin /share/licenses/infojap.dat
	rm -f PSX.hsf