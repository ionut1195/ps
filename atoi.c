#include "swap.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	itr;

	sign = 1;
	itr = 0;
	result = 0;
	while ((nptr[itr] >= 7 && nptr[itr] <= 13) || nptr[itr] == ' ')
		itr++;
	if (nptr[itr] == '-')
		sign = -1;
	if (nptr[itr] == '-' || nptr[itr] == '+')
		itr++;
	while (nptr[itr] >= '0' && nptr[itr] <= '9' && nptr[itr])
	{
		result = result * 10 + (nptr[itr] - '0');
		nptr++;
	}
	return (sign * result);
}