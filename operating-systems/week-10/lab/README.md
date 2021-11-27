# Operating Systems Lab 10 -- Socket Programming Part 1

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

This week we will explore how the operating system allows us to connect between different applications. To do so, the operating system provides a **socket** API. A socket contains all the information required to connect one process to another process, either on the local machine or across a network. For our purposes, a socket requires two pieces of information:

- An **address** (in our case an **IP address**) used to determine which system we want to connect to.
- A **port** which is a unique number that allows us to create multiple sockets in an operating system, and therefore connect to a specific application.

All operating systems (and most programming language standard libraries) provide a socket API and it's use is standardised across the different implementations, so the ideas here work in other situations.

## Creating a Socket

Linux provides its socket API in the `socket.h` header file:

```c
#include <sys/socket.h>
```

Creating a socket is simple -- we use the `socket` function call:

```c
int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
```

`socket` takes three parameters:

- A *domain* value which defines what protocol we are using. We will be using TCP/IP in this lab, so our protocol domain is IPv4 or `AF_INET` in Linux.
- The *type* of socket being created. We are using TCP/IP and our socket type will be TCP which is represented by `SOCK_STREAM` in Linux.
- The *protocol* used. In our case only one exists, so we use `0`.

The call to `socket` returns an `int` that is the unique ID for the socket in the operating system.

### Your Task

Let us create our first socket application. It won't do anything but create a socket.

1. **Download the code [`ex10_1.c`](ex10_1.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex10_1.c -o ex10_1` on the terminal.**
4. **Run the application  using `./ex10_1` on the terminal.**

If all has gone well your output will be:

```shell
Socket created
```

## Resolving a Host IP Address

Before we can connect our socket to something we require an IP address to connect to. Let us imagine we want to connect to Roehampton's web site -- <www.roehampton.ac.uk>. How do we find the IP address for Roehampton's web site? Well, we need to resolve the name to an address. Firstly, we require two new headers:

```c
#include <netdb.h>
#include <arpa/inet.h>
```

Our first data structure we need to know about is `hostent`:

```c
struct hostent he;
```

`hostent` contains various pieces of information, one of which is the list of IP addresses we can use to connect to a host. *That's right -- a host may have multiple IP addresses* (how do you think Google works?).

To initialise a `hostent` data structure we use `gethostbyname`:

```c
struct hostent* he = gethostbyname("hostname");
```

`gethostbyname` requires the name of the host we want to resolve (it will be `www.roehampton.ac.uk` in our case). Note that `gethostbyname` returns a pointer to a `hostent` data structure.

We can get the IP addresses from a `hostent` structure by accessing the `h_addr_list` property. `h_addr_list` is an array of `char*` but is actually a series of bytes representing the IP address which we'll have to convert to a `struct in_addr` type:

```c
struct in_addr *addr = (struct in_addr*)he->h_addr_list[0];
```

We will just use the first address in the list and hope it works for now.

To actually convert the `struct in_addr` to an IP address we can display we use `inet_ntoa`, the result of which we copy into a `char*` using `strcpy`.

```c
strcpy(ip, inet_ntoa(*addr));
```

We now have the IP address as a string in our program.

### Your Task

Let us now resolve the IP address for Roehampton's website in our program.

1. **Download the code [`ex10_2.c`](ex10_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex10_2.c -o ex10_2` on the terminal.**
4. **Run the application  using `./ex10_2` on the terminal.**

If the program has worked the output should be (**note** -- the IP address might be different):

```shell
www.roehampton.ac.uk resolved to: 104.18.24.40
```

## Connecting to another Host

Now we have an IP address we can connect our socket to the relevant host. To do this, we first need to describe what we want to connect to using a `sockaddr_in` data structure:

```c
struct sockaddr_in server;
```

`sockaddr_in` has a number of values we can set, but we are interested in only three:

- The IP address.
- The protocol type.
- The port number we want to connect to.

If you don't remember, the default website port is `80`. To set up our `struct sockaddr_in` we do the following:

```c
server.sin_addr.s_addr = inet_addr(ip);
server.sin_family = AF_INET;
server.sin_port = htons(80);
```

For our three values:

- We have the IP address (stored in the value `ip`), but we have to convert it to a `in_addr_t` using the function `inet_addr` with the parameter `ip`. This goes in the value `sin_addr.s_addr` of our `struct sockaddr_in`.
- We set `sin_family` to `AF_INET` -- the same domain family we use in our `socket`.
- We set `sin_port` to `80`. However, we have to use `htons` to convert the port number from Linux byte ordering to network byte ordering (that is right -- the network stores numbers differently to Linux).

With these three values set we can use the `connect` function to connect to the web server:

```c
status = connect(socket_desc, (struct sockaddr*)&server, sizeof(server));
```

`connect` takes three parameters:

- The `socket` we want to use to connect.
- The address we want to connect to, which we convert to a `sockaddr*` type.
- The size of the address data structure.

`connect` returns a status value to define if the connection has been successful.

### Your Task

Let us connect to Roehampton's web server:

1. **Download the code [`ex10_3.c`](ex10_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex10_3.c -o ex10_3` on the terminal.**
4. **Run the application  using `./ex10_3` on the terminal.**

Your output should be similar to the following:

```shell
www.roehampton.ac.uk resolved to: 104.18.25.40
Socket created
Connected
```

## Sending a Message

Now we have connected to the web server we can send it a message. You probably don't know enough about the HTTP protocol, but we can construct a message to get a web page. For example, to get the root document (also known as `index.html` of <www.roehampton.ac.uk`) we send a message as follows:

```http
GET / HTTP1.1

```

We write this in our C program as follows:

```c
message = "GET / HTTP/1.1\r\n\r\n";
```

To send a message to another application via a socket we use the `send` function:

```c
status = send(socket_desc, message, strlen(message), 0);
```

`send` takes four parameters:

- The *socket* we are sending the message on.
- The *message* to send -- a `char*` or array of bytes.
- The *size* of the message sent in bytes.
- Any *flags* associated with the message send. We won't be using any so set this to zero.

`send` returns a status value to tell you if it was successful.

### Your Task

Now let us send a message to the web server we have connected to.

1. **Download the code [`ex10_4.c`](ex10_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex10_4.c -o ex10_4` on the terminal.**
4. **Run the application  using `./ex10_4` on the terminal.**

Your output should be similar to the following:

```shell
www.roehampton.ac.uk resolved to: 104.18.24.40
Socket created
Connected
Data sent
```

## Receiving a Response

Once we've sent a message to the web server we will get a response back again. To receive a response we use the `recv` function:

```c
status = recv(socket_desc, server_reply, 2000, 0);
```

`recv` takes four parameters and is very similar to `send`:

- The *socket* we are receiving the message on.
- A *buffer* to receive the message into -- a `char*` or array of bytes.
- The *size* of the buffer we can receive into.
- Any *flags* associated with the message receive. We won't be using any so set this to zero.

`recv` also returns a status value to tell you if it was successful.

### Your Task

Let us now receive the response from the web server to see what our request resulted in.

1. **Download the code [`ex10_5.c`](ex10_5.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex10_5.c -o ex10_5` on the terminal.**
4. **Run the application  using `./ex10_5` on the terminal.**

Your output should be as follows:

```c
www.roehampton.ac.uk resolved to: 104.18.25.40
Socket created
Connected
Data sent
Reply received
HTTP/1.1 400 Bad Request
Server: cloudflare
Date: Sat, 27 Nov 2021 08:22:29 GMT
Content-Type: text/html
Content-Length: 155
Connection: close
CF-RAY: -

<html>
<head><title>400 Bad Request</title></head>
<body>
<center><h1>400 Bad Request</h1></center>
<hr><center>cloudflare</center>
</body>
</html>
```

This response is expected. We send a standrad HTTP request and most websites today expect an HTTPS (secure HTTP) request.

## Over to You -- Experimenting with Sockets

Now you know how to create a network socket, connect it to a server, and send and receive responses. You should experiment with this now. For example, try accessing different websites, different webpages, and sending different HTTP requests. You have complete flexibility to experiment and see what the result will be.