#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T *array, int num, void (*f)(T))
{
	for (int i = 0; i < num; i++)
		f(array[i]);
}

#endif
