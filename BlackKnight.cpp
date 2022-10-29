/**
* Implémentation classe BlackKnight
* \file   BlackKnight.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "BlackKnight.hpp"

BlackKnight::BlackKnight(std::pair<int, int> position) : BlackPiece()
{
	imagePath_ = "Images/BlackKnight.png";
	position_ = position;
}

BlackKnight::BlackKnight(const BlackKnight& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

std::shared_ptr<Piece> BlackKnight::clone()
{
	return std::make_shared<BlackKnight>(*this);
}

void BlackKnight::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();

	std::pair<int, int> position = position_;
	position.first -= 2;
	position.second += 1;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.second -= 1;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.first += 2;
	position.second -= 1;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.first += 2;
	position.second += 1;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.second += 2;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.first += 1;
	position.second += 2;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.second -= 2;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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
	position.first += 1;
	position.second -= 2;
	if (board.isValidPosition(position) && !board.hasBlackPiece(position))
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