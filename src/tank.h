#include <SFML/Graphics.h>
#include "config.h"

class Tank;


class Tank
{
private:
	int hitpoints;
	int speed;
	int shootspeed;
	sf::Vector2 position;
	sf::Vector2 size;

public:
	bool damage(int dmg);
	bool move(direction dir, int val=speed);
	bool setposition(const sf::Vector2 &position);
	bool setsize(const sf::Vector2 &size);
	sf::Vector2 getsize();
	sf::Vector2 getposition();
	void setspeed(int speed);
	void setshootspeed(int shootspeed);
};
