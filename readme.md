# Minitalk 💬

## What's Cooking? 🧑‍🍳

![](minitalk.png)
Welcome to Minitalk! 🎉 It's a nifty, cool-as-cucumber server-client setup that speaks the language of UNIX signals (SIGUSR1 and SIGUSR2). It's the brainchild of the programming adventures at the 42 School! 🏫

The essence of Minitalk? The client sends a string over to the server, and the server just prints it out, like the good buddy it is! 📝 And the most fascinating part? The string gets converted into binary and is sent bit by bit!

Our two superheroes in this saga are:

- `client.c` 📤: The client, always ready to send out the message.
- `server.c` 📥: The server, patiently waiting to receive and decode the message.

## The Magical Process ✨

### Client, the Messenger 📤

The client needs two things to get started: the PID (Process ID) of the server and a string. Then, it's game time! 🚀 The client converts each character of the string into binary, bit by bit. These bits are then sent as separate signals to the server. Here's a fun fact: SIGUSR1 is the messenger for bit value '1', and SIGUSR2 carries '0'.

### Server, the Receiver 📥

The server has a simple life. It starts its day by announcing its PID to the console. After that, it's all about waiting for the signals, like a faithful dog waits for its owner! 🐕 When a signal comes in, it joins the current bit sequence. And once we have a full byte (that's 8 bits), it's transformed back into a character and printed to the console. Voila! 🎁

## Let's Get Rolling 🎲

1. Fire up the terminal and compile the server and client with a simple `make` command:

```bash
make
```
2. Time to wake up the server:

```bash
./server
```

The server will greet you with its PID. Remember it, you'll need it!

3. Get the client into the game:

```bash
./client <server_pid> <string>
```

Heads Up! 🎈

This project is like a fascinating sandbox where we play around with UNIX signals and interprocess communication. It's not built for big-league matches like large data transfers, but hey, it's super fun and insightful! 😁

Prerequisites 📋

A brave GCC compiler (or equivalent)
A Unix-like operating system to host the party
A basic knack for C programming and Unix signals. But don't worry, you've got this!