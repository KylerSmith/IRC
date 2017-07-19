/*
 * Client for the IRC.
 *
 * @author: Kyler Smith, 2017.
 */


////////////////////////////////////////////////////////////////////////////////
// INCLUDES
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <GLUT/GLUT.h>

////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
int connectToServer(const char s[]);

////////////////////////////////////////////////////////////////////////////////
// MAIN
int main(int argc, const char * argv[]) {
    
    int socketfd = connectToServer(argv[1]);
    
    
    char str[1024];
    printf("Send to server: ");
    scanf("%s", str);
    
    // send request to server
    write(socketfd, str, 1024);
    
    printf("Looking for: %s\n", str);
    
    printf("Disconnecting from server.\n");
    
    return 0;
}

/**
 * Connects the client to the server.
 * Port is specified through command line right now,
 *      hopefully will have specified in Java front end,
 *      or default somewhere with ability to modify.
 *
 * @param port: Port to connect, where the server should be.
 */
int connectToServer(const char port[]) {

    int sckt = atoi(port);
    
    struct sockaddr_in server;
    
    int scktFileDesc = socket(AF_INET, SOCK_STREAM, 0);
    if(scktFileDesc < 0) { return 1; }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(sckt);
    server.sin_addr.s_addr = INADDR_ANY;
    
    socklen_t length = sizeof(struct sockaddr_in);
    
    if(connect(scktFileDesc, (struct sockaddr *)(struct sockaddr_in *)&server, length) != 0) {
        printf("Connection unsuccessful!\n");
        return 1;
    } else {
        printf("Connection successful!\n");
    }
    
    return scktFileDesc;
}
