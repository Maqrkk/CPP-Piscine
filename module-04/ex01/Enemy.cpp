#include "Enemy.hpp"
#include <string>

Enemy::Enemy(int hp, std::string const &type) : _hp(hp), _type(type)
{
	return ;
}

Enemy::Enemy(Enemy const &src)
{
	*this = src;
	return ;
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy				&Enemy::operator=(Enemy const &src)
{
	this->_hp = src._hp;
	this->_type = src._type;
	return (*this);
}

std::string const	&Enemy::getType(void) const
{
	return (this->_type);
}

int					Enemy::getHP(void) const
{
	return (this->_hp);
}

void				Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return ;
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
}

Enemy::Enemy(void)
{
	return ;
}
