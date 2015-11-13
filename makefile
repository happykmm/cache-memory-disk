ok : cache.exe memory.exe disk.exe
cache.exe : cache.c
	gcc cache.c -o  cache.exe -g
memory.exe  : memory.c
	gcc memory.c -o memory.exe -g 
disk.exe : disk.c
	gcc disk.c -o disk.exe -g