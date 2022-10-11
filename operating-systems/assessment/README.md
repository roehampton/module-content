# Operating Systems Coursework

This coursework is worth **50% of the total module mark.** The coursework is divided into two parts.

The coursework evaluates the following learning outcomes of the module:

- **Construct a simple program using methods of layering, error detection and recovery, and reflection of error status across layers.**
- **Implement a simple client-server socket-based application.**

## Part One -- Lab Exercises (25% of coursework total)

**Various Deadlines -- Final 13/12/2022**

25% of the coursework marks will be awarded for completing the following lab exercises:

- **Completed by Week 6 of Teaching (Lab on 31/10/2022 or 1/11/2022)**
  
  - 3.3 - Printing from Multiple Processes
  
  - 3.5 - Waiting for Processes
  
  - 3.6 - Waiting for Specific Processes
  
  - 4.2 - Thread ID
  
  - 4.3 - Sleeping
  
  - 4.4 - Mutual Exclusion
  
  - 5.6 - Setting Thread Scheduler
  
  - 5.7 - Round Robin and Thread Priorities
  
  - 5.8 - Setting Thread Affinity

- **Completed by Week 10 of Teaching (Lab 28/11/2022 or 29/11/2022)**
  
  - 6.1 - Creating a Linux Kernel Module
  
  - 6.2 - Flexible Kernel Module Development
  
  - 6.4 - Module Parameters
  
  - 7.1 - Creating a Kernel Thread
  
  - 7.2 - Stopping a Kernel Thread
  
  - 7.3 - Using Kernel Mutual Exclusion Locks
  
  - 8.4 - Implementing Read Behaviour
  
  - 8.5 - Implementing Write Behaviour
  
  - 9.3 - Sending Data From a User Program
  
  - 9.4 - Writing Data to a User Program

- **Completed by Week 12 of Teaching (Lab 12/12/2022 or 13/12/2022)**
  
  - 10.3 - Connecting to Another Host
  
  - 10.4 - Sending a Message
  
  - 10.5 - Receiving a Response
  
  - 11.3 - Sending and Receiving Messages
  
  - 11.4 - Accepting Multiple Connections
  
  - 11.5 - Handling Multiple Connections with Threads

**You must demonstrate and explain your solution to the lab exercises to a member of the teaching team. This must be done during any lab session before the deadlines provided above.** Failure to demonstrate and explain your solution by the appropriate date will mean scoring a zero for that exercise.

A checklist will be kept on Moodle and updated by the teaching team as you complete tasks.

## Part Two -- Coursework Deliverable (75% of coursework total)

This part of the coursework is divided into two parts - Part A and Part B.

**Various Deadlines -- Final 06/01/2023.**

**All coursework must be demonstrated and explained to a member of the teaching team. Not demonstrating the coursework will result in a mark of zero.****

### Part A -- Kernel Module Development (45% of coursework total)

**Deadline -- end of Week 10 of Teaching 02/12/2022.**

#### Specification

In Part A of the coursework, you will develop a Linux kernel module and the supporting client program. The kernel module will have the following functionality:

- The kernel module must have appropriate information added (license, author, and description).
- The kernel module will have two parameters:
  - `num1` is an integer.
  - `num2` is another integer.
- The kernel module must respond to commands via `ioctl` as follows:
  - `HELLO` -- the kernel module prints `Hello World` to the log.
  - `GOODBYE` -- the kernel module prints `Goodbye World` to the log.
  - `PRINT_1` -- the kernel module prints the current value of `num1` to the log and increments `num1` by 1.
  - `PRINT_2` -- the kernel module prints the current value of `num2` to the log and increments `num2` by 1.
  - If the kernel module receives a command it does not recognise, it must print an error message to the log but **not** terminate.
- The kernel module should respond as a character device to read and write messages:
  - When a program reads from the character device, it should provide the current values of `num1` and `num2` in the following message format: `MY MODULE: num1 num2` with `num1` and `num2` replaced by the appropriate values.
  - When a program writes to the character device, it should print the message to the log in the following format: `MY MODULE RECEIVED: message` where `message` is replaced by the incoming message.

The supporting client program should ask the user what commands they want to perform and send them to the kernel module as appropriate.

#### Advice

Approach developing this program over several weeks based on what you know. Do so iteratively. The following stages are probably the most sensible. Each should be an individual working program/system:

1. Create a Linux kernel module.
2. Add the kernel module information.
3. Add the kernel module parameters.
4. Extend the kernel module to print the messages to the log.
5. Extend the kernel module to act as a character device with read and write messaging.
6. Extend the kernel module to accept `ioctl` commands.
7. Write the user program to communicate with the kernel module.

#### Submission Requirements

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

You are required to submit the following four files only:

- The Linux kernel module source file.
- The Linux kernel module `Makefile`.
- The client application source file.
- A readme detailing the application and how it works, including any assumptions you have made during development.

**All submissions must be demonstrated to the module tutor. If you fail to demonstrate your assessment it will result in a mark of zero.**

#### Marking Scheme

The following rubric will be used:

| **Criteria**                                                                                                              | **Excellent**                                                                                                                                                                                                                | Good                                                                                                                                                     | **Satisfactory**                                                                                                                                                                         | **Unsatisfactory**                                                                                                                                         | **Not Attempted**                                                                                                                                                         |
| ------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Solution** the completeness of the code to meet the specification given.                                                | A running solution meeting all the specification.                                                                                                                                                                            | A running solution that meets the majority of the specification.                                                                                         | A running solution that only meets about 50% of the specifications.                                                                                                                      | A running solution but lacks much of the specification.                                                                                                    | Solution doesn’t run or does not meet the specifications defined.                                                                                                         |
| **Design** the suitability of the design of the program to meet the objectives and be maintainable.                       | An excellent design using appropriate layering techniques, breaking up of solution into suitable parts, and appropriate interfaces between solution components.                                                              | A good design that uses appropriate layering techniques, but solution could have been broken down somewhat more. Interfaces between components suitable. | A suitable design that could have been layered better and decomposition of components improved. Interfaces between components could be better.                                           | Design is poor, and misses layering and decomposition opportunities throughout. Interfaces are weak.                                                       | There appears to be no design thinking undertaken for how to solve the coursework.                                                                                        |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results.                     | Program produces correct answers or appropriate results for all inputs tested.                                                                                                                                               | Program produces correct answers or appropriate results for the majority of inputs.                                                                      | Program produces correct answers or appropriate results for about 50% of all inputs.                                                                                                     | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations.                                                 | Program does not produce correct answers or appropriate results for most inputs.                                                                                          |
| **Logic** ability to use correct program structures appropriate to the problem domain.                                    | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions.                                                                                                                        | Program logic is correct contains minor boundary errors, redundant conditions, or contradictory conditions.                                              | Program logic is mostly correct but contains some boundary error, redundant conditions, or contradictory condition.                                                                      | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=).                                                    | Program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous or unexpected input gracefully; action is taken without surprising the user.                                                                                                                       | Program handles almost all erroneous or unexpected input gracefully without surprising the user.                                                         | All obvious error conditions are checked for and appropriate action is taken.                                                                                                            | Some obvious error conditions are checked for and some sort of action is taken.                                                                            | Program often fails or fails completely. Boundary conditions are not tested for.                                                                                          |
| **Clarity** ability to format and document code for human consumption (Good Style)                                        | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. Readme is clear and describes program submission. | Program is mostly documented. Indentation and other formatting is appropriate. Readme documents how the program works.                                   | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. Readme generally describes the submission. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. Readme is very brief. | Program contains no documentation, or grossly misleading indentation. No readme or an improper readme provided.                                                           |

### Part B -- Client-Server Program (30% of coursework total)

**Deadline -- Assessment Week 1 06/01/2023.**

#### Specification

In Part B of the coursework, you will create two programs -- a client and a server -- that allow a remote machine to interact with your kernel module. The programs must have the following functionality:

- **Client program**
  
  - The client program should provide an interface similar to the one developed for your user program in Part A, except rather than communicating with the kernel module directly, it should send a message to the server application to perform the task, receive the result, and then print it to the screen.

- **Server program**
  
  - The server program should run, listening on port `5000`, and wait for a client connection.
  
  - When a new client connection is received, the server application should start a separate thread to manage the client connection and go back to waiting for new client connections.
  
  - The spawned thread should receive messages from the client application, perform the necessary interaction with the kernel module, and send back the response. The thread will keep doing this until a message `QUIT` is received from the client program.

#### Advice

Approach developing this program over several weeks based on what you know. Do so iteratively. The following stages are probably the most sensible. Each should be an individual working program/system:

1. Create a basic server program for the client to connect to.
2. Create a basic client program and connect it to the server, sending a simple message.
3. Update the client program to send the appropriate messages to the server program.
4. Update the server program to send back appropriate dummy messages to client based on the message received.
5. Update the server program to communicate with the kernel module and send back the correct message.

#### Marking Scheme

The following rubric will be used:

| **Criteria**                                                                                                              | **Excellent**                                                                                                                                                                                                                | Good                                                                                                                                                     | **Satisfactory**                                                                                                                                                                         | **Unsatisfactory**                                                                                                                                         | **Not Attempted**                                                                                                                                                         |
| ------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Solution** the completeness of the code to meet the specification given.                                                | A running solution meeting all the specification.                                                                                                                                                                            | A running solution that meets the majority of the specification.                                                                                         | A running solution that only meets about 50% of the specifications.                                                                                                                      | A running solution but lacks much of the specification.                                                                                                    | Solution doesn’t run or does not meet the specifications defined.                                                                                                         |
| **Design** the suitability of the design of the program to meet the objectives and be maintainable.                       | An excellent design using appropriate layering techniques, breaking up of solution into suitable parts, and appropriate interfaces between solution components.                                                              | A good design that uses appropriate layering techniques, but solution could have been broken down somewhat more. Interfaces between components suitable. | A suitable design that could have been layered better and decomposition of components improved. Interfaces between components could be better.                                           | Design is poor, and misses layering and decomposition opportunities throughout. Interfaces are weak.                                                       | There appears to be no design thinking undertaken for how to solve the coursework.                                                                                        |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results.                     | Program produces correct answers or appropriate results for all inputs tested.                                                                                                                                               | Program produces correct answers or appropriate results for the majority of inputs.                                                                      | Program produces correct answers or appropriate results for about 50% of all inputs.                                                                                                     | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations.                                                 | Program does not produce correct answers or appropriate results for most inputs.                                                                                          |
| **Logic** ability to use correct program structures appropriate to the problem domain.                                    | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions.                                                                                                                        | Program logic is correct contains minor boundary errors, redundant conditions, or contradictory conditions.                                              | Program logic is mostly correct but contains some boundary error, redundant conditions, or contradictory condition.                                                                      | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=).                                                    | Program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous or unexpected input gracefully; action is taken without surprising the user.                                                                                                                       | Program handles almost all erroneous or unexpected input gracefully without surprising the user.                                                         | All obvious error conditions are checked for and appropriate action is taken.                                                                                                            | Some obvious error conditions are checked for and some sort of action is taken.                                                                            | Program often fails or fails completely. Boundary conditions are not tested for.                                                                                          |
| **Clarity** ability to format and document code for human consumption (Good Style)                                        | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. Readme is clear and describes program submission. | Program is mostly documented. Indentation and other formatting is appropriate. Readme documents how the program works.                                   | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. Readme generally describes the submission. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. Readme is very brief. | Program contains no documentation, or grossly misleading indentation. No readme or an improper readme provided.                                                           |

## Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.
