#pragma once

/**
* Déclaration classe WhitePawn
* \file   WhitePawn.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <utility>
#include "WhitePiece.hpp"

class WhitePawn : public WhitePiece
{
public:
	WhitePawn(std::pair<int, int> position);
	WhitePawn(const WhitePawn& other);
	~WhitePawn() = default;
	void findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead = false);
	virtual std::shared_ptr<Piece> clone();
};
