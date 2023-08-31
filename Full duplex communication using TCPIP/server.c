#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
   
    // Set up the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;
   
    // Bind
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
   
    // Listen
    listen(serverSocket, 5);
    printf("Leo is listening...\n");
   
    // Accept a client connection
    int clientSocket = accept(serverSocket, NULL, NULL);
    printf("Miko is connected!\n");
   
    // Communication loop
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
       
        // Receive message from Miko
        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Miko: %s\n", buffer);
       
        // Respond with Leo's tale
        printf("Leo: ");
        fgets(buffer, sizeof(buffer), stdin); // Simulate Leo's response
        send(clientSocket, buffer, strlen(buffer), 0);
    }
   
    // Close sockets
    close(clientSocket);
    close(serverSocket);
   
    return 0;
}