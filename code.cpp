#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstring>
#include <string>
#include "timmathfunctions.h"
#include "timstreamandarr.h"
#include "timotherfunctions.h"
#include "timlinkedlist.h"
using namespace std;

struct forced_mon_en
{
    bool forced;
    int num_of_loops;
    int type_of_mon;
};

void main_looper (int& num, bool& game_over, bool& cave_var, int& lives, bool& out_of_lives);
//Runs the display function, takes in user input and validates it based on the compare_array_and_var function, changes num when num = 13, runs mon_en function
void change_num (int& num, char user_choice);
//Precondition: num must be within 1-15 with some exceptions, user_choice must be valid
//Postcondition: num will be changed accordingly to the value of num and user_choice
void display (int& num, int& lives, bool& game_over, bool& cave_var, char valid_letters [], char not_available_letters[], bool& out_of_lives, bool& skip, bool& tenlives);
//Precondition: num must be a number in scenarios.txt
//Postcondition: Displays text from scenarios.txt accordingly to the value of num and sets the values of game_over, cave_var, skip, valid_letters, not_available_letters according to scenarios.txt. (last two for comparision for main_looper)
//When reading a '|' in scenarios.txt, it will run rand_math_prob 10 times and set tenlives accordingly to whether or not lives remained the same
void mon_en (int& lives, forced_mon_en en);
//Picks a random line from monsters.txt and displays text accordingly. Then runs rand_math_prob and displays more text according to the line selected in monsters.txt
void cave_game (bool& game_over, int& lives, bool& out_of_lives);
//Runs a game where the user has to navigate through a "cave" by entering numbers. Taking a wrong path
//means that a monster has a 50% chance of spawning (by running mon_en). Will set game_over, out_of_lives vars to true when lives = 0.
void read (ifstream& fin, int& lives, bool& cave_var);
//Precondition: Stream fin must have a ; or { or | or [ or } somewhere
//Postcondition: Output every character in the stream fin until it reaches one of the characters defined in the precondition above
//Will stop when reaching ;, run mon_en when reaching {, [, or }, or set cave_var to true when reaching | 

int main ()
{
  char trash;
  int num, lives;
  bool end, end_all, game_over, cave_var, out_of_lives;
  //Introduction to the game
  cout << "Welcome to A Trip into The House - A Math Game! "
          << "Press any key and Enter to start: ";
  cin >> trash;
  cout << "Welcome to the game. You are on a journey to find your long-lost friend.\nYou travel all over the world, looking for clues as to where he is.\nIn the end, every clue you find points to an abandoned house in the countryside. You head there.\n\n";
  cout << "Instructions: the game will give you various options throughout the game.\nType the underlined letter to do a certain option.\nThere will also be various math problems you need to solve.\nJust type in the answer and press Enter.\nMake sure to keep a paper and pencil handy!\n" << endl;
  do
  {
    //Initialization put here to ensure that every time the game is restarted, these variables will be reset.
    num = 1;
    end = false; 
    end_all = false;
    lives = 5;
    game_over = false;
    cave_var = false;
    out_of_lives = false;
    do
    {
        main_looper (num, game_over, cave_var, lives, out_of_lives);
        if (game_over == true)
        {
            end = true;
        }
    } while (end == false);
  } while (after_game_over (out_of_lives));
  cout << endl;
  return 0;
}

void main_looper (int& num, bool& game_over, bool& cave_var, int& lives, bool& out_of_lives)
{
    char valid_letters [4], not_available_letters [4];
    bool pass, not_valid, skip, tenlives;
    char user_choice;
    forced_mon_en en;
    do
    {
        display (num, lives, game_over, cave_var, valid_letters, not_available_letters, out_of_lives, skip, tenlives);
        if (skip == false)
        {
            cin.ignore(1000000, '\n');
            cin >> user_choice;
            cout << endl;
            if (compare_array_and_var (user_choice, valid_letters)) //valid path
            {
                pass = true;
                change_num (num, user_choice);
            }
            else if (compare_array_and_var (user_choice, not_available_letters)) //under-development path
            {
                not_valid = false;
                redisplay (not_valid, pass);
                cout << endl;
            }
            else //invalid path
            {
                not_valid = true;
                redisplay (not_valid, pass);
                cout << endl;
            }
        }
        else if ((skip == true && tenlives == true) && num == 13) //if player wins the movie scene
        {
            num = 15;
        }
        else if ((skip == true && tenlives == false) && num == 13) // if player loses the movie scene
        {
            num = 14;
        }
        else if (skip == true && num == 4) // if player loses against Sean
        {
            pass = true;
        }
    } while (pass == false);
    if (skip == false) //for special scenes
    {
        cout << "You head that way...\n";
        mon_en (lives, en);
        if (lives == 0)
        {
            game_over = true;
            out_of_lives = true;
        }
    }
    else //separate content
    {
        cout << endl;
    }
}

void change_num (int& num, char user_choice)
{
    if (num == 1 && user_choice == 'c')
        num = 2;
    else if (num == 2 && user_choice == 'k')
        num = 3;
    else if (num == 3 && user_choice == 'i')
        num = 4;
    else if (num == 3 && user_choice == 'r')
        num = 6;
    else if (num == 3 && user_choice == 'g')
        num = 5;
    else if (num == 6 && user_choice == 'l')
        num = 7;
    else if (num == 6 && user_choice == 'r')
        num = 8;
    else if (num == 8 && user_choice == 'l')
        num = 9;
    else if (num == 9 && user_choice == 'd')
        num = 10;
    else if (num == 9 && user_choice == 'f')
        num = 11;
    else if (num == 11 && user_choice == 'l')
        num = 12;
    else if (num == 11 && user_choice == 'r')
        num = 13;
    else if (num == 13 && user_choice == 'l')
        num = 14;
    else if (num == 13 && user_choice == 'w')
        num = 15;
    else if (num == 15 && user_choice == 'h')
        num = 16;
    else if (num == 15 && user_choice == 'e')
        num = 17;
    else if (num == 15 && user_choice == 'E')
        num = 18;
}

void display (int& num, int& lives, bool& game_over, bool& cave_var, char valid_letters [], char not_available_letters[], bool& out_of_lives, bool& skip, bool& tenlives)
{
    char letter, wait, trash, read_letter;
    int temp_num, max, index, original_lives;
    bool pass, loop;
    ifstream fin;
    fin.open ("scenarios.txt", ios::app);
    do //finds the correct scenario in scenarios.txt
    {
        fin >> temp_num;
        if (num != temp_num)
        {
            new_line (fin, '\n');
            pass = false;
        }
        else if (fin.eof())
        {
            cout << "Something's wrong. Press any letter and Enter to end program: ";
            cin >> trash;
            exit (1);
        }
        else
        {
            new_line (fin, ':');
            fin.get (trash);
            pass = true;
        }
    } while (pass == false);
    read (fin, lives, cave_var);
    if (cave_var == true)
    {
        cave_game (game_over, lives, out_of_lives);
        read (fin, lives, cave_var);
    }
    fin.get (read_letter);
    if (read_letter == ';') //gets the next letter
    {
        fin.get (read_letter);
    }
    if (read_letter == '(') //gets the valid letters and invalid letters and reads it out
    {
        fin.get (read_letter);
        max = strlen (valid_letters);
        for (int index = 0; index != max; index++)
        {
            valid_letters [index] = '\0';
        }
        max = strlen (not_available_letters);
        for (int index = 0; index != max; index++)
        {
            not_available_letters [index] = '\0';
        }
        for (int index = 0; read_letter != ',' && read_letter != ')'; index++)
        {
            valid_letters [index] = read_letter;
            fin.get (read_letter);
        }
        if (read_letter == ',')
        {
            fin.get (read_letter);
            for (int index = 0; read_letter != ')'; index++)
            {
                not_available_letters [index] = read_letter;
                fin.get (read_letter);
            }
        }
        else
        {
            max = strlen (not_available_letters);
            for (int index = 0; index != max; index++)
            {
                not_available_letters [index] = '\0';
            }
        }
        cout << " (";
        for (auto index = 0; index != strlen (valid_letters); index++)
        {
            letter = valid_letters [index];
            cout << letter;
            if (index != (strlen (valid_letters) - 1))
            {
                cout << '/';
            }
        }
        for (auto index = 0; index != strlen (not_available_letters); index++)
        {
            if (index != strlen (not_available_letters))
            {
                cout << '/';
            }
            letter = not_available_letters [index];
            cout << letter;
        }
        cout << "): ";
        skip = false;
    }
    else if (read_letter == '/') //ending
    {
        game_over = true;
        skip = true;
    }
    else if (read_letter == '"' && lives != 0) //investigation monster
    {
        num = 6;
        display (num, lives, game_over, cave_var, valid_letters, not_available_letters, out_of_lives, skip, tenlives);
        skip = false;
    }
    else if (read_letter == '|') //movie scene
    {
        cout << endl << endl << "Save yourself! Answer 10 questions to live, or else you will succumb to the temptation!" << endl;
        original_lives = lives;
        index = 10;
        pass = false;
        cout << endl;
        while (index != 0 && pass != true)
        {
            rand_math_prob (lives);
            if (original_lives != lives)
            {
                pass = true;
            }
            else
            {
                pass = false;
                index--;
            }
        }
        if (original_lives != lives)
        {
            skip = true;
            tenlives = false;
        }
        else
        {
            skip = true;
            tenlives = true;
        }
    }
    else if (lives == 0) //game over
    {
        game_over = true;
        skip = true;
        out_of_lives = true;
    }
    else if (lives != 0)
    {
        cout << "Something's wrong. Press any letter and Enter to exit: ";
        cin >> trash;
        exit (1);
    }
    fin.close ();
}

void mon_en (int& lives, forced_mon_en en)
{
    int mon_num, loops, ran_num, temp_id, index, enloops, oriloops;
    char trash, read;
    bool pass;
    types_of_monsters *firstptr, *temp_ptr, *monster;
    types_of_monsters build;
    ifstream fin;
    srand (time(0));
    fin.open ("monsters.txt", ios::app);
    firstptr = build.build_and_return_list (fin); //builds the linked list
    ran_num = rand() % (100-0) + 0;
    this_thread::sleep_for(chrono::seconds(1));  
    if (en.forced == true)
        ran_num = 1;
    if (ran_num <= 30)
    {
        srand (time(0));
        mon_num = rand () % (10-1) + 1;
        if (en.forced == true)
        {
            mon_num = en.type_of_mon;
            enloops = en.num_of_loops;
        }
        monster = build.get_monster (firstptr, mon_num);
        build.change_num_of_probs (monster->get_num_of_probs());
        do
        {
            monster->display_before();
            cout << endl;
            loops = build.get_num_of_probs();
            //loops = 1;
            oriloops = loops;
            do
            {
                cout << "Enemy Health: " << loops << "/" << oriloops << endl;
                cout << "Your Health: " << lives << "/5" << endl << endl;
                rand_math_prob (lives);
                loops--;
            } while (loops != 0 && lives != 0);
            enloops--;
        } while (en.forced == true && enloops != 0);
        if (lives != 0)
        {
            monster->display_after();
            cout << endl;
        }
    }
}

void cave_game (bool& game_over, int& lives, bool& out_of_lives)
{
    int num_of_levels, orinum, nownum, num_of_ways, correct_way, user_choice, mon;
    bool pass, outer_pass;
    forced_mon_en no_en;
    no_en.forced = false;
    cout << "It's time to navigate through this deadly cave. Choose the correct way\n"
         << "(indicate by number) or else you might encounter a monster. Don't die!\n";
    srand (time(0));
    num_of_levels = rand() % (15-10) + 10;
    orinum = num_of_levels;
    //num_of_levels = 1;
    do
    {
        nownum = abs (num_of_levels-orinum);
        this_thread::sleep_for(chrono::seconds(1));
        srand (time(0));
        num_of_ways = rand() % (5-2) + 2;
        this_thread::sleep_for(chrono::seconds(1));
        srand (time(0));
        correct_way = rand() % (num_of_ways - 1) + 1;
        do
        {
            cout << "Cave level: " << nownum << "/" << orinum << endl;
            cout << "There are " << num_of_ways << " ways to go. Which way?: ";
            cin >> user_choice;
            if (user_choice != correct_way)
            {
                srand(time(0));
                mon = rand() % (100-0) + 0;
                if (mon < 50)
                    mon_en (lives, no_en);
                if (lives == 0)
                    pass = true;
                else
                    pass = false;
                if (lives != 0)
                    cout << "You have hit a dead end. Try again.\n";
            }
            else
            {
                cout << "You have chosen the correct way.\n";
                pass = true;
            }
        } while (pass == false);
        if (lives == 0)
        {
            outer_pass = true;
            out_of_lives = true;
        }
        else if (num_of_levels != 0)
        {
            num_of_levels--;
            outer_pass = false;
        }
        else
        {
            outer_pass = true;
        }
    } while (outer_pass == false);
}

void read (ifstream& fin, int& lives, bool& cave_var)
{
    int space = 0;
    char read_letter, wait;
    fin.get (read_letter);
    do
    {
        this_thread::sleep_for(chrono::milliseconds(30));
        if (read_letter != '|')
        {
            cout.put(read_letter);
            fin.get (read_letter);
        }
        if (read_letter == ' ' && space > 60)
        {
            cout.put(read_letter);
            fin.get (read_letter);
            cout << endl;
            space = 0;
        }
        else
        {
            space++;
        }
    } while (((read_letter != ';' && read_letter != '{') && (read_letter != '|' && read_letter != '[')) && read_letter != '}');
    if (read_letter == '{') //Dust Monster
    {
        cout << endl;
        forced_mon_en en;
        en.forced = true;
        en.type_of_mon = 11;
        en.num_of_loops = 1;
        mon_en (lives, en);
        cave_var = false;
    }
    else if (read_letter == '|') //Cave game
    {
        cave_var = true;
    }
    else if (read_letter == '[') //3 zombies
    {
        forced_mon_en en;
        en.forced = true;
        en.type_of_mon = 1;
        en.num_of_loops = 3;
        cout << endl;
        mon_en (lives, en);
        cave_var = false;
        read (fin, lives, cave_var);
    }
    else if (read_letter == '}') //fighting the investigation monster
    {
        forced_mon_en en;
        en.forced = true;
        en.type_of_mon = 12;
        en.num_of_loops = 1;
        mon_en (lives, en);
        cave_var = false;
        read (fin, lives, cave_var);
    }
    else
    {
        cave_var = false;
    }
}