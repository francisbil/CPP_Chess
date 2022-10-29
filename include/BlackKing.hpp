#pragma once

/**
* Déclaration classe BlackKing
* \file   BlackKing.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"
#include "TooManyKingsException.hpp"

class BlackKing : public BlackPiece
{
public:
	BlackKing(std::pair<int, int> position);
	BlackKing(const BlackKing& other);
	~BlackKing();
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();

private:
	static int blackKingCount;
};

