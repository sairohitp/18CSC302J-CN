#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h> // Include this for the 'close' function

void udp_echo_server(int port) {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in serverAddr, clientAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    std::cout << "UDP Echo Server is listening on port " << port << std::endl;

    while (true) {
        char buffer[1024];
        socklen_t clientAddrLen = sizeof(clientAddr);
        ssize_t recvLen = recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        sendto(serverSocket, buffer, recvLen, 0, (struct sockaddr*)&clientAddr, clientAddrLen);
    }

    close(serverSocket);
}

int main() {
    int port = 12345;
    udp_echo_server(port);

    return 0;
}