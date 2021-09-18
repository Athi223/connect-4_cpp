#pragma once
#if _WIN32
#include <windows.h>
#endif
class Board
{
	public:
		Board();
		void display();
		int getPlayer() const;
		int makeMove(int);
		int checkEnd(int, int);				// 0 - Not Ended, 1 - Current Player won, 2 - Draw

	private:
		int board[6][7];
		int available;						// To keep a track of available spaces, used to decide Draw
		int player;							// 1 or -2
};