#pragma once

/**
* Déclaration classe BlackBishop
* \file   BlackBishop.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"

class BlackBishop : public BlackPiece
{
public:
	BlackBishop(std::pair<int, int> position);
	BlackBishop(const BlackBishop& other);
	~BlackBishop() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
#pragma once
