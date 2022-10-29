#pragma once

/**
* Déclaration classe BlackQueen
* \file   BlackQueen.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"

class BlackQueen : public BlackPiece
{
public:
	BlackQueen(std::pair<int, int> position);
	BlackQueen(const BlackQueen& other);
	~BlackQueen() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};