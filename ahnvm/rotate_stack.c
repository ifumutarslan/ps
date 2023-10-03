/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:07:04 by acan              #+#    #+#             */
/*   Updated: 2023/09/25 18:02:17 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	ft_stacklast((*a))->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
	indexstack((*a));
	if (flag == 0)
		ft_putstr_fd ("ra\n",1);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*tmp;

	tmp = (*b)->next;
	ft_stacklast((*b))->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	indexstack((*b));
	if (flag == 0)
		ft_putstr_fd ("rb\n",1);
}

void	rr(t_stack **a, t_stack **b)
{
	if ((*a)->next != NULL && (*b)->next != NULL)
	{
		ra(a, 1);
		rb(b, 1);
		ft_putstr_fd ("rr\n",1);
	}
}