#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

static int animationPeriod = 4;
static int isAnimate = 0;

const int fact = 3;
const int x = 80;
const double DEG2RAD = 3.1415926535897932384/180;

static double w = 200;
static int flag = 0;
static int walk = 0;
static int x_ = 2500;
using namespace std;

void animate(int value){
    if(isAnimate){
        glutPostRedisplay();
        glutTimerFunc(animationPeriod, animate, 1);
    }
}

void keyInput(unsigned char key , int x, int y){
    switch(key){
    case 27:
        exit(0);
    case ' ':
        if(isAnimate) isAnimate = 0;
        else{
            isAnimate = 1;
            animate(1);
        }
        break;
    }
}
bool collision(double len){
    if(abs(157 + x - (x_ + x + 50)) <= 100 + x){
        if(5 * fact + w <= 650 * len)return 1;
        return 0;
    }
    return 0;
}

void specialKeyInput(int key , int x , int y ){
    if( key == GLUT_KEY_UP && flag==0 && w <= 200.0){
        flag  = 1;
    }
    glutPostRedisplay();
}

void draw_circle(double theta, double inner_radius, double outer_radius, int x, int y, int sin_sign = 1, int cos_sign = 1){
   glBegin(GL_POINTS);
   glColor3f(0.0/ 255.0, 0.0/ 255.0, 0.0/ 255.0);
   for(double r = outer_radius; r >= inner_radius; r -= 3.0){
        for(double i = 0; i < theta ; i++){
          double degInRad = i * DEG2RAD;
          glVertex2f( cos_sign * cos(degInRad) * r + x , sin_sign * sin(degInRad) * r + y  );
       }
   }
   glEnd();
}

void generate_tree(int x_, double len){
    int x = 30;
    glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
    glBegin(GL_POLYGON);
        glVertex2f(x_, 250 * len);
        glVertex2f(x_ + x, 250 * len);
        glVertex2f(x_ + x, 650 * len);
        glVertex2f(x_, 650 * len);
    glEnd();

    draw_circle(180.0, 0.0, x / 2, x_ + x / 2, 650 * len);

    glBegin(GL_POLYGON);
        glVertex2f(x_ + x + 25, 400 * len);
        glVertex2f(x_ + x + 50, 400 * len);
        glVertex2f(x_ + x + 50, 600 * len);
        glVertex2f(x_ + x + 25, 600 * len);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ + x + 75.0 / 2, 600 * len);

    glBegin(GL_POLYGON);
        glVertex2f(x_ - 25, 400 * len);
        glVertex2f(x_ - 50, 400 * len);
        glVertex2f(x_ - 50, 600 * len);
        glVertex2f(x_ - 25, 600 * len);
    glEnd();

    draw_circle(180.0, 0.0, 25.0 / 2, x_ - 75.0 / 2, 600 * len);
    draw_circle(90.0, 25, 50, x_ + x, 400 * len, -1);
    draw_circle(90.0, 25, 50, x_, 400 * len, -1, -1);
}

void reset(){
    w = 200;
    flag = 0;
    walk = 0;
    x_ = 2500;
    animationPeriod = 4;
    isAnimate = 0;
}
void render( void ){
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(2);
    glBegin(GL_POINTS);
        glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
        for(int i = 0; i < 100; i++){
            glVertex2f(rand() % 2000, 200);
            glVertex2f((rand() + 31) % 2000, 150);
        }
    glEnd();

    generate_tree(x_, 1.0);


    if(x_>= 0)
        x_ -= 5;
    else{
        x_ = 2000 + rand()%400;
    }
    glLineWidth(2);
    glBegin(GL_LINES);
        glColor3f((0) / 255.0, (0) / 255.0, (0) / 255.0);
        glVertex2f(0, 250);
        glVertex2f(2000, 250);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
        glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);

        glVertex2f(10 + x, 75 * fact + w);
        glVertex2f(10 + x, 45 * fact + w);
        glVertex2f(15 + x, 65 * fact + w);
        glVertex2f(15 + x, 40 * fact + w);
        glVertex2f(20 + x, 60 * fact + w);
        glVertex2f(20 + x, 35 * fact + w);
        glVertex2f(25 + x, 55 * fact + w);
        glVertex2f(25 + x, 35 * fact + w);
        glVertex2f(30 + x, 55 * fact + w);
        glVertex2f(30 + x, 35 * fact + w);
        glVertex2f(35 + x, 55 * fact + w);
        glVertex2f(35 + x, 25 * fact + w);
        glVertex2f(40 + x, 60 * fact + w);
        glVertex2f(40 + x, 5 * fact + w-walk);
        glVertex2f(45 + x, 65 * fact + w);
        glVertex2f(45 + x, 15 * fact + w);
        glVertex2f(45 + x, 10 * fact + w-walk);
        glVertex2f(45 + x, 5 * fact + w-walk);
        glVertex2f(50 + x, 10 * fact + w-walk);
        glVertex2f(50 + x, 5 * fact + w-walk);
        glVertex2f(55 + x, 10 * fact + w-walk);
        glVertex2f(55 + x, 5 * fact + w-walk);
        glVertex2f(50 + x, 65 * fact + w);
        glVertex2f(50 + x, 20 * fact + w);
        glVertex2f(55 + x, 70 * fact + w);
        glVertex2f(55 + x, 25 * fact + w);
        glVertex2f(63 + x, 75 * fact + w);
        glVertex2f(63 + x, 20 * fact + w);
        glVertex2f(70 + x, 115 * fact + w);
        glVertex2f(70 + x, 5 * fact + w+walk);
        glVertex2f(78 + x, 120 * fact + w);
        glVertex2f(78 + x, 25 * fact + w);
        glVertex2f(78 + x, 10 * fact + w+walk);
        glVertex2f(78 + x, 5 * fact + w+walk);
        glVertex2f(85 + x, 10 * fact + w+walk);
        glVertex2f(85 + x, 5 * fact + w+walk);
        glVertex2f(87 + x, 120 * fact + w);
        glVertex2f(87 + x, 115 * fact + w);
        glVertex2f(87 + x, 110 * fact + w);
        glVertex2f(87 + x, 30 * fact + w);
        glVertex2f(95 + x, 120 * fact + w);
        glVertex2f(95 + x, 35 * fact + w);
        glVertex2f(103 + x, 120 * fact + w);
        glVertex2f(103 + x, 75 * fact + w);
        glVertex2f(103 + x, 65 * fact + w);
        glVertex2f(103 + x, 60 * fact + w);
        glVertex2f(110 + x, 65 * fact + w);
        glVertex2f(110 + x, 60 * fact + w);
        glVertex2f(118 + x, 65 * fact + w);
        glVertex2f(118 + x, 55 * fact + w);
        glVertex2f(112 + x, 120 * fact + w);
        glVertex2f(112 + x, 85 * fact + w);
        glVertex2f(112 + x, 80 * fact + w);
        glVertex2f(112 + x, 75 * fact + w);
        glVertex2f(120 + x, 120 * fact + w);
        glVertex2f(120 + x, 85 * fact + w);
        glVertex2f(120 + x, 80 * fact + w);
        glVertex2f(120 + x, 75 * fact + w);
        glVertex2f(126 + x, 120 * fact + w);
        glVertex2f(126 + x, 85 * fact + w);
        glVertex2f(126 + x, 80 * fact + w);
        glVertex2f(126 + x, 75 * fact + w);
        glVertex2f(135 + x, 120 * fact + w);
        glVertex2f(135 + x, 85 * fact + w);
        glVertex2f(135 + x, 80 * fact + w);
        glVertex2f(135 + x, 75 * fact + w);
        glVertex2f(142 + x, 120 * fact + w);
        glVertex2f(142 + x, 85 * fact + w);
        glVertex2f(150 + x, 120 * fact + w);
        glVertex2f(150 + x, 85 * fact + w);
        glVertex2f(157 + x, 115 * fact + w);
        glVertex2f(157 + x, 85 * fact + w);

    glEnd();

    if(collision(1.0)){
        reset();
    }
    if( w <=200){
        if(walk==-20 )
            walk = 20;
        else{
            walk = -20;
        }
    }
    else{
        walk = 0;
    }

    if(flag==1){
        if(w<=1000 ){
            w = w + 8;
        }
        else {
            flag = 0;
        }
    }
    else if(w >= 200 )
        w = w - 8;
    glFlush();
}


void setup(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 2000, 0.0, 2000);
}

int main( int argc , char** argv ){
    srand(time(NULL));
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA );
    glutInitWindowSize( 1230, 650 );
    glutInitWindowPosition( 50 , 0 );
    glutCreateWindow("Dinosaur!!");
    setup();
    glutDisplayFunc(render);

    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);

    glutMainLoop();
}
