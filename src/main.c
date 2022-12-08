#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int board[3][3];	// board for gameplay
int turn;			// current move
int result;			// Result of the game
bool over; 		// Is the game Over?

/*
	Sets the board for Tic Tac Toe
*/
void intialize()
{
    turn=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            board[i][j]=0;
    }
}


/*
	Called when Mouse is clicked
*/
void onMouseClick(int button,int state,int x,int y)
{
    if(over==false && button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        if(turn==1)
        {
            if(board[(y-50)/100][x/100]==0)
            {
                board[(y-50)/100][x/100]=1;
                turn=2;
            }
        }
        else if(turn==2)
        {
            if(board[(y-50)/100][x/100]==0)
            {
                board[(y-50)/100][x/100]=2;
                turn=1;
            }
        }
    }
}

/*
	Utility function to draw string
*/
void DrawString(void *font,const char s[],float x,float y)
{
    unsigned int i;
    glRasterPos2f(x,y);
    for(i=0;i<strlen(s);i++)
    {
        glutBitmapCharacter(font,s[i]);
    }
}



/*
	Function to draw up the horizontal and vertical lines
*/
void drawLines()
{
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(100,50);
    glVertex2f(100,340);
    glVertex2f(200,340);
    glVertex2f(200,50);

    glVertex2f(0,150);
    glVertex2f(300,150);
    glVertex2f(0,250);
    glVertex2f(300,250);
    glEnd();
}

/*
	Utility function to draw the circle
*/
void drawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * i / num_segments;//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

/*
	Function to draw the cross and circle of Tic Tac Toe
*/
void DrawXO()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==1)
            {
                glBegin(GL_LINES);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
                glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
                glEnd();
            }
            else if(board[i][j]==2)
            {

                drawCircle(50 + j*100 , 100 + i*100 , 25 , 15);
            }
        }
    }
}
/*
	Function to display up everything
*/
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    if(turn == 1)
        DrawString(GLUT_BITMAP_HELVETICA_18, "Player1's turn", 100, 30);
    else
        DrawString(GLUT_BITMAP_HELVETICA_18, "Player2's turn", 100, 30);
    drawLines();
    DrawXO();
    glutSwapBuffers();
}

/*
	Function to reshape
*/
void Reshape(int x, int y)
{
    glViewport(0, 0, x, y);
    glLoadIdentity();
    glOrtho(0, x, y, 0, 0, 1);
}

/*
	Driver Function
*/
int main(int argc, char **argv)
{
    intialize();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(550,200);
    glutInitWindowSize(300,350);
    glutCreateWindow("Tic Tac Toe");
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutMouseFunc(onMouseClick);
    glutIdleFunc(Display);
    glutMainLoop();
    return 0;
}