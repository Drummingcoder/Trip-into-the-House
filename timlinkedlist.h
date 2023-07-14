//This is the INTERFACE for timlinkedlist.
#include <iostream>
#include <vector>
using namespace std;

class types_of_monsters
{
    public:
    types_of_monsters* build_and_return_list (istream& fin);
    types_of_monsters* get_monster (types_of_monsters* monster, int mon_num);
    int get_num_of_probs ();
    void change_num_of_probs (int num);
    void display_before ();
    void display_after ();
    char after_dialogue [60];

    private:
    vector <char> before;
    vector <char> after;
    int id_num;
    int num_of_probs;
    types_of_monsters *ptr;
};