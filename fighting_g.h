#include <iostream>
#include <array>
#include <string>
using namespace std;

void fighting_g()
{
    // The available attack options and their respective attack points are stored in arrays
    const int fight_options = 4;
    array<string, fight_options> fight = {"punch", "knife", "bat", "gun"};
    array<int, fight_options> attack_points = {5, 10, 15, 25};

    // The player and enemy start with a certain amount of health and have the option to defend with their hands or a shield
    int hand = 5;
    int shield = 15;
    int ememy_Health = 35;
    int my_Health = 35;

    // The game instructions are displayed to the player
    cout << "   " << endl;
    cout << "Your attack option:  " << endl;
    cout << "   punch =5; knife =10; baseball=15; gun =25  " << endl;
    cout << "   " << endl;
    cout << "Your defense option:  " << endl;
    cout << "   hand=5; int shield = 15 " << endl;
    cout << "   " << endl;
    cout << "Your and Ememy health is 35  " << endl;
    cout << " _____________________________________________" << endl;

    // The game loop runs until one of the characters runs out of health
    while (true)
    {
        // The player is prompted to choose an attack option
        cout << "   " << endl;
        cout << "Your trun to attack " << endl;
        cout << "   Choose: punch, knife, bat, gun " << endl;
        string action;
        cin >> action;
        int points = 0;

        // The chosen attack option is matched with its respective attack points
        for (int i = 0; i < fight_options; i++)
        {
            if (fight[i] == action)
            {
                points = i;
            }
        }

        // If a valid attack option is chosen, the enemy's health is reduced by the corresponding attack points
        if (points > 0)
        {
            ememy_Health -= attack_points[points];
            cout << "Your ememy health has decreased to  " << ememy_Health << endl;
        }
        else
        {
            cout << "Please put right attack " << endl;
        }

        // If the enemy's health reaches zero, the player wins and the game ends
        if (ememy_Health <= 0)
        {
            cout << "Hurray!, You have killed the ememy" << endl;
            break;
        }

        cout << " _____________________________________________" << endl;

        // It's now the enemy's turn to attack, and the player must choose to defend with their hand or shield
        cout << "Ememy is attacking " << endl;
        cout << "Defense using hand or shield " << endl;
        int ememy_Attack = rand() % 15;
        int ememy_attack = ememy_Attack;
        string defense;
        cin >> defense;

        // If the player chooses to defend with their hand, the amount of health they lose is calculated and displayed

        if ((defense == "hand") || (defense == "h"))
        {
            int health = (ememy_attack - hand);
            if (health > 0)
            {
                my_Health -= health;
            }
            cout << "Ememy attacked, (power level : " << ememy_attack << ")  your health has decreased to  " << my_Health << endl;
        }
        else if ((defense == "shield") || (defense == "s"))
        {
            int health = (ememy_attack - shield);
            if (health > 0)
            {
                my_Health -= health;
            }
            cout << "Ememy attacked, (power level : " << ememy_attack << ")  your health has decreased to  " << my_Health << endl;
        }
        else
        {
            cout << "Please put right defense value " << endl;
        }
        if (my_Health <= 0)
        {
            cout << "You have been killed, you are dead" << endl;
            break;
        }
    }
}
