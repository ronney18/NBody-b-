/* Name: Ronney Sanchez
 * Date: November 7, 2018
 * Course: COMP2040 Computing 4
 * Assignment: PS3b
 */

#ifndef Body_INCLUDED
#define Body_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Body : public sf::Drawable
{
	public:
		Body(float size, string xPosition, string yPosition, string xVelocity, string yVelocity, string myMass, string filename);
		void resetForce();
		void addForce(Body b);
		void step(double seconds);
		double distanceTo(Body b);

        private:
		const double G = 6.67e-11;
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f windowSize;
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		sf::Vector2f force;
		double mass;
		string filename;
		void draw(sf::RenderTarget& target, sf::RenderStates state) const;
		friend istream& operator>>(istream& in, Body& body);
		friend ostream& operator<<(ostream& out, const Body& body);
};
#endif
