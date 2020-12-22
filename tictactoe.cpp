#include <iostream>
#include <stdlib.h>

#define ex 'X'
#define oh 'O'

//declarations
int ctoi(char let);
int itoi(int num);

int main() 
{
    //creating the board
    char board[6][7]= {
        {' ', '1', ' ', '2', ' ', '3', '\n'},
        {'A', ' ', '|', ' ', '|', ' ', '\n'}, 
        {' ', '-', '+', '-', '+', '-', '\n'}, 
        {'B', ' ', '|', ' ', '|', ' ', '\n'},
        {' ', '-', '+', '-', '+', '-', '\n'},
        {'C', ' ', '|', ' ', '|', ' ', '\n'}
    };

    //Printing Setup
    std::cout << "========================" << std::endl;
    std::cout << "      TIC-TAC-TOE" << std::endl;
    //std::cout << "========================" << std::endl;
    std::cout << "  Created by Dylan Ang" << std::endl;
    std::cout << "========================" << std::endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            std::cout << board[i][j];
        }
    }
    //std::cout << "A1 is the top left box" << std::endl;
    std::cout << "Enter q to quit." << std::endl;
    char pl1[10];
    char pl2[10];
    std::cout << "Enter Player 1's name: ";
    std::cin >> pl1;
    if (strcmp(pl1, "q") == 0) {
        std::cout << "You have quit" << std::endl;
        return 0;
    }
    std::cout << "Enter Player 2's name: ";
    std::cin >> pl2;
    if (strcmp(pl2, "q") == 0) {
        std::cout << "You have quit" << std::endl;
        return 0;
    }

    //game loop
    int moves = 0;
    //char* mov;
    char y = 0;
    int x = 0;
    bool win = false;
    while(1)
    {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                std::cout << board[i][j];
            }
        }
        if (win == true) {
            std::cout << "================================" << std::endl;
            std::cout << "Winner Winner Chicken Dinner!" << std::endl;
            std::cout << "================================" << std::endl;
            break;
        }
        //get input
        if ((moves % 2) == 0) std::cout << pl1 << "'s move: ";
        else std::cout << pl2 << "'s move: ";
        std::cin >> y;
        std::cout << std::endl;
        if (y == 'q') {
            std::cout << "You have quit" << std::endl;
            break;
        }
        std::cin >> x;
        int yy = ctoi(y);
        int xx = itoi(x);
        if (yy == 0 || xx == 0) std::cout << "Invalid Input" << std::endl;
        //claim tiles
        else {
            if (board[yy][xx] == ' ') {
                if ((moves % 2) == 0) board[yy][xx] = ex;
                else board[yy][xx] = oh;  
                moves++;
            }
        }
        //Win check
        //rows
        for (int i = 1; i <= 5; i += 2) {
            if (board[i][1] != ' ' && board[i][1] == board[i][3] && board[i][3] == board[i][5])
                win = true;
        }
        //columns
        for (int i = 1; i <= 5; i += 2) {
            if (board[1][i] != ' ' && board[1][i] == board[3][i] && board[3][i] == board[5][i])
                win = true;
        }
        //diagonal
        if (board[1][5] != ' ' && board[1][5] == board[3][3] && board[3][3] == board[5][1])
            win = true;
        if (board[1][1] != ' ' && board[1][1] == board[3][3] && board[3][3] == board[5][5])
            win = true;
    }
}

int ctoi(char let) {
    switch (let) {
        case 'A':
            return 1;
        case 'a':
            return 1;
        case 'B':
            return 3;
        case 'b':
            return 3;
        case 'C':
            return 5;
        case 'c':
            return 5;
        case 'q':
            return 6;
        case 'Q':
            return 6;
        default:
            return 0;
    }
    return 0;
}

int itoi(int num) {
    switch (num) {
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 5;
        default:
            return 0;
    }
    return 0;
}