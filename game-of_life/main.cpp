#include<stdio.h>
#include<GL/glut.h>

GLfloat r[3] = {1,0,0};
GLfloat g[] = {0,1,0};
GLfloat b[] = {0,1,0};
GLfloat x,y,length=0.5,width=0.5;
GLint life[10][10];
GLfloat black[] = {0,0,0};
GLfloat white[] = {1,1,1};
int liveneigh;


void init()
{
    glClearColor(0,0,0,0);
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    gluOrtho2D(0,10,0,10);
    for (int i=0; i<10; i++)
{
    for (int j=0; j<10; j++)
    {
        life[i][j] = 0;
    }
}




}
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0,10,0,10);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void Timer(int value) {
   glutPostRedisplay();    // Post a paint request to activate display()
   //if (lifespan>0)

   //glutTimerFunc(refreshMillis, Timer, 1); // subsequent timer call at milliseconds
}

void organism(GLint i, GLint j, GLfloat my_col[],int alive)
{
    glColor3fv(my_col);
           glBegin(GL_QUADS);
           glVertex2f(i,j);
           glVertex2f(i,j-1);
           glVertex2f(i+1,j-1);
           glVertex2f(i+1,j);
           glEnd();
    if (alive==1)
        life[i][j] = 1;
    else
        life[i][j] = 0;

}

void makeCells(int row, int col)
{
       for(int i=0; i<=row; i=i+1)
   {
       for (int j=col; j>=0; j=j-1)
       {
           GLfloat mycol[3] = {0,0,1};
           organism(i,j, mycol,1);
           //glFlush();


       }

   }
}

void death ()
{
    for (int i=0; i<10; i++)
{
    for (int j=0; j<10; j++)
    {

        if(i!=0 & j!=0)
        {
             liveneigh = life[i+1][j] + life[i-1][j]+
                life[i][j+1] + life[i][j-1]+
                life[i+1][j+1]+ life[i-1][j-1]+
                life[i+1][j-1]+life[i-1][j+1];
            if (life[i][j] == 1)
        {
            if(liveneigh<2 or liveneigh>3)
                {
                    life[i][j] = 0;
                }
            else if (liveneigh==2 or liveneigh==3)
                life[i][j] = 1;
        }
        else if (liveneigh==3)
            life[i][j] = 1;
        }

    }
}
}



void display()
{
   glClear(GL_COLOR_BUFFER_BIT);//|GL_DEPTH_BUFFER_BIT);

   //organism(-1.5,-1.5,1,1,r);
   //organism(1.5,0.5,1,1,r);
   //organism(-4.5,4.5,1,1,g);
   //organism(-4.5,-4.5,1,1,g);
   //organism(4.5,4.5,1,1,g);
   //organism(4.5,-4.5,1,1,g);
   for (int i=0; i<10; i++)
   {
       for (int j=0; j<10; j++)
       {
           printf("%d\t",life[i][j]);
       }
       printf("\n");
   }
printf("\n\n");


   GLfloat mc[] ={1,1,1};
   //makeCells(10,10);
   organism(2,3,mc,1);
   organism(3,4,mc,1);
   organism(5,5,mc,1);
   organism(5,6,mc,1);
   organism(5,7,mc,1);
   organism(6,5,mc,1);
      for (int i=0; i<10; i++)
   {
       for (int j=0; j<10; j++)
       {
           printf("%d\t",life[i][j]);
       }
       printf("\n");
   }
printf("\n\n");
   //death();
   //organism(4,4,mc,1);
   //death();
   //glEnd();

      for (int i=0; i<10; i++)
   {
       for (int j=0; j<10; j++)
       {
           //printf("%d\t",life[i][j]);
           if(life[i][j]==0)
            organism(i,j,black,0);
           else
            organism(i,j,white,1);
       }
       //printf("\n");
   }
  glFlush();
   //glEnd();

   //glutSwapBuffers();

}

void mykeyboard(unsigned char Key,int x, int y)
{
    switch(Key)
    {
    case 'n':
        death();
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("game of life");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutTimerFunc(0, Timer, 0);
    glutKeyboardFunc(mykeyboard);
    glutMainLoop();
    return 0;
}
