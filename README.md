This project implements a simple Taxi Ride Management System in C using a linked list to store taxi information. It allows users to add, update, and manage taxi trip records, focusing on assigning taxis to rides and saving ride data to a file.

# Features:
Read taxi data from a file (Taxies.txt) and store it in a linked list.
Print the list of available taxis before and after updating their ride status.
Assign taxis to rides based on their category and rate.
Save ride information to an output file.
Implementation Details
struct Taxi: Represents a taxi with attributes like ID, driver name, category, plate number, color, rate, minimum charge, and state ('A' for available, 'R' for in-ride).
Global List pointer: Maintains the linked list of taxis.
Functions:
addTripCar(): Reads taxi details from Taxies.txt and initializes the linked list.
setTripCar(char* category, float* rate): Updates taxi status to "In Ride" ('R') if it matches the given category and rate.
writeCarsInRide(char* fileName): Saves taxis in ride state ('R') to a file.
printList(): Prints the taxi list.
