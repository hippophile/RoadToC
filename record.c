
#include <stdio.h>
#include <string.h>

typedef struct{
    char name [80];
    char street [80];
    char number [80];
    char city [80];
}record;

void read_record(record *p){
    printf("\nWhat is your name?");
    fgets(p->name, sizeof(p->name), stdin);

    printf("\nWhat is your street?");
    fgets(p->street, sizeof(p->street), stdin);

    printf("\nWhat is your number?");
    fgets(p->number, sizeof(p->number), stdin);

    printf("\nWhat is your city?");
    fgets(p->city, sizeof(p->city), stdin);    
}

void printf_record(record x){
    printf("\n%s %s %s %s\n", x.name, x.street, x.number, x.city);
}

int main(void){

    record a,b;

    printf("\nFisrts person");
    read_record(&a);

    printf("\nSecond person");
    read_record(&b);

    printf_record(a);
    printf_record(b);

    return 0;
}
