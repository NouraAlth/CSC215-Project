#include <stdio.h>

typedef struct{
int id;
char driver[20];
char category[20];
char plate[7];
char color[20];
float rate;
float minCharge;
char state;
Taxi *next ; //self-referential
}Taxi;

void addTripCar();
void setTripCar (char* category, float* rate);
void writeCarsInRide(char* fileName);


int main(){

/*node* head ;
head = (node*)malloc(sizeof(node));

if(head == NULL)
return 1 ;*/

return 0;
}

void writeCarsInRide(char* fileName){

FILE* f ;


fclose(f);
}