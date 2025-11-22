
#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    //create server socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        cout << "Socket creation failed" << endl;
        return 1;
    }

    //Specify server address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    //bind socket to the specified IP and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Bind failed" << endl;
        close(serverSocket);
        return 1;
    }

    //listen for incoming connections
    if (listen(serverSocket, 5) < 0) {
        cout << "Listen failed" << endl;
        close(serverSocket);
        return 1;
    }

    cout << "Server listening on port 8080..." << endl;

    //Accept a client connection
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket < 0) {
        cout << "Accept failed" << endl;
        close(serverSocket);
        return 1;
    }

    char buffer[1024] = {0};

    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Received message from client: " << buffer << endl;

    //Close the sockets
    close(clientSocket);
    close(serverSocket);
    return 0;
}