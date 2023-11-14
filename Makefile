
#variable declaration :-
cc=gcc      
MAKE=make
RM =rm

#targets .
all: newclient.c newserver.c client.c server.c
    
	$(cc) -o client newclient.c	
	$(cc) -o server newserver.c
	$(cc) -o cl client.c	
	$(cc) -o ser server.c
	gnome-terminal -t server --working-directory=/home/oumayma/UNIXInterface -e "./server"
	
	$(MAKE) client_target
	gnome-terminal -t ser --working-directory=/home/oumayma/UNIXInterface -e "./ser"
	$(MAKE) cl_target	


#another target for client
client_target:
	./client  
cl_target:
	./cl 


clean:server client
	$(RM) server
	$(RM) client
	$(RM) ser
	$(RM) cl
	