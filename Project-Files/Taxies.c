#include <stdio.h>

struct Taxi{
int id;
char driver[20];
char category[20];
char plate[7];
char color[20];
float rate;
float minCharge;
char state;
struct Taxi *next ; //self-referential
};

struct Taxi *List ;

void addTripCar();
void setTripCar (char* category, float* rate);
void writeCarsInRide(char* fileName);
void printList();

int main(){



return 0;
}

void writeCarsInRide(char* fileName){

FILE* f ;
f = fopen(fileName,"a") ;
if(f != NULL){

struct Taxi *cur = List ; //List is global


fprintf(f,"-----------------------------------------\n");
fprintf(f,"The Cars in Ride:\n");
fprintf(f,"%-8d %-8s %-8s ","id","driver","category");//print the first line after -------
fprintf(f,"%-8s %-8d %-8s \n","plate","rate","state");
//fputs(f,"-----------------------------------------\n");
//fputs(f,"The Cars in Ride:\n");

while(cur != NULL){

if(cur -> state == 'R'){
fprintf(f,"%-8d %-8s %-8s %-8s ",cur -> id , cur -> driver , cur -> category);
fprintf(f,"%-8s %-8d %-8d \n",cur -> plate , cur -> rate , cur -> state );
}//if state is R

}//while

fclose(f);

}
else
printf("File could not be opened.");


} //end method

void printList(){

if(List != NULL){



}
else
printf("list is empaty \n");


}//end method