//----------------------------------------------------------------------------------------------------------------------
// Project Arion2
// Created by Juan Jose Blasco Burguillos
// On November 21st, 2013
//----------------------------------------------------------------------------------------------------------------------
// Interface to deal with different boards

#ifndef _ARION2_CORE_BOARD_BOARD_H_
#define _ARION2_CORE_BOARD_BOARD_H_

namespace arion2
{
	class Board
	{
	public:
		static void		end	();
		static Board*	get	(); // Singleton accessor

	public:
		virtual ~Board() {}; // Virtual destructor to ensure proper deletion of child classes

		// Digital pins
		virtual void	digitalHigh		(unsigned _pin) = 0;
		virtual void	digitalLow		(unsigned _pin) = 0;
		virtual void	digitalToggle	(unsigned _pin) = 0;
		virtual bool	digitalRead		(unsigned _pin) = 0;
		
		// The following functions are to specialised use only. Not recommended for general purpose
        virtual void	setPinToInput   (uint8_t _pin) = 0;
        virtual void    setPinToOutput	(uint8_t _pin) = 0;

	protected:
		Board() {}

	private:
		static void		init();
		static Board*	sBoard;
	};

	//-----------------------------------------------------------------------------------------
	// Inline implementation
	//-----------------------------------------------------------------------------------------
	inline Board* Board::get()
	{
		if(nullptr == sBoard)
			init();
		return sBoard;
	}
}	// namespace arion2

#endif // _ARION2_CORE_BOARD_BOARD_H_