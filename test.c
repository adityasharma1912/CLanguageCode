#include <stdio.h>

#include <arpa/inet.h>

typedef int (*func_cb_t)(int);

void func(func_cb_t func_cb, int value){
    func_cb(value);
    return;
}

int call_back_func(int value){
    printf("Callback function called with value = %d\n", value);
    return 0;
}

char *getName(){
    char *name = (char *)malloc(sizeof(char) * 4);
    memset(name, 0x0, 4);
    strncpy(name, "aditya", 3);
    return name;
}

void getAuthToken(char **token){
    char *priv_token = "Aditya";
    printf("priv token addr : %x with length = %d\n", priv_token, strlen(priv_token));
    memcpy(token, priv_token, strlen(priv_token));
    return;
}

void main(){
    unsigned int addr_int;
    unsigned int addr2;
    char *token = "First";
    int ret =  inet_pton(AF_INET, "127.0.0.1", &addr_int);
    printf("ret = %u and add_int", addr_int);
    ret =  inet_pton(AF_INET, "10.65.22.147", &addr2);
    printf("ret = %u and add_int", addr_int);

    char ip_addr1[INET6_ADDRSTRLEN];
    char ip_addr2[INET6_ADDRSTRLEN];

    printf("htonl %u",htonl(addr2));
    inet_ntop(AF_INET, &addr_int, ip_addr1, sizeof(ip_addr1));
    inet_ntop(AF_INET, &addr2, ip_addr2, sizeof(ip_addr2));

    printf("\nip_addr1: %s  %u\n", ip_addr1, addr_int);
    printf("\nip_addr2: %s  %u\n", ip_addr2, addr2);
    printf("token addr : %x\n", token);
    getAuthToken(&token);
    printf("token addr : %x\n", token);
    printf("After getting token: %s", token);

    return;
}
