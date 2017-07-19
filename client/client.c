/**
 * Client for the IRC.
 * Created by Kyler Smith, 2017.
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

////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES


////////////////////////////////////////////////////////////////////////////////
// MAIN
int main(int argc, const char * argv[]) {

// connect to the server -----------------------------------------
    int sckt = atoi(argv[1]);

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
// connect to the server -----------------------------------------

    char str[1024];
    printf("Send to server: ");
    scanf("%s", str);

    // send request to server
    write(scktFileDesc, str, 1024);
    // int n = (int)read(scktFileDesc, str, 1024);
    // if(n < 0) { return 1; }

    // receive if file was found or not
    printf("Looking for: %s\n", str);

    printf("Disconnecting from server.\n");
    // }

    return 0;
}
