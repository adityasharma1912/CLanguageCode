
#include <stdio.h>
#include <arpa/inet.h>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
typedef unsigned char u8;
typedef unsigned short u16;
#define ACOS_RATELIMIT_JIFFY_TO_SECS(time_jiffies)  ((u16)((time_jiffies)/250))
typedef struct structa_tag
{
   char        c;
   short int   s;
   u8 one_bit :1,
      second_part:7;
} structa_t;

// structure B
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;

// structure C
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;

// structure D
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;

void setvalue(structa_t *strct, u8 value){
    strct->second_part = value;
    return;
}

int main()
{
    structa_t value;
    memset(&value,0,sizeof(structa_t));
    setvalue(&value,234);
    value.second_part+=100;
    u16 value1 = ACOS_RATELIMIT_JIFFY_TO_SECS(123);
    unsigned int value2 = (1<<63)-1;//ACOS_RATELIMIT_JIFFY_TO_SECS(65535*252);
    printf("value1 = %d and value2 = %u\n",value1, value2);
    printf("Final value set: one_bit = %d and second_part = %d\n",
          value.one_bit, value.second_part);
    printf("sizeof(structa_t) = %d\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %d\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %d\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %d\n", sizeof(structd_t));
    printf("last statement = %.2f\n",atof("5.3e3"));
    unsigned int addr = 2567374599;
    char dest[32];
    memset(dest, 0, 32);
    const char *ip_addr = inet_ntop(AF_INET, &addr, dest, 32);
    printf("ip fetched is: %s and dest = %s\n", ip_addr, dest);
    unsigned int new_value = 0;
    inet_pton(AF_INET, dest, &new_value);
    printf("New_ip value fetched is: %u \n", new_value);
    return 0;
}
