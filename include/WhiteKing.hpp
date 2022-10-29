#pragma once

/**
* Déclaration classe WhiteKing
* \file   WhiteKing.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"
#include "TooManyKingsException.hpp"

class WhiteKing : public WhitePiece
{
public:
	WhiteKing(std::pair<int, int> position);
	WhiteKing(const WhiteKing& other);
	~WhiteKing();
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();

private:
	static int whiteKingCount;
};

