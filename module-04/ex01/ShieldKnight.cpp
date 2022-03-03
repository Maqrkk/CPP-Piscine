#include "ShieldKnight.hpp"
#include <iostream>

ShieldKnight::ShieldKnight(void) : Enemy(100, "ShieldKnight")
{
	std::cout << "Face me in battle!" << std::endl;
	return ;
}

ShieldKnight::ShieldKnight(ShieldKnight const &src) : Enemy(src._hp, src._type)
{
	std::cout << "Face me in battle!" << std::endl;
	return ;
}

ShieldKnight::~ShieldKnight(void)
{
	std::cout << "You've defeated me, nooo!" << std::endl;
	return ;
}

ShieldKnight	&ShieldKnight::operator=(ShieldKnight const &src)
{
	Enemy::operator=(src);
	return (*this);
}

void			ShieldKnight::takeDamage(int amount)
{
	Enemy::takeDamage(amount / 2);
}
