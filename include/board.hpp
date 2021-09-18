#pragma once

class Board
{
	public:
		Board();
		void display();
		int getPlayer() const;
		int makeMove(int);
		int dropDisk(int);
		int checkEnd(int, int);				// 0 - Not Ended, 1 - Current Player won, 2 - Draw

	private:
		int board[6][7];
		int player;							// 1 or -2
};