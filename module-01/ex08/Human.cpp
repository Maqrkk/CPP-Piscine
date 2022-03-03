#include "Human.hpp"
#include <iostream>

void		Human::action(std::string const &action_name, std::string const &target)
{
	typedef void(Human::*HumanFunction)(std::string const &target);
	HumanFunction	functions[] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string		functionNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

	for (int i = 0; i < 3; i++)
	{
		if (functionNames[i] == action_name)
		{
			(this->*functions[i])(target);
			return ;
		}
	}
	std::cout << "Unknown attack: " << action_name << std::endl;
}

void		Human::meleeAttack(std::string const &target)
{
	std::cout << "Using melee attack on " << target << std::endl;
}

void		Human::rangedAttack(std::string const &target)
{
	std::cout << "Using ranged attack on " << target << std::endl;
}

void		Human::intimidatingShout(std::string const &target)
{
	std::cout << "Using intimidating shout on " << target << std::endl;
}
