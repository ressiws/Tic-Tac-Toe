#include "tictactoe.h"

// constructor to initialize the game
tic_tac_toe::tic_tac_toe( )
{
	// initialize the board with empty spaces
	for ( int i = 0; i < 3; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			board[i][j] = ' ';
		}
	}

	player1_turn = true; // player 1 starts the game
}

// functions to start the game
void tic_tac_toe::start_game( )
{
	int row, column;

	while ( true )
	{
		system( "cls" );
		std::cout << "Current score: " << cur_score << std::endl << std::endl;

		print_board( );

		if ( player1_turn )
		{
			std::cout << std::endl << "Player 1, enter row (1-3) and column (1-3): ";
			std::cin >> row >> column;
			row--;
			column--;

			if ( !place_marker( row, column ) )
			{
				std::cout << "Invalid move! Please try again." << std::endl;
				continue;
			}
		}
		else
		{
			std::pair<int, int> best_move = get_best_move( );
			board[best_move.first][best_move.second] = 'O';
		}

		if ( check_winner( ) ) 
		{
			print_board( );

			std::cout << ( player1_turn ? "Player" : "AI" ) << " wins!" << std::endl;
			break;
		}
		else if ( board_full( ) ) 
		{
			print_board( );

			std::cout << "It's a tie!" << std::endl;
			break;
		}

		player1_turn = !player1_turn;
	}
}

std::pair<int, int> tic_tac_toe::get_best_move( )
{
	int best_score = INT_MIN;
	std::pair<int, int> move;

	for ( int i = 0; i < 3; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			if ( board[i][j] == ' ' )
			{
				board[i][j] = 'O';

				int score = minimax( board, false );

				board[i][j] = ' ';

				if ( score > best_score )
				{
					best_score = score;
					move.first = i;
					move.second = j;
				}
			}
		}
	}

	return move;
}

int tic_tac_toe::minimax( char board[3][3], bool is_maximizing )
{
	if ( check_winner( ) && !is_maximizing ) 
	{
		cur_score += 10;// AI wins
		return 10; 
	}
	else if ( check_winner( ) && is_maximizing ) 
	{
		cur_score -= 10; // player wins
		return -10; 
	}
	else if ( board_full( ) ) 
	{
		return 0; // tie
	}

	if ( is_maximizing )
	{
		int bestScore = INT_MIN;
		for ( int i = 0; i < 3; ++i ) 
		{
			for ( int j = 0; j < 3; ++j ) 
			{
				if ( board[i][j] == ' ' ) 
				{
					board[i][j] = 'O';
					int score = minimax( board, false );
					board[i][j] = ' ';
					bestScore = std::max( bestScore, score );
				}
			}
		}

		return bestScore;
	}
	else 
	{
		int bestScore = INT_MAX;
		for ( int i = 0; i < 3; ++i ) 
		{
			for ( int j = 0; j < 3; ++j ) 
			{
				if ( board[i][j] == ' ' ) 
				{
					board[i][j] = 'X';
					int score = minimax( board, true );
					board[i][j] = ' ';
					bestScore = std::min( bestScore, score );
				}
			}
		}

		return bestScore;
	}
}

// function to print the game board
void tic_tac_toe::print_board( )
{
	for ( int i = 0; i < 3; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			std::cout << board[i][j];

			if ( j < 2 )
				std::cout << "|";
		}

		std::cout << std::endl;

		if ( i < 2 )
			std::cout << "-----" << std::endl;
	}
}

// function to place a marker on the board
bool tic_tac_toe::place_marker( int row, int column )
{
	// check if the chosen position if valid
	if ( row >= 0 && row < 3 && column >= 0 && column < 3 && board[row][column] == ' ' )
	{
		board[row][column] = ( player1_turn ? 'X' : 'O' );

		return true; // successfully placed the marker
	}

	return false; // invalid move
}

// function to check for a winner
bool tic_tac_toe::check_winner( )
{
	// check rows, columns, and diagonals for a win
	for ( int i = 0; i < 3; ++i )
	{
		if ( board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ' )
			return true; // row win

		if ( board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ' )
			return true; // column win
	}

	if ( ( board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ' ) ||
		 ( board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ' ) )
		return true; // diagonal win

	return false; // no winner yet
}

// functions to check if the board is full (tie)
bool tic_tac_toe::board_full()
{
	for ( int i = 0; i < 3; ++i )
	{
		for ( int j = 0; j < 3; ++j )
		{
			if ( board[i][j] == ' ' )
				return false; // the board is not full
		}
	}

	return true; // the board is full
}