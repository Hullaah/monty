# 🏗️ Monty Bytecode Interpreter — Stack & Queue Virtual Machine in C

This project is a **stack-based bytecode interpreter** written in C.  
It executes Monty bytecode files line by line, implementing core **stack and queue operations** along with arithmetic and string instructions.

The interpreter is modular, making it easy to extend with new opcodes.

## 📌 Motivation

The Monty project was built to:

- Deepen understanding of **stacks**, **queues**, and **data structures** in C  
- Gain hands-on experience with **parsing**, **error handling**, and **low-level programming**  
- Practice writing clean, modular code that mimics real interpreters and virtual machines  


## ✨ Key Features

- ✅ Stack (LIFO) and Queue (FIFO) modes  
- ✅ Arithmetic instructions (`add`, `sub`, `mul`, `div`, `mod`)  
- ✅ String/char printing instructions (`pchar`, `pstr`)  
- ✅ Rotation instructions (`rotl`, `rotr`)  
- ✅ Robust error handling with line numbers  
- ✅ Modular opcode handlers — easy to extend  

## 🧾 Supported Bytecode Instructions

| Opcode | Description | Usage | Error Cases |
|--------|-------------|-------|-------------|
| **push `<int>`** | Pushes an integer onto the stack | `push 5` | Missing argument or non-integer → `L<line>: usage: push integer` |
| **pall** | Print all values on the stack, from top down | `pall` | — |
| **pint** | Print the value at the top of the stack | `pint` | Stack empty → `L<line>: can't pint, stack empty` |
| **pop** | Remove the top element of the stack | `pop` | Stack empty → `L<line>: can't pop an empty stack` |
| **swap** | Swap the top two elements of the stack | `swap` | Fewer than two elements → `L<line>: can't swap, stack too short` |
| **add** | Add the top two elements | `add` | Fewer than two elements → `L<line>: can't add, stack too short` |
| **sub** | Subtract top element from second top | `sub` | Fewer than two elements → `L<line>: can't sub, stack too short` |
| **mul** | Multiply top two elements | `mul` | Fewer than two elements → `L<line>: can't mul, stack too short` |
| **div** | Divide the second top element by the top | `div` | Fewer than two → `L<line>: can't div, stack too short`; division by zero → `L<line_number>: division by zero`|
| **mod** | Modulus of second top by top | `mod` | Fewer than two elements → `L<line>: can't mod, stack too short`; modulus by zero → `L<line_number>: division by zero`|
| **nop** | Does nothing | `nop` | — |
        
## 🛠️ Building the Project

### 🔧 Requirements
- GCC or Clang  
- `make`  
- Unix-like OS (Linux, macOS, WSL, etc.)  

### 🧪 Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/Hullaah/monty.git
cd monty
```
2. Build the project:
```bash
make
```
3. Optionally, generate compile_commands.json for code navigation
```bash
bear -- make
```

## ▶️ Usage
Run the interpreter with a Monty bytecode file:
```bash
./monty <file.m>
```
Example:
```bash
➜  monty git:(main) ✗ cat bytecodes/89.m 
push 100
push 20
push 5
push 4
mul
pall
div
pall                             
                             div
push 25
add
pall
push 90
push 120
push 30
                  sub
pall
mod
pall
# div
# pall
push # 50
➜  monty git:(main) ✗ ./monty bytecodes/89.m 
20
20
100
1
100
125
90
90
125
0
125
L22: usage: push integer
➜  monty git:(main) ✗ valgrind ./monty bytecodes/89.m
==125624== Memcheck, a memory error detector
==125624== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==125624== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==125624== Command: ./monty bytecodes/89.m
==125624== 
20
20
100
1
100
125
90
90
125
0
125
L22: usage: push integer
==125624== 
==125624== HEAP SUMMARY:
==125624==     in use at exit: 0 bytes in 0 blocks
==125624==   total heap usage: 163 allocs, 163 frees, 4,163 bytes allocated
==125624== 
==125624== All heap blocks were freed -- no leaks are possible
==125624== 
==125624== For lists of detected and suppressed errors, rerun with: -s
==125624== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
➜  monty git:(main) ✗   
```

## 🧠 What I Learned
- How stack and queue data structures are implemented at a low level
- Writing interpreters that parse and execute instructions line by line
- Designing modular opcode dispatch systems
- Handling edge cases gracefully (empty stack, bad instructions, division by zero)
- Error reporting with helpful line numbers

## 👨‍💻 Author
**Umar Adelowo**

Intermediate systems programmer focused on **OS, networking,** and **low-level development.**
Aiming to contribute to the **Linux Kernel** and become a **security and systems expert.**

[📧 Contact me](umaradelo1.247@gmail.com)

🌐 GitHub: [@Hullaah](https://github.com/Hullaah)
