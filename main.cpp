/* Name: Ronney Sanchez
 * Date: November 7, 2018
 * Course: COMP2040 Computing 4
 * Assignment: PS3b
 */

#include <sstream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Body.hpp"

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "ERROR: execute file with [Time], [Delta(Change in)-Time], < [filename] argument!" << endl;
	       return -1;	
	}

	string  xPos, yPos, xVelocity, yVelocity, mass, filename;

	unsigned int numParticles;
	float size;
	float windowSize;
	double elapseTime = atof(argv[1]);
	double deltaT = atof(argv[2]);
	double time = 0.0;
	cout << "Elapse Time: "<< elapseTime << endl; 
	cout << "Change In Time: " << deltaT << endl;
	
	cin >> numParticles >> size;
	windowSize = (size/5e+8);
	vector<shared_ptr<Body>> vecBody;
	for(unsigned int i = 0; i < numParticles; i++)
	{
		cin >> xPos >> yPos >> xVelocity >> yVelocity >> mass >> filename;
		auto body = make_shared<Body>(windowSize, xPos, yPos, xVelocity, yVelocity, mass, filename);
		vecBody.push_back(body);

	}


	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "The Solar System!");
	
	sf::Image image;
	
	if(!image.loadFromFile("nbody/starfield.jpg"))
	{
		cerr << "ERROR: Unable to open \"starfield.jpg\"!" << endl;
		exit(1);

	}

	sf::Texture texture;
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Music audio;

	if(!audio.openFromFile("nbody/2001.wav"))
	{
		cerr << "The file \"2001.wav\" does not exist!" << endl;
		exit(1);
	}

	audio.setVolume(5000);
	audio.play();
	while(window.isOpen() && time < elapseTime)
	{
         	sf::Event event;

                while(window.pollEvent(event))
                {
                 	if(event.type == sf::Event::Closed || time >= elapseTime)
			{
                         	window.close();
			}
		}
                window.clear();
		window.draw(sprite);

		sf::Font font;
		if(!font.loadFromFile("nbody/DIGITALDREAM.ttf"))
		{
			cerr << "The file \"DIGITALDREAM.ttf\" does not exist!" << endl;
			exit(1);
		}



		sf::Text clock;
		stringstream str;

		for(unsigned int i = 0; i < vecBody.size(); i++)
		{
			(*vecBody.at(i)).resetForce();
			for(unsigned int j = 0; j < vecBody.size(); j++)
			{
				if(i != j)
				{
					(*vecBody.at(j)).resetForce();
					(*vecBody.at(i)).addForce(*vecBody.at(j));
				}
			}
			(*vecBody.at(i)).step(deltaT);
                        window.draw(*vecBody.at(i));
			double timeClock = time;
			str << fixed << setprecision(2) << timeClock << " \n";
			string change;
			getline(str, change, '\n');
			clock.setString(change);
			clock.setFont(font);
			clock.setPosition(0, 0);
		}
		window.draw(clock);
		window.display();
		time += deltaT;	
	}
	cout << "\nElapse Time: " << time << endl << endl;
	cout << "\nTHE UNIVERSE STATE" << endl;
	cout << numParticles << endl;
	cout << size << endl;
	for(auto obj : vecBody)
	{
		cout << *obj << endl;
	}
	return 0;
}
