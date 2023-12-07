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

void tic_tac_toe::clear_board( )
{
#ifdef _WIN32
	system( "cls" );
#elif
	system( "clear" );
#endif
}

// functions to start the game
void tic_tac_toe::start_game( )
{
	int row, column;

	while ( true )
	{
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

			if ( player1_turn )
				cur_score += 10; // Player wins
			else
			{
				cur_score -= 10; // A.I wins
				player1_turn = false; // player who lost will start next game
			}

			restart_game( ); // ask if the player wants to play again
			break;
		}
		else if ( board_full( ) )
		{
			clear_board( );

			std::cout << "It's a tie!" << std::endl;
			restart_game( ); // ask if the player wants to play again
			break;
		}

		player1_turn = !player1_turn;
	}
}

void tic_tac_toe::restart_game( )
{
	char choice;
	std::cout << std::endl << "Do you want to play again? ( Y/N ): ";
	std::cin >> choice;

	if ( toupper( choice ) == 'Y' )
	{
		// reset the board to empty spaces
		for ( int i = 0; i < BOARD_DIRECTION; ++i )
		{
			for ( int j = 0; j < BOARD_DIRECTION; ++j )
			{
				board[i][j] = ' ';
			}
		}

		// change turn order if AI won the last game
		if ( !player1_turn )
			player1_turn = true; // player start next game


		start_game( );
	}
	else
		std::cout << std::endl << "Thanks for playing!" << std::endl;
}

std::pair<int, int> tic_tac_toe::get_best_move( )
{
	int best_score = INT_MIN;
	std::pair<int, int> move;

	for ( int i = 0; i < BOARD_DIRECTION; ++i )
	{
		for ( int j = 0; j < BOARD_DIRECTION; ++j )
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
		return 10; // player wins
	}
	else if ( check_winner( ) && is_maximizing ) 
	{
		return -10; // A.I wins
	}
	else if ( board_full( ) ) 
	{
		return 0; // tie
	}

	if ( is_maximizing )
	{
		int best_score = INT_MIN;
		for ( int i = 0; i < BOARD_DIRECTION; ++i )
		{
			for ( int j = 0; j < BOARD_DIRECTION; ++j )
			{
				if ( board[i][j] == ' ' ) 
				{
					board[i][j] = 'O';
					int score = minimax( board, false );
					board[i][j] = ' ';
					best_score = std::max( best_score, score );
				}
			}
		}

		return best_score;
	}
	else 
	{
		int best_score = INT_MAX;
		for ( int i = 0; i < BOARD_DIRECTION; ++i )
		{
			for ( int j = 0; j < BOARD_DIRECTION; ++j )
			{
				if ( board[i][j] == ' ' ) 
				{
					board[i][j] = 'X';
					int score = minimax( board, true );
					board[i][j] = ' ';
					best_score = std::min( best_score, score );
				}
			}
		}

		return best_score;
	}
}

// function to print the game board
void tic_tac_toe::print_board( )
{
	clear_board( );
	std::cout << "Current score: " << cur_score << std::endl << std::endl;

	for ( int i = 0; i < BOARD_DIRECTION; ++i )
	{
		for ( int j = 0; j < BOARD_DIRECTION; ++j )
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
	if ( row >= 0 && row < BOARD_DIRECTION && column >= 0 && column < BOARD_DIRECTION && board[row][column] == ' ' )
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
	for ( int i = 0; i < BOARD_DIRECTION; ++i )
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
	for ( int i = 0; i < BOARD_DIRECTION; ++i )
	{
		for ( int j = 0; j < BOARD_DIRECTION; ++j )
		{
			if ( board[i][j] == ' ' )
				return false; // the board is not full
		}
	}

	return true; // the board is full
}