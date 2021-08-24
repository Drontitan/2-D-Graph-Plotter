#include <GL/gl.h>
#include <glut.c>
#include <math.h>
#include <stdio.h>

int xo, yo, r;

// Function to display the circle using
// the above algorithm
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Color of printing object
    glColor3f(1, 0, 0);

    // Giving the size of the point
    glPointSize(2);

    int x = 0;
    int y = r;
    float p = 5 / 4 - r;

    glColor3f(1, 0, 0);

    // Starting of drawing the circle
    glBegin(GL_POINTS);

    while (y > x)
    {
        if (p < 0)
        {

            // Increment x to x+1
            x++;
            p = p + 2 * x + 1;
        }
        else
        {

            // Increment x to x+1
            // and decrease y to y-1
            y--;
            x++;
            p = p + 2 * (x - y) + 1;
        }

        // Draw the coordinates
        glVertex2d(x + xo, y + yo);
        glVertex2d(-x + xo, y + yo);
        glVertex2d(x + xo, -y + yo);
        glVertex2d(-x + xo, -y + yo);
        glVertex2d(y + yo, x + xo);
        glVertex2d(-y + yo, x + xo);
        glVertex2d(y + yo, -x + xo);
        glVertex2d(-y + yo, -x + xo);
    }

    glEnd();

    // Its empties all the buffer
    // causing the issue
    glFlush();
}

// Driver Code
int main(int argc, char **argv)
{
    printf("X-coordinate Y-coordinate radius:");
    scanf("%d %d %d", &xo, &yo, &r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Assigning the size of window
    glutInitWindowSize(1000, 1000);

    // Assign the position of window
    // to be appeared
    glutInitWindowPosition(100, 100);

    // Defining the heading of the window
    glutCreateWindow("GeeksforGeeks");

    // Backgronnd Color
    glClearColor(1, 1, 1, 1);

    // limit of the coordinate points
    gluOrtho2D(-500, 500, -500, 500);

    // Calling the function
    glutDisplayFunc(Display);

    glutMainLoop();

    return 0;
}