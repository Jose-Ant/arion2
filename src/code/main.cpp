#include <core/board/board.h>

using namespace arion2;

int main ()
{
	Board * board = Board::get();	
	board->digitalHigh(13);
	
	while(1) // Keep looping forever
	{
		
	}

	return 0;
}	// namespace arion2