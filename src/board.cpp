#include <board.hpp>
#include <iostream>
#include <cstdlib>

Board :: Board()
{
	int row, col;
	for (row = 0; row < 6; ++row)
	{
		for (col = 0; col < 7; ++col)
		{
			board[row][col] = 0;
		}
	}
	player = 1;
	available = 42;
}

void Board :: display()
{
	int row, col;
	#ifdef __unix__
		system("clear");
	#elif defined(_WIN32) || defined(WIN32)
		system("cls");
	#endif
	for(col = 0; col < 7; ++col)
	{
		std :: cout << "\t" << col << "\t" << (col == 6 ? "" : "|");
	}
	std :: cout << "\n" << std::string(112, '-') << "\n";
	for(row = 0; row < 6; ++row)
	{
		for(col = 0; col < 7; ++col)
		{
			std :: cout << (col == 0 ? "" : "|");
			switch (board[row][col])
			{
			case 1:
				std :: cout << "\tX\t";
				break;
			case -2:
				std :: cout << "\tO\t";
				break;
			default:
				std :: cout << "\t\t";
			}
		}
		std :: cout << "\n";
		std :: cout << std::string(112, '-');
		std :: cout << "\n";
	}
}

int Board :: getPlayer() const
{
	return player;
}

int Board :: makeMove(int col)
{
	if(col >= 0 and col <= 6)
	{
		int row;
		for(row = 5; row >= 0; --row)
		{
			if(board[row][col] == 0)
			{
				board[row][col] = player;
				--available;
				return row;
			}
		}
		return -1;
	}
	return -2;
}

int Board :: checkEnd(int i, int j)
{
	int row, col, count;
	if(available == 0)	return 2;
	// Vertical
	count = 0;
	for(row = 0; row < 6; ++row)
	{
		if(board[row][j] == player)
		{
			if(++count > 3) return 1;
		}
		else
		{
			count = 0;
		}
	}
	// Horizontal
	count = 0;
	for(col = 0; col < 7; ++col)
	{
		if(board[i][col] == player)
		{
			if(++count > 3) return 1;
		}
		else
		{
			count = 0;
		}
	}
	// L2R Diagonal
	count = 0;
	for(row = (i > j ? i-j : 0), col = (j > i ? j-i : 0); row < 6 and col < 7; ++row, ++col)
	{
		if(board[row][col] == player)
		{
			if(++count > 3) return 1;
		}
		else
		{
			count = 0;
		}
	}
	// R2L Diagonal
	count = 0;
	for(row = (i+j < 6 ? 0 : i+j-6), col = (i+j < 6 ? i+j : 6); row < 6 and col >= 0; ++row, --col)
	{
		if(board[row][col] == player)
		{
			if(++count > 3) return 1;
		}
		else
		{
			count = 0;
		}
	}
	// If move was valid, change player (-1 & -2 represent invalid moves according to dropDisk & makeMove)
	if(i >= 0)
	{
		player = ~player;
	}
	return 0;
}