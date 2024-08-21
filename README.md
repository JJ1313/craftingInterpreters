# CRAFTING INTERPRETERS

## THE LOX LANGUAGE

### Dynamic Typing

Variables can store values of ant type. If you try to perform an operation on values  of the wrong type then the error is detected and reported at runtime.

### Automatic Memory Managment

There is two main techniques for managing memory: reference counting and tracing garbage collection (GC).

- Ref. counting: Simple to implement but the limitations become troublesome.
- GC: Harder to work with, but best results at the end.

### Data Types

- Booleans: true / false
- Numbers: Just double-precision floating points.

`1234;

12.34;`
