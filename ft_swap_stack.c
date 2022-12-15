/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:28:26 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 15:08:55 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_cursor *cursor)
{
	t_stack	*buff;

	if (cursor->a == NULL || cursor->a->next == NULL)
		return ;
	buff = cursor->a;
	buff->id = cursor->a->id;
	cursor->a->id = cursor->a->next->id;
	cursor->a->next->id = buff->id;
	write(1, "sa\n", 3);
	return ;
}

void	ft_swap_b(t_cursor *cursor)
{
	t_stack	*buff;

	if (cursor->b == NULL || cursor->b->next == NULL)
		return ;
	buff = cursor->b;
	buff->id = cursor->b->id;
	cursor->b->id = cursor->b->next->id;
	cursor->b->next->id = buff->id;
	write(1, "sb\n", 3);
	return ;
}
