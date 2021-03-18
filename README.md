# EvilEval: Calculator in C (Parser)


## Algorithm

![](img/arithmetic_operation.png)


### Structure

- `Numbers`
- `Operators`
- `Orders`
- `Paranthesis counter`


#### Definition

- What is `Orders`
    - The order to be evaluated in an equation


#### Relation between `Numbers` / `Operators` / `Orders`

- `length(Numbers)` = `length(Operators)` + 1
    - Ex. `2/4`
- `Length(Operators)` = `Length(Orders)`

### Evaulation

```pseudo
# Do a/b
b = pop(Numbers)
a = pop(Numbers)
op = pop(Operators)
pop(Orders)

r = eval(op, a, b) # div(a,b)

push(Numbers, r)
```


### Initiate an evalution

```pseudo
op_new = read()
order_new = order_current  + order(op_new)
b_new = read()

if (Query(Orders) < order_new) # Add to list
    push(Orders, order_new)
    push(Operators, op_new)
    push(Numbers, b_new)
else 
    Do Evalution
```
Length affected by single evalution

### How to update order base `()`

```psudo

order_base = 0

while (symbol != EOF)
    symbol = read_char()

    if symbol == `(`
        order_base += 2
    else if(symbol == `)`)
        order_base -= 2
    else 
        Do Operation
end
```

Rule
1. `Evaluate` when the incoming order is smaller than the end of the stack


## String Operation


### Usage of `fscanf`




- Source: [Fun with “scanf” in c](https://medium.com/@zoha131/fun-with-scanf-in-c-3d7a8d310229)

#### Return Value

- Source: [TutorialPoint](https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm)

##  Data Type and Range

|Data Type|Range|Size|
|---|---|---|
|`int`|-2,147483648E9 to 2.147483647E9|4 bytes|
|`double`|2.3E-308 to 1.7E+308|8 bytes|
|`Char`|1 Byte|


- Source: [TutorialPoint](https://www.tutorialspoint.com/cprogramming/c_data_types.htm)



## Constraints

- Maximum storage: **1GB**
- Time limit: **1s**

### Number of parameters

#### Input String Size

|Symbol|Description|
|:---:|:---:|
|$L$|length of a line|
|$T$|Lines|

- $L < 10^6$
    - Maximum usage of memory
        - 8MB
        - RAM: 10 MB
- $L\cdot T \leq 10^6$
    - 1 MB

### Strategy of storage

- String
    - Store in **stack**
- Numbers / Operators / Orders
    - Store in **Heap** (`malloc`)

Test: https://onlinegdb.com/BJHmN8lNd


## Implementation

### What do I need?


- Package
    - Stack in Heap
        - Allow big storage

    - String Parser
        - Get `+-*/`
        - Get Numbers
    - Equation Eval

- Algorithm
    - Arithmatic Operation
        - In `Equation Eval`
