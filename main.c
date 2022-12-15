/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:21:59 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 16:58:26 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_a(t_cursor *cursor, int number)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		ft_error();
	tmp->number = number;
	if (cursor->a == 0)
	{
		tmp->previous = tmp;
		tmp->next = tmp;
	}
	if (cursor->a != 0)
	{
		tmp->previous = cursor->a->previous;
		cursor->a->previous->next = tmp;
		tmp->next = cursor->a;
		cursor->a->previous = tmp;
	}
	cursor->a = tmp;
	if (cursor->a->number > cursor->a->next->number)
		cursor->need_sort = 1;
	cursor->i = 2;
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_error_bye(int *array)
{
	free(array);
	ft_error();
}

void	ft_clean(t_stack *cursor)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (i < cursor->previous->id)
	{
		if (cursor->id >= 0 && cursor->id < cursor->previous->id)
		{
			tmp = cursor->next;
			tmp->next->previous = cursor;
			cursor->next = tmp->next;
			free(tmp);
			tmp = NULL;
		}
		i++;
	}
	free(cursor);
	cursor = NULL;
}

int	main(int argc, char **argv)
{
	t_cursor	cursor;
	t_stack		stack;

	if (argc < 2)
		return (0);
	stack.next = NULL;
	stack.previous = NULL;
	stack.id = 0;
	stack.number = 0;
	cursor.a = NULL;
	cursor.b = NULL;
	cursor.count_a = 0;
	cursor.count_b = 0;
	cursor.need_sort = 0;
	cursor.i = 0;
	ft_respect_the_subject(&cursor, argv, argc);
	ft_sort_quick(&cursor);
	if (cursor.count_a >= 2 && cursor.count_a <= 5 && cursor.need_sort == 1)
		ft_sort_small(&cursor);
	if (cursor.count_a >= 6 && cursor.need_sort == 1)
		ft_sort_big(&cursor);
	if (cursor.i == 2)
		ft_clean(cursor.a);
	return (0);
}
