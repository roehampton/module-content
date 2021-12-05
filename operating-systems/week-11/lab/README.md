# Operating Systems Lab 11 -- Socket Programming Part 2: Server Sockets

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this final lab, you will learn how to create a socket that listens for new incoming connections. This is the fundamental building block for all Internet servers -- creating a server socket and listening for new incoming connections.

## Creating a Server Socket

Creating a server socket is a two step process. First, we have to describe the server socket using a `sockaddr_in` structure.

```c
struct sockaddr_in server;

server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(port);
```

The three values we want to set are:

- `sin_family` -- this is `AF_INET` as we have been using for IPv4 connections.
- `sin_addr.s_addr` -- as you might remember, a device can have multiple IP addresses -- one for each interface/device. We can listen on specific addresses, but it is normally best to listen on all addresses using `INADDR_ANY`.
- `sin_port` -- the port we want to listen on. This is the port number a client uses to connect to the server.

Then to create the server socket we just use the `bind` function:

```c
status = bind(socket_desc, (struct sockaddr*)&server, sizeof(server));
```

`bind` is similar to `connect` but is used by server sockets. The parameters are:

- The socket that we are binding.
- The `sockaddr_in` data structure that describes the socket.
- The size of the address data structure.

Finally, when we are finished with a socket, we must close it using `close`:

```c
close(socket_desc);
```

### Your Task

There are two programs you will be using for each exercise. The first program -- `test_client.c` -- is a simple test application to communicate with our server. The exercises will slowly develop a server application.

1. **Download the code [`test_client.c`](test_client.c){:target="_blank"}**.
2. **Comment the code of `test_client.c` to ensure you understand what it does.**
3. **Build the application using `gcc test_client.c -o test_client` on the terminal.**
4. **Download the code [`ex11_1.c`](ex11_1.c){:target="_blank"}**.
5. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
6. **Build the application using `gcc ex11_1.c -o ex11_1` on the terminal.**
7. **Run the application  using `./ex11_1` on the terminal.**

The server doesn't do anything right now, so your output will only be as follows if it works:

```c
Server socket created
```

## Listening For and Accepting a New Connection

Creating a server socket does not do much. To activate the server socket we have to tell it to listen for connections using `listen`:

```c
listen(socket_desc, 3);
```

`listen` takes two parameters:

- The socket we want to listen on.
- The number of waiting connections we will queue. We will use `3` as a value, but anything more than `0` is acceptable. It depends how bust the connection is.

Once we are listening on a socket, we can use `accept` to complete a connection from a client. Sample code is:

```c
struct sockaddr_in client;

size = sizeof(client);
new_socket = accept(socket_desc, (struct sockaddr*)&client, &size);
```

`accept` returns a new socket -- this allows us to communicate with the other device independently of the listening connection. `accept` takes three parameters:

- The socket we are accepting a connection on.
- A pointer to an address data structure that will contain the client connection information.
- A pointer to a value representing the size of the address.

Finally, we must close the new connection when we are finished with it.

```c
close(new_socket);
```

### Your Task

1. **Download the code [`ex11_2.c`](ex11_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex11_2.c -o ex11_2` on the terminal.**
4. **Run the application  using `./ex11_2` on the terminal.**
5. **In a separate terminal, run the test client using `./test_client` -- make sure you are in the correct directory.**
6. **Enter `0` on the `test_client` to exit.**

The output on the server program will be:

```c
Server socket created
Server listening on port 5000
Connection successful
```

For the client it will be:

```c
Socket created
Connected
Enter message to send (0 to exit): 0
```

## Sending and Receiving Messages

Once you have a new client connection, we can use `recv` and `send` to communicate with the other device.

1. **Download the code [`ex11_3.c`](ex11_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex11_3.c -o ex11_3` on the terminal.**
4. **Run the application  using `./ex11_3` on the terminal.**
5. **In a separate terminal, run the test client using `./test_client` -- make sure you are in the correct directory.**
6. **Enter a message to send from `test_client`, for example `hello`.**
7. **Enter `0` on the `test_client` to exit.**

The output on the server will be:

```c
Server socket created
Server listening on port 5000
Connection successful
Server received hello
```

On the client it will be:

```shell
Socket created
Connected
Enter message to send (0 to exit): hello
Data sent
Reply received
Goodbye, world!
Enter message to send (0 to exit): 0
```

## Accepting Multiple Connections

Our program only accepts a single message. We can extend it to loop accepting new connections easily enough.

1. **Download the code [`ex11_4.c`](ex11_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex11_4.c -o ex11_4` on the terminal.**
4. **Run the application  using `./ex11_4` on the terminal.**
5. **In a separate terminal, run the test client using `./test_client` -- make sure you are in the correct directory.**
6. **Enter a message to send from `test_client`, for example `hello`.**
7. **Enter a message to send from the server to the `test_client`**
8. **Enter `0` on the `test_client` to exit.**
9. **Run `test_client` again and send new messages between the programs, then exit.**
10. **Stop the server program using CTRL-C.**

For example, your server output could be:

```shell
Server socket created
Server listening on port 5000
Connection successful
Server received boo
Enter reply: hello
Connection successful
Server received test
Enter reply: test 2
```

## Handling Multiple Connections with Threads

The problem we have right now is we can only talk to one client. We need a way to accept a new connection and then manage that communication separately to the listening for new connections. For that we need threads!

1. **Download the code [`ex11_5.c`](ex11_5.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex11_5.c -o ex11_5 -pthread` on the terminal.**
4. **Run the application  using `./ex11_5` on the terminal.**
5. **In a separate terminal, run the test client using `./test_client` -- make sure you are in the correct directory.**
6. **Enter a message to send from `test_client`, for example `hello`.**
7. **Enter a message to send from the server to the `test_client`**
8. **Continue to send messages back and forth between the two programs, entering `0` to exit the `test_client`.**
9. **Run `test_client` again and send new messages between the programs, then exit.**
10. **Stop the server program using CTRL-C.**

An example output from the server could be:

```shell
Server socket created
Server listening on port 5000
Connection successful
Starting new connection handler
Received: hello

Enter reply: goodbye
Received: test

Enter reply: test2
```

## Over to You -- Running Servers

You now know how to create your own simple server. You can do almost anything you want now for delivering content and services online in your own way. The general principle is the same for all languages and libraries supporting networking -- create a server socket and service new connections.

You should consider the following exercise challenges:

- Creating a simple Telnet server.
- Updating the server application to properly manage the threads and connections.
- Integrating the server model into a kernel module.

Also, you can try connecting between two actual devices. **NOTE** -- on Azure Labs this might not be possible, but find someone else's IP address and one of you run the client and the other the server.