/**
* Implémentation classe WhiteRook
* \file   WhiteRook.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "WhiteRook.hpp"

WhiteRook::WhiteRook(std::pair<int, int> position) : WhitePiece()
{
	imagePath_ = "Images/WhiteRook.png";
	position_ = position;
}

WhiteRook::WhiteRook(const WhiteRook& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

std::shared_ptr<Piece> WhiteRook::clone()
{
	return std::make_shared<WhiteRook>(*this);
}

void WhiteRook::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();

	std::pair<int, int> position = position_;
	position.first -= 1;
	while (board.isValidPosition(position) && !board.hasWhitePiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasBlackPiece(position))
		{
			break;
		}
		position.first -= 1;
	}

	position = position_;
	position.first += 1;
	while (board.isValidPosition(position) && !board.hasWhitePiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasBlackPiece(position))
		{
			break;
		}
		position.first += 1;
	}

	position = position_;
	position.second -= 1;
	while (board.isValidPosition(position) && !board.hasWhitePiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasBlackPiece(position))
		{
			break;
		}
		position.second -= 1;
	}

	position = position_;
	position.second += 1;
	while (board.isValidPosition(position) && !board.hasWhitePiece(position))
	{
		if (!isOneMoveAhead)
		{
			if (preventsCheck(board, position))
				availablePositions_.push_back(position);
		}
		else
		{
			availablePositions_.push_back(position);
		}
		if (board.hasBlackPiece(position))
		{
			break;
		}
		position.second += 1;
	}
}