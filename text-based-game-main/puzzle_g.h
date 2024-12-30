#include <iostream>
#include"puzzle_d.h"
using namespace std;

void puzzle_g(){

    // "1" to indicate there is a piece of a key
    bool keys[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}};

    int open = 0;
    int numberOfTurns = 0;

    cout << "Warning!! : You only have 10 chances to open the box to receive Keys otherwise..... " << endl;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << "[ ]";
        }
        cout << endl;
    }

    while (open < 4)
    {

        int row, column;

        cout << "Selecting coordinates\n";

        cout << "Choose a row number between 0 and 3: ";
        cin >> row;

        cout << "Choose a column number between 0 and 3: ";
        cin >> column;

        // Check if a keys exists in those coordinates
        if (keys[row][column])
        {
            // If the player get a key, remove it by setting the value to zero.
            keys[row][column] = 0;

            open++;

            cout << "Received! " << (4 - open) << " left\n\n";
        }
        else
        {

            cout << "Miss\n\n";
        }

        // Count how many turns the player has taken
        numberOfTurns++;
        int turnsLeft = 10 - numberOfTurns;
        cout << "Number of turns left: " << turnsLeft << endl;
        
        if (numberOfTurns == 10)
        {
            cout << "oh No!, You lost 20 percent health ";
            break;
        }
        else if (open == 4)
        {
            cout << "Victory!\n";
            cout << "You won in " << numberOfTurns << " turns";
            break;
        }
    }
}
