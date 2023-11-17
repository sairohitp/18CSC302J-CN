## File Transfer Protocol implementation in C

The server offers the following operations:
 - `PUT` : Upload a file to server
 - `GET` : Download file from server
 - `MPUT` : Upload multiple files of specified extension
 - `MGET` : Download multiple files of specified extension

## Instructions
============

```
$ gcc server.c -lpthread -o server
$ ./server <PORT_NUM>
$ gcc client.c -o client
$ ./client <SERVER_ADDR> <SERVER_PORT>
```
