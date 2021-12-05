#include<stdio.h>
#include<string.h>
#include <arpa/inet.h>

#define DDOS_SCRIPT_MAX_NUM 30
 enum {
     DDOS_SCRIPT_INTERNAL_IDX_START = DDOS_SCRIPT_MAX_NUM,
     DDOS_SCRIPT_INTERNAL_API_NOTIFICATION_IDX = DDOS_SCRIPT_INTERNAL_IDX_START,
     DDOS_SCRIPT_INTERNAL_IDX_END,
     DDOS_SCRIPT_INTERNAL_MAX_NUM = DDOS_SCRIPT_INTERNAL_IDX_END,
 };
#define DDOS_SCRIPT_TOTAL_MAX_NUM   (DDOS_SCRIPT_MAX_NUM + DDOS_SCRIPT_INTERNAL_MAX_NUM)


void add(int a, int b, int *sum){
    *sum = a+b;
}

void div(int a, int b, float *div){
    *div =  (float)a/b;
}

void product(int a, int b, int *product){
    *product = a*b;
}

void diff(int a, int b, int *diff){
    *diff = (a>b)?(a-b):(b-a);
}

void print_port_number(int port){
    char port_no[5];
    int total_bytes_copied = 0;
    if (port) {
        total_bytes_copied += snprintf(port_no,sizeof(port_no),"%d", port);
    } else {
        total_bytes_copied += snprintf(port_no,sizeof(port_no),"%s", "NONE");
    }
    printf("port_no = %s",port_no);
    return;
}

int main(int argc, char *argv[]){
    int a,b;
    int sum;
    int mul;
    int difference;
    float aByb;
    char port_no[5];
    int ip_addr_bin = 0;
    char ip_addr[46];
    memset(port_no,0,sizeof(port_no));
    //scanf("%d",&a);
    //scanf("%d",&b);
    add(a,b,&sum);
    diff(a,b,&difference);
    product(a,b,&mul);
    div(a,b,&aByb);
    printf("Sum = %d\n",sum);
    printf("Diff = %d\n",difference);
    printf("Product = %d\n",mul);
    printf("Divi = %.2f\n",aByb);
    snprintf(port_no,sizeof(port_no), "%d", 6543);
    printf("size = %d --  %s",strlen(port_no), port_no);

    inet_ntop(AF_INET, &ip_addr_bin, ip_addr, sizeof(ip_addr));
    printf("\n\nip_addr = %s\n",ip_addr);
    print_port_number(53);
    print_port_number(0);

    printf("DDOS_SCRIPT_TOTAL_MAX_NUM = %d \n\n",DDOS_SCRIPT_TOTAL_MAX_NUM);
    return 0;
}
