//This is the IMPLEMENTATION of timotherfunctions
#include <iostream>
#include "timotherfunctions.h"
#include "timmathfunctions.h"
#include "timstreamandarr.h"
using namespace std;

void redisplay (bool not_valid, bool& pass)
{
    if (not_valid == false)
    {
        cout << "Not an available option. We're working on it!\nIn the meanwhile, choose a different path.\n";
    }
    else
    {
        cout << "Not a valid option. Please try again.\n";
    }
    pass = false;
}

bool after_game_over (bool out_of_lives)
{
    char user_ans;
    if (out_of_lives == true)
    {
        cout << "You died! Start over? (y/n): ";
    }
    else 
    {
        cout << "Great job! You reached an ending!\n"
             << "Start over? (y/n): ";
    }
    cin >> user_ans;
    if (user_ans == 'N' || user_ans == 'n')
        return false;
    else
        return true;
}