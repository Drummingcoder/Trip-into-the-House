#include <iostream>
#include <fstream>
#include <cstring>
#include "timstreamandarr.h"
#include "timmathfunctions.h"
#include "timotherfunctions.h"
using namespace std;

bool compare_array_and_var (char user_choice, char compare [])
{
    int index = 0;
    bool found = false, pass;
    do
    {
        if (user_choice == compare [index])
        {
            pass = true;
            found = true;
        }
        else if (index != strlen (compare))
        {
            index++;
            pass = false;
        }
        else
        {
            pass = true;
            found = false;
        }
    } while (pass == false);
    return found;
}

void display_arr (char arr [])
{
    int index = 0;
    bool pass;
    do
    {
        cout << arr [index];
        if (index != strlen(arr))
        {
            index++;
            pass = false;
        }
        else
        {
            pass = true;
        }
    } while (pass == false);
}

void new_line (ifstream& in, char up_to)
{
    in.ignore (100000000, up_to);
}

void new_line ()
{
    cin.ignore(1000000, '\n');
}