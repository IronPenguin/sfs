#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

SDL_Event event;

void sdl_init() {

    SDL_Init(SDL_INIT_VIDEO);
    atexit(SDL_Quit);
    SDL_WM_SetCaption("Kobayashi Space Program", NULL);
    SDL_SetVideoMode(1024, 512, 32, SDL_OPENGL);
}

void gl_init() {
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(70,(double)1024/512,1,1000);

    glEnable(GL_DEPTH_TEST);
}

void Dessiner(double angleX, double angleZ) {
    
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
 
    gluLookAt(3,4,2,0,0,0,0,0,1);
 
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
    SDL_GL_SwapBuffers();
}

int main() {
	sdl_init();
	gl_init();
    
	unsigned last_time = SDL_GetTicks();
    	unsigned current_time,ellapsed_time;
    	unsigned start_time;
	double angleX = 0, angleZ = 0; 

    while(1)
    {
        start_time = SDL_GetTicks();
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
 
        Dessiner(angleX, angleZ);
 
        ellapsed_time = SDL_GetTicks() - start_time;
        if (ellapsed_time < 10)
        {
            SDL_Delay(10 - ellapsed_time);
        }
 
    }
	return 0;
}
