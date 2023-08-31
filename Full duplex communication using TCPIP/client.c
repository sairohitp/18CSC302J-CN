#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
   
    // Set up the server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP
   
    // Connect to the server
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("Connected to Leo!\n");
   
    // Communication loop
    char buffer[1024];
    while (1) {
        printf("Miko: ");
        fgets(buffer, sizeof(buffer), stdin); // Input Miko's tale
        send(clientSocket, buffer, strlen(buffer), 0);
       
        memset(buffer, 0, sizeof(buffer));
       
        // Receive Leo's response
        recv(clientSocket, buffer, sizeof(buffer), 0);
        printf("Leo: %s\n", buffer);
    }
   
    // Close socket
    close(clientSocket);
   
    return 0;
}