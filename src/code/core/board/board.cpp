//----------------------------------------------------------------------------------------------------------------------
// Project Arion2
// Created by Juan Jose Blasco Burguillos
// On Novembe 21st, 2013
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with different boards

#include "board.h"

#include "arduinoMega2560/arduinoMega2560Board.h"

namespace arion2
{
	// Static data definition
	Board* Board::sBoard = nullptr;

//----------------------------------------------------------------------------------------------------------------------
	void Board::init()
	{
#ifdef ATMEGA2560
		sBoard = new ArduinoMega2560Board();
#endif // ATMEGA2560
	}

//----------------------------------------------------------------------------------------------------------------------
	void Board::end()
	{
		delete sBoard;
		sBoard = 0;
	}

}	// namespace arion2