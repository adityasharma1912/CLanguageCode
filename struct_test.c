#include <stdio.h>

typedef struct person
{
    int age;
    int height;
    char *name;
}person_t;

int main(){
    person_t person1;
    char name[64] = "FirstName LastName";
    person1.age = 10;
    person1.height = 140;
    person1.name = (char *)malloc(64*sizeof(char));
    memset(person1.name, 0x0, 64);
    memcpy(person1.name, name, 64);
    person_t person2 = person1;
    printf("address person1 = %x\naddress person2 = %x\nname = %s\n",&person1.name, &person2.name, person2.name);
    return 0;
}
