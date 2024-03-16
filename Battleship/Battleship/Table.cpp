#include "Table.h"
#include <iostream>
#include <string>

using namespace std;

Table::Table()
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void Table::Clear()
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

char Table::SetOrientetion()
{
    int orientation = rand() % 2;

    switch (orientation)
    {
    case 0: return 'H';
        break;
    case 1: return 'V';
        break;
    }
    return 'N';
}

bool Table::CheckNeighbours(int x, int y)
{
    if (matrix[x][y + 1] == 'O') return true;
    if (matrix[x][y - 1] == 'O') return true;
    if (matrix[x + 1][y] == 'O') return true;
    if (matrix[x - 1][y] == 'O') return true;
    if (matrix[x + 1][y + 1] == 'O') return true;
    if (matrix[x - 1][y + 1] == 'O') return true;
    if (matrix[x + 1][y - 1] == 'O') return true;
    if (matrix[x - 1][y - 1] == 'O') return true;
    return false;
}

void Table::SetShips()
{
    Clear();
    //4-1,3-2,3-4
    int s = 0;

    while (s < 10)
    {
        int x = rand() % rows;
        int y = rand() % columns;
        char orient = SetOrientetion();

        if (s < 3)
        {
            if (orient == 'H' && y <= 6)
            {
                if (CheckNeighbours(x, y) == false && CheckNeighbours(x, y + 1) == false && CheckNeighbours(x, y + 2) == false && CheckNeighbours(x, y + 3) == false)
                {
                    matrix[x][y] = 'O';
                    matrix[x][y + 1] = 'O';
                    matrix[x][y + 2] = 'O';
                    matrix[x][y + 3] = 'O';
                    s++;
                }
            }
            else if (orient == 'V' && x <= 6)
            {
                if (CheckNeighbours(x, y) == false && CheckNeighbours(x + 1, y) == false && CheckNeighbours(x + 2, y) == false && CheckNeighbours( x+ 3, y) == false)
                {
                    matrix[x][y] = 'O';
                    matrix[x + 1][y] = 'O';
                    matrix[x + 2][y] = 'O';
                    matrix[x + 3][y] = 'O';
                    s++;
                }
            }
        }
        else if (s >= 3 && s < 6)
        {
            char orient = SetOrientetion();

            if (matrix[x][y] != 'O' && CheckNeighbours(x, y) == false)
            {
                if (orient == 'H')
                {
                    if (matrix[x][y + 1] != 'O' && CheckNeighbours(x, y + 1) == false)
                    {
                        matrix[x][y + 1] = 'O';
                        matrix[x][y] = 'O';
                        s++;
                    }
                }
                else if (orient == 'V')
                {
                    if (matrix[x + 1][y] != 'O' && CheckNeighbours(x + 1, y) == false)
                    {
                        matrix[x + 1][y] = 'O';
                        matrix[x][y] = 'O';
                        s++;
                    }
                }
            }
        }
        else if (s >= 6 && s < 10)
        {
            if (CheckNeighbours(x, y) == false)
            {
                matrix[x][y] = 'O';
                s++;
            }
        }
    }
}

void Table::ShowTable()
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool Table::checkPoint(int x, int y)
{ 
    return (matrix[x][y] == 'O');
}

void Table::changePoint(int x, int y, char a)
{
    if (a == 'H')
    {
        matrix[x][y] = 'X';
    }
    else
    {
        matrix[x][y] = '*';
    }
}

void Table::ShowSecretTable()
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            if (matrix[i][j] == 'X' || matrix[i][j] == '*')
            {
                cout << matrix[i][j] << " ";
            }
            else  cout << '.' << " ";
        }
        cout << endl;
    }
}

Table::~Table()
{

}