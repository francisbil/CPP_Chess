/**
* Implémentation classe WhitePawn
* \file   WhitePawn.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "WhitePawn.hpp"

WhitePawn::WhitePawn(std::pair<int, int> position) : WhitePiece()
{
	imagePath_ = "Images/WhitePawn.png";
	position_ = position;
}

WhitePawn::WhitePawn(const WhitePawn& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

std::shared_ptr<Piece> WhitePawn::clone()
{
	return std::make_shared<WhitePawn>(*this);
}

void WhitePawn::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();

	std::pair<int, int> position = position_;
	position.first -= 1;
	if (board.isValidPosition(position) && !board.hasWhitePiece(position) && !board.hasBlackPiece(position))
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
	}

	position.second -= 1;
	if (board.isValidPosition(position) && board.hasBlackPiece(position))
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
	}

	position.second += 2;
	if (board.isValidPosition(position) && board.hasBlackPiece(position))
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
	}

	position = position_;
	position.first -= 2;
	std::pair<int, int> position2 = position_;
	position2.first -= 1;
	if (board.isValidPosition(position) && position_.first == 6 && !board.hasWhitePiece(position) && !board.hasBlackPiece(position)
		&& !board.hasWhitePiece(position2) && !board.hasBlackPiece(position2))
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
	}

	position = position_;
	position.first -= 1;
	position.second += 1;
	if (board.isValidPosition(position) && position == board.getEnPassant())
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
	}

	position.second -= 2;
	if (board.isValidPosition(position) && position == board.getEnPassant())
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
	}
}