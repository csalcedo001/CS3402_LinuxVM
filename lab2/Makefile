bin/info_pc1_cesar: src/info_pc1_cesar.c $(patsubst lib/%.c, build/%.o, $(wildcard lib/*))
	gcc -I include -o $@ $^

build/%.o: lib/%.c include/%.h
	gcc -I include -c $< -o $@
