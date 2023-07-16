#include "timlinkedlist.h"
#include <iostream>
#include <vector>
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
            temp_ptr->before.push_back(read);
            fin.get (read);
        }
        index++;
        temp_ptr->before.push_back ('\0');
        fin >> temp_ptr->num_of_probs;
        fin.get (trash);
        fin.get (trash);
        fin.get (read);
        for (index = 0; read != '"'; index++)
        {
            temp_ptr->after.push_back(read);
            fin.get (read);
        }
        index++;
        temp_ptr->after_dialogue [index] = '\0';
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
    int index = 0;
    bool pass;
    vector<char>::iterator p;
    do
    {
        cout << before [index];
        if (index != before.size())
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

void types_of_monsters::display_after ()
{
    int index = 0;
    bool pass;
    do
    {
        cout << after [index];
        if (index != after.size())
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