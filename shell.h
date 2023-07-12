#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define INIT_DATA \
{ \
	NULL, NULL, 0, NULL  \
}

/**
 * struct datanode - structure of the information of the simple shell
 * @program_name: pointer to the program name
 * @lineptr: out put of the getline (command entered by user)
 * @status: the status of the shell
 * @command: the output after parsing the command
 */
typedef struct datanode
{
	char *program_name;
	char *lineptr;
	int status;
	char **command;
} data_t;

/* prototypes of functions*/
void ctrlc(int sig);
void _puts(char *str);
void _puts_e(char *str);
char **splitter(char *str, char *d);
char *_strtok(char *s, char *d, char **p);
void cmd_parser(char *cmd, data_t *data);
void *_realloc(void *p, unsigned int prev, unsigned int current);
void check_new_lines(char *str);
char *_getenv(char *en);
void env(char **command);
void exit_shell(data_t *data);
int _atoi(char *string);
char *path_checker(char *cmd);

/*prototypes of execution functions*/
void execute_builtin_cmd(data_t *data);
void execute_ex_cmd(data_t *data);
void execute_path_cmd(data_t *data);
void invalid_cmd(data_t *data);

/*prototypes of string fyunctions*/
int _strspn(char *s1, char *s2);
int _strcspn(char *s1, char *s2);
char *_strchr(char *string, char character);
char *_strcat(char *dest, char *origin);
int _strlen(char *s);
void _strcpy(char *src, char *dest);
int _strcmp(char *s1, char *s2);
void non_interactive(data_t *data);

/*global variables*/
extern char **environ;

#endif

