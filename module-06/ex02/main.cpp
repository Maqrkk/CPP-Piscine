#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base::~Base()
{
}

Base		*generate(void)
{
	// Randomly create an instance of either A, B or C and return as a
	// pointer to a Base class.

	Base	*base;
	int		type;

	type = rand() % 3;
	if (type == 0)
	{
		base = dynamic_cast<Base*>(new A());
		std::cout << "Generated an instance of class A." << std::endl;
	}
	else if (type == 1)
	{
		base = dynamic_cast<Base*>(new B());
		std::cout << "Generated an instance of class B." << std::endl;
	}
	else
	{
		base = dynamic_cast<Base*>(new C());
		std::cout << "Generated an instance of class C." << std::endl;
	}
	return base;
}

void		identify_from_pointer(Base *p)
{
	// This function identifies which subclass the pointer belongs to.
	// It casts to all 3 types, and whichever is not NULL, is the subclass.

	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	std::cout << "From pointer: ";
	if (a != NULL)
		std::cout << "A" << std::endl;
	else if (b != NULL)
		std::cout << "B" << std::endl;
	else if (c != NULL)
		std::cout << "C" << std::endl;
}

void		identify_from_reference(Base &p)
{
	// This function identifies which subclass the reference belongs to.
	// It uses try and catch blocks to determine the type.

	std::cout << "From reference: ";
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int			main()
{
	srand(time(NULL));

	Base	*base;

	for (int i = 0; i < 5; i++)
	{
		base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
	}
}
