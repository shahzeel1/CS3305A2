part1: a2p1.c 
	gcc -pthread -o part1 a2p1.c -I.

part2: a2p2.c 
	gcc -o part2 a2a2.c  -I.
clean:
	rm -f part1*.o core part1
	rm -f part2*.o core part2
	
