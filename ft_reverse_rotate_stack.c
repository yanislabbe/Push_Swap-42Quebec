/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:31:11 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 15:10:26 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_cursor *cursor)
{
	cursor->a = cursor->a->previous;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_cursor *cursor)
{
	cursor->b = cursor->b->previous;
	write(1, "rrb\n", 4);
}
