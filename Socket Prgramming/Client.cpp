#include <iostream>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    //socket() -> connect() -> send()/write()
    //create client socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        cout << "Socket creation failed" << endl;
        return 1;
    }

    //specify client address
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    //send connection request to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cout << "Connection failed" << endl;
        close(clientSocket);
        return 1;
    }

    //sending data
    const char* message = "Hello from Client";

    send(clientSocket, message, strlen(message), 0);

    close(clientSocket);

    return 0;
}