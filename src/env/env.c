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

/* Splitting the key and its value & storing it inside a node, ignoring '=' */
t_env	*new_env_node(char *str)
{
	t_env	*node;
	char	*equal_ptr;
	size_t	key_len;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->next = NULL;
	equal_ptr = ft_strchr(str, '=');
	if (equal_ptr)
	{
		key_len = equal_ptr - str;
		node->key = ft_substr(str, 0, key_len);
		node->value = ft_strdup(equal_ptr + 1);
	}
	else
	{
		node->key = ft_strdup(str);
		node->value = NULL;
	}
	return (node);
}

/* Copying the *envp[] from the system into a linked list */
t_env	*copy_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	t_env	*new_node;
	size_t	i;

	head = NULL;
	i = 0;
	while (envp[i])
	{
		new_node = new_env_node(envp[i]);
		if (!new_node)
			return (free_env_list(head), NULL);
		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	return (head);
}

/*
int	main(int ac, char *av[], char *envp[])
{
	t_env	*env_copy;
	size_t	i;

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