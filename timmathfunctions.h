//This is the INTERFACE for timmathfunctions.
#include <iostream>
using namespace std;

void rand_math_prob (int& lives);
//Precondition: lives must not be equal to zero
//Postcondition: Displays a random math problem and takes an answer. Subtracts one from lives if the user's answer is wrong. 
//Will run division_prob or square_prob when their operation is selected
void division_prob (double& op1, double& op2);
//Precondition: op2 must not be equal to zero
//Postcondition: Changes op1 and op2 so that op1/op2 equals a whole number. op2 will be a num from 1-12
void square_prob (double& op2);
//Changes op2 to be within a random number from 1-3, and leaves it alone if it is.