#include "shell.h"

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * change_dir - for changing the directory
 * @data: pointer to data structure
 *
 * Return: 0 on success
 */
int change_dir(sh_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SETOWD(data->oldpwd);
		if (chdir(home) < 0)
			return (FAIL);
		return (SUCCESS);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == 0)
		{
			SETOWD(data->oldpwd);
			if (chdir(home) < 0)
				return (FAIL);
		}
		else
		{
			SETOWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (FAIL);
		}
	}
	else
	{
		SETOWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (FAIL);
	}
	return (SUCCESS);
}
#undef GETCWD
/**
 * abort_prg - for exiting
 * @data: the pointer to data structure
 *
 * Return: 0 on success
 */
int abort_prg(sh_t *data __attribute__((unused)))
{
	int code, i = 0;

	if (data->args[1] == NULL)
	{
		free_data(data);
		exit(errno);
	}
	while (data->args[1][i])
	{
		if (_isalpha(data->args[1][i++]) < 0)
		{
			data->error_msg = _strdup("Illegal number\n");
			return (FAIL);
		}
	}
	code = _atoi(data->args[1]);
	free_data(data);
	exit(code);
}
/**
 * display_help - for displaying the help menu
 * @data: the pointer to  data structure
 *
 * Return: 0 on success
 * ------- (Fail) negative number will returned
 */
int display_help(sh_t *data)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(data->args[1], O_RDONLY);
	if (fd < 0)
	{
		data->error_msg = _strdup("no help topics match\n");
		return (FAIL);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			data->error_msg = _strdup("cannot write: permission denied\n");
			return (FAIL);
		}
	}
	PRINT("\n");
	return (SUCCESS);
}
/**
 * handle_builtin - for handling and managing builtins commands
 * @data: the  pointer to data structure
 *
 * Return: 0 on success
 */
int handle_builtin(sh_t *data)
{
	blt_t blt[] = {
		{"exit", abort_prg},
		{"cd", change_dir},
		{"help", display_help},
		{NULL, NULL}
	};
	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return ((blt + i)->f(data));
		i++;
	}
	return (FAIL);
}
