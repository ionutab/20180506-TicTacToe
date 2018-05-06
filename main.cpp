#include <iostream>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char game[3][3];

bool checkwin();
void displayArray(char[] array);
void displayGame();
void initGame();

int main()
{
    string player1, player2;
    int player = 1;
    char mark;
    bool win = false;
    int choice;

    do
    {
        initGame();
        displayGame();
        // player = (player % 2) ? 1 : 2;
        // player = 1;

        cout << "Please enter player names:";
        cout << "Player 1:";
        cin >> player1;
        cout << "Player 2:";
        cin >> player2;

        if (player == 1)
        {
            cout << "Player " << player1 << ", enter a number:  ";
        }
        else
        {
            cout << "Player " << player2 << ", enter a number:  ";
        }

        cin >> choice;

        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        //read choice
        //make move

        cin.ignore();
        cin.get();
        win = checkwin();

        // if not win update player

    } while (win == false);

    displayGame();

    // display winner
    // if (player == 1)
    //     cout << "==>\aPlayer " << --player << " win ";
    // else
    //     cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

bool checkwin()
{
    return true;
}

void initGame()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            game[i][j] = ' ';
        }
    }
}

void displayArray(char[] array)
{
    for (int i = 0; i < array.length; i++)
    {
        cout << array[i] << " ";
    }
}

void displayGame()
{
    system("cls");

    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl
         << endl;
    cout << endl;

    for (int i = 0; i < game.length; i++)
    {
        displayArray(game[i]);
    }
}
