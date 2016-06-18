#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <iostream>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>


using namespace std;

int main() { 

    struct addrinfo hints,*answer,*curr,*p;

    int error;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET6;//AF_UNSPEC; // use AF_INET6 to force IPv6
    hints.ai_socktype = SOCK_STREAM;//SOCK_DGRAM; // SOCK_STREAM

    if ((error = getaddrinfo("api.mch.weixin.qq.com", NULL, &hints, &answer)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        return 1;
    } else cout <<"Success with a URL\n";

    char ipstr[16];  
    for (curr = answer; curr != NULL; curr = curr->ai_next) {
        inet_ntop(AF_INET,&(((struct sockaddr_in *)(curr->ai_addr))->sin_addr),ipstr, 16);
        printf("%s\n", ipstr);
    }

    freeaddrinfo(answer);


    return 0;
}
