#pragma once

/**
* Déclaration classe ChessWindow
* \file   ChessWindow.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <QMainWindow>
#include <QMessageBox>
#include "Board.hpp"

namespace Ui
{
	class ChessWindow;
}

class Ui::ChessWindow : public QMainWindow
{
	Q_OBJECT

public:
	ChessWindow(QWidget* parent = Q_NULLPTR);
	~ChessWindow();
public slots:
	void buttonPressed();
	void handlePawnPromotion();
	void drawPiece(const std::shared_ptr<Piece> piece);
	void undrawPiece(std::pair<int, int> position);
	void gameOverWindow(char winner);
	void whitePawnPromotionWindow(std::pair<int, int> position);
	void blackPawnPromotionWindow(std::pair<int, int> position);
	void colorButton(std::pair<int, int> position);
	void uncolorButtons();
	void startGame();
private:

	void drawAllPieces();

	Chess::Board* board_ = nullptr;
	QPushButton* buttons_[8][8];
};