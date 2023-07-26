#include "shell.h"

/**
 * execute_builtin_cmd - executes the builtin commands
 * @data: the structure of shell data
 */
void execute_builtin_cmd(data_t *data)
{
	if (_strcmp(data->command[0], "env") == 0)
		env(data->command);
	else if (_strcmp(data->command[0], "exit") == 0)
		exit_shell(data);
}

/**
 * execute_ex_cmd - execute external commands
 * @data: the struct of shell data
 */
void execute_ex_cmd(data_t *data)
{
	pid_t PID;

	PID = fork();
	if (PID == 0)
	{
		if (execve(data->command[0], data->command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	else
	{
		waitpid(PID, &(data->status), 0);
		data->status >>= 8;
	}
}

/**
 * execute_path_cmd - execute the path commands of the struct shell
 * @data: the struct of data of shell
 */
void execute_path_cmd(data_t *data)
{
	pid_t PID;

	PID = fork();
	if (PID == 0)
	{
		if (execve(path_checker(data->command[0]), data->command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	else
	{
		waitpid(PID, &(data->status), 0);
		data->status >>= 8;
	}
}
/**
 * invalid_cmd - handling the invalid commands of the struct data
 * @data: the struct of shell data
 */
void invalid_cmd(data_t *data)
{

	_puts_e(data->program_name);
	_puts_e(": 1: ");
	_puts_e(data->command[0]);
	_puts_e(": not found\n");
	data->status = 127;
}
