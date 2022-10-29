#pragma once

/**
* Déclaration classe WhitePawnPromotionDialog
* \file   WhitePawnPromotionDialog.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QPushButton>
#include <QVariant>
#include <QKeyEvent>

class WhitePawnPromotionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit WhitePawnPromotionDialog(std::pair<int, int> position, QWidget *parent);
	~WhitePawnPromotionDialog() = default;
	void keyPressEvent(QKeyEvent* e);
};
