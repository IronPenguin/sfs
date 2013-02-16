#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <GL/gl.h>
#include <GL/glu.h>

#define WIN_WIDTH 1024
#define WIN_HEIGHT 512
#define TITLE "Kobayashi Space Program"

#define FOVY 70
#define RATIO (WIN_WIDTH / WIN_HEIGHT)
#define NEAR 1
#define FAR 1000

#define FPS 24

SDL_Event event;

void Dessiner(double, double, double, double);
void Render(double, double, unsigned, unsigned);
void sdl_init();
void gl_init();

void sdl_init() {
    
    printf("Initializing SDL ... ");
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	printf("\nKSP : Error from initializing SDL\n");
	exit(0);
    }
    atexit(SDL_Quit);
    
    if(TTF_Init() < 0) {
	printf("\nKSP : Error from initializing TTF\n");
	exit(0);
    }
    atexit(TTF_Quit);

    SDL_WM_SetCaption(TITLE, NULL);
    SDL_SetVideoMode(WIN_WIDTH, WIN_HEIGHT, 32, SDL_OPENGL);
    
    printf("[OK]\n");
}

void gl_init() {

    printf("Initializing GL ... ");
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(FOVY,RATIO,NEAR,FAR);
    
    glEnable(GL_DEPTH_TEST);
    
    printf("[OK]\n");
}

void init_render() {
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(3,4,2,0,0,0,0,0,1);
}

void Render(double angleX, double angleZ, unsigned start_time, unsigned ellapsed_time) {

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    init_render();

    start_time = SDL_GetTicks();

	//Draw here
	//	

	Dessiner(3, 0, angleX, angleZ);
	
	//
	//Draw end
        ellapsed_time = SDL_GetTicks() - start_time;
        
	if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        } 
}

void Dessiner(double ox, double oy, double angleX, double angleZ) { 
    
    glPushMatrix();
    glTranslated(ox, oy, 0);
    glRotated(angleZ,0,0,1);
    glRotated(angleX,1,0,0);

    glBegin(GL_QUADS);
 
    glColor3ub(255,0,0); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);
 
    glColor3ub(0,255,0); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);
 
    glColor3ub(0,0,255); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);
 
    glColor3ub(255,255,0); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);
 
    glColor3ub(0,255,255); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);
 
    glColor3ub(255,0,255); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);
 
    glEnd();
    glFlush();
    glPopMatrix();
    SDL_GL_SwapBuffers();
}

int main() {

	sdl_init();
	gl_init();
	init_render();

	unsigned last_time = SDL_GetTicks();
    	unsigned current_time = 0, ellapsed_time = 0;
    	unsigned start_time = 0;
	double angleX = 0, angleZ = 0; 

    while(1)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
            }
        }
 
        current_time = SDL_GetTicks();
        ellapsed_time = current_time - last_time;
        last_time = current_time;
 
        angleZ += 0.05 * ellapsed_time;
        angleX += 0.05 * ellapsed_time;

	Render(angleX, angleZ, start_time, ellapsed_time);
    }
	return 0;
}
