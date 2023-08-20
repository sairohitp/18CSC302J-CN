SIMPLE TCP/IP CLIENT SERVER COMMUNICATION

Aim:
There are two hosts, Client and Server. The Client accepts the message from the user and sends it to the Server. The Server receives the message and prints it.

TECHNICAL OBJECTIVE:
To implement a simple TCP Client-Server application , where the Client on establishing a connection with the Server, sends a string to the Server. The Server reads the String and prints it.

METHODOLOGY: 

Server:
• Include the necessary header files.
• Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
• Initialize server address to 0 using the bzero function.
• Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to a dynamically assigned port number.
• Bind the local host address to socket using the bind function.
• Listen on the socket for connection request from the client.
• Accept connection request from the client using accept function.
• Within an infinite loop, using the recv function receive message from the client and print it on the console.

Client:
• Include the necessary header files.
• Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
• Initialize server address to 0 using the bzero function.
• Assign the sin_family to AF_INET.
• Get the server IP address and port number from the console.
• Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of the server address structure.
• Request a connection from the server using the connect function.
• Within an infinite loop, read message from the console and send the message to the server using the send function.