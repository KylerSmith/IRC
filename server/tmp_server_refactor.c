/* Server for the IRC.
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
#include <dirent.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// MACROS

////////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
int connectToClient(const char port[]);


////////////////////////////////////////////////////////////////////////////////
// MAIN
int main(int argc, const char * argv[]) {
    
    
    int fileDesc = connectToClient(argv[1]);
    char buf[256];
    
    int x = (int)read(fileDesc, buf, 255);
    printf("Input from client:\n%s\n", buf);
        
    return 0;
    
}

int connectToClient(const char port[]) {
    
    int sckt = atoi(port);
    struct sockaddr_in server_address, client_address;
    int fileDesc = socket(AF_INET, SOCK_STREAM, 0), new_fileDesc;
    
    // didn't create a good socket
    if(fileDesc < 0) { return 1; }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(sckt);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    // bind the socket to an address
    if((bind(fileDesc, (struct sockaddr *)&server_address, sizeof(server_address)) ) < 0) { return 1; }
    
    listen(fileDesc, 5);
    socklen_t clientLength = sizeof(client_address);
    
    
    
    printf("Server running... Waiting for client...\n");
    
    // gets new client
    new_fileDesc = accept(fileDesc, (struct sockaddr *) &client_address, &clientLength);
    if (new_fileDesc < 0) { return 1; }
    
    return 0;
}
















































