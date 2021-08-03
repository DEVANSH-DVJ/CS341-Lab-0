#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "argparse.h"

#define ARGCAP 3

struct argParser argParser;

void initArgs()
{
	argParser.capacity = ARGCAP;
	argParser.argList = malloc(sizeof(struct arg)*argParser.capacity);
	argParser.len = 0;
}

void addArg(char* name)
{
	if(argParser.len < argParser.capacity)
	{
		argParser.argList[argParser.len++].name = strdup(name);
		return;
	}

	argParser.capacity += ARGCAP;
	struct arg* tempArgs = malloc(sizeof(struct arg)*argParser.capacity);
	
	for(int i = 0; i < argParser.len; i++)
	{
		tempArgs[i] = argParser.argList[i];
	}

	free(argParser.argList);
	argParser.argList = tempArgs;
	argParser.argList[argParser.len++].name = strdup(name);
}

void parseArgs(int argc, char** argv)
{
	for(int i = 0; i < argc; i++)
	{
		for(int j = 0; j < argParser.len; j++)
		{
			if(strcmp(argv[i], argParser.argList[j].name) == 0)
			{
				if(i+1 < argc)
				{
					argParser.argList[j].result = strdup(argv[i+1]);
				}
				else
				{
					fprintf(stderr, "Argument %s not found\n", argv[i]);
				}
			}
		}
	}
}

char* getArg(char* name)
{
	for(int i = 0; i < argParser.len; i++)
	{
		if(strcmp(name, argParser.argList[i].name) == 0)
		{
			return strdup(argParser.argList[i].result);
		}
	}
}