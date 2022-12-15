/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:57:03 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 16:42:47 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index_number(t_cursor *cursor, int *array)
{
	t_stack	*tmp;
	int		index;
	int		count;

	tmp = cursor->a;
	index = 0;
	count = 0;
	while (count != cursor->count_a)
	{
		while (tmp->number != array[index] && index <= cursor->count_a)
			index++;
		if (tmp->number == array[index])
		{
			tmp->id = index;
			tmp = tmp->next;
		}
		count++;
		index = 0;
	}
}

static int	*ft_sort_to_array(int *array, int *start, int *end, int average)
{
	int	first;
	int	last;
	int	tmp;

	first = *start;
	last = *end;
	while (first < last)
	{
		while (array[first] < average && first < last)
			first++;
		while (array[last] > average && first < last)
			last--;
		if (array[first] == array[last] && first != last)
			ft_error_bye(array);
		if (array[first] > array[last])
		{
			tmp = array[first];
			array[first] = array[last];
			array[last] = tmp;
		}
	}
	*start = first;
	*end = last;
	return (array);
}

static int	*ft_sort_very_quick(int *array, int start, int end)
{
	int	average;
	int	first;
	int	last;

	first = start;
	last = end;
	average = array[(first + last) / 2];
	*array = *ft_sort_to_array(array, &first, &last, average);
	first--;
	if (first >= start)
		ft_sort_very_quick(array, start, first);
	last++;
	if (last <= end)
		ft_sort_very_quick(array, last, end);
	return (array);
}

void	ft_sort_quick(t_cursor *cursor)
{
	t_stack	*tmp;
	int		*array;
	int		count;

	tmp = cursor->a;
	count = 0;
	array = malloc(sizeof(t_stack));
	if (!array || cursor->i == 3)
	{
		ft_clean(cursor->a);
		free(array);
		ft_error();
	}
	while (count != cursor->count_a)
	{
		array[count] = tmp->number;
		tmp = tmp->next;
		count++;
	}
	*array = *ft_sort_very_quick(array, 0, (count - 1));
	ft_index_number(cursor, array);
	free(array);
}
