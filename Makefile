main: dungeon_maker.c
	gcc -c dungeon_maker.c -Wall -Werror -ggdb -o dungeon

#f2c.o: f2c.c cf.h
 #       gcc -c f2c.c -Wall -Werror -ggdb -o f2c.o

clean:
	rm -f dungeon *~
