#pragma once

/**
* Déclaration exception personnalisée TooManyKingsException
* \file   TooManyKingsException.hpp
* \author Francis Bilodeau-Lecomte
* \date   6 mai 2022
* Créé le 24 avril 2022
*/

#include <stdexcept>

class TooManyKingsException : public std::exception
{
public:
	using std::exception::exception;
};