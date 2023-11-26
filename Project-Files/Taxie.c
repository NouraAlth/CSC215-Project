#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
printf("%d,%s,%s,%s,%lf,%f,%c\n",(cur ->id),(cur ->driver),(cur ->category),(cur->plate),(cur ->rate),(cur->minCharge),(cur ->state));

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
   if(strcmp(current->category,category) == 0 && current->rate == *rate){
    current->state = 'R'; // in a Ride
    return;
   }
   current = current->next; // moves current to next wether found it or not
  }
  }
  
void addTripCar() {
    struct Taxi *head = NULL, *current;
    FILE *ff;
    ff = fopen("Taxies.txt", "r");
    if (ff == NULL)
        return;

    int numOfLines = 0;
    int ch;
    while ((ch = fgetc(ff)) != EOF) {
        if (ch == '\n') {
            numOfLines++;
        }
    }

    // Move the file pointer back to the beginning of the file
    fseek(ff, 0, SEEK_SET);

    int c;
    while ((c = fgetc(ff)) != '\n') {
        // Read and discard characters until a newline is encountered
    }

    for (int i = 0; i < numOfLines - 1; i++) {
        struct Taxi *temp = (struct Taxi *)malloc(sizeof(struct Taxi));
        fscanf(ff, "%d %s %s %s %s %f %f ",
               &(temp->id), temp->driver, temp->category, temp->plate, temp->color, &(temp->rate), &(temp->minCharge));
        temp->state = 'A';
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = current->next;
        }
    }

    List = head;
    fclose(ff);
}

int main(){
addTripCar();
printf("The Available Trip Cars:\n");
printList(); // printing before the updates
char *c1 = "Business" ; float r1 = 4.5 ;
char *c2= "Family" ; float r2 = 5.0 ;
char *c3= "Family" ; float r3 = 4.0 ;
char *c4= "standard" ; float r4 = 3.4 ;
char *c5= "standard" ; float r5 = 5.0 ;
setTripCar( c1 , &r1 );
setTripCar( c2 , &r2 );
setTripCar( c3 , &r3 );
setTripCar( c4 , &r4 );
setTripCar( c5 , &r5 );
 
printf("the Cars in Ride :\n");
printList(); // printing after the updates
writeCarsInRide("Taxies.txt");
return 0;
}

