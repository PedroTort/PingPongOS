all:
	gcc -Wall -o run ppos-core-aux.c pingpong-scheduler-srtf.c libppos_static.a 

# remove temporary files
clean:
	rm -rf *o run