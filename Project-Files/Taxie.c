#include <stdio.h>
#include <stdlib.h>

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

writeCarsInRide("Taxies.txt");


return 0;
}

void writeCarsInRide(char* fileName){
//check if list empty
if(List == NULL){
printf("The list is empty! \n");
return ;
}

FILE* f ;
f = fopen(fileName,"a") ;
if(f != NULL){

struct Taxi *cur = List ; //List is global


fprintf(f,"-----------------------------------------\n");
fprintf(f,"The Cars in Ride:\n");
fprintf(f,"%-8s %-8s %-8s ","id","driver","category");//print the first line after -------
fprintf(f,"%-8s %-8s %-8s \n","plate","rate","state");
//fputs(f,"-----------------------------------------\n");
//fputs(f,"The Cars in Ride:\n");

while(cur != NULL){

if(cur -> state == 'R'){
fprintf(f,"%-8d %-8s %-8s ",cur -> id , cur -> driver , cur -> category);
fprintf(f,"%-8s %-8f %-8c \n",cur -> plate , cur -> rate , cur -> state );
}//if state is R

cur = cur -> next ;
}//while

fclose(f);

}//if the file open
else
printf("File could not be opened.");

} //end method

void printList(){

if(List != NULL){
struct Taxi *cur = List ; //list is global

while(cur != NULL){


cur = cur -> next ;
}//while

}
else
printf("list is empaty \n");


}//end method

void setTripCar (char* category, float* rate){
  if(List == NULL) {
    printf("Empty list");
    return;
  } 
  struct Taxi *current;
  current = List;// points at first element (node) in the list
  while (current!=NULL ){
   if(strcomp(current->category,category) == 0 && current->rate == *rate){
    current->state = 'R'; // in a Ride
    return;
   }
   current = current->next; // moves current to next wether found it or not
  }
  
}