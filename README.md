# CRAFTING INTERPRETERS
:link: (Link)[https://craftinginterpreters.com/welcome.html]

## THE LOX LANGUAGE

### :fly: High-Level Language
#### Dynamic Typing


Variables can store values of ant type. If you try to perform an operation on values of the wrong type, then the error is detected and reported at runtime.

#### Automatic Memory Managment

There is two main techniques for managing memory: reference counting and tracing garbage collection (GC).

- Ref. counting: Simple to implement but the limitations become troublesome.
- GC: Harder to work with, but best results at the end.

### :fly: Data Types

- Booleans: true or false.
- Numbers: Just double-precision floating points.
```
1234;
12.34;
```
- String: Enclosed in double quotes.
```
"String 1";
"";    // Empty String
"123"; // String not a number
```
- Nil: Represent no values. In others Languages is often called null.

### :fly: Expressions
#### Arithmetics
```
add + me;
substract - me;
multiply * me;
divide / me;
-negateMe;
```

#### Comparision and Equality
```
less < than;
lessThan <= orEqual;
greater > than;
greaterTahn >= orEqual;
```

```
1 == 2;        // false
"cat" != "dog" // true
```

```
314 == "pi"  // false
123 == "123" // false
```
Values of different types are never equivalent.

#### Logical Operators
```
!true;  // false
!false; // true
```
```
true and false; // false
true and true;  // true
```
```
false or true;  // true
false or false; // false
```

#### Precedence and Grouping

It's boring, so this will work like in C, you can use parentheses to change the precedence if it isn't what you want.
```
var average = (min + max) / 2;
```


### :fly: Statements 
