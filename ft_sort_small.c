/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:56:44 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 15:11:04 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_three(t_cursor *c)
{
	if (c->a->number > c->a->previous->number
		&& c->a->number > c->a->next->number)
		ft_rotate_a(c);
	if (c->a->next->number > c->a->number
		&& c->a->next->number > c->a->previous->number)
		ft_reverse_rotate_a(c);
	if (c->a->number > c->a->next->number)
		ft_swap_a(c);
}

void	ft_sort_small_five(t_cursor *cursor)
{
	int	count;

	count = 5;
	while (count != 0)
	{
		if (cursor->a->id == 0 || cursor->a->id == 1)
			ft_push_b(cursor);
		else
			ft_rotate_a(cursor);
		count--;
	}
	ft_sort_small_three(cursor);
	if (cursor->b->number < cursor->b->next->number)
		ft_swap_b(cursor);
	ft_push_a(cursor);
	ft_push_a(cursor);
}

void	ft_sort_small_four(t_cursor *cursor)
{
	ft_push_b(cursor);
	ft_sort_small_three(cursor);
	if (cursor->b->id == 2)
	{
		ft_reverse_rotate_a(cursor);
		ft_push_a(cursor);
		ft_rotate_a(cursor);
		ft_rotate_a(cursor);
	}
	else
		ft_push_a(cursor);
	if (cursor->a->id == 1)
		ft_swap_a(cursor);
	if (cursor->a->id == 3)
		ft_rotate_a(cursor);
}

void	ft_sort_small(t_cursor *cursor)
{
	if (cursor->count_a == 2)
		if (cursor->a->number > cursor->a->next->number)
			ft_reverse_rotate_a(cursor);
	if (cursor->count_a == 3)
		ft_sort_small_three(cursor);
	if (cursor->count_a == 4)
		ft_sort_small_four(cursor);
	if (cursor->count_a == 5)
		ft_sort_small_five(cursor);
}
