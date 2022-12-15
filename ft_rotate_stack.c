/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:30:39 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 15:10:15 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_cursor *cursor)
{
	cursor->a = cursor->a->next;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_cursor *cursor)
{
	cursor->b = cursor->b->next;
	write(1, "rb\n", 3);
}
