/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:39:08 by aben-ham          #+#    #+#             */
/*   Updated: 2022/03/29 13:09:25 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	q_clear(t_queue *queue, void (*del_ptr)(void *p))
{
	t_node	*node;
	t_node	*target;

	if (!queue)
		return ;
	node = queue->first;
	while (node)
	{
		target = node;
		node = node->next;
		if (del_ptr)
			del_ptr(target->p);
		else
			target->p = NULL;
	}
	queue->first = NULL;
	queue->last = NULL;
	queue->len = 0;
}
