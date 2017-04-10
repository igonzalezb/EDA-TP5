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




//int main(void) 
//{
//	WINDOW * winTest=NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.
//	GenericEvent * newEv = NULL;
//	string lastEvent;
//	int key;
//
//	//Inicializo la terminal y verifico que se haya inicializado correctamente:
//	winTest = initscr();
//	if(winTest == NULL)
//	{
//		return EXIT_FAILURE;
//	}
//	//Esta opción hace que siempre que se llame a una función que escribe se refresque la pantalla.
//	immedok(winTest,TRUE);
//	//Con las dos opciones de abajo elijo que el getch()sea no bloqueante (nodelay TRUE) y que no
//	//muestr los caracteres cuando el usuario los escribe (noecho).
//	nodelay(winTest, TRUE);
//	noecho();
//	curs_set(0);
//
//	printw("\tPrograma de simulación de cliente TFTP implementado con FSM \n\n"
//		"\tCuando el usuario presiona las teclas de Eventos entiende \n"
//		"\tque se generó un nuevo evento y responde ante ese evento \n"
//		"\trealizando una acción y cambiando el estado.\n\n"
//		"\t Simular lectura o escritura? (r/w) ");
//
//	
//	GenericFSM fsm;
//
//	do { key = getch();	}
//	while (key!= 'r' && key != 'w');
//
//	
//	move(5,0);
//	printw("\t\t\t\t\t\t\t");
//
//	move (7,20);
//	switch (key) {
//		case 'r':
//			fsm.setState(new Reading());
//			printw("Estado = Reading");
//		break;
//
//		case 'w':
//			fsm.setState(new Writing());
//			printw("Estado = Writing");
//		break;
//	}
//
//
//	move(8, 20);
//	printw("Evento Recibido: Esperando Evento...");
//	move(9, 20);
//	printw("Último Evento Recibido: N/A");
//	move(10, 20);
//	printw("Accion ejecutada: N/A");
//
//	move(2*EVENT_COUNT + 7,0);			
//	printw("Press \"Q\" to continue...\n");
//
//
//	do {
//		delete newEv;
//		newEv = eventGenerator();
//
//		if (newEv != NULL) {
//			move(8, 20);
//			lastEvent = ((SimulationEvent*)newEv)->getName();
//			printw("Evento Recibido: %s\t\t", &(lastEvent[0]));
//			this_thread::sleep_for(chrono::seconds(1));
//
//			fsm.dispach(*newEv);
//			this_thread::sleep_for(chrono::seconds(1));
//			move(9, 20);
//			printw("Ultimo evento Recibido: %s\t\t", &(lastEvent[0]));
//		}
//		else {
//			move(8,20);
//			printw("Evento Recibido: esperando evento\t\t");
//		}
//	}
//	while (newEv == NULL || (newEv->type() != EXIT && newEv->type()!= ERROR));
//	
//
//	//Llamo para termiar PDCurses.
//	endwin();
//	
//		
//	return 0;
//}
//

int main(void) 
{
	WINDOW * winTest=NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.
	GenericEvent * newEv = NULL;
	string lastEvent;
	int key;

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
	curs_set(0);

	printw("\tPrograma de simulación de cliente TFTP implementado con FSM \n\n"
		"\tCuando el usuario presiona las teclas de Eventos entiende \n"
		"\tque se generó un nuevo evento y responde ante ese evento \n"
		"\trealizando una acción y cambiando el estado.\n\n"
		"\t Simular lectura o escritura? (r/w) ");

	
	move(2*EVENT_COUNT + 7,0);			
	
	GenericFSM fsm;

	do { key = getch();	}
	while (key!= 'r' && key != 'w');

	move(5,0);
	printw("\t\t\t\t\t\t\t");
	
	move(6, 45);
	printw("Status de la FMS");
	move(9, 40);
	printw("Evento Recibido: Esperando Evento...");
	move(10, 40);
	printw("Último Evento Recibido: N/A");
	move(11, 40);
	printw("Accion ejecutada: N/A");
	
	move (8,40);
	switch (key) {
		case 'r':
			fsm.setState(new Reading());
			printw("Estado = Reading");
		break;

		case 'w':
			fsm.setState(new Writing());
			printw("Estado = Writing");
		break;
	}

	move(6, 3);
	printw("Eventos\t\t\t|");
	move(8, 3);
	printw("A = WRQ\t\t\t|");
	move(9, 3);
	printw("B = TIMEOUT\t\t\t|");
	move(10, 3);
	printw("C = LAST_DATA_PAQUET\t\t|");

	move(2*EVENT_COUNT + 7,0);			
	printw("\tPress \"Q\" to continue...\n");


	do {
		delete newEv;
		newEv = eventGenerator();

		if (newEv != NULL) {
			move(9, 40);
			lastEvent = ((SimulationEvent*)newEv)->getName();
			printw("Evento Recibido: %s\t\t\t", &(lastEvent[0]));
			this_thread::sleep_for(chrono::seconds(1));

			fsm.dispach(*newEv);
			this_thread::sleep_for(chrono::seconds(1));
			move(10, 40);
			printw("Ultimo evento Recibido: %s\t\t\t", &(lastEvent[0]));
		}
		else {
			move(9,40);
			printw("Evento Recibido: esperando evento\t\t\t");
		}
	}
	while (newEv == NULL || (newEv->type() != EXIT && newEv->type()!= ERROR));
	

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
			ev = new Ack(8,40); 
			break;

		case LAST_ACK_K:
			ev = new LastAck(8,40); 
			break;

		case DATA_K: 
			ev = new Data(8,40); 
			break;

		case LAST_DATA_K: 
			ev = new LastData(8,40); 
			break;

		case TIMEOUT_K: 
			ev = new Timeout(8,40); 
			break;

		case ERROR_K: 
			ev = new Error(8,40); 
			break;

		case EXIT_K: 
			ev = new Exit(8,40); 
			break;
	}

	return ev;
}