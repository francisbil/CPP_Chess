#pragma once

/**
* Déclaration classe WhiteBishop
* \file   WhiteBishop.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"

class WhiteBishop : public WhitePiece
{
public:
	WhiteBishop(std::pair<int, int> position);
	WhiteBishop(const WhiteBishop& other);
	~WhiteBishop() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
