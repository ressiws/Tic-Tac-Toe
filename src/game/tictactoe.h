#pragma once
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include "../common.h"

#define BOARD_DIRECTION 3

class tic_tac_toe {
private:
	char board[3][3];	// the tic-tac-toe board
	int cur_score = 0;	// current player score

public:
	tic_tac_toe( );											// constructor to initialize the game
	void clear_board( );									// clear the game board
	void start_game( );										// start the game
	void restart_game( );									// restart the game
	std::pair<int, int> get_best_move( );					// get best move for the AI
	int minimax( char board[3][3], bool is_maximizing );	// minimax algorithm for AI move evaluation
	void print_board( );									// print the game board
	bool place_marker( int row, int column );				// place a marker on the board
	bool check_winner( );									// check for a winner
	bool board_full( );										// check if the board is full (tie)

	bool player1_turn;	// track which player's turn it is
};

#endif // include guard