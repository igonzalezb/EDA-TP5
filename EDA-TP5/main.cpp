extern "C" {
#include "curses.h"
}
#include <cstdio>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "GenericEvent.h"
#include "GenericFSM.h"
#include "events.h"
#include "ClientStates.h"
#include <cctype>



#if I_AM == CLIENT
#include "client.h"

//teclas correspondientes a cada evento:
#define ACK_K		'a'
#define LAST_ACK_K	'l'
#define DATA_K		'd'
#define LAST_DATA_K	'b'
#define TIMEOUT_K	't'
#define ERROR_K		'e'
#define EXIT_K		'q'


GenericEvent * eventGenerator();


#elif I_AM == SERVER
#include "server.h"
#else
#error	"This program must emulate either a CLIENT or a SERVER in a TFTP connection"
#endif




using namespace std;




int main(void) 
{
	WINDOW * winTest=NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.
	GenericEvent * newEv;
	string lastEvent = NULL;


	//Inicializo la terminal y verifico que se haya inicializado correctamente:
	winTest = initscr();
	if(winTest == NULL)
	{
		return EXIT_FAILURE;
	}
	//Esta opción hace que siempre que se llame a una función que escribe se refresque la pantalla.
	immedok(winTest,TRUE);
	//Con las dos opciones de abajo elijo que el getch()sea no bloqueante (nodelay TRUE) y que no
	//muestr los caracteres cuando el usuario los escribe (noecho).
	nodelay(winTest, TRUE);
	noecho();


	printw("Programa de simulación de cliente TFTP implementado con FSM \n\n"
		"Cuando el usuario presiona las teclas de Eventos entiende \n"
		"que se generó un nuevo evento y responde ante ese evento \n"
		"realizando una acción y cambiando el estado.");

	move(7, 20);
	printw("Estado = Idle");
	move(8, 20);
	printw("Evento Recibido: Esperando Evento...");
	move(9, 20);
	printw("Último Evento Recibido: N/A");
	move(10, 20);
	printw("Accion ejecutada: N/A");

	move(2*EVENT_COUNT + 7,0);			
	printw("Press \"Q\" to continue...\n");

	GenericFSM fsm (new Writing());

	do {
		newEv = eventGenerator();

		if (newEv != NULL) {
			move(8, 20);
			lastEvent = ((SimulationEvent*)newEv)->getName();
			printw("Evento Recibido: %s", lastEvent);
			this_thread::sleep_for(chrono::seconds(1));

			fsm.dispach(*newEv);
			this_thread::sleep_for(chrono::seconds(1));
			move(9, 20);
			printw("Ultimo evento Recibido: %s", lastEvent);
			delete newEv;
		}
	}
	while (newEv->type() != EXIT);
	

	//Llamo para termiar PDCurses.
	endwin();
	
		
	return 0;
}






GenericEvent * eventGenerator()
{
	GenericEvent * ev = NULL;

	int key = getch();
	
	switch(tolower(key)){
		case ACK_K:
			ev = new Ack(7,20); 
			break;

		case LAST_ACK_K:
			ev = new LastAck(7,20); 
			break;

		case DATA_K: 
			ev = new Data(7,20); 
			break;

		case LAST_DATA_K: 
			ev = new LastData(7,20); 
			break;

		case TIMEOUT_K: 
			ev = new Timeout(7,20); 
			break;

		case ERROR_K: 
			ev = new Error(7,20); 
			break;

		case EXIT_K: 
			ev = new Exit(7,20); 
			break;
	}

	return ev;
}