/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:31:40 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 15:09:18 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_cursor *cursor)
{
	t_stack	*tmp;

	tmp = cursor->a;
	cursor->a = cursor->b;
	cursor->b = cursor->a->next;
	cursor->b->previous = cursor->a->previous;
	cursor->b->previous->next = cursor->b;
	if (cursor->count_a == 0)
	{
		cursor->a->previous = cursor->a;
		cursor->a->next = cursor->a;
	}
	else
	{
		cursor->a->previous = tmp->previous;
		cursor->a->next = tmp;
		cursor->a->next->previous = cursor->a;
		cursor->a->previous->next = cursor->a;
	}
	cursor->count_b--;
	cursor->count_a++;
	if (cursor->count_b == 0)
		cursor->b = NULL;
	write(1, "pa\n", 3);
	return ;
}

void	ft_push_b(t_cursor *cursor)
{
	t_stack	*tmp;

	tmp = cursor->b;
	cursor->b = cursor->a;
	cursor->a = cursor->b->next;
	cursor->a->previous = cursor->b->previous;
	cursor->a->previous->next = cursor->a;
	if (cursor->count_b == 0)
	{
		cursor->b->previous = cursor->b;
		cursor->b->next = cursor->b;
	}
	else
	{
		cursor->b->previous = tmp->previous;
		cursor->b->next = tmp;
		cursor->b->next->previous = cursor->b;
		cursor->b->previous->next = cursor->b;
	}
	cursor->count_a--;
	cursor->count_b++;
	if (cursor->count_a == 0)
		cursor->a = NULL;
	write(1, "pb\n", 3);
	return ;
}
