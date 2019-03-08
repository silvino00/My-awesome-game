#include"SDL/include/SDL.h"
#include <iostream>
#include <time.h>

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")

//Namespacce para la liberería iostream(std::)
using namespace std;

int main(int argc, char *argv[]) {
	
	SDL_Window *window;
	SDL_Renderer *render;
	int num = 1;
	int spacekey = 0;


	//Iniciamos SDL en modo video
	int SDL_init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Box", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	//coordenadas inicializadas para que el quadrado despues se mueva
	int x = 320;
	int y = 240;
	
	int z = x + 25;
	int w = y + 25;

	//añadimos un loop infinito
	while (num==1) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					num = 0;
					break;
				case SDLK_LEFT:
					x -= 20;
					break;
				case SDLK_RIGHT:
					x += 20;
					break;
				case SDLK_UP:
					y -= 20;
					break;
				case SDLK_DOWN:
					y += 20;
					break;
				case SDLK_SPACE:
					z = x;
					w = y + 25;
					break;
				default:
					break;
				}
				break;
			
			case SDL_QUIT:
				num = 0;
				break;
			}

			
		}
			
		z = z + 20;
	
		//dibujamos nuestra app
		render = SDL_CreateRenderer(window, -1, 0);

		//seleccionamos el color de fondo en RGB->azul
		SDL_SetRenderDrawColor(render, 0, 0, 255, 255);

		//llenamos la pantalla del color seleccionado anteriormente
		SDL_RenderClear(render);


		//utilizamos la funcion para definir un rectangulo
		SDL_Rect rectangle;

		//colocamos el cuadrado rojo
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);

		//rellenamos el rectangulo del color que hemos escogido
		SDL_RenderFillRect(render, &rectangle);

		//actualizamos y mostramos lo que hay en pantalla tras renderizar capa a capa
		SDL_RenderPresent(render);

		//utilizamos la funcion para definir un rectangulo
		SDL_Rect rectangle2;

		//colocamos la bala de la nave de color verde
		SDL_SetRenderDrawColor(render, 0, 255, 0, 0);

		//rellenamos el rectangulo del color que hemos escogido
		SDL_RenderFillRect(render, &rectangle2);

		//actualizamos y mostramos lo que hay en pantalla tras renderizar capa a capa
		SDL_RenderPresent(render);

		//asignamos posicion x e y con semilla aleatoria
		rectangle.x = x;
		rectangle.y = y;
		//asignamos alto y ancho en px
		rectangle.w = 50;
		rectangle.h = 50;

		//asignamos posicion x e y con semilla aleatoria
		rectangle2.x = z;
		rectangle2.y = w;
		//asignamos alto y ancho en px
		rectangle2.w = 10;
		rectangle2.h = 5;

		//destruimos el render para poder comenzar de nuevo otra posicion aleatoria
		SDL_DestroyRenderer(render);
	}
	//destruimos la ventana creada anteriormente
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}