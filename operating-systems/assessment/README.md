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

You are required to submit the following four files only:

- The Linux kernel module source file.
- The Linux kernel module `Makefile`.
- The client application source file.
- A readme detailing the application and how it works, including any assumptions you have made during development.

