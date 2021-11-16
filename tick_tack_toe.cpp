// tick_tack_toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"
std::string Turn(Player player) {
    std::string p;
    if (player == cross) {
        p = "Cross";
    }
    else {
        p = "Circle";
    }
    return p;
}
int main()
{
    bool end = false;
    Board game;
    Player turn = cross;
    while (!end) {
        
        std::cout <<"Current turn: "<<Turn(turn) <<std::endl;
        std::cout << std::endl;
        game.display();
        
        bool valid = false;
        while (!valid) 
        {
            std::cout << "Please pick where you want to place your piece:\n";
            int mov;
            std::cin >> mov;
            if (!(game.move(mov, turn))) {
                std::cout<<"invalid move, please pick another position\n";
            }
            else {
                valid=true;
            }
        }
        


        end = game.win();
        if (end) {
            game.display();
            game.display_winner(turn);
            std::cout << "Play again(y/n)?\n";
            char again;
            std::cin >> again;
            if (again == 'y') {
                end = false;
                game.reset();
                turn = cross;
            }
        }
        else {
            if (turn == cross)
                turn = circle;
            else
                turn = cross;
        }
        if (game.stale_mate()) {
            std::cout << "No more available moves, want to play again?\n";
            char again;
            std::cin >> again;
            if (again == 'y') 
            {
                game.reset();
                turn = cross;
            }
            else {
                end = true;
            }
        }
        //end = true;
    }
    std::cout << "GAME OVER\n";
}

