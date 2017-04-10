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
#include <cctype>

enum rows{STATE_X = 10, EV_X, LAST_EV_X, ACTION_X};

#define ACTION_Y	58
#define STATE_Y		48
#define EV_Y		57
#define LAST_EV_Y	64


#if I_AM == CLIENT
#include "ClientStates.h"

#elif I_AM == SERVER
#include "ServerStates.h"

#define WRQ_K		'w'	//eventos unicamente para server
#define	RRQ_K		'r'

#else
#error	"This program must emulate either a CLIENT or a SERVER in a TFTP connection"
#endif

//teclas correspondientes a cada evento:
#define ACK_K		'a'
#define LAST_ACK_K	'l'
#define DATA_K		'd'
#define LAST_DATA_K	'b'
#define TIMEOUT_K	't'
#define ERROR_K		'e'
#define EXIT_K		'q'



using namespace std;

GenericEvent * eventGenerator();


int main(void) 
{
	WINDOW * winTest=NULL;                     //Variable en dónde se guarda la terminal (Window) en donde voy a trabajar.
	GenericEvent * newEv = NULL;
	string lastEvent;


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

	

#if I_AM == CLIENT	
	printw("\tPrograma de simulación de cliente TFTP implementado con FSM \n\n"
		"\tCuando el usuario presiona las teclas de Eventos entiende \n"
		"\tque se generó un nuevo evento y responde ante ese evento \n"
		"\trealizando una acción y cambiando el estado.");
	
	move(6,0);
	printw("\tSimular lectura o escritura? (r/w)");
	
	GenericFSM fsm;
	int key;
	do { key = tolower(getch());	}
	while (key!= 'r' && key != 'w');

	move (STATE_X,40);
	switch (key) {
		case 'r':
			fsm.setState(new Reading(STATE_X, STATE_Y));
			printw("Estado: Reading");
			clrtoeol();
		break;

		case 'w':
			fsm.setState(new Writing(STATE_X, STATE_Y));
			printw("Estado: Writing");
			clrtoeol();
		break;
	}

	move(6,0);
	clrtoeol();	
#else
	
	printw("\tPrograma de simulación de servidor TFTP implementado con FSM \n\n"
		"\tCuando el usuario presiona las teclas de Eventos entiende \n"
		"\tque se generó un nuevo evento y responde ante ese evento \n"
		"\trealizando una acción y cambiando el estado.");
	move(10,40);
	printw("Estado: Idle");
	GenericFSM fsm(new Idle(STATE_X, STATE_Y));
#endif
	move(STATE_X-1, 45);
	printw("Status de la FSM");
	move(EV_X, 40);
	printw("Evento Recibido: Esperando Evento...");
	move(LAST_EV_X, 40);
	printw("Último Evento Recibido: N/A");
	move(ACTION_X, 40);
	printw("Accion ejecutada: N/A");	

	move(8, 3);
	printw("Eventos\t\t\t|");
	move(10, 3);
	printw("A = ACK\t\t\t|");
	move(11, 3);
	printw("L = LAST_ACK\t\t\t|");
	move(12, 3);
	printw("D = DATA\t\t\t|");
	move(13, 3);
	printw("B = LAST_DATA\t\t|");
	move(14, 3);
	printw("T = TIMEOUT\t\t\t|");
	move(15, 3);
	printw("E = ERROR\t\t\t|");
	move(16, 3);
	printw("Q = EXIT\t\t\t|");

#if I_AM == SERVER
	move(17, 3);
	printw("R = RRQ\t\t\t|");
	move(18, 3);
	printw("W = WRQ\t\t\t|");
#endif

	do {
		delete newEv;
		newEv = eventGenerator();

		if (newEv != NULL) {
			lastEvent = ((SimulationEvent*)newEv)->getName();
			move(EV_X, EV_Y);
			printw("%s", &(lastEvent[0]));
			clrtoeol();
			this_thread::sleep_for(chrono::seconds(1));

			fsm.dispach(*newEv);
			this_thread::sleep_for(chrono::seconds(1));
			move(LAST_EV_X, LAST_EV_Y);
			printw("%s", &(lastEvent[0]));
			clrtoeol();
		}
		else {
			move(EV_X,EV_Y);
			printw("esperando evento");
			clrtoeol();
		}
	}
#if I_AM == CLIENT
	while (newEv == NULL || (newEv->type() != EXIT && newEv->type()!= ERROR && newEv->type()!=LAST_DATA));
#else
	while (newEv == NULL || newEv->type() != EXIT);
#endif
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
			ev = new Ack(ACTION_X,ACTION_Y); 
			break;

		case LAST_ACK_K:
			ev = new LastAck(ACTION_X,ACTION_Y); 
			break;

		case DATA_K: 
			ev = new Data(ACTION_X,ACTION_Y); 
			break;

		case LAST_DATA_K: 
			ev = new LastData(ACTION_X,ACTION_Y); 
			break;

		case TIMEOUT_K: 
			ev = new Timeout(ACTION_X,ACTION_Y); 
			break;

		case ERROR_K: 
			ev = new Error(ACTION_X,ACTION_Y); 
			break;

		case EXIT_K: 
			ev = new Exit(ACTION_X,ACTION_Y); 
			break;
#if I_AM == SERVER
		case RRQ_K:
			ev = new Rrq(ACTION_X,ACTION_Y);
			break;

		case WRQ_K:
			ev = new Wrq(ACTION_X,ACTION_Y);
			break;
#endif // I_AM == SERVER
	}

	return ev;
}