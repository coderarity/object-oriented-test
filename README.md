# Object Oriented Test

Since there are so many ways to make object oriented C code, I decided to try
out a few different methods and develop my favorite one. This is the result of
that experiment. It's a simple example with a few classes and a simple class
structure, with a parent Animal class and a child Dog class. The Animal class
has a virtual method that the Dog class overwrites. It's a pretty simple method
to do some really cool things, IMO. Other ways seemed to involve a lot more
boilerplate code and didn't really look as pretty as I would have liked.

## Build it

```
make
```

## Try it

```
./test
```

## Clean it

```
make clean
```

## Check it for memory leaks (requires valgrind)

```
make memcheck
```
