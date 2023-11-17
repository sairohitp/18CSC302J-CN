Aim:<br/>
There are two hosts, Client and Server. Both the Client and the Server exchange message i.e. they send messages to and receive message from the other. There is a two way communication between them.

TECHNICAL OBJECTIVE:<br/>
To implement a full duplex application, where the Client establishes a connection with the Server. The Client and Server can send as well as receive messages at the same time. Both the Client and Server exchange messages.

Algorithm:<br/>
<br/>
Server:<br/>
<br/>
• Include the necessary header files.
• Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
• Initialize server address to 0 using the bzero function.
• Assign the sin_family to AF_INET, sin_addr to INADDR_ANY, sin_port to dynamically assigned port number.
• Bind the local host address to socket using the bind function.
• Listen on the socket for connection request from the client.
• Accept connection request from the Client using accept function.
• Fork the process to receive message from the client and print it on the console.
• Read message from the console and send it to the client.

Client:<br/>
• Include the necessary header files.
• Create a socket using socket function with family AF_INET, type as SOCK_STREAM.
• Initialize server address to 0 using the bzero function.
• Assign the sin_family to AF_INET.
• Get the server IP address and the Port number from the console.
• Using gethostbyname function assign it to a hostent structure, and assign it to sin_addr of the server address structure.
• Request a connection from the server using the connect function.
• Fork the process to receive message from the server and print it on the console.
• Read message from the console and send it to the server.