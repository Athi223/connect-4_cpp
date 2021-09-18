#include <iostream>
#include <board.hpp>

int main()
{	
	Board *board = new Board();
	int player, col, row = 0;
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
		std :: cout << "Player " << abs(player) << ":" << std :: endl;
		std :: cout << "Please Enter a Column to Drop the Disk: ";
		std :: cin >> col;
		row = board->makeMove(col);
	}
	while(!board->checkEnd(row, col));
	if(board->checkEnd(row, col) == 1)
	{
		board->display();
		std :: cout << "Player " << abs(player) << " Won!";
	}
	delete board;
	return 0;
}