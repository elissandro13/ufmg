#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <time.h>


const float FPS = 100;  

const int SCREEN_W = 960;
const int SCREEN_H = 540;
const int NAVE_W = 100;
const int NAVE_H = 50;
int pontos = 0;
int cont = 0;

ALLEGRO_COLOR COR_CENARIO;


typedef struct Inimigo
{
	int x,y;
	int w,h;
	int vel;
	ALLEGRO_COLOR cor;
} Inimigo;


typedef struct Nave
{
	int x,y;
	int dir_x, dir_y;
	//int esq, dir, cima, baixo;
	float vel;
	ALLEGRO_COLOR cor;
} Nave;

typedef struct Bloco
{
	int x, y;
	int w ,h;
	float vel;
	ALLEGRO_COLOR cor;
} Bloco;


typedef struct Tiro {
	int x;
	int y;
	float raio;
	int on;
	ALLEGRO_COLOR cor;
} Tiro;



void initGlobais() {
	COR_CENARIO = al_map_rgb(rand()%64, rand()%64, rand()%64);
}

void initInimigo(Inimigo *inimigo) {

	inimigo->w = 20 + rand()%30;
	inimigo->h = 20 + rand()%30;
	inimigo->y = rand()%(SCREEN_H);
	inimigo->x = SCREEN_W + rand()%(SCREEN_W/4);
	inimigo->cor = al_map_rgb(rand(), rand(), rand());
	inimigo->vel = 1 + rand()%3;

}

void initNave(Nave *nave) {

	nave->x = 10 + NAVE_W;
	nave->y = SCREEN_H/2;
	nave->vel = 3;
	nave->dir_x = 0;
	nave->dir_y = 0;
	nave->cor = al_map_rgb(192 + rand()%64, 192 + rand()%64, 192 + rand()%64);
}

void initTiro(Nave nave, Tiro *tiro) {

	tiro->raio = 5;
	tiro->y = nave.y;
	tiro->x = nave.x + 3;
	tiro->on = 1;
	tiro->cor = al_map_rgb(255, 0, 0);
}

void initBloco(Bloco *bloco) {

	bloco->x = SCREEN_W + rand()%(SCREEN_W/2);
	bloco->y = rand()%(4*SCREEN_H/5);
	bloco->w = SCREEN_W + rand()%(SCREEN_W);
	bloco->h = SCREEN_H/5 + rand()%(2*SCREEN_H/5);
	bloco->cor = al_map_rgb(rand(), rand(), rand());
	//bloco->cor = al_map_rgb(255, 0, 0);
}

void desenhaCenario() {

	al_clear_to_color(COR_CENARIO);

}

void desenhaNave(Nave nave) {

	al_draw_filled_triangle(nave.x, nave.y, nave.x-NAVE_W, nave.y - NAVE_H/2, nave.x-NAVE_W, nave.y + NAVE_H/2, nave.cor);
}

void desenhaInimigo(Inimigo inimigo) {

	al_draw_filled_rectangle(inimigo.x, inimigo.y, inimigo.x + inimigo.w, inimigo.y+ inimigo.h, inimigo.cor);
}

void desenhaBloco(Bloco bloco) {

	al_draw_filled_rectangle(bloco.x, bloco.y, bloco.x + bloco.w, bloco.y + bloco.h, bloco.cor);
}

void desenhaTiro(Tiro tiro) {

	al_draw_filled_circle(tiro.x, tiro.y, tiro.raio, tiro.cor);
}

void atualizaTiro(Tiro *tiro) {

	
	if(tiro->on == 1) {
		if(tiro->x > SCREEN_W)
			tiro->on = 0;
		tiro->x += 3;
	}
}

void atualizaInimigo(Inimigo *inimigo) {
	
	inimigo->x -= inimigo->vel;
	if(inimigo->x + inimigo->w < 0){
		initInimigo(inimigo);
	}
}

void atualizaBloco(Bloco *bloco) {
	
	bloco->x -= 1;
	if(bloco->x + bloco->w < 0){
		initBloco(bloco);
	}
}

void atualizaNave(Nave *nave) {


	if(nave->x - NAVE_W + (nave->dir_x * nave->vel) > 0 && nave->x + (nave->dir_x * nave->vel) <= 960 && nave->y + (nave->dir_y * nave->vel)- NAVE_H/2 > 0 && nave->y + NAVE_H/2 + (nave->dir_y * nave->vel) <= 540){
		nave->x += nave->dir_x * nave->vel;
		nave->y += nave->dir_y  * nave->vel;
	} 
}

void colisaoInimigosBloco(Inimigo *inimigo, Bloco bloco) {
	if(inimigo->x < bloco.x + bloco.w && inimigo->x + inimigo->w > bloco.x && inimigo->y < bloco.y + bloco.h &&
   			inimigo->y + inimigo->h > bloco.y) {
		initInimigo(inimigo);
		printf("bateu\n");
	}
}

void colisaoTiroBloco(Tiro *tiro, Bloco bloco) {

	if(tiro->x < bloco.x + bloco.w && tiro->x + tiro->raio > bloco.x && tiro->y < bloco.y + bloco.h &&
   			tiro->y + tiro->raio > bloco.y) {
		tiro->on =  0;
	}

}


void colisaoTiroInimigo(Tiro *tiro, Inimigo *inimigo) {


			/* code */
		
		

	if(tiro->x < inimigo->x + inimigo->w && tiro->x + tiro->raio > inimigo->x && tiro->y < inimigo->y + inimigo->h &&
			tiro->y + tiro->raio > inimigo->y) {
		tiro->on =  0;
		pontos += (inimigo->w + inimigo->h) * 10;
		initInimigo(inimigo);
	}
	
} 

int colisaoNaveBloco(Nave nave, Bloco bloco) {

	nave.x = nave.x - NAVE_W;
	nave.y = nave.y - NAVE_H/2;
	

	if (nave.x < bloco.x + bloco.w && nave.x + NAVE_W > bloco.x && nave.y < bloco.y + bloco.h &&
   			nave.y + NAVE_H > bloco.y) {
		printf("Matou\n");
    	return 1;
	}
	
	return 0;
}

int colisaoNaveInimgos2(Nave nave, Inimigo *inimigos) {

	nave.x = nave.x - NAVE_W;
	nave.y = nave.y - NAVE_H/2;
	if (nave.x < inimigos->x + inimigos->w && nave.x + NAVE_W > inimigos->x && nave.y < inimigos->y + inimigos->h &&
				nave.y + NAVE_H > inimigos->y) {
			printf("MORREUlllllllllll\n");
			printf("%d %d %d %d", nave.x, nave.y, inimigos->x, inimigos->y, inimigos->w, inimigos->h);
			return 1;
		}
	
	return 0;
}


int main(int argc, char **argv){

	srand(time(NULL));
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
   
	//----------------------- rotinas de inicializacao ---------------------------------------
    
	//inicializa o Allegro
	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	
    //inicializa o módulo de primitivas do Allegro
    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }	
	
	//inicializa o modulo que permite carregar imagens no jogo
	if(!al_init_image_addon()){
		fprintf(stderr, "failed to initialize image module!\n");
		return -1;
	}
   
	//cria um temporizador que incrementa uma unidade a cada 1.0/FPS segundos
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
 
	//cria uma tela com dimensoes de SCREEN_W, SCREEN_H pixels
	display = al_create_display(SCREEN_W, SCREEN_H);
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	//instala o teclado
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}
	
	//instala o mouse
	if(!al_install_mouse()) {
		fprintf(stderr, "failed to initialize mouse!\n");
		return -1;
	}

	//inicializa o modulo allegro que carrega as fontes
	al_init_font_addon();

	//inicializa o modulo allegro que entende arquivos tff de fontes
	if(!al_init_ttf_addon()) {
		fprintf(stderr, "failed to load tff font module!\n");
		return -1;
	}
	
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    ALLEGRO_FONT *size_32 = al_load_font("arial.ttf", 32, 1);   
	if(size_32 == NULL) {
		fprintf(stderr, "font file does not exist or cannot be accessed!\n");
	}

 	//cria a fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}
   


	//registra na fila os eventos de tela (ex: clicar no X na janela)
	al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila os eventos de tempo: quando o tempo altera de t para t+1
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	//registra na fila os eventos de teclado (ex: pressionar uma tecla)
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//registra na fila os eventos de mouse (ex: clicar em um botao do mouse)
	al_register_event_source(event_queue, al_get_mouse_event_source());  	

	initGlobais();

	Nave nave;
	Bloco bloco;
	Tiro tiro;
	Inimigo inimigos[11];

	initNave(&nave);
	initBloco(&bloco);
	for (int i = 0; i <= 10; i++)
	{
		initInimigo(&inimigos[i]);
	}
	
	
	tiro.on = 0;

	//inicia o temporizador
	al_start_timer(timer);
	

	int playing = 1;
	while(playing) {
		al_init_font_addon();
		al_init_ttf_addon();

		if(cont == 3){
			nave.cor = al_map_rgb(rand()%64, rand()%64, rand()%64);
			cont = 0;
		}


		ALLEGRO_EVENT ev;
		//espera por um evento e o armazena na variavel de evento ev
		al_wait_for_event(event_queue, &ev);

		//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
		if(ev.type == ALLEGRO_EVENT_TIMER) {

			//int num_ini = 6 + rand()%10;

			desenhaCenario();
			atualizaBloco(&bloco);
			desenhaBloco(bloco);
			//atualizaInimigo();
			//desenhaInimigo();
			atualizaNave(&nave);
			desenhaNave(nave);

			for (int i = 0; i <= 10; i++)
			{
				atualizaInimigo(&inimigos[i]);
				desenhaInimigo(inimigos[i]);
				colisaoInimigosBloco(&inimigos[i], bloco);
				if(colisaoNaveInimgos2(nave, &inimigos[i])){
					playing = 0;
					break;
				}
			}

			if(playing == 0){ 
				break;
			}
			
			if(tiro.on) {
				atualizaTiro(&tiro);
				desenhaTiro(tiro);
				colisaoTiroBloco(&tiro, bloco);
			}
			//atualiza a tela (quando houver algo para mostrar)

			if(colisaoNaveBloco(nave, bloco)) {
				playing = 0;
				break;
			}
			
			//if(colisaoNaveInimgos(nave, inimigos) == 1) {
			//	playing = 0;
			//	break;
			//}

			//printf("Colwediou\n");
			//playing = !colisaoNaveInimgo(nave, inimigos[i]);
			//if(playing)
			//		break;

			for (int i = 0; i <= 10; i++)
			{
				colisaoTiroInimigo(&tiro, &inimigos[i]);
			}
			
			
			
			
			//playing = != colisaoNaveInimigo(nave, inimigo);

			al_flip_display();
			
			if(al_get_timer_count(timer)%(int)FPS == 0)
				printf("\n%d segundos se passaram...", (int)(al_get_timer_count(timer)/FPS));
		}
		//se o tipo de evento for o fechamento da tela (clique no x da janela)
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			playing = 0;
		}
		//se o tipo de evento for um clique de mouse
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			printf("\nmouse clicado em: %d, %d", ev.mouse.x, ev.mouse.y);
		}
		//se o tipo de evento for um pressionar de uma tecla
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);

			switch(ev.keyboard.keycode) {
				
				case ALLEGRO_KEY_W:
					nave.dir_y--;
					//nave.cima = 1;
				break;
				case ALLEGRO_KEY_S:
					nave.dir_y++;
					//nave.baixo = 1;
				break;
				case ALLEGRO_KEY_D:
					nave.dir_x++;
					//nave.dir = 1;
				break;
				case ALLEGRO_KEY_A:
					nave.dir_x--;
					//nave.esq = 1;
				break;
				case ALLEGRO_KEY_SPACE:
					//tiro.on = 1;
					if(tiro.on == 0){
						initTiro(nave, &tiro);
						cont++;
					}
				break;
			}
		}

		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			//imprime qual tecla foi
			printf("\ncodigo tecla: %d", ev.keyboard.keycode);

			switch(ev.keyboard.keycode) {
				
				case ALLEGRO_KEY_W:
					nave.dir_y++;
					//nave.cima = 0;
				break;
				case ALLEGRO_KEY_S:
					nave.dir_y--;
					//nave.baixo = 0;
				break;
				case ALLEGRO_KEY_D:
					nave.dir_x--;
					//nave.dir = 0;
				break;
				case ALLEGRO_KEY_A:
					nave.dir_x++;
					//nave.esq = 0;
				break;
			}
		}

	} //fim do while

	printf("Pontos %d", pontos);
	FILE *file = fopen("records.txt","r");
	char str[1000];
	fgets(str, 1000, file);
	///printf("ADSsad %s", str);
	char *token = strtok(str, "\n");
	int num_record = atoi(token);
	//printf("%d", num_record);
	//printf("Record %d", num_record);
	fclose(file);
	if(pontos > num_record){
		FILE *file = fopen("records.txt","w");
		fprintf(file, "%d\n",pontos);
		fclose(file);
	}
	
	//al_draw_text();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font24 = al_load_font("arial.ttf", 24, 0);
	ALLEGRO_DISPLAY *display_font =  al_create_display(960, 540);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_textf(font24, al_map_rgb(255, 0,255), 50, 50, 0, "Record Atual %d Nova Pontuação %d", num_record, pontos);
	al_flip_display();
	al_rest(5);
	//sleep(1);

     
	//procedimentos de fim de jogo (fecha a tela, limpa a memoria, etc)
	
 
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
   
	
	return 0;
}