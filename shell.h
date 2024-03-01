#ifndef SHELL_H
#define SHELL_H

#include "cmd.h"
#include "shellData.h"

char runCmd(shellData_t *shData, cmd_t *command);
int runCmdList(shellData_t *shData);
int getCommandLine(shellData_t *shData);
int startShell(char **argv, char **env);

#endif /* SHELL_H */
