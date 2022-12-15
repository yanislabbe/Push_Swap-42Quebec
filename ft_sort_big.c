/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:58:11 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/01 15:02:46 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_shortcut(t_stack *stack, int id)
{
	t_stack	*tmp;
	int		count_next;
	int		count_previous;

	count_previous = 0;
	count_next = 0;
	tmp = stack;
	while (tmp->id != id - 1)
	{
		tmp = tmp->next;
		count_next++;
	}
	tmp = stack;
	while (tmp->previous->id != id - 1)
	{
		tmp = tmp->previous;
		count_previous++;
	}
	if (count_next <= count_previous)
		return (0);
	return (1);
}

static void	ft_push_sort_to_stack_b(t_cursor *cursor)
{
	int	id_tmp;
	int	i;

	id_tmp = cursor->count_a - 3;
	i = 0;
	while (cursor->count_a > 3)
	{
		if (cursor->a->id <= 30 + i && cursor->a->id < id_tmp)
		{
			ft_push_b(cursor);
			if (cursor->b->id < i && cursor->count_a > 2)
				ft_rotate_b(cursor);
			i++;
		}
		else
			ft_rotate_a(cursor);
	}
}

void	ft_sort_big(t_cursor *cursor)
{
	ft_push_sort_to_stack_b(cursor);
	ft_sort_small_three(cursor);
	while (cursor->count_b != 0)
	{
		if (ft_shortcut(cursor->b, cursor->a->id) == 0)
		{
			while (cursor->b->id != cursor->a->id - 1)
				ft_rotate_b(cursor);
			ft_push_a(cursor);
		}
		else
			ft_reverse_rotate_b(cursor);
	}
}
