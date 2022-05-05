# distributed_systems_C
To run compile this program see the screenshot.pdf where it shows how the programmed is used,compiled and run.
Description of the project:
There are 3 main files ask1_client.c,ask1_client_soc.c,ask1_server.c

ask1_client_soc.c is a socket client that sends the user input to ask1_client.c whick ats as the socket server.

ask1_client.c receives the users input from ask1_client_soc.c and uses multithreading to be able to be used from multiple users at the same time.After the thread is created and the user input is received ask1_client.c sends the appropriate RPC call depending from the user's choice and then receives the results from the RPC server (TLDR ask1_client.c is a socket server and a RPC client at the same time).

ask1_server.c is the RPC server that receives the necessary data from ask1_client.c and then sends the results to  ask1_client.c
