/**
* Implémentation classe BlackKing
* \file   BlackKing.cpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include "BlackKing.hpp"
#include "BlackRook.hpp"

int BlackKing::blackKingCount = 0;

BlackKing::BlackKing(std::pair<int, int> position) : BlackPiece()
{
	if (blackKingCount == 2)
		throw TooManyKingsException("You tried to instantiate a second black king!");
	imagePath_ = "Images/BlackKing.png";
	position_ = position;
	blackKingCount++;
}

BlackKing::BlackKing(const BlackKing& other)
{
	position_ = other.position_;
	imagePath_ = other.imagePath_;
	for (std::list<std::pair<int, int>>::const_iterator it = other.cbegin(); it != other.cend(); it++)
	{
		availablePositions_.push_back(*it);
	}
}

BlackKing::~BlackKing()
{
	blackKingCount--;
}

std::shared_ptr<Piece> BlackKing::clone()
{
	return std::make_shared<BlackKing>(*this);
}

void BlackKing::findAvailablePositions(const Chess::Board& board, bool isOneMoveAhead)
{
	availablePositions_.clear();
	std::pair<int, int> position = position_;
	position.first -= 1;
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
	position.first += 1;
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
	position.first += 1;
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
	position.first -= 1;
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
	position.first -= 1;
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
	if (board.hasBlackPiece(std::pair<int, int>(0, 7)))
	{
		std::shared_ptr<Piece> piece = board.getPiece(std::pair<int, int>(0, 7));
		if (dynamic_cast<BlackRook*>(piece.get()) != nullptr)
		{
			if (!this->hasMoved() && !piece->hasMoved() && !board.hasWhitePiece(std::pair<int, int>(0, 5)) &&
				!board.hasBlackPiece(std::pair<int, int>(0, 5)) && !board.hasWhitePiece(std::pair<int, int>(0, 6)) &&
				!board.hasBlackPiece(std::pair<int, int>(0, 6)) && !board.isCoveredByWhite(position_) &&
				!board.isCoveredByWhite(std::pair<int, int>(0, 5)) && !board.isCoveredByWhite(std::pair<int, int>(0, 6)))
			{
				if (!isOneMoveAhead)
				{
					if (preventsCheck(board, std::pair<int, int>(0, 6)))
						availablePositions_.push_back(std::pair<int, int>(0, 6));
				}
				else
				{
					availablePositions_.push_back(std::pair<int, int>(0, 6));
				}
			}
		}
	}
	if (board.hasBlackPiece(std::pair<int, int>(0, 0)))
	{
		std::shared_ptr<Piece> piece = board.getPiece(std::pair<int, int>(0, 0));
		if (dynamic_cast<BlackRook*>(piece.get()) != nullptr)
		{
			if (!this->hasMoved() && !piece->hasMoved() && !board.hasWhitePiece(std::pair<int, int>(0, 1)) &&
				!board.hasBlackPiece(std::pair<int, int>(0, 1)) && !board.hasWhitePiece(std::pair<int, int>(0, 2)) &&
				!board.hasBlackPiece(std::pair<int, int>(0, 2)) && !board.hasWhitePiece(std::pair<int, int>(0, 3)) &&
				!board.hasBlackPiece(std::pair<int, int>(0, 3)) && !board.isCoveredByWhite(position_) &&
				!board.isCoveredByWhite(std::pair<int, int>(0, 2)) && !board.isCoveredByWhite(std::pair<int, int>(0, 3)))
			{
				if (!isOneMoveAhead)
				{
					if (preventsCheck(board, std::pair<int, int>(0, 2)))
						availablePositions_.push_back(std::pair<int, int>(0, 2));
				}
				else
				{
					availablePositions_.push_back(std::pair<int, int>(0, 2));
				}
			}
		}
	}
}