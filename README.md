# Monty

**Exploring Stacks and Bytecode Interpretation**

Welcome to my Monty repository! This project delves into the world of stacks and bytecode interpretation using the C programming language.

## Key Goals:

- **Master Stack Operations:** Develop a deep understanding of stack data structures, including pushing, popping, and managing data efficiently.
- **Interpret Bytecode  Instructions:** Learn to decode and execute bytecode instructions, simulating a virtual machine-like environment.

## Features:

- **Stack Implementation:** Provides core stack functionalities for data storage and retrieval.
- **Bytecode Interpreter:** Reads and executes custom bytecode instructions, manipulating data on the stack.

## Supported Bytecode Instructions:
- **push `<int>`**: The opcode push pushes an element to the stack.
    * *Usage*: push `<int>` where `<int>` is an integer
    * if `<int>` is not an integer or if there is no argument given to push, prints the error message `L<line_number>: usage: push integer`, followed by a new line

- **pall**: The opcode pall prints all the values on the stack, starting from the top of the stack.
    * *Usage*: pall

- **pint**: The opcode pint prints the value at the top of the stack, followed by a new line.
    * *Usage*: pint
    * If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`

- **pop**: The opcode pop removes the top element of the stack.
    * *Usage*: pop
    * If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`

- **swap**: The opcode swap swaps the top two elements of the stack.
    * *Usage*: swap
    * If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`

- **add**: The opcode add adds the top two elements of the stack.
    * *Usage:* add
    * If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`
    * The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
        - The top element of the stack contains the result
        - The stack is one element shorter

- **nop**: The opcode nop doesn’t do anything.
    * *Usage:* nop

- **sub**: The opcode sub subtracts the top two elements of the stack.
    * *Usage:* sub
    * If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`
    * The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
        - The top element of the stack contains the result
        - The stack is one element shorter

- **div**: The opcode div divides the second top element of the stack by the top element of the stack.
    * *Usage:* div
    * If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`
    * The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
        - The top element of the stack contains the result
        - The stack is one element shorter
    * If the top element of the stack is 0, print the error message `L<line_number>: division by zero`

- **mul**: The opcode mul multiplies the second top element of the stack with the top element of the stack.
    * *Usage*: mul
    * If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`
    * The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
        - The top element of the stack contains the result
        - The stack is one element shorter
        
