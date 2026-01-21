#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

/* shell loop */
void shell_loop(void);

/* execution */
void execute_cmd(char *cmd);

/* helpers */
char *trim_spaces(char *str);

#endif /* SHELL_H */
