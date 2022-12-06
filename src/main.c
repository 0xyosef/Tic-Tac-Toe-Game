#include <GL/glut.h>

void drawLine(){
    glBegin(GL_LINES);//draw line
    glColor3f(0, 0, 0);
    glVertex2f(100,50);
    glVertex2f(100,340);

    glVertex2f(200,340);
    glVertex2f(200,50);

    glVertex2f(0,150);
    glVertex2f(300,150);

    glVertex2f(0,250);
    glVertex2f(300,250);
    glEnd();
    //to show draw
    glFlush();

}
void display(){
    //set clear
    glClearColor(1, 1, 1, 0);
    //clear buffer color
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine();
}

int main(int argc, char* argv[])
{
    glutInit(&argc,argv);
    glutInitWindowPosition(550,200);
    glutInitWindowSize(300,350);
    glutCreateWindow("Tic Tac Toe");
    glutDisplayFunc(display);
    gluOrtho2D(0,300,0,350);
    glutMainLoop();
    return 0;
}
