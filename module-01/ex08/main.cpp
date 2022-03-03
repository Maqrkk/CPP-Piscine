#include "Human.hpp"

int		main(void)
{
	Human	bob;

	bob.action("meleeAttack", "Jim");
	bob.action("rangedAttack", "Karl");
	bob.action("intimidatingShout", "Peter");
	bob.action("nonExistantAttack", "Jeff");
}
