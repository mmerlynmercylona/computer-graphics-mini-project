#include <GL/glut.h>
#include<stdio.h>

const int X=20,Y=15;
int point_size = 50;
float w = X*point_size;
float h = Y*point_size;
int play = true;
bool mouse_down = false;
int mouse_x, mouse_y;
void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,h,0,-1,1);
    //gluOrtho2D(0,X,0,Y);
}

struct P
{
    bool alive;
    int age=0;
} p[X][Y];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,255);
    glPointSize(point_size);
    glBegin(GL_POINTS);
        for(int y=0; y<Y; y++)
            for(int x=0; x<X; x++)
                {
                    if(p[x][y].age >30) //Dead by old age
                    {
                        p[x][y].alive = 0;
                        p[x][y].age = 0;
                    }


                if(p[x][y].alive)

                    {//if(p[x][y].age>5)
                        //glColor3f(1/(x+0.000000001),0,1/(y+0.00000001));
                        glColor3f(0.75*p[x][y].age/30,0,0.45*p[x][y].age/30);
                    //else
                      //  glColor3f(1,1,1);

                    glVertex2f(point_size/2+x*point_size, point_size/2+y*point_size);
                    p[x][y].age +=1;
                    //printf("Age: %d, posx: %d, posy: %d\n",p[x][y].age,x,y);
                    }
                }

    if (mouse_down && mouse_x >0 && mouse_y >0 && mouse_x<X*point_size && mouse_y<Y*point_size)
        p[mouse_x/point_size][mouse_y/point_size].alive=1;
    /*else
    {
        //int x = mouse_x/point_size; int y= mouse_y/point_size;
        //glVertex2f(point_size/2 + point_size*x, point_size/2+point_size*x);
    }*/
    glEnd();
    glutSwapBuffers();

}

void death ()
{
    for (int i=0; i<X; i++)
{
    for (int j=0; j<Y; j++)
    {
        int liveneigh = 0;

        if(i!=0 & j!=0)
        {
             liveneigh = p[i+1][j].alive + p[i-1][j].alive+
                p[i][j+1].alive + p[i][j-1].alive+
                p[i+1][j+1].alive+ p[i-1][j-1].alive+
                p[i+1][j-1].alive+p[i-1][j+1].alive;
            if (p[i][j].alive == 1)
        {
            if(liveneigh<2 or liveneigh>3)
                {
                    p[i][j].alive = 0;
                    p[i][j].age=0;
                }
            else if (liveneigh==2 or liveneigh==3)
                p[i][j].alive = 1;
        }
        else if (liveneigh==3)
            p[i][j].alive = 1;
        }

    }
}
}

void timer(int=0)
{
    if(GetAsyncKeyState('1')) play=1;
    if(GetAsyncKeyState('2')) play=0;
    if(GetAsyncKeyState('3'))
        for(int y=0;y<Y;++y)
            for(int x=0;x<X;++x)
                {
                    p[x][y].alive=0;
                }
    if(play) death();
    display();
    glutTimerFunc(250,timer,0);

}

void mouse (int button, int state, int ax, int ay)
{
    mouse_x = ax;
    mouse_y = ay;
    mouse_down = state == GLUT_DOWN;
}

void motion(int ax,int ay)
{
    mouse_x = ax;
    mouse_y = ay;
}

void motionpass(int ax, int ay)
{
    mouse_x = ax;
    mouse_y = ay;
}
void mousewrite()
{

}

int main(int argc, char **argv)
{
    for(int x=0;x<X;x++)
        for(int y=0; y<Y;y++)
    {

        p[x][y].alive = rand()%2;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutCreateWindow("Game of life");
    init();
    glutDisplayFunc(display);
    timer();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(motionpass);
    mousewrite();
    glutMainLoop();

}
