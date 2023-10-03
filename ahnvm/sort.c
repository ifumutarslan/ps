/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uarslan <umutiliyus@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:15:36 by acan              #+#    #+#             */
/*   Updated: 2023/10/03 22:27:40 by uarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	movecounter(t_stack **a)
// {
// 	t_stack	*tmp;
// 	long	firstmvcount;
// 	int		secondmvcount;

// 	firstmvcount = 2147483648;
// 	secondmvcount = -1;
// 	tmp = (*a);
// 	while (tmp)
// 	{
// 		if (tmp ->index <= ft_stacklast (*a)->index / 2)
// 			if (tmp->content < fifthbiggest(a,5))
// 				if (firstmvcount > tmp->index)
// 					firstmvcount = tmp->index;
// 		if (tmp ->index > ft_stacklast (*a)->index / 2)
// 			if (tmp->content < fifthbiggest(a,5))
// 				if (secondmvcount < tmp->index)
// 					secondmvcount = tmp->index;
// 		tmp = tmp->next;
// 	}
// 	if (firstmvcount == 2147483648)
// 		return (secondmvcount);
// 	if (firstmvcount > ft_stacklast(*a)->index-secondmvcount + 1)
// 		return (secondmvcount);
// 	else
// 		return (firstmvcount);
// }


void	pushback(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		biggestindex;

	tmp = (*b);
	while (ft_stacklast(*b)->index > 0)
	{
		biggestindex = getbiggest(b);
		if (biggestindex >= ft_stacklast(*b)->index/2)
		{
			biggestindex = ft_stacklast(*b)->index - biggestindex + 1;
			while (biggestindex--)
				rrb(b, 0);
			pa(a, b);
		}
		else
		{
			while (biggestindex--)
				rb(b, 0);
			pa (a, b);
		}
	}
	pa(a, b);
}

static int	sortalg(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		first;
	int		last;
	int		index;

	last = 0;
	index = 0;
	if (*a)
		index = ft_stacklast(*a)->index + 1;
	first = index;
	tmp = *a;
	while (tmp)
	{
		if (tmp->content > (*b)->content && first > tmp->index)
			first = tmp->index;
		if (tmp->content > (*b)->content && last < tmp->index)
			last = tmp->index;
		tmp = tmp->next;
	}
	if ((last - index < 0 ? last *= -1: last)  < first)
		return (last);
	else
		return (first);
}

void	basicsort(t_stack **a, t_stack **b)
{
	int	value;

	pb(a, b);
	while (*a)
	{
		value = sortalg(a, b);
		if (value < 0)
			value *= -1;
		if (value > ft_stacklast(*a)->index / 2)
		{
			value = value - (ft_stacklast(*a)->index + 1);
			if (value < 0)
				value *= -1;
			while (value != 0)
			{
				rra (a, 0);
				value--;
			}
		}
		else
		{
			while (value != 0)
			{
				if (value < 0)
					value *= -1;
				ra (a, 0);
				value--;
			}
		}
		pb(a, b);
	}
}
