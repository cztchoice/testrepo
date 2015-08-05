#include <stdio.h>
#include <string.h>

const int BUILTIN_COMMAND_NUM = 50;

static char *BuiltinCommand[ BUILTIN_COMMAND_NUM ] = {
    "",
    "alias",
    "bind",
    "builtin",
    "caller",
    "command",
    "declare",
    "echo",
    "enable",
    "fg",
    "help",
    "let",
    "local",
    "logout",
    "mapfile",
    "printf",
    "read",
    "readarray",
    "source",
    "type",
    "typeset",
    "ulimit",
    "unalias",
    ""//The end of BuiltinCommands
};

int isBuiltinCommand(char *str){
    int i = 1;
    while(strcmp(BuiltinCommand[i], "") != 0){
        if(strcmp(BuiltinCommand[i], str) == 0){
            return i;
        }
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    printf("%d\n", isBuiltinCommand("fg"));
    return 0;
}
