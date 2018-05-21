#include <iostream>
using namespace std;

//matricea ce contine starea jocului
//o declar aici pentru a fi vizibila pentru toate metodele
char game[3][3];

void makeMove(int choice, char mark);
bool checkwinRow(int row, char mark);
bool checkwinCol(int col, char mark);
bool checkwinDiag1(char mark);
bool checkwinDiag2(char mark);
bool checkwin(char mark);
void displayGame();

int main()
{
    //un array care are trei array-uri separate
    //starea initiala a jocului
    //fiecare numar reprezinta o casuta din joc
    // game;
    game[0][0] = '1';
    game[0][1] = '2';
    game[0][2] = '3';
    game[1][0] = '4';
    game[1][1] = '5';
    game[1][2] = '6';
    game[2][0] = '7';
    game[2][1] = '8';
    game[2][2] = '9';

    // numele jucatorilor
    string player1, player2;
    // player 1 incepe tot timpul
    int player = 1;
    // semnul curent al jucatorului
    char mark;
    //daca avem stare de WIN sau nu
    bool win = false;
    //mutarea curenta
    int choice;
    //numarul curent de mutari
    int moves = 0;

    //citesc numele jucatorilor
    cout << "Please enter player names" << endl;
    cout << "Player 1: ";
    cin >> player1;
    cout << "Player 2: ";
    cin >> player2;

    //joc jocul cat timp nu am stare de WIN si numarul de mutari este < 9
    do
    {
        displayGame();

        //in functie de jucatorul curent, afisez mesaj corspunzator
        if (player == 1)
        {
            cout << "Player " << player1 << ", enter a number:  ";
        }
        else
        {
            cout << "Player " << player2 << ", enter a number:  ";
        }

        //citesc mutarea
        cin >> choice;
        cout << "Choice " << choice;

        //determin semnul jucatorului in functie de numarul curent al jucatorului
        if (player == 1)
        {
            mark = 'X';
        }
        else
        {
            mark = 'O';
        }

        //fac mutarea - adica pun in casuta aleasa, semnul curent al jucatorului
        makeMove(choice, mark);
        //make move
        moves++;
        //testez daca starea jocului este stare de win
        //pot sa pun un test si sa testez daca e win doar daca numarul de mutari >= 5
        win = checkwin(mark);

        // daca nu este stare de win ... schimb jucatorul
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

    // cin.ignore();
    // cin.get();
    return 0;
}

void makeMove(int choice, char mark)
{
    cout << "Mutarea curenta " << choice;
    // catul impartirii mutarii - 1 / 3 va reprezenta numarul liniei
    int i = (choice - 1) / 3;
    // restul impartirii va reprezenta coloana
    int j = (choice - 1) % 3;
    //pun semnul
    game[i][j] = mark;
}

//verific daca un rand din matrice, randul ROW este castigator
//presupun ca randul este castigator si daca gasesc un caracter diferit de semnul curent, este clar ca nu este un row castigator
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

//verific daca o coloan din matrice este castigatoare, coloana COL
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

//diag 1 sau diag pricipala ( i == j )
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

//diag 2 sau diag secundara ( i == j )
//pentru o matrice de n, diag secund. i, n - 1 - i;
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

//functie separata ce testeaza daca jocul este intr-o stare de WIN sau nu
bool checkwin(char mark)
{
    bool win = false;

    // i merge 0, 1, 2
    // pentru fiecare iteratie testez daca linia sau coloana i sunt castigatoare
    for (int i = 0; i < 3; i++)
    {
        //daca jocul este win, nu are sens sa mai testez
        if (win == false)
        {
            win = checkwinRow(i, mark);
        }
        if (win == false)
        {
            win = checkwinCol(i, mark);
        }
    }

    //testez daca diagonalele sunt castigatoare
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

//afisez starea jocului, adica matricea
void displayGame()
{
    //face clear la ecran, nu poti sa dai scroll in sus
    // system("cls");

    //numele jocului
    cout << "\n\n\tTic Tac Toe\n\n";

    //afisez jucatorii si semnele lor
    cout << "Player 1 (X)  -  Player 2 (O)" << endl;
    cout << endl;

    //pentru fiecare linie, afisez linia, o linie este un array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << game[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
