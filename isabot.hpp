#include <stdlib.h>
#include <stdio.h>
#include <regex>
#include <string>
#include <string.h>
#include <getopt.h>
#include<unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<arpa/inet.h> 

#define INTERNAL_ERROR 99
#define INVALID_INPUT_ARG_ERROR 1
#define MISSING_INPUT_ARG_ERROR 2
#define INVALID_OPT_ERROR 3
#define MISSING_TOKEN 4
#define INVALID_HOST 5
#define CONECTION_ERROR 6

#define BUFFER_SIZE 2048


using namespace std;

typedef struct
{
	bool verbose = false;
	string  token = "";
}input_result;