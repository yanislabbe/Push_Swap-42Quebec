/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_respect_the_subject.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:57:26 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/01 14:57:27 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_int_min_max(long int number, int neg)
{
	if (number * neg < -2147483648)
		ft_error();
	if (number * neg > 2147483647)
		ft_error();
}

static int	ft_extra_atoi(const char *argv, int str)
{
	long int	number;
	int			neg;
	int			count;

	count = str;
	number = 0;
	neg = 1;
	while (argv[count] == ' ')
		count++;
	if ((argv[count] == '-' || argv[count] == '+')
		&& argv[count + 1] != '\0')
	{
		if (argv[count] == '-')
			neg *= -1;
		count++;
	}
	while (argv[count] != ' ' && argv[count] != '\0')
	{
		if ((argv[count] < 48 || argv[count] > 57))
			ft_error();
		number = number * 10 + (argv[count] - '0');
		count++;
	}
	ft_int_min_max(number, neg);
	return (number * neg);
}

static void	ft_find_and_replace(char *argv, int *str)
{
	int	count;

	count = *str;
	if (argv[count] == '\0' && count > 0)
		count--;
	while (argv[count] == ' ' && count > 0)
		count--;
	while (argv[count] != ' ' && count > 0)
		count--;
	*str = count;
}

static int	ft_extra_strlen(char *argv)
{
	int	count;

	count = 0;
	while (argv[count] != '\0')
	{
		if (argv[count] != ' ')
			while (argv[count] != ' ' && argv[count] != '\0')
				count++;
		if (argv[count] != '\0')
			count++;
	}
	return (count);
}

void	ft_respect_the_subject(t_cursor *cursor, char **argv, int nb_argc)
{
	int	count;

	while ((--nb_argc) > 0)
	{
		count = ft_extra_strlen(argv[nb_argc]);
		while (count > 0)
		{
			ft_find_and_replace(argv[nb_argc], &count);
			ft_stack_a(cursor, ft_extra_atoi(argv[nb_argc], count));
			cursor->count_a += 1;
		}
	}
}
