#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ElementoDeJuego : public sf::Drawable
{
	public:
		void Update(float);
};