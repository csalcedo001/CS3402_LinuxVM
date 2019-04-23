.PRECIOUS: build/%.o

all: $(addprefix bin/, $(basename $(notdir $(wildcard src/*))))

bin/%: src/%.c $(patsubst lib/%.c, build/%.o, $(wildcard lib/*))
	gcc -o $@ -I include $^ -lpthread

build/%.o: lib/%.c include/%.h
	gcc -o $@ -I include -c $<

clean:
	rm bin/*
	rm build/*
