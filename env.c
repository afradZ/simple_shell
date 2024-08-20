#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: struct containing potential args
 *
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the val of an environ variable
 * @info: struct containing potential args
 * @name: env variable name
 *
 * Retuen: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes a new env variable or mods an existing one
 * @info: struct containing potential args
 *
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("incorrect number of args\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an env variabel
 * @info: struct containing potential args
 *
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("not enough args\n");
		return (1);
	}
	for (i = 1 ; i<= info -> argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Struct containing potential args
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return(0);
}
