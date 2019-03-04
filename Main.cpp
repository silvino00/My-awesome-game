#include"SDL/include/SDL.h"
#include <iostream>
#include <time.h>

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")

//Namespacce para la liberer�a iostream(std::)
using namespace std;

int main(int argc, char *argv[]) {
	
	SDL_Window *window;
	SDL_Renderer *render;

	//Iniciamos SDL en modo video
	int SDL_init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Nave", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	//coordenadas inicializadas para que el quadrado despues se mueva
	int x = 0;
	int y = 0;
	int moverx = 3;
	int movery = 3;

	//a�adimos un loop infinito
	while (true==1) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					x -= 1;
					break;
				case SDLK_RIGHT:
					x += 1;
					break;
				case SDLK_UP:
					y -= 1;
					break;
				case SDLK_DOWN:
					y += 1;
					break;
				default:
					break;
				}
							
			}
		}
		/*
		while (SDL_PollEvent(&event)) {
			//aqui colocamos nuestro evento
			x = x + moverx;
			y = y + movery;
			if (x >= 490) {
				moverx = -3;
			}
			else if (y >= 330) {
				movery = -3;
			}
			else if (x <= 0) {
				moverx = 3;
			}
			else if (y <= 0) {
				movery = 3;
			}
			
		}
		*/

		//dibujamos nuestra app
		render = SDL_CreateRenderer(window, -1, 0);

		//seleccionamos el color de fondo en RGB->azul
		SDL_SetRenderDrawColor(render, 0, 0, 255, 255);

		//llenamos la pantalla del color seleccionado anteriormente
		SDL_RenderClear(render);

		//colocamos el cuadrado rojo
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		//utilizamos la funcion para definir un rectangulo
		SDL_Rect rectangle;

		//asignamos posicion x e y con semilla aleatoria
		rectangle.x = x;
		rectangle.y = y;
		//asignamos alto y ancho en px
		rectangle.w = 150;
		rectangle.h = 150;

		//rellenamos el rectangulo del color que hemos escogido
		SDL_RenderFillRect(render, &rectangle);

		//actualizamos y mostramos lo que hay en pantalla tras renderizar capa a capa
		SDL_RenderPresent(render);

		//a�adimos un delay para poder ver cada movimiento del cuadrado en cada iteraci�n del bucle
		SDL_Delay(1);

		//destruimos el render para poder comenzar de nuevo otra posicion aleatoria
		SDL_DestroyRenderer(render);
	}
	//destruimos la ventana creada anteriormente
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}