.PHONY: all
all: hello_world echo calc
hello_world: hello_world.c
	gcc --std=c99 -o $@ $^
echo: echo.c
	gcc --std=c99 -o $@ $^
calc: calc.c
	gcc --std=c99 -o $@ $^
