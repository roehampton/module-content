# Operating Systems Coursework

This coursework is worth **50% of the total module mark.** The submission date is **Wednesday 15th of December (Week 12) online via Moodle by 2pm.**

The coursework evaluates the following learning outcomes of the module:

- **Construct a simple program using methods of layering, error detection and recovery, and reflection of error status across layers.**
- **Implement a simple client-server socket-based application.**

## Specification

In this coursework you will develop a Linux kernel module to listen to incoming connections. The kernel module will have the following functionality:

- The kernel module will have one parameter -- `port` which is the port number that the module will use. By default, `port=5000`.
- On start, the kernel module will launch a kernel thread (`kthread`).
- The launched `kthread` will listen for incoming connections on the defined `port`.
- When a connection is received, an absolute filename is read from the client (e.g., `/etc/fstab`).
- Depending on if the file exists, the module will perform one of the following:
  - If the file exists:
    - A kernel information message is printed to the log stating `Reading file <filename>` with `<filename>` replaced with the name of the file requested.
    - The complete file contents should be read and sent back to the client.
    - A kernel information message is printed to the log stating `<filename> sent to <ip>` with `<filename>` replaced by the name of the file and `<ip>` replaced with the IP address of the client.
  - If the file does not exist:
    - A kernel error message is printed to the log stating `Error <filename> does not exist` with `<filename>` replaced by the name of the file.
    - A message `NULL` is sent back to the client.
- On module unloading, the `kthread` must be stopped.

You **must** also create a client program which performs the following:

- Asks the user for an IP address to connect to.
- Asks the user for a port to connect to.
- Connects to the IP address and port.
- Loops until the user enters `exit` as a filename:
  - Ask the user for a filename.
  - Requests the filename from the server.
  - Reads the file contents from the server.
  - If the return value is not `NULL`:
    - Prints `<filename> is <size> bytes` to the terminal, with `<filename>` replaced by the name of the file and `<size>` replaced by the size of the file in bytes.
  - If the return value is `NULL`:
    - Prints `<filename> does not exist on the server` with `<filename>` replaced by the name of the file.

## Advice

Approach developing this program over several weeks based on what you know. Do so iteratively. The following stages are probably the most sensible. Each should be an individual working program/system:

1. Create a Linux kernel module.
2. Extend the Linux kernel module to create a thread that just prints messages every second.
3. Extend the kernel module so that the thread listens and accepts incoming connections.
4. Create a client application that can connect to the kernel module.
5. Extend the kernel module to read in the file names.
6. Extend the client application to send file names to the kernel module.

## Submission Requirements

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

You are required to submit the following four files only:

- The Linux kernel module source file.
- The Linux kernel module `Makefile`.
- The client application source file.
- A readme detailing the application and how it works, including any assumptions you have made during development.

**All submissions must be demonstrated to the module tutor. If you fail to demonstrate your assessment it will result in a mark of zero.**

## Marking Scheme

The following rubric will be used:

| **Criteria**                                                 | **Excellent**                                                | Good                                                         | **Satisfactory**                                             | **Unsatisfactory**                                           | **Not Attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Solution** the completeness of the code to meet the specification given. | A running solution meeting all the specification.            | A running solution that meets the majority of the specification. | A running solution that only meets about 50% of the specifications. | A running solution but lacks much of the specification.      | Solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | Program produces correct answers or appropriate results for all inputs tested. | Program produces correct answers or appropriate results for the majority of inputs. | Program produces correct answers or appropriate results for about 50% of all inputs. | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | Program does not produce correct answers or appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is correct contains minor boundary errors, redundant conditions, or contradictory conditions. | Program logic is mostly correct but contains some boundary error, redundant conditions, or contradictory condition. | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=). | Program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous or unexpected input gracefully; action is taken without surprising the user. | Program handles almost all erroneous or unexpected input gracefully without surprising the user. | All obvious error conditions are checked for and appropriate action is taken. | Some obvious error conditions are checked for and some sort of action is taken. | Program often fails or fails completely. Boundary conditions are not tested for. |
| **Error freedom** removal of all errors existing within the current program. | All errors removed such that the program will compile and run under all conditions. | All obvious errors are removed but there are some smaller issues not rectified. Program will compile and run. | Most obvious errors are removed but there are some. Program will compile and run. | Some obvious errors fixed (about 50%) but some still exist. Program will compile and run. | Program either fails to compile, or if it does then it fails to run or has serious errors when running. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. Readme is clear and describes program submission. | Program is mostly documented. Indentation and other formatting is appropriate. Readme documents how the program works. | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. Readme generally describes the submission. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. Readme is very brief. | Program contains no documentation, or grossly misleading indentation. No readme or an improper readme provided. |

### Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university <https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx>.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.
