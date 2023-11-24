#include <stdio.h>

extern Taxi ;

typedef struct{
Taxi data ;
node *next ;
} node ;

typedef struct{
int id;
char driver[20];
char category[20];
char plate[7];
char color[20];
float rate;
float minCharge;
char state;
node next ;
}Taxi;

void addTripCar();
void setTripCar (char* category, float* rate);
void writeCarsInRide(char* fileName);


int main(){

    return 0;
}