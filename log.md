# Assignment from Shanti

- implement the echo

```
./echo toni
```

to return like this

```
echo toni
-----
toni
```

# Create a calc method

- Input will be multiple(can be 2,3,4 or more)
- Return to the sum of all of inputs
- Through error if the input number is 1

- i.g)

```
    calc 123 123 123 123
```

# .PHONY: all

- .PHONY is a special built-in target in Make, used to declare that all is a "phony" target. Phony targets are not files; they're just names for a recipe to be executed when you make an explicit request. This is useful for grouping or labeling certain commands.
  In this case, it's saying that all is not a file to be built, but a label for a group of tasks.

# **$^**

- Example:Suppose you have a Makefile rule like this:

```
    myprogram: main.o utils.o
        gcc -o myprogram main.o utils.o
```

- This can be simplified using $^:

```
    myprogram: main.o utils.o
        gcc -o myprogram $^
```

- Here, $^ will be expanded to main.o utils.o, so the command that gets executed is the same as the original: gcc -o myprogram main.o utils.o.

* Note: $^ includes all prerequisites, but it doesn't remove duplicate names. If the same filename appears more than once as a prerequisite, it will appear the same number of times in $^. For a version of this variable that removes duplicates, you can use $?.

# h file and c file

- Seems like **h file** is for declaring methods
- And **c file** is for implementing method details
