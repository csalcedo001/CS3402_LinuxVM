bin/info_pc2_cesar: src/info_pc2_cesar.c $(patsubst lib/%.c, build/%.o, $(wildcard lib/*))
	gcc -I include -o $@ $^

build/%.o: lib/%.c include/%.h
	gcc -I include -c $< -o $@
