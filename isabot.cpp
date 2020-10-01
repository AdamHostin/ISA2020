#include "isabot.hpp"




void Print_help(){
	printf("description\n");
	printf("Program echo messages that are not send by it or other bots in #isa-bot discord chanell\n\n");
	printf("options\n");
	printf("-v [verbose]\tprints output to terminal (default format \"<channel> - <username>: <message>\")\n");
	printf("-t [token]\tmandatori option\n");
	exit(0);
}

input_result Resolve_Input(int argc, char  *argv[]){

	input_result result;
	int c;

	static const char *short_opt = "hvt:";
		static const struct option long_opt[] = {
			
			{"help", no_argument, nullptr, 'h'},
			{"verbose", no_argument, nullptr, 'v'},
			{"token", required_argument, nullptr, 't'},			
			{nullptr, 0, nullptr, 0},
		};

  	while ((c = getopt_long(argc, argv, short_opt, long_opt, NULL)) != -1){
  		
  		switch(c){
  			case 'h':
  				Print_help();
  			case 'v':
  				result.verbose =true;
  				break;
  			case 't':
  				result.token.assign(optarg);
  				break;
  			case '?':
	        	
	        	printf("invalid input for more information run program with -h or --help\n");
	        	exit(INVALID_OPT_ERROR); //unknown option
	          break;


	    	default:
	    		
	    		exit(INVALID_OPT_ERROR);

  		}
  		
  		
  	}
  	if (result.token.compare("") == 0)
  		{
  			printf("Token not assigned for more information run program with -h or --help\n");
  			exit(MISSING_TOKEN);
  		}

  	return result;
}




class IsaBot
{
public:

	int sockfd, n;
	int portnum = 80;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    string outputStr;

    // Source :  "https://www.bogotobogo.com/cplusplus/sockets_server_client.php"
	IsaBot(){

		string getGatewayMessage = "GET /api/v6/channels/<channel_id>/messages HTTP/1.1\nAuthorization: Bot muj_token\nConnection: keep-alive";
		char buffer[BUFFER_SIZE]; 

		sockfd = socket(AF_INET, SOCK_STREAM, 0);
	    if (sockfd < 0){ 
	        fprintf(stderr,"ERROR opening socket\n");
	    	exit(INTERNAL_ERROR);
	    }
	    server = gethostbyname("discord.com");
	    if (server == NULL) {
	        fprintf(stderr,"ERROR, no such host\n");
	        exit(INVALID_HOST);
    	}
    	
    	serv_addr.sin_addr = *(in_addr*)(server->h_addr);   // set the server address
    	
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_port = htons(portnum); 
	    
	    //connection
	    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){ 
	        fprintf(stderr,"ERROR connecting\n");
	        exit(CONECTION_ERROR);
	    	}
	    printf("Conect ok\n");


	    //send reqest
	    n = write(sockfd, getGatewayMessage.c_str(), strlen(getGatewayMessage.c_str()));
	    if (n < 0){ 
	         fprintf(stderr,"ERROR writing to socket\n");
	         exit(CONECTION_ERROR);
	     }
	    

	    //reciev message
	    while(true){
	    n = read(sockfd, /*&(outputStr[0])*/ buffer, BUFFER_SIZE);
	    if (n < 0){ 
	         fprintf(stderr,"n is %d ERROR reading from socket\n",n);
	         exit(CONECTION_ERROR);
	     }
	    printf("%s\n", /*outputStr.c_str()*/ buffer);
	 }
		}
	
	
};

int main(int argc, char  *argv[])
{
	/*if (argc<2)
	{
		fprintf(stderr,"MISSING_TOKEN\n");
	        exit(MISSING_TOKEN);
	}*/
	input_result input = Resolve_Input(argc,argv);
	IsaBot bot;

	// connect
	// authorization
	// while true
	//    if new message start thread
	return 0;
}

//threaad 
// if sender is me || "*bot*"
//    return
// send message
// return