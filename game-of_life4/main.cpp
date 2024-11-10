#include <GL/glut.h>

const int X=200,Y=150;
int point_size = 5;
int old_age = 50;
int speed = 100;
float w = X*point_size;
float h = Y*point_size;
int play = true;
bool mouse_down = false;
int mouse_x, mouse_y;


void init()
{
    glClearColor(0,0,0,0); //Make background black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,h,0,-1,1);
}

struct P //Organism structure
{
    bool alive; //status of organism
    int age=0;  //Age
    int next=0; //stores status in next iteration

} p[X][Y]; //Matrix of organisms

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(point_size); //size
    glBegin(GL_POINTS);
        for(int y=0; y<Y; y++)
            for(int x=0; x<X; x++)
                {   // Set color based on age
                    if(p[x][y].age<5)
                        //glColor3ub(224,186,211); Color scheme 1
                        glColor3ub(225,232,255); //Color scheme 2
                    else if(p[x][y].age<10)
                        //glColor3ub(239,93,96);
                        glColor3ub(251,202,239);
                    else if(p[x][y].age<15)
                        //glColor3ub(236,64,103);
                        glColor3ub(255,103,184);
                    else if (p[x][y].age<20)
                        //glColor3ub(237,52,156);
                        glColor3ub(234,55,136);
                    else if(p[x][y].age<25)
                        //glColor3ub(160,26,125);
                        glColor3ub(196,25,159);
                    else if(p[x][y].age<45)
                        //glColor3ub(49,24,71);
                        glColor3ub(126,25,108);
                    else

                        glColor3ub(255,199,89);

                if(p[x][y].alive)
                    glVertex2f(point_size/2+x*point_size, point_size/2+y*point_size); //Draw point
                }

    //Draw at Mouse click
     if (mouse_down && mouse_x >0 && mouse_y >0 && mouse_x<X*point_size && mouse_y<Y*point_size)
        p[mouse_x/point_size][mouse_y/point_size].alive=1;
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
            liveneigh = p[i+1][j].alive + p[i-1][j].alive+
                p[i][j+1].alive + p[i][j-1].alive+
                p[i+1][j+1].alive+ p[i-1][j-1].alive+
                p[i+1][j-1].alive+p[i-1][j+1].alive;

            if (p[i][j].alive == 1)
            {
                //If less than 2 neighbours, isolation->death
                //If more than 3 neighbours, overpopulation->death
                if(liveneigh<2 or liveneigh>3)
                {
                    p[i][j].next = 0;
                    p[i][j].age=0;
                }
                //If exactly 2 or 3 neighbours, happy->alive
                else if (liveneigh==2 or liveneigh==3)
                {
                    p[i][j].next = 1;
                    p[i][j].age +=1;
                }
            }
        //If dead, and has exactly 3 neighbours, birth->alive
        else if (liveneigh==3)
            p[i][j].next = 1;
        }
    }

for(int i=0;i<X;i++)
    for (int j=0; j<Y; j++)
    {
        if(p[i][j].age >old_age) //Custom rule: Old age->death
        {
            p[i][i].alive = 0;
            p[i][j].age = 0;
            p[i][j].next = 0;
        }
        p[i][j].alive = p[i][j].next; //Setting next state
    }
}

void timer(int=0)
{
    if(GetAsyncKeyState('1')) {play=1;} //Press 1 to play animation
    if(GetAsyncKeyState('2')) {play=0;} //Press 2 to pause
    if(GetAsyncKeyState('3')) //Press 3 to reset board
        for(int y=0;y<Y;++y)
            for(int x=0;x<X;++x)
                {
                    p[x][y].alive=0;
                    p[x][y].next=0;
                    p[x][y].age = 0;
                }
    if(play) death(); //Call death function repeatedly while playing
    display(); // Display board
    glutTimerFunc(speed,timer,0); //Iterate, to speed up decrease time argument (here time is set as 100ms)
}

void mouse (int button, int state, int ax, int ay) //Function to get mouse click position
{
    mouse_x = ax;
    mouse_y = ay;
    mouse_down = state == GLUT_DOWN;
}

void motion(int ax,int ay) // Function to allow user to draw continuously, no need to click at every point
{
    mouse_x = ax;
    mouse_y = ay;
}


int main(int argc, char **argv)
{
    //Randomly initialize board
    for(int x=0;x<X;x++)
        for(int y=0; y<Y;y++)
    {
        p[x][y].alive = rand()%2; //Randomly set alive or dead
        p[x][y].next=0; //Initialize next state
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutCreateWindow("Game of life");
    init();
    glutDisplayFunc(display);
    timer();
    glutMouseFunc(mouse); //Get mouse coordinates
    glutMotionFunc(motion); //Get moving mouse coordinates
    glutMainLoop();

}
