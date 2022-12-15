/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:22:45 by ylabbe            #+#    #+#             */
/*   Updated: 2022/10/05 17:00:56 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*previous;
	int				id;
	int				number;
}	t_stack;

typedef struct s_cursor
{
	t_stack	*a;
	t_stack	*b;
	int		need_sort;
	int		count_a;
	int		count_b;
	int		i;
}	t_cursor;

/*	main.c	*/
void	ft_stack_a(t_cursor *cursor, int number);
void	ft_error(void);
void	ft_clean(t_stack *cursor);
void	ft_error_bye(int *array);

/*	ft_respect_the_subjet.c	*/
void	ft_respect_the_subject(t_cursor *cursor, char **argv, int nb_argc);

/*	ft_sort_quick.c	*/
void	ft_sort_quick(t_cursor *cursor);

/*	ft_sort_small.c	*/
void	ft_sort_small(t_cursor *cursor);
void	ft_sort_small_three(t_cursor *c);
void	ft_sort_small_four(t_cursor *cursor);
void	ft_sort_small_five(t_cursor *cursor);

/*	ft_sort_big.c	*/
void	ft_sort_big(t_cursor *cursor);

/*	ft_push_stack.c	*/
void	ft_push_a(t_cursor *cursor);
void	ft_push_b(t_cursor *cursor);

/*	ft_swap_stack.c	*/
void	ft_swap_a(t_cursor *cursor);
void	ft_swap_b(t_cursor *cursor);

/*	ft_rotate_stack.c	*/
void	ft_rotate_a(t_cursor *cursor);
void	ft_rotate_b(t_cursor *cursor);

/*	ft_reverse_rotate_stack.c	*/
void	ft_reverse_rotate_a(t_cursor *cursor);
void	ft_reverse_rotate_b(t_cursor *cursor);

#endif
