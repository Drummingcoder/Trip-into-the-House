//This is the INTERFACE of timotherfunctions
#include <iostream>
using namespace std;

void redisplay (bool not_valid, bool& pass);
//Displays a "try again" message that varies based on the value of not_valid and sets pass to false
bool after_game_over (bool out_of_lives);
//Displays a game over message based on the value of out_of_lives