#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
static int spin = 0;
void init()
{
    //glClearColor(0,0.6,1,0);
    glClearColor(0.68,0.8437,0.98,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //gluLookAt(0,0,0,1,1,1,1,1,1);

   GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat position[] = {5.0, 5.0, 8, 1.0 }; //If w is 1.0, we are defining a light at a point in space.  If w is 0.0, the light is at infinity.
   GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat local_view[] = { 0.0 };
   //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   //glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   //glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   //glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   //glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
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
   glOrtho(-5,5,-5,5,0,5);
   //glOrtho(-5,5,-5,5);
    //gluPerspective(1,2,-5,5);
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity ();
}
void stem()
{
    glColor3f(0,0.8,0.1);
    glLineWidth(4);
    glBegin(GL_LINES);
    glPushMatrix();
    glVertex3f(0,0,0);
    glVertex3f(0,-2.5,0);

    glPopMatrix();
    glEnd();
}
void flower_center()
{
      glColor3f(0.9,1,0.9);
    glBegin(GL_TRIANGLES);
        glVertex3f(-0.5,0,0);
        glVertex3f(0.5,0,0);
        glVertex3f(0,0.5,0);
        glColor3f(0.9,1,0.7);
        glVertex3f(0.25,0,0);
        glVertex3f(-0.25,0,0);
        glVertex3f(0,-0.25,0);
    glEnd();
}
void petal()

{

    glBegin(GL_POLYGON);
    glColor3f(0.8,0.8,1);
    glVertex3f(0,1.5,0);
    glVertex3f(0,0.5,0);
    glVertex3f(0.5,0,0);
    glVertex3f(1.5,0,0);

    glColor3f(0.8,0.4,1);
    glVertex3f(2.5,1,0);
    glVertex3f(2.5,2.5,0);
    glVertex3f(1,2.5,0);
    glVertex3f(0,1.5,0);
    //glVertex2f(0,0.5);
    glEnd();
}
void petal_small()
{
    glBegin(GL_POLYGON);

    glColor3f(0.5,0.2,0.7);
    glVertex3f(0,1.5,1);
    glVertex3f(0,0.5,1);
    glVertex3f(0.5,0,1);
    glVertex3f(1.5,0,1);
    glColor3f(0.7,0.7,1);
    glVertex3f(2.5,1,1);
    glVertex3f(2.5,2.5,1);
    glVertex3f(1,2.5,1);

    //glVertex2f(0,0.5);
    glEnd();
}
void flower()
{

    flower_center();

    glPushMatrix();
    glScaled(0.6,0.6,0);
    glTranslatef(0.2,0.2,0);
    petal_small();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,0,0);
    glScaled(0.6,0.6,0);
    glTranslatef(0.2,0.2,0);
    petal_small();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glTranslatef(0,0,0);
    petal();
    glPopMatrix();

    petal();
    stem();
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
    glVertex3f(0.5,-2.2,0);
    //glVertex2f(1,-2.5);
    glColor3f(0,0.4,0);
    glVertex3f(1.5,-2,0);
    glVertex3f(1.5,-1.45,0);
    glVertex3f(1,-1.45,0);
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
void display()
{

    GLfloat position[] = { 0, 5, 0, 1.0 };
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
/*
    glPushMatrix ();
   glRotated ((GLdouble) spin, 0.0, 1.0, 1.0);
   glLightfv (GL_LIGHT0, GL_POSITION, position);

   glTranslated (0.0, 0.0, 1.5);
   glDisable (GL_LIGHTING);
   glColor3f (0.0, 1.0, 1.0);
   glutWireCube (0.1);
   glEnable (GL_LIGHTING);
   glPopMatrix ();
   */

    GLfloat mat[] = {0.1,0.1,0.1,0};
    GLfloat mat2[] = {1,1,1,0};
    glPushMatrix();
    GLfloat mat_shiny1 [] = {0.5,0,0.1,0};
    //glMaterialfv(GL_FRONT, GL_SHININESS, mat2);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, mat2);
    glMaterialfv(GL_FRONT, GL_SPECULAR,mat_shiny1);
    glTranslatef(2.5,0,-1);
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
    glPopMatrix();

    glPushMatrix();
    GLfloat mat_shiny2 [] = {0.1,0,0.4,0};
    //glMaterialfv(GL_FRONT, GL_SHININESS, mat2);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, mat2);
    glMaterialfv(GL_FRONT, GL_SPECULAR,mat_shiny2);
      glTranslatef(-2.5,0,-1);
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

    glPopMatrix();

        glPushMatrix();
    GLfloat mat_shiny3 [] = {0.2,0.5,0.2,0};
    //glMaterialfv(GL_FRONT, GL_SHININESS, mat2);
    //glMaterialfv(GL_FRONT, GL_AMBIENT, mat2);
    glMaterialfv(GL_FRONT, GL_SPECULAR,mat_shiny3);
      glTranslatef(0,1,-2);
      glScalef(0.8,0.8,0.8);
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

    glPopMatrix();

/*
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
    */
    glBegin(GL_QUADS);
    //glColor3f(0,0.5,0.5);
    glColor3f(0.75,0.66,0.512);
    glVertex3f(-5,-2.6,0);
    glVertex3f(5,-2.6,0);
    glColor3f(0,0.9,0.4);
    glVertex3f(5,-5,0);
    glVertex3f(-5,-5,0);
    glEnd();
    glFlush();
    //glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN) {
            spin = (spin + 30) % 360;
            glutPostRedisplay();
         }
         break;
      default:
         break;
   }
}


int main(int argc , char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("plant3d");
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshapegl);
    glutMouseFunc(mouse);
    //glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
