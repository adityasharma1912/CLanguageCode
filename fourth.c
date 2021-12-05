#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

typedef struct mon_entity_flow_key {
     union {
         int ip;
     } __attribute__((packed));
     int  port: 16,
             protocol: 8,    // protocol number from ip header
             is_ipv6: 1,
             spare:  7;
 } __attribute__((packed)) mon_entity_flow_key_t;

int main(){
    mon_entity_flow_key_t temp_flow_key;
    mon_entity_flow_key_t *final_key = (mon_entity_flow_key_t *)malloc(sizeof(mon_entity_flow_key_t));
    memset(&temp_flow_key,0, sizeof(mon_entity_flow_key_t));
    temp_flow_key.port = 53;
    temp_flow_key.protocol = 17;
    temp_flow_key.ip = 1;
    temp_flow_key.ip = ntohl(temp_flow_key.ip);

    char ip_addr[16] = {0};

    printf("port = %d\n",temp_flow_key.port);
    printf("protocol = %d\n", temp_flow_key.protocol);

    memcpy(final_key, &temp_flow_key, sizeof(mon_entity_flow_key_t));

    snprintf(ip_addr, sizeof(ip_addr),"%d",final_key->ip);

    inet_ntop(AF_INET, ip_addr, ip_addr, sizeof(ip_addr));

    printf("new port = %d\n",final_key->port);
    printf("new protocol = %d\n", final_key->protocol);

    printf("final ip address %s\n",ip_addr);
    float value = 1.23456789;
    printf("value is: == %f",value);

    return 0;
}
