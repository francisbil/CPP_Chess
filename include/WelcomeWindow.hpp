#pragma once

/**
* Déclaration classe WelcomeWindow
* \file   WelcomeWindow.hpp
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

class WelcomeWindow : public QDialog
{
	Q_OBJECT

public:
	WelcomeWindow(QWidget *parent);
	~WelcomeWindow() = default;
	void keyPressEvent(QKeyEvent* e);
};
