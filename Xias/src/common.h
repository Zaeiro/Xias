#pragma once

// Triggers a garbage collection before every allocation.
//#define DEBUG_STRESS_GC
// Prints information about garbage collection
//#define DEBUG_LOG_GC

// Prevents duplicates in generated constant vectors. Decreases memory usage while
// increasing compilation time. May decrease VM performance.
//#define COMPRESS_CONSTANTS

// Values always store whether they are an object or not. With this define,
// values will always store their exact type. May be used in the future.
// #define COMPLETE_TYPING

/*
Built in types are initialized to:
void   - V
bool   - B
int    - I
uint   - U
float  - F
double - D
string - S
object - O

Method signature is as follows:
V;EmptyFunction;I;String;Digit;

V; - The return type.
EmptyFunction; - The name of the method.
I;S;Digit; - Parameters, including Digit, a user defined class.

The signature of constructor methods is:
;<>;I;

There is no return type, and the name is '<>'

Operator signatures are like this:
Fraction;+;Fraction;Fraction;

The method name is the operator

The method names for cast operators are as such:
float;();int; -> cast to float from int

The method names for post- and pre- operators are as such:
I;_++;I; - Post increment
I;--_;I; - Pre decrement
*/
