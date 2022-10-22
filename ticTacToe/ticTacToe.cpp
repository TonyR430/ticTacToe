#include <iostream>
#include <stdlib.h>
using namespace std;
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int choice;
int row, column;
char turn = 'X';
bool draw = false;

//draws the board, shows current player moves, clears the screen after each move

void display_board() {

    system("CLS");


    //Renders the game board

    cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
   
}

//Function to get the player input and update the board

void player_turn() {
    if (turn == 'X') {
        cout << "\n\tPlayer - 1 [X] turn : ";
    }
    else if (turn == 'O') {
        cout << "\n\tPlayer - 2 [O] turn : ";
    }
   
    cin >> choice;

    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        //Add's X's move and makes sure the square isn't already taken
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
       //Add's O's move and makes sure the square isn't already taken
        board[row][column] = 'O';
        turn = 'X';
    }
    else {
        //Prompts for a new choice if square is taken
        cout << "Box already filled!n Please choose another!!\n\n";
        player_turn();
    }
   
    
    display_board();
}

//Below checks current status of the board, if a player won, its a draw, or if the game will continue

bool gameover() {
    //Checks for win rows\columns 
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

   //Checks for win diagonally
    // this is a push

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Determines if game contin
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    //Determines if game is a draw
    draw = true;
    return false;
   
}

//Main function, calls prior functions to draw board, get turns, and check for win

int main()
{
    cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    while (gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    if (turn == 'O' && draw == false) {
        cout << "\n\n\nCongratulations!Player with 'X' has won the game";
    }
    else if (turn == 'X' && draw == false) {
        cout << "\n\n\nCongratulations!Player with 'O' has won the game";
    }
    else
        cout << "\n\nGAME DRAW!!!\n\n";
}