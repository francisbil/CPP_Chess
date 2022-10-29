#pragma once

/**
* Déclaration classe BlackPawn
* \file   BlackPawn.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"

class BlackPawn : public BlackPiece
{
public:
	BlackPawn(std::pair<int, int> position);
	BlackPawn(const BlackPawn& other);
	~BlackPawn() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
