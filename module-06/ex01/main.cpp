#include <iostream>
#include <cstdlib>
#include <ctime>

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void			printData(Data *data)
{
	// This will print the values of the Data struct.
	std::cout << "The struct contains these values:" << std::endl;
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
}

std::string		randomizeString()
{
	// Build a random string of 8 alphanumeric characters.
	std::string		result;
	const char		alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 8; i++)
		result += alphanum[rand() % 62];
	return result;
}

void		*serialize(void)
{
	// Create a Data struct, populate it with random inputs and cast it
	// to a void pointer to return it.
	Data	*data = new Data();
	data->s1 = randomizeString();
	data->n = rand();
	data->s2 = randomizeString();

	// You can uncomment the next line to print the values as they are
	// generated, before casting it to a void pointer!
	// It should match the data printed in the main function afterwards.
	
	// printData(data);

	return reinterpret_cast<void *>(data);
}

Data		*deserialize(void *raw)
{
	// Return the void pointer as a pointer to a Data struct.
	return reinterpret_cast<Data *>(raw);
}

int			main()
{
	Data	*dataPointer;
	void	*voidPointer;

	srand(time(NULL));

	voidPointer = serialize();
	dataPointer = deserialize(voidPointer);

	printData(dataPointer);
}
