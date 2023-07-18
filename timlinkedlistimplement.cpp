#include "timlinkedlist.h"
#include <iostream>
#include <string>
using namespace std;


types_of_monsters* types_of_monsters::build_and_return_list (istream& fin)
{
    auto count = 0, index = 0;
    char trash, read;
    types_of_monsters *firstptr, *temp_ptr;
    temp_ptr = new types_of_monsters;
    firstptr = temp_ptr;
    while (count < 12)
    {
        fin >> temp_ptr->id_num;
        fin.get (trash);
        fin.get (trash);
        fin.get (read);
        for (index = 0; read != '"'; index++)
        {
            temp_ptr->before += read;
            fin.get (read);
        }
        index++;
        temp_ptr->before += '\0';
        fin >> temp_ptr->num_of_probs;
        fin.get (trash);
        fin.get (trash);
        fin.get (read);
        for (index = 0; read != '"'; index++)
        {
            temp_ptr->after += read;
            fin.get (read);
        }
        index++;
        temp_ptr->after += '\0';
        count++;
        if (count < 12)
        {
            temp_ptr->ptr = new types_of_monsters;
            temp_ptr = temp_ptr->ptr;
        }
        else
        {
            temp_ptr->ptr = nullptr;
        }
    }
    return firstptr;
}

types_of_monsters* types_of_monsters::get_monster (types_of_monsters* monster, int mon_num)
{
    auto pass = false;
    char trash, read;
    types_of_monsters *temp_ptr;

    temp_ptr = monster;
    
    while (pass == false)
    {
        if (temp_ptr->id_num != mon_num)
        {
            temp_ptr = temp_ptr->ptr;
            pass = false;
        }
        else
        {
            pass = true;
        }
    }

    return temp_ptr;
}

int types_of_monsters::get_num_of_probs () 
{
    return num_of_probs;
}

void types_of_monsters::change_num_of_probs (int num)
{
    num_of_probs = num;
}

void types_of_monsters::display_before () 
{
    cout << before;
}

void types_of_monsters::display_after ()
{
    cout << after;
}

types_of_monsters::~types_of_monsters()
{
    delete [] ptr;
    delete ptr;
}