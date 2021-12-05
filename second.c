#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STREET_NAME_MAX_LENGTH 64
#define CITY_NAME_MAX_LENGTH 25
#define PERSON_NAME_MAX_LENGTH 64
#define CHRISMA

typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;


typedef struct address{
    char *street_name;
    int apartment_number;
    int zip_code;
    char *city_name;
}address_t;

typedef struct person{
    char *name;
    int height;
    int age;
    address_t address;
}person_t;

struct in6_addr {
    union {
        __u8   __u6_addr8[16];
        __u16  __u6_addr16[8];
        __u32  __u6_addr32[4];
    } __u6_addr;            /* 128-bit IP6 address */
};


int main(){
    printf("Enter Person Details:\n");
    int size = sizeof(person_t) + PERSON_NAME_MAX_LENGTH + STREET_NAME_MAX_LENGTH + CITY_NAME_MAX_LENGTH;
    printf("size = %d\n",size);
    person_t *first_person  = (person_t *)malloc(size);
    first_person->address.street_name = (char *)first_person+sizeof(person_t);
    strncpy(first_person->address.street_name, "Turin's First Street",STREET_NAME_MAX_LENGTH);
    first_person->name = "Andrea Pirlo";
    first_person->address.city_name = "Turin";
    printf("%s's native city is %s and street is: %s\n",first_person->name,first_person->address.city_name, first_person->address.street_name);
#ifdef CHRISMA
    printf("Memory Address of person is : 0x%x\n",&first_person);
    printf("Memory Address of name inside person is : 0x%x\n",&first_person->name);
    printf("Size of in6_addr = %d",sizeof(struct in6_addr));
#endif // CHRISMA
    return 0;
}
