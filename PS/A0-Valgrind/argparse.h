struct arg
{
	char* name;
	char* result;
};

struct argParser
{
	struct arg* argList;
	int capacity;
	int len;
};

void initArgs();
void addArg(char* name);
void parseArgs(int argc, char** argv);
char* getArg();