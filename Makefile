.PHONY: all
all: hello_world echo calc dynarray_test string
hello_world: hello_world.c
	gcc --std=c99 -o $@ $^
echo: echo.c
	gcc --std=c99 -o $@ $^
calc: calc.c
	gcc --std=c99 -o $@ $^
dynarray_test: dynarray_test.c dynarray.c
	gcc --std=c99 -o $@ $^
string: string.c
	gcc --std=c99 -o $@ $^
