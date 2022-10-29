#pragma once

/**
* Déclaration classe abstraite BlackPiece
* \file   BlackPiece.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "Piece.hpp"

class BlackPiece : public Piece
{
public:
	BlackPiece() = default;
	virtual ~BlackPiece() = default;
	virtual std::shared_ptr<Piece> clone() = 0;
	virtual void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false) = 0;
	bool preventsCheck(const Chess::Board& board, std::pair<int, int> move);
};
