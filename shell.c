#include "shell.h"

/**
 * main - entry point
 * @argc: no. of arguments
 * @argv: pointer of pointer of a string
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	size_t len = 0;
	data_t data[] = {INIT_DATA};

	(void)argc;

	signal(SIGINT, ctrlc);
	data->program_name = argv[0];
/* making infinite loop */
	while (1)
	{
		non_interactive(data);
		_puts("shell$ ");

		if (getline(&(data->lineptr), &len, stdin) == -1)
		{
			free(data->lineptr);
			exit(data->status);
		}
		check_new_lines(data->lineptr);
		data->command = splitter(data->lineptr, " ");
		if (data->command[0] == NULL)
		{
			free(data->command);
			break;
		}
		cmd_parser(data->command[0], data);
		free(data->command);
	}
	free(data->lineptr);
	return (data->status);
}
