/* Name: Ronney Sanchez
 * Date: November 7, 2018
 * Course: COMP2040 Computing 4
 * Assignment: PS3b
 */

#include "Body.hpp"

Body::Body(float size, string xPosition, string yPosition, string xVelocity, string yVelocity, string myMass, string filename)
{
	position.x = stof(xPosition.c_str());
	position.y = stof(yPosition.c_str());

	velocity.x = stof(xVelocity.c_str());
	velocity.y = stof(yVelocity.c_str());

	mass = stof(myMass);
	windowSize.x = size;
	windowSize.y = size;

	this->filename = filename;

	image.loadFromFile(filename);

	texture.loadFromImage(image);

	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height)/2.f);
	sprite.setPosition((size/2.f), (size/2.f));
	sprite.move((position.x/10e+8), (position.y/10e+8));
}

void Body::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(sprite, state);
}

void Body::resetForce()
{
	force.x = 0.0;
	force.y = 0.0;
}

void Body::addForce(Body b)
{
	double xDistance = b.position.x - this->position.x;
        double yDistance = b.position.y - this->position.y;
	double dist = sqrt(xDistance * xDistance + yDistance * yDistance);
	double F = (G * this->mass * b.mass) / (dist * dist);
	this->force.x += F * xDistance / dist;
	this->force.y += F * yDistance / dist;
}

void Body::step(double time)
{
        acceleration.x = force.x/mass;
        acceleration.y = force.y/mass;
        velocity.x += time * acceleration.x;
        velocity.y += time * acceleration.y;
        position.x += time * velocity.x;
        position.y += time * velocity.y;
	sprite.setPosition((position.x/10e+8), (position.y/10e+8) * -1);
	sprite.move((windowSize.x/2.0), (windowSize.y/2.0));
}

double Body::distanceTo(Body b)
{
        double xDistance = position.x - b.position.x;
        double yDistance = position.y - b.position.y;
        return sqrt((xDistance * xDistance) + (yDistance * yDistance));
}

istream& operator>>(istream& in, Body& body)
{
	in >> body.position.x >> body.position.y >> body.velocity.x >> body.velocity.y >> body.mass >> body.filename;
	body.image.loadFromFile(body.filename);
        body.texture.loadFromImage(body.image);
        body.sprite.setTexture(body.texture);
        body.sprite.setPosition((body.position.x), (body.position.y));
	return in;
}

ostream& operator<<(ostream &out, const Body &body)
{
        out << body.position.x << " " << body.position.y << " " << body.velocity.x << " " << body.velocity.y << " " <<  body.mass << " " << body.filename;
        return out;
}
