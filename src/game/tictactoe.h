#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "../common.h"

class tic_tac_toe {
private:
	char board[3][3];	// the tic-tac-toe board
	bool player1_turn;	// to track which player's turn it is
	int cur_score = 0;

public:
	tic_tac_toe( );											// constructor to initialize the game
	void start_game( );										// start the game
	std::pair<int, int> get_best_move( );					// get best move for the AI
	int minimax( char board[3][3], bool is_maximizing );	// minimax algorithm for AI move evaluation
	void print_board( );									// print the game board
	bool place_marker( int row, int column );				// place a marker on the board
	bool check_winner( );									// check for a winner
	bool board_full( );										// check if the board is full (tie)
};

#endif // include guard