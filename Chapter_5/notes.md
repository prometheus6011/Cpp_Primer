# Chapter 5 - Statements
- provides statements for conditional execution, loops that repeatedly execute the same body of code, and jump statements that interrupt the flow of control

### 5.1 - Simple Statements
- statements that end in a semicolon are an expression statement, which is to be evaluated and its result discarded

- Null Statements
	- the simplest statement is the empty statement, also known as a null statement
	- one semicolon
	useful where the language requires a statement but the prorgram's logic does not
- because a null statement is a statement, it is legal anywhere a statement is expected
- Compound Statements (Blocks)
	- a sequence of statements and declarations surrounded by a pair of curly braces
	- a block is a scope
	- compound statements are used when the language requires a single statement but the logic of our program needs more than one

###### Exercises
1. a null statement is a statement of one semicolon, it is used when the program requires a statement but logic does not
2. a block is a sequence of statement enclosed in curly braces, it is used when the program requires a statement but logic requires multiple
3. `5_3.cpp`

### 5.2 - Statement Scope
- we can define variables inside the control structure of the `if`, `switch`, `while`, and `for` statements
- variables defined in the control structure are visible only within that statement and are out of scope after the statement ends
- if we need access to the control variable, then that variable must be defined outside the statement

###### Exercises
4. scope
	- `iter` needs to be initialized before usage
	- if `status` is going to be used outside the loop scope, then it needs to be defined before the `while` structure

### 5.3 - Conditional Statements

##### 5.3.1 - The `if` Statement
- an `if` statement conditionally executes another statement based on whether a specified condition is true
- the expression or variables must have a type that is convertible to `bool`
- each `else` branch is matched with the closest preceding unmatched `if`

###### Exercises
5. `5_5.cpp`
6. `5_6.cpp`
7. `5_7.cpp`
8. a dangling `else` is an `else` clause that does not belong to the `if`, an `else` clause is resolved to the nearest `if` statement

##### 5.3.2 - The `switch` Statement
- provides a convenient way of selecting among a (possibly large) number of fixed alternatives
- executes by evaluating parenthesizes expression that follows the keyword `switch`
- if no match is found, execution falls through to the first statement following the `switch`

- control flow within a `switch`
	- after a case label is matched, execution starts at the label and continues across all the remaining vases or until the program explicitly interrupts it
	- use `break` to tell the compiler to stop execution
- the `default` label
	- the statement following the `default` label are executed when no `case` label matches the value of the `switch` expression

###### Exercises
9. `5_9.cpp`
10. `5_9.cpp`
11. `5_9.cpp`
12. `5_9.cpp`
13. errors
	- there are no break statements, therefore for every time a is seen, `aCnt` and `eCnt` will be incremented
	- `ix` cannot be used in different scopes
	- `case` statements can only have one argument
	- `case` statements must be integral const expressions

### 5.4 - Iterative Statements

##### 5.4.1 - The `while` Statement
- repeatedly executes a target statement as long as a condition is true

###### Exercises
14. `5_14.cpp`

##### 5.4.2 - Traditional `for` Statement
- order of evaluation
	- init-statement is executed once at the start of the loop
	- condition is evaluated, if true the for body is executed, else the loop terminates
	- if the condition is true, the `for` body executes
	- expression is evaluated

###### Exercises
15. problems in loops
	- `ix` cannot be used outside the `for` loop body, declare it outside the `for` loop
	- the `for` header needs a semi-colon to terminate the declaration statement
	- this is an infinite loop
17. `5_17.cpp`

##### 5.4.3 - Range `for` Statement
- the expression must be of type that return iterators
- we can always use the type `auto` to match the declaration for the variable

##### 5.4.4 - The `do while` Statement
- the condition is tested after the statement body completes

###### Exercises
18. explanation of loops
	- lines 2-5 need to be in curly braces, prints sum of every input
	- error, cannot have variable declarations in a condition
	- error, loop will define a new condition variable everytime
19. `5_19.cpp`

### 5.5 - Jump Statements
- interrupt the flow of execution

##### 5.5.1 - The `break` Statement
- terminates the nearest enclosing `while`, `do while`, `for`, or `switch` statement
- can only appear within an iteration statement or `switch` statement

###### Exercises
20. `5_20.cpp`

##### 5.5.2 - The `continue` Statement
- terminates the current iteration of the nearest enclosing loop and immediately begins the next iteration

###### Exercises
21. `5_21.cpp`

###### 5.5.3 - The `goto` Statement
- provides an unconditional jump from the `goto` to a another statement in the same function

###### Exercises
22. `5_22.cpp`

### 5.6 - `try` Blocks and Exception Handling

##### 5.6.1 - A `throw` expression
- a `throw` expression is the detecting part of a program

##### 5.6.2 - The `try` Block
- a `try` block has a sequence of statements
- following the `try` is a list of one or more `catch` clauses
	- the `catch` has an object within the parentheses

###### Exercises
23. `5_23.cpp`