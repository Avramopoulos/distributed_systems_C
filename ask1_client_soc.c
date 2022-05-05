#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n, t, done;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int choice,i,size,max_min[2];
    float avg,a;
    float *Y_prod;
    int *Y;
    
    if (argc < 3) {	//πρότυπο χρήσης
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);	//νούμερο πόρτας
    sockfd = socket(AF_INET, SOCK_STREAM, 0);		//άνοιγμα TCP socket
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);		//όνομα host
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    
    		//προετοιμασία socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("Trying to connect...\n");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    printf("Connected.\n");
    
    done = 0; //όταν done == 1 κλείνει το πρόγραμμα
        
    do {
           printf("-------------------------------------------------------------------------------\n");
           printf("Choose one of the following by typing the coresponding number:\n  ");
           printf("1) Find the average value of an array.\n  ");
           printf("2) Find the maximum and the minimum values of an array.\n  ");
           printf("3) Find the product of an array.\n  ");
           printf("4) Quit.\n");
           printf("-------------------------------------------------------------------------------\n\n\n");
           printf(">");
           
           scanf("%d", &choice);
           
           send(sockfd, &choice, sizeof(int),0); 	//στείλε την επιλογή του χρήστη
           
           if(choice >=1 && choice<=3){ 	//valid επιλογή 
           
            	printf("Give size of Y[]: ");
            	scanf("%d", &size);		//μέγεθος πίνακα
            
            	Y=(int *)malloc(size*sizeof(int));	//δεσμευση μνήμης 
			
	 	send(sockfd, &size, sizeof(int),0);		//στειλε το μέγεθος του Υ 
	        printf("\n");
	     
            	for (i = 0; i < size; i++) {
               	 printf("Y[%d] = ", i);			//διάβασε τις τιμές του Y
               	 scanf("%d", &Y[i]);	
            	}
            	
           	send(sockfd,Y,size*sizeof(int),0);		//στειλε το Υ
           	
           	if(choice == 1)
           	{
           		recv(sockfd,&avg,sizeof(float),0);  //παρε το μέσο όρο
           		printf("The average is: %f\n",avg);
           	}	
           	else if(choice == 2)
           	{
           		recv(sockfd,max_min,2*sizeof(int),0); //παρε το
           		printf("The max is: %d\nThe min is: %d\n",max_min[0],max_min[1]);
           	}
           	else if(choice == 3)
           	{
           		printf("Type the multiplier a: ");
            		scanf("%f", &a);
            		printf("\n");
            		
           		send(sockfd, &a, sizeof(float),0);  //στείλε τον τελεστέο για τον πολλαπλασιασμό του πίνακα
           		
           		recv(sockfd,Y_prod,size*sizeof(float),0); //πάρε τον πίνακα μετά τον πολλαπλασιασμό του με το α
           		
           		for (i = 0; i < size; i++) 
               		printf("Y[%d] = %f\n", i,Y_prod[i]);			
            		
           	}
           }
           else if(choice == 4)
           	done=1; 	//τέλος
           else
           	printf("Invalid Choice.\nPlease try again\n");

    } while (!done);

    close(sockfd);

    return 0;
}
