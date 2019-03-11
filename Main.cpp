#include "SDL/include/SDL.h"
#include <iostream>
#include <time.h>
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")


using namespace std;

int main(int argc, char *argv[]) {
	
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_Surface *background;
	SDL_Surface *spaceship;
	SDL_Surface *laser;
	//utilizamos la funcion para definir un rectangulo
	SDL_Rect rectangle;
	//utilizamos la funcion para definir un rectangulo
	SDL_Rect rectangle2;
	
	background = IMG_Load("Assets/background.png");
	spaceship = IMG_Load("Assets/descarga.png");
	laser = IMG_Load("Assets/laser.png");
	//SDL_Surface* surf;
	//SDL_Texture* background;
	//SDL_Texture* blueshapes;

	int num = 1;
	int spacekey = 0;
	int up = 0, left = 0, right = 0, down = 0;

	int imgflags = IMG_INIT_PNG;


	//coordenadas inicializadas para que el quadrado despues se mueva
	int x = 320;
	int y = 240;

	int z = x + 25;
	int w = y + 25;

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
	rectangle2.w = 40;
	rectangle2.h = 30;



	

	//Iniciamos SDL en modo video
	int SDL_init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Box", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);
	
	//dibujamos nuestra app
	render = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture *background_text = SDL_CreateTextureFromSurface(render, background);
	SDL_Texture *spaceship_text = SDL_CreateTextureFromSurface(render, spaceship);
	SDL_Texture *laser_text = SDL_CreateTextureFromSurface(render, laser);
	
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
					left = 1;
					rectangle.x -= 1;
					break;
				case SDLK_RIGHT:
					right = 1;
					rectangle.x += 1;
					break;
				case SDLK_UP:
					up = 1;
					rectangle.y -= 1;
					break;
				case SDLK_DOWN:
					down = 1;
					rectangle.y += 1;
					break;
				case SDLK_SPACE:
					spacekey = 1;
					rectangle2.x= rectangle.x;
					rectangle2.y = rectangle.y + 25;
					break;
				default:
					break;
				}
				break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					up = 0;
					break;
				case SDLK_DOWN:
					down = 0;
					break;
				case SDLK_RIGHT:
					right = 0;
					break;
				case SDLK_LEFT:
					left = 0;
					break;
				case SDLK_ESCAPE:
					spacekey = 0;
					break;
				default:
					break;
				}
			}

		}
		if (up == 1) {
			if (right == 1) {
				rectangle.x += 1;
				rectangle.y -= 1;
			}
			else if (left == 1) {
				rectangle.x -= 1;
				rectangle.y -= 1;
			}
			else {
				rectangle.y -= 1;
			}
		}
		else if (down == 1) {
			if (right == 1) {
				rectangle.x += 1;
				rectangle.y += 1;
			}
			else if (left == 1) {
				rectangle.x -= 1;
				rectangle.y += 1;
			}
			else {
				rectangle.y += 1;
			}
		}
		else if (right == 1) {
			rectangle.x += 1;
		}
		else if (left == 1) {
			rectangle.x -= 1;
		}
		rectangle2.x = rectangle2.x + 1;
	
	
		//llenamos la pantalla del color seleccionado anteriormente
		SDL_RenderClear(render);
		SDL_RenderCopy(render, background_text, NULL, NULL);
		SDL_RenderCopy(render, spaceship_text, NULL, &rectangle);
		SDL_RenderCopy(render, laser_text, NULL, &rectangle2);
		//actualizamos y mostramos lo que hay en pantalla tras renderizar capa a capa
		SDL_RenderPresent(render);

		
	}
	//destruimos la ventana creada anteriormente
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(background_text);
	SDL_DestroyTexture(spaceship_text);
	SDL_DestroyTexture(laser_text);
	SDL_FreeSurface(background);
	SDL_FreeSurface(spaceship);
	SDL_FreeSurface(laser);
	IMG_Quit();
	SDL_Quit();

	return 0;
	
}




