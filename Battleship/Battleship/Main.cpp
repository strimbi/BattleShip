// Battleship.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <ctime>
#include <string>
#include "Table.h"

using namespace std;

int maxships = 10;
Table table;

int main()
{
    Table table;
    srand(time(NULL));
    table.SetShips();
    table.ShowSecretTable();
    cout << "------------------------------" << endl;
    int pos1, pos2;
    char prompt;
    while (1)
    {
        cout << "Please input location: ";
        cin >> pos1 >> pos2;
        if (pos1 < 1 || pos1>10 || pos2 < 1 || pos2>10)
        {
            cout << "Wrong coordinates";
            break;
        }
        if (table.checkPoint(pos1, pos2))
        {
            cout << "You got me! " << endl;
            table.changePoint(pos1, pos2, 'H');//H-hit
        }
        else
        {
            cout << "Sorry no ship at this position" << endl;
            table.changePoint(pos1, pos2, 'G');//G-guessed
        }
        table.ShowSecretTable();
    }
    cout << "Game over" << endl;
    
    table.ShowTable();
    system("pause");
    return 0;
}

