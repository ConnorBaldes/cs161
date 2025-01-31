# CS161: Introduction to Computer Science I

## Course Description
CS161 covers the fundamentals of computer science, focusing on problem-solving, software engineering, and object-oriented programming. The course introduces algorithm design, program development, and key programming concepts in C++. Topics include variable types, control flow, functions, arrays, and recursion, and students will apply these concepts through practical projects.

## Course Objectives
- Design and implement programs using control statements such as selection, repetition, and recursion.
- Develop programs utilizing variables, constants, operators, and data structures like arrays and strings.
- Apply the principles of object-oriented programming and abstraction.
- Debug syntax and runtime errors effectively.
- Implement recursive algorithms and understand when to use recursion versus iteration.
- Follow basic software engineering principles and ensure program quality.
- Understand memory management and pointers in C++.

## Projects

### [The Size of Numbers in C++](./projects/size_of_numbers.cpp)
Explore the size of different types of numbers in C++ by using preprocessor macros, `sizeof()`, and the `pow()` function. This project helps understand memory limitations in C++ and calculates values based on the size of data types.  

#### Tasks:
- Print preprocessor macros for signed and unsigned types.
- Use `sizeof()` and `pow()` to calculate the size and limit of number types.
- Implement program style guidelines with appropriate comments.



---

### [Variables and Conditionals](./projects/variables_and_conditionals.cpp)
Create a text adventure game using if-statements and conditionals to design paths and random outcomes. Handle user input and implement a decision-making structure with nested if-statements.

#### Tasks:
- Create a text adventure with branching paths.
- Implement a random element that influences the user's journey.
- Ensure proper handling of user input and validation.


---

### [Conditionals and Loops](./projects/conditionals_and_loops.cpp)
Design a card game similar to BlackJack, where players bet against the dealer and try to reach a total closer to 21 without busting. Handle multiple players, bets, and gameplay mechanics.

#### Tasks:
- Simulate a card game using conditionals and loops.
- Handle user input for multiple players and bets.
- Implement logic for the dealer's behavior and player outcomes.


---

### [Functions](./projects/functions.cpp)
Create a program that calculates a business trip expense report. The program will handle expenses like airfare, car rental, meals, and hotel fees, with various reimbursement rules.

#### Tasks:
- Collect input for trip expenses (car rental, meals, etc.).
- Calculate total expenses and reimbursements based on company policies.
- Ensure proper validation of input and handling of invalid data.



---

### 1D Array and Recursion
This project includes two parts: Word Frequency and Recursive Fractals. For Word Frequency, count the occurrence of specific words in a paragraph. For Recursive Fractals, generate patterns using recursion.

#### Tasks:
- Implement word frequency calculation using dynamic arrays.
- Create a fractal pattern using recursion with specific input parameters.

[Project File One](./projects/word_frequency.cpp)  
[Project File Two](./projects/recursive_fractals.cpp)

---

### [1D and 2D Arrays](./projects/heat_diffusion.cpp)
Simulate heat diffusion using a 1D or 2D model. The program will calculate temperature diffusion over time using the explicit method for finite difference approximations.

#### Tasks:
- Simulate heat diffusion using arrays.
- Implement the explicit method and calculate stability based on input parameters.
- Handle 1D and 2D simulations and print results at each time interval.


## Labs
Lab work resides in the ```labs/``` folder where there are nine folders labeled one through ten excluding lab two because it did not require programming work. Below is a short description of each lab, the full lab assignments are available in their respected folder in a pdf document.

### [Lab One](./labs/one/)
#### Introduction to Linux and C++ Setup
This lab introduces essential Linux commands and the process of setting up a development environment for C++ programming. Participants configure their ENGR accounts, connect to the ENGR server, navigate the Linux file system, and create directories. Additionally, they write, compile, and execute a basic C++ program while exploring differences between the GNU and Clang compilers.

#### Tasks:
- Establish an ENGR account and connect via SSH.
- Practice fundamental Linux commands (e.g., ```ls```, ```pwd```, ```mkdir```).
- Use the ```vim``` editor to write a "Hello World" program in C++.
- Compile and execute the program using both ```g++``` and ```clang++```.
- Analyze compilation errors by modifying the code and comparing compiler outputs.



### [Lab Three](./labs/three/)
#### Take-Home Lab: Logical Operators and Loops
This lab focuses on understanding logical and relational operators, short-circuiting, and implementing loops in C++. It includes a quiz, a worksheet on operators, and a programming task to determine prime numbers using loops.

#### Tasks:

- Complete a quiz on course policies and submission guidelines.
- Identify and differentiate logical and relational operators.
- Design and implement a prime number checker (```is_prime.cpp```) that validates user input and allows multiple tests in a single run.
- Use ```while``` and ```for``` loops to process user inputs and determine primality.

### [Lab Four](./labs/four/)
#### Roman Numeral Conversion and Functions
This lab focuses on problem-solving with loops, functions, and refactoring in C++. Participants will design and implement programs to convert between Roman numerals and decimal values. Pair programming is encouraged, with structured collaboration roles.

#### Tasks:

- Complete a quiz on functions and refactoring.
- Design a solution to convert Roman numerals to decimal values.
- Implement ```decimal_to_roman.cpp,``` converting decimal numbers to Roman numerals.
- Refactor the conversion logic into a function ```d_to_r()```, improving code modularity.

### [Lab Five](./labs/five/) 
#### Proficiency Demo, Vim, and Functions
This lab focuses on demonstrating coding proficiency, mastering Vim, and working with value-returning and void functions in C++. Participants will complete a timed coding challenge, practice Vim commands, and explore different ways to pass arguments in functions.

#### Tasks:

- **Proficiency Demo:** Select and complete one coding problem involving variables, user input, conditionals, and loops within 50 minutes.
- **Vim Exercises:** Practice essential Vim commands, create a ```.vimrc``` configuration file, and write a simple C++ program.
- **Value-Returning Functions:** Implement ```get_sentence()``` to return a user-inputted string using ```getline()```.
- **Void Function with Argument Passing:** Modify ```get_sentence()``` to take a string argument and demonstrate the effect of passing by value.
- **Pass by Reference:** Update ```get_sentence()``` to use pass-by-reference and observe how the output changes.

### [Lab Six](./labs/six/) 
#### Function Parameters and Recursion
This lab focuses on understanding function parameters, pass-by-reference, and recursion. Participants will analyze how function arguments are passed and explore recursive function behavior using factorial computation.

#### Tasks:

- **Function Parameter Analysis:** Compare pass-by-value and pass-by-reference by tracing ```get_sentence()``` with and without an ampersand (```&```). Use a diagram to illustrate how function arguments are handled in memory.
- **Recursion Exploration:** Examine a recursive ```factorial()``` function, tracing its execution step by step.
- **Conceptual Questions:** Analyze the impact of missing function prototypes, base cases, and variable scope in recursive functions.

### [Lab Seven](./labs/seven/)
#### Recursion, Fibonacci, and Pointers
This lab explores recursion, pointers, and function design in C++. Participants will analyze recursive functions, implement Fibonacci calculations, and practice working with pointers in function parameters.

#### Tasks:

- **Code Tracing:** Analyze given recursive functions, predicting outputs and identifying infinite recursion cases.
- **Conceptual Discussion:** Compare and contrast references and pointers in C++, examining memory access and usage.
- Recursive Fibonacci Function: Implement ```fib_recurs()``` to compute Fibonacci numbers and apply the concept to a staircase problem.
- **Pointer-Based String Manipulation:** Design and implement functions to manipulate a string using pointers, including replacing characters and searching for specific letters.

### [Lab Eight](./labs/eight/)
#### Memory Management, Debugging, and Arrays
This lab focuses on dynamic memory, debugging with GDB, and working with 1-D arrays in both C-style and C++ string formats. Participants will learn to handle memory issues, debug programs, and implement array-based solutions to handle user input.

#### Tasks:

- **Conceptual Questions:** Discuss the stack vs. heap memory, dynamic memory, memory leaks, and array handling in C++ and C-style strings.
- **Debugging with GDB:** Use GDB to debug a simple program, set breakpoints, step through code, inspect variable values, and track segmentation faults.
- **1-D Arrays in Assignment 5:**
    - **C-style string:** Create a C-style string to store a sentence and handle user input with ```cin.getline()```.
    - **C++ strings:** Implement an array of C++ strings, allowing the user to input multiple search words and print both arrays to validate input.
    - **Memory Management:** Check for memory leaks and handle potential errors when reading more characters than allocated. 


### [Lab Nine](./labs/nine/)
#### Towers of Hanoi: Recursion and Dynamic Memory
This lab focuses on implementing the Towers of Hanoi puzzle using recursion, static and dynamic 2D arrays, and memory management. Participants will explore recursion to solve the puzzle, then transition to dynamically allocated memory for larger problem sizes.

#### Tasks:

- **Worksheet - Design:**
    - Analyze and write the steps for solving Towers of Hanoi for 1, 2, and 3 disks.
    - Observe patterns and identify the base case in recursion.
    - Walk through the algorithm with the TA using recursive function calls, e.g., ```towers(1, 1, 2, 3)```, ```towers(2, 1, 2, 3)```, and ```towers(3, 1, 2, 3)```.
- **Static 2D Array Implementation:**
    - Implement the Towers of Hanoi solution using a static 2D array to represent the board, printing the board after each move.
- **Dynamic 2D Array Implementation:**
    - Transition to dynamically allocating the 2D array based on user input (e.g., ```towers 5```), and modify the ```towers()``` and ```print_array()``` functions to work with dynamically allocated memory.
- **Memory Management:**
    - Create functions to allocate and deallocate the 2D array dynamically.
    - Use ```valgrind``` to check for memory leaks and ensure proper memory handling.

### [Lab Ten](./labs/ten/)
#### Dynamic Arrays and 2D Arrays in C++
This lab focuses on the use of dynamic memory allocation with 1D and 2D arrays, as well as basic memory management. Participants will learn how to dynamically allocate memory for arrays and work with multi-dimensional arrays, including how to fill them with data, perform calculations, and output results.

#### Tasks:

- **Dynamic Memory Allocation with 1D Arrays:**
    - In the ```1_D_INT.cpp``` file, dynamically allocate memory for arrays using ```new``` and initialize them with a sequence of numbers. Use a ```sum()``` function to add corresponding elements from two dynamically allocated arrays and store the result in a third array. Ensure proper memory management by deallocating the arrays with ```delete[]```.
- **Randomized 2D Arrays:**
    - In the ```2_D_ARRAY.cpp``` file, generate a 2D array of random numbers and calculate row and column sums. Dynamically compute and display these sums while properly formatting the output.
- **Memory Management:**
    - Understand the importance of memory allocation and deallocation. In the 1D array example, dynamically allocate memory for three integer arrays, perform operations, and free the memory using ```delete[]```.
    - In the 2D array example, allocate memory for a static 2D array, perform calculations, and print the results formatted in columns.
- **Pattern Observation and Debugging:**
    - Analyze the outputs of both programs to understand the relationship between memory management and array manipulation. Debug any errors related to dynamic allocation and output formatting.






