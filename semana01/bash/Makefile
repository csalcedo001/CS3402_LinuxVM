bin/bash: src/bash.c $(patsubst lib/%.c, build/%.o, $(wildcard lib/*))
	gcc -I include -o $@ $^

build/%.o: lib/%.c include/%.h
	gcc -I include -c $< -o $@

clean:
	rm bin/* build/*
