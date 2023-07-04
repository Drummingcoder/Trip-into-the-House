//This is the IMPLEMENTATION for timmathfunctions.
#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>
#include <iomanip>
#include "timmathfunctions.h"
#include "timotherfunctions.h"
#include "timstreamandarr.h"
using namespace std;

void rand_math_prob (int& lives)
{
    double op1, op2, ans, user_ans;
    int num;
    bool loop;
    srand(time(0));
    num = rand () % (5-0) + 0;
    this_thread::sleep_for(chrono::seconds(1));
    srand(time(0));
    op1 = rand () % (100-1) + 1;
    this_thread::sleep_for(chrono::seconds(1));
    srand(time(0));
    op2 = rand () % (100-1) + 1;
    do
    {
        if (num == 0)
        {
            cout << op1 << "+" << op2 << "=";
            ans = op1 + op2;
        }
        else if (num == 1)
        {
            cout << op1 << "-" << op2 << "=";
            ans = op1 - op2;
        }
        else if (num == 2)
        {
            cout << op1 << "x" << op2 << "=";
            ans = op1 * op2;
        }
        else if (num == 3)
        {
            division_prob (op1, op2);
            cout << op1 << "/" << op2 << "=";
            ans = op1 / op2;
        }
        else if (num == 4)
        {
            square_prob (op2);
            cout << op1 << "^" << op2 << "=";
            ans = pow(op1, op2);
        }
        cin >> user_ans;
//This part is game-specific and should be customized game to game.
        if (user_ans == ans)
        {
            cout << "Correct!" << endl;
            loop = false;
        }
        else
        {
            cout << "Wrong! You lost a life." << endl;
            loop = true;
            lives--;
        }
    } while (loop == true && lives != 0);
}

void division_prob (double& op1, double& op2)
{
    int round_ans, divisor;
    double ans;
    setprecision (5);
    ans = op1 / op2;
    round_ans = round (ans);
    if (round_ans != ans)
    {
        srand (time(0));
        op2 = rand () % (12-1) + 1;
        op1 = (rand () % (12-1) + 1) * op2;
    }
}

void square_prob (double& op2)
{
    if (op2 > 3)
    {
        srand (time(0));
        op2 = rand() % (4-1) + 1;
    }
}