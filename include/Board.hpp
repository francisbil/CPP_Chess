#pragma once

/**
* Déclaration classe Board
* \file   Board.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <QObject>
#include <unordered_map>
#include <memory>
#include <utility>
#include "PairHash.hpp"
#include <gtest/gtest_prod.h>

class Piece;
class WhiteKing;
class WhiteQueen;
class WhiteBishop;
class WhiteKnight;
class WhiteRook;
class WhitePawn;
class BlackKing;
class BlackQueen;
class BlackBishop;
class BlackKnight;
class BlackRook;
class BlackPawn;

namespace Chess
{
	class Board;
};

class Chess::Board : public QObject
{
	Q_OBJECT
	FRIEND_TEST(Board, movement);
	FRIEND_TEST(Board, castling);
	FRIEND_TEST(Board, promotion);
	FRIEND_TEST(Board, enPassant);
public:
	Board(int mode = 1);
	Board(const Chess::Board& board);
	~Board();
	void createWhiteKing(std::pair<int, int> position);
	void createWhiteQueen(std::pair<int, int> position);
	void createWhiteBishop(std::pair<int, int> position);
	void createWhiteKnight(std::pair<int, int> position);
	void createWhiteRook(std::pair<int, int> position);
	void createWhitePawn(std::pair<int, int> position);
	void createBlackKing(std::pair<int, int> position);
	void createBlackQueen(std::pair<int, int> position);
	void createBlackBishop(std::pair<int, int> position);
	void createBlackKnight(std::pair<int, int> position);
	void createBlackRook(std::pair<int, int> position);
	void createBlackPawn(std::pair<int, int> position);
	void createPieces1();
	void createPieces2();
	void createPieces3();
	void createPieces4();
	void deletePiece(std::pair<int, int> position);
	bool isValidPosition(std::pair<int, int> position) const;
	bool hasWhitePiece(std::pair<int, int> position) const;
	bool hasBlackPiece(std::pair<int, int> position) const;
	bool isCoveredByWhite(std::pair<int, int> position) const;
	bool isCoveredByBlack(std::pair<int, int> position) const;
	bool isWhiteKingInCheck() const;
	bool isBlackKingInCheck() const;
	bool isWhiteKingCheckmate() const;
	bool isBlackKingCheckmate() const;
	bool isStalemate() const;
	void updateAvailablePositionsWhite(bool isOneMoveAhead = false);
	void updateAvailablePositionsBlack(bool isOneMoveAhead = false);
	void movePiece(std::pair<int, int> oldPosition, std::pair<int, int> newPosition);
	void simulateMove(std::pair<int, int> oldPosition, std::pair<int, int> newPosition);
	void replacePiece(std::pair<int, int> position, char color, char piece);
	std::shared_ptr<Piece> getSelectedPiece() const;
	std::pair<int, int> getEnPassant() const;
	std::pair<int, int> getWhiteKingsPosition() const;
	std::pair<int, int> getBlackKingsPosition() const;
	std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>>::const_iterator cbegin();
	std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>>::const_iterator cend();
	std::shared_ptr<Piece> getPiece(std::pair<int, int> position) const;
public slots:
	void updateState(std::pair<int, int> position);
signals:
	void pieceToDelete(std::pair<int, int> position);
	void pieceToDraw(std::shared_ptr<Piece> piece);
	void gameOver(char winner);
	void promoteWhitePawn(std::pair<int, int> position);
	void promoteBlackPawn(std::pair<int, int> position);
	void colorAvailablePosition(std::pair<int, int> position);
	void resetButtons();
private:
	std::unordered_map<std::pair<int, int>, std::shared_ptr<Piece>, PairHash> pieces_;
	enum class State { WHITES_TURN, WHITE_MOVE, BLACKS_TURN, BLACK_MOVE, GAME_OVER };
	State currentState_;
	std::shared_ptr<Piece> selectedPiece_;
	std::pair<int, int> enPassant_;
};
