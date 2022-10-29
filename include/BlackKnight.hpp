#pragma once

/**
* Déclaration classe BlackKnight
* \file   BlackKnight.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "BlackPiece.hpp"

class BlackKnight : public BlackPiece
{
public:
	BlackKnight(std::pair<int, int> position);
	BlackKnight(const BlackKnight& other);
	~BlackKnight() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
