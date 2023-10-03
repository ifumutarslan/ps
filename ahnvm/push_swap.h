/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uarslan <umutiliyus@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:59:03 by acan              #+#    #+#             */
/*   Updated: 2023/10/03 21:20:15 by uarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# include <stdio.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}						t_stack;

void	print_error(char *error);
void	isvalid1(int ac, char **av);
int		countword_onearg(const char *s, char c);
int		arglen(char **args);
char	**argjoin(char **seperated, char *raw);
char	**seperate_all(char **av);
int		myatoi(char *str);
t_stack	*stacknew(int index, int content);
t_stack	*ft_stacklast(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	addtostack(char **last, t_stack **a);
void	indexstack(t_stack *stack);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	sortcheck(t_stack **a, t_stack **b,int len);
int		islistsorted(t_stack **stack);
int		getaverage (t_stack **a);
void	basicsort(t_stack **a, t_stack **b);
void	print_list(t_stack **mystack);
int		fifthbiggest(t_stack **a, int five);
int		getbiggest(t_stack **b);
void	sorttry(t_stack **b);
void	pushback(t_stack **a, t_stack **b);

#endif