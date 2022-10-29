#pragma once

/**
* Déclaration classe BlackRook
* \file   BlackRook.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"

class BlackRook : public BlackPiece
{
public:
	BlackRook(std::pair<int, int> position);
	BlackRook(const BlackRook& other);
	~BlackRook() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
