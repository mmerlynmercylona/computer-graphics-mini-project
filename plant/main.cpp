#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

void init()
{
    glClearColor(1,1,1,0);
    //glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
         2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-2.5*(GLfloat)w/(GLfloat)h,
         2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
}

void reshapegl(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-5,5,-5,5);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
}
void stem()
{
    glColor3f(0,0.8,0.1);
    glLineWidth(4);
    glBegin(GL_LINES);
    glPushMatrix();
    glVertex2f(0,0);
    glVertex2f(0,-2.5);

    glPopMatrix();
    glEnd();
}
void flower_center()
{
      glColor3f(0.9,1,0.9);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5,0);
        glVertex2f(0.5,0);
        glVertex2f(0,0.5);
        glColor3f(0.9,1,0.7);
        glVertex2f(0.25,0);
        glVertex2f(-0.25,0);
        glVertex2f(0,-0.25);
    glEnd();
}
void petal()
{
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,1);
    glVertex2f(0,1.5);
    glVertex2f(0,0.5);
    glVertex2f(0.5,0);
    glVertex2f(1.5,0);

    glColor3f(0.8,0.4,1);
    glVertex2f(2.5,1);
    glVertex2f(2.5,2.5);
    glVertex2f(1,2.5);
    glVertex2f(0,1.5);
    //glVertex2f(0,0.5);
    glEnd();
}
void petal_small()
{
    glBegin(GL_POLYGON);

    glColor3f(0.5,0.2,0.7);
    glVertex2f(0,1.5);
    glVertex2f(0,0.5);
    glVertex2f(0.5,0);
    glVertex2f(1.5,0);
    glColor3f(0.7,0.7,1);
    glVertex2f(2.5,1);
    glVertex2f(2.5,2.5);
    glVertex2f(1,2.5);

    //glVertex2f(0,0.5);
    glEnd();
}
void flower()
{
    stem();
    flower_center();
    petal();
    glPushMatrix();
    glScaled(0.6,0.6,0);
    glTranslatef(0.2,0.2,0);
    petal_small();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,0,0);
    petal();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,0,0);
    glScaled(0.6,0.6,0);
    glTranslatef(0.2,0.2,0);
    petal_small();

    glPopMatrix();

}
void leaf()
{
    glBegin(GL_LINES);
        glColor3f(0,0.8,0);
    glLineWidth(2);
    glVertex2f(0,-2.5);
    glVertex2f(1.5,-1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,0.8,0);
    //glVertex2f(0.5,-2);
    glVertex2f(0.5,-2.2);
    //glVertex2f(1,-2.5);
    glColor3f(0,0.4,0);
    glVertex2f(1.5,-2);
    glVertex2f(1.5,-1.45);
    glVertex2f(1,-1.45);
    glEnd();
}
void flower_pair()
{
    glPushMatrix();
    glTranslatef(-0.75,0,0);
    glRotatef(45,0,0,1);
    glScalef(0.4,0.4,0);
    flower();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.75,0,0);
    glRotatef(-45,0,0,1);
    glScalef(0.4,0.4,0);
    flower();
    glPopMatrix();
}
void inflorence()
{
    flower_pair();
    glPushMatrix();
    glTranslatef(0,2,0);
    flower_pair();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-2,0);
    flower_pair();
    glPopMatrix();
    glBegin(GL_LINES);
    glColor3f(0,0.8,0.1);
    glLineWidth(5);
    glVertex2f(0,1.34);
    glVertex2f(0,-2.75);
    glEnd();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);


    //stem();
    //flower();
    //leaf();
    inflorence();


    //glBegin(GL_LINES);

    //glEnd();




    glFlush();
    //glutSwapBuffers();
}


int main(int argc , char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("plant");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshapegl);
    //glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
