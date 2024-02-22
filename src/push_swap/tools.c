/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:55:34 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/22 11:39:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len ++;
	}
	return (len);
}

void	print_stack(t_stack_node* a, t_stack_node* b)
{
	t_stack_node	*current1;
	t_stack_node	*current2;

	current1 = a;
	current2 = b;
	printf("Contenu de la liste a : ");
	while (current1 != NULL)
	{
		printf("%d ", current1->nb);
		current1 = current1->next;
	}
	printf("\n");

	printf("Contenu de la liste b : ");
	while (current2 != NULL)
	{
		printf("%d ", current2->nb);
		current2 = current2->next;
	}
	printf("\n");
}

t_stack_node	*point_on_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*min_o_stack(t_stack_node *stack)
{
	long		min;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*max_o_stack(t_stack_node *stack)
{
	long		max;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}