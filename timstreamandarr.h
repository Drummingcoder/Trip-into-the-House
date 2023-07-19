//This is the INTERFACE of timstreamandarr
#include <iostream>
#include <vector>
using namespace std;

bool compare_array_and_var (char user_choice, vector<char> compare);
//Precondition: compare is not empty
//Postcondition: Checks the value of user_choice to each value of the array compare. Returns true if user_choice is in the array, else returns false
void display_arr (char arr []);
//Precondition: The array arr is not empty
//Postcondition: Outputs every value of arr to the screen
void new_line (ifstream& in, char up_to);
//Precondition: The stream in must be a ifstream type.
//Postcondition: Everything in the stream will be discarded until the value of up_to
void new_line ();
//Postcondition: 1000000 characters in the stream will be discarded