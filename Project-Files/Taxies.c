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

/*Taxi* head ;
head = (Taxi*)malloc(sizeof(Taxi));

if(head == NULL)
return 1 ;*/

return 0;
}

void writeCarsInRide(char* fileName){

FILE* f ;

if(f = fopen(fileName,"a")){


fclose(f);

}
else
printf("File could not be opened.");


}