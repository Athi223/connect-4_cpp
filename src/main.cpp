#include <iostream>
#include <board.hpp>

inline std :: string printPlayer(int player)
{
	return std :: string("Player ") + (player == 1 ? "X" : "O");
}

int main()
{	
	int player, col, row = 0;
	char choice = 'y';
	do
	{
		Board *board = new Board();
		do
		{
			board->display();
			player = board->getPlayer();
			if(row == -1)
			{
				std :: cout << "Column Already Filled !" << std :: endl;
			}
			else if(row == -2)
			{
				std :: cout << "Enter Valid Column(0-6) !" << std :: endl;
			}
			std :: cout << printPlayer(player) << ":\n" << "Please Enter a Column (0-6) to Drop the Disk: ";
			std :: cin >> col;
			row = board->makeMove(col);
		}
		while(board->checkEnd(row, col) == 0);

		if(board->checkEnd(row, col) == 1)
		{
			board->display();
			std :: cout << printPlayer(player) << " Won!\n";
		}
		else
		{
			board->display();
			std :: cout << "Its a Draw!\n";
		}
		delete board;
		std :: cout << "DO YOU WANT TO PLAY AGAIN (Y/N) : ";
		std :: cin >> choice;
	} while (choice == 'y' or choice == 'Y');
	return 0;
}