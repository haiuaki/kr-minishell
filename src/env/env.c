/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juljin <juljin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:12:55 by juljin            #+#    #+#             */
/*   Updated: 2026/01/26 23:12:57 by juljin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Copying the *envp[] from the system into a linked list */
t_env	*copy_env(char **envp)
{
	t_env	*head;
	t_env	*new_node;
	size_t	i;

	head = NULL;
	i = 0;
	while (envp[i])
	{
		new_node = new_env_node(envp[i]);
		if (!new_node)
			return (free_env_list(head), NULL);
		env_add_back(&head, new_node);
		i++;
	}
	return (head);
}

/*
int	main(int ac, char *av[], char *envp[])
{
	t_env	*env_copy;

	(void)ac;
	(void)av;
	env_copy = copy_env(envp);
	if (!env_copy)
		return (1);
	while (env_copy)
	{
		printf("Key : %s\n", env_copy->key);
		printf("Value : %s\n", env_copy->value);
		env_copy = env_copy->next;
	}
	return (0);
}
*/