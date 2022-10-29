#pragma once

/**
* Déclaration classe BlackPawnPromotionDialog
* \file   BlackPawnPromotionDialog.hpp
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

class BlackPawnPromotionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit BlackPawnPromotionDialog(std::pair<int, int> position, QWidget* parent);
	~BlackPawnPromotionDialog() = default;
	void keyPressEvent(QKeyEvent* e);
};
