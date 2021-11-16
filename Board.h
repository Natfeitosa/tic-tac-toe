#pragma once
#include <vector>
#include <iostream>
#include "Pieces.h"
#include <unordered_map>

class Board {
public:
	Board();
	void init();
	bool win();
	bool move(int player_move, Player player);
	void display();
	void reset();
	void display_winner(Player player);

private:
	std::unordered_map<int,Parts> board;
	//bool valid_move(int move);
	char ch(int position);


};


void Board::init() {
	for (int i = 1; i < 10; i++) {
		board[i] = EMPTY;
	}

}
Board::Board() {
	init();
}
bool Board::move(int player_move,Player player) {
	if (player_move > 9 && player_move < 1) {
		return false;
	}
	if (player == circle) {
		if (board[player_move] == EMPTY) {
			board[player_move] = CIRCLE;
		}
		else {
			return false;
		}
	}
	else {
		if (board[player_move] == EMPTY) {
			board[player_move] = CROSS;
		}
		else {
			return false;
		}
	}
	
	return true;
}
bool Board::win() {
	if (board[1] == board[2] && board[2] == board[3] && board[1]!=EMPTY)//top row accross
		return true;
	if (board[1] == board[4] && board[4] == board[7] && board[1] != EMPTY)//top down left
		return true;
	if (board[1] == board[5] && board[5] == board[9] && board[1] != EMPTY)//diagnol 1
		return true;
	if (board[2] == board[5] && board[5] == board[8] && board[2] != EMPTY)//top down middle
		return true;
	if (board[3] == board[6] && board[6] == board[9] && board[3] != EMPTY)//top down right
		return true;
	if (board[3] == board[5] && board[5] == board[7] && board[3] != EMPTY)//diagnol 2
		return true;
	if (board[4] == board[5] && board[5] == board[6] && board[4] != EMPTY)//middle row accross
		return true;
	if (board[7] == board[8] && board[8] == board[9] && board[7] != EMPTY)// bottom row accross
		return true;
	return false;
}
char Board::ch(int position) {
	if (board[position] == CROSS) {
		return 'X';
	}
	else if (board[position] == CIRCLE) {
		return 'O';
	}
	else {
		char pos = '0' + position;
		return pos;
	}
}
void Board::display() {
	std::cout << ch(1) << " | " << ch(2) << " | " << ch(3) << std::endl;
	std::cout << "----------\n";
	std::cout << ch(4) << " | " << ch(5) << " | " << ch(6) << std::endl;
	std::cout << "----------\n";
	std::cout << ch(7) << " | " << ch(8) << " | " << ch(9) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

}
void Board::reset() {
	init();
}
void Board::display_winner(Player player){
	if (player == cross) {
		std::cout << "Congrats Cross won!\n";
	}
	else
		std::cout << "Congrats Circle won!\n";
}