#include <iostream>
using namespace std;

char game[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void makeMove(int choice, char mark);
bool checkwinRow(int row, char mark);
bool checkwinCol(int col, char mark);
bool checkwinDiag1(char mark);
bool checkwinDiag2(char mark);
bool checkwin(char mark);
void displayArray(char array[]);
void displayGame();

int main()
{
    string player1, player2;
    int player = 1;
    char mark;
    bool win = false;
    int choice;
    int moves = 0;

    cout << "Please enter player names" << endl;
    cout << "Player 1: ";
    cin >> player1;
    cout << "Player 2: ";
    cin >> player2;

    do
    {
        displayGame();

        if (player == 1)
        {
            cout << "Player " << player1 << ", enter a number:  ";
        }
        else
        {
            cout << "Player " << player2 << ", enter a number:  ";
        }

        //read choice
        cin >> choice;
        cout << "Choice " << choice;

        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        makeMove(choice, mark);
        //make move
        moves++;
        win = checkwin(mark);

        // if not win update player
        if (win == false)
        {
            if (player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }
        }

    } while (win == false && moves < 9);

    displayGame();

    // display winner
    if (win == true)
    {
        if (player == 1)
        {
            cout << "Player " << player1 << " wins! ";
        }
        else
        {
            cout << "Player " << player2 << " wins! ";
        }
    }
    else
    {
        cout << "Tie game! Play again.";
    }
    cout << endl;
    cin.ignore();
    cin.get();
    return 0;
}

void makeMove(int choice, char mark)
{
    int i = choice / 3;
    int j = choice % 3 - 1;

    game[i][j] = mark;
}

bool checkwinRow(int row, char mark)
{
    for (int i = 0; i < 3; i++)
    {
        if (game[row][i] != mark)
        {
            return false;
        }
    }
    return true;
}
bool checkwinCol(int col, char mark)
{
    for (int i = 0; i < 3; i++)
    {
        if (game[i][col] != mark)
        {
            return false;
        }
    }
    return true;
}
bool checkwinDiag1(char mark)
{
    for (int i = 0; i < 3; i++)
    {
        if (game[i][i] != mark)
        {
            return false;
        }
    }

    return true;
}
bool checkwinDiag2(char mark)
{
    for (int i = 0; i < 3; i++)
    {
        if (game[i][3 - 1 - i] != mark)
        {
            return false;
        }
    }

    return true;
}

bool checkwin(char mark)
{
    bool win = false;

    for (int i = 0; i < 3; i++)
    {
        if (win == false)
        {
            win = checkwinRow(i, mark);
        }
        if (win == false)
        {
            win = checkwinCol(i, mark);
        }
    }

    if (win == false)
    {
        win = checkwinDiag1(mark);
    }
    if (win == false)
    {
        win = checkwinDiag2(mark);
    }

    return win;
}

void displayArray(char a[3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
}

void displayGame()
{
    system("cls");

    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl;
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        displayArray(game[i]);
        cout << endl;
    }
    cout << endl;
}
