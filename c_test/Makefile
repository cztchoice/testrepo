.PHONY: default
default: ncurses_hello

ncurses_hello: ncurses_hello.cpp
	g++ -g $< -o $@ -lncurses


%.o: %.cpp
	g++ -g $< -o $@

clean:
	rm *.o
