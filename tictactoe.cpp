#include <iostream>

#define ex 'X'
#define oh 'O'

int main() 
{
    //creating the board
    char board[6][7]= {
        {' ', '1', ' ', '2', ' ', '3', '\n'},
        {'1', ' ', '|', ' ', '|', ' ', '\n'}, 
        {' ', '-', '+', '-', '+', '-', '\n'}, 
        {'2', ' ', '|', ' ', '|', ' ', '\n'},
        {' ', '-', '+', '-', '+', '-', '\n'},
        {'3', ' ', '|', ' ', '|', ' ', '\n'}
    };

    //Printing Setup
    std::cout << "TIC-TAC-TOE" << std::endl;
    std::cout << "Created by Dylan Ang" << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j];
        }
    }
    std::cout << "Enter your move as y x" << std::endl;

    //game loop
    while(1)
    {
        break;
    }
}