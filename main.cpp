#include<windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdlib.h>q
#include <stdio.h>
#include <math.h>
#define PI 3.1416

int a = 50, b = 40, c = 47;


double rotAngle = 0;
bool reverseColors = false;
bool birdfly = false;

GLfloat m1 = 0.0, m2=-30.0, m3=-10.0, m0=-24.0, m4=0.0, m5=0.0, k6=0.0;

GLint i;
GLfloat cx=0,str=500.0,mn=500.0;
GLfloat dx=0.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
    glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

// cloud, sun..........
GLvoid drawCircle(GLdouble rad)
{
	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;
GLint i=0;
	glBegin(GL_POLYGON);
	{
		for(i = 0; i <=50; i++, theta += delTheta )
		{
			glVertex2f(rad * cos(theta),rad * sin(theta));
		}
	}
	glEnd();
}

// sky start
void sky()
{

	glBegin(GL_POLYGON); //sky
      glVertex3f (50, 10, 0);
      glVertex3f (50, 50, 0);
      glVertex3f (-50, 50, 0);
      glVertex3f (-50, 10, 0);
	glEnd();

}
// sky end

//man start
void man()
{
    int l;
    glColor3f (0.561, 0.737, 0.561);
	  glBegin(GL_POLYGON);
      glVertex3f (880-i,330,0);
      glVertex3f (910.5-i,330,0);
      glVertex3f (910.5-i,287.5,0);
      glVertex3f (880-i,287.5,0);
	  glEnd();
	//right leg
	  glColor3f (0.0, 0.0, 0.0);
	  glBegin(GL_POLYGON);
      glVertex3f (880-i,287.5,0);
      glVertex3f (890.5-i,287.5,0);
      glVertex3f (890.5-i,257.5,0);
      glVertex3f (880-i,257.5,0);
	  glEnd();
	//left leg
	  glColor3f (0.0, 0.0, 0.0);
	  glBegin(GL_POLYGON);
      glVertex3f (900-i,287.5,0);
      glVertex3f (910.5-i,287.5,0);
      glVertex3f (910.5-i,257.5,0);
      glVertex3f (900-i,257.5,0);
	  glEnd();
	//head
	for(l=0;l<15;l++)
   {
	glColor3f(1.0,0.5,0.5);
	draw_circle(895-i,340,l);

   }
   //left eye
   for(l=0;l<2;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(890-i,345,l);

   }
   //right eye
    for(l=0;l<2;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(900-i,345,l);
   }
   //lip
   for(l=0;l<4;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(895-i,335,l);

   }
//right hand
glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(850-i,320);
glVertex2f(880-i,320);
glVertex2f(880-i,330);
glVertex2f(850-i,330);
glEnd();
//left hand
glColor3f(0.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2f(910-i,320);
glVertex2f(940-i,320);
glVertex2f(940-i,330);
glVertex2f(910-i,330);
glEnd();
}

//man end

//dview start  durer tree
void dview()
{
	glColor3f(0.2, 0.4, 0.2);
    glPushMatrix();
    glTranslatef(-40,30,0);
    glScalef(0.31,0.95,0);
    drawCircle(5.5);
    glPopMatrix();
}
//dview end

//ground start
void ground()
{
    glBegin(GL_POLYGON); //ground
    glVertex3f (50, 10, 0);
    glVertex3f (-50, 10, 0);
    glVertex3f (-50, -30, 0);
    glVertex3f (50, -30, 0);
	glEnd();
}
// ground end

// h.b start gorer sather gula
 void ati()
 {
    glColor3f(0.6, 0.4, 0.0);
	glBegin(GL_POLYGON); //h.b
	glVertex3f (-6 , -2, 0.0);
    glVertex3f (-5 , 0, 0.0);
    glVertex3f (-3.5, 4, 0.0);
    glVertex3f (-3, 6, 0.0);
	glVertex3f (-3.5 , 8.5, 0.0);
	glVertex3f (-4, 11, 0.0);
	glVertex3f (-5, 13, 0.0);
	glVertex3f (-7 , 15, 0.0);
	glVertex3f (-9, 16, 0.0);
	glVertex3f (-11 , 15, 0.0);
	glVertex3f (-13, 13, 0.0);
	glVertex3f (-14, 11, 0.0);
	glVertex3f (-14.5 , 8.5, 0.0);
	glVertex3f (-15, 6, 0.0);
	glVertex3f (-14.5, 4, 0.0);
	glVertex3f (-13, 0, 0.0);
	glVertex3f (-12 , -2, 0.0);
	glEnd();
 }
 // h.b end

 // Ft ree start

void tree2()
{

    glColor3f(0, .9, 0); //tree ar guri
	glPushMatrix();
	glTranslatef(2,-30,0);
	glColor3f(.3, 0, 0);
	glBegin(GL_POLYGON);

	glVertex3f(-.5,0, 0);
    glVertex3f(.5, 0, 0);
    glVertex3f(.5,-10, 0);
	glVertex3f(-.5,-10, 0);

	glEnd();
	glPopMatrix();
	glColor3f(0, .9, 0); //head of the tree
	glPushMatrix();
	glTranslatef(5,-29,0);
	drawCircle(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1,-29,0);
	drawCircle(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2,-31,0);
	drawCircle(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(2,-27.4,0);
	drawCircle(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5,-32,0);
	drawCircle(2);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1,-32,0);
	drawCircle(2);
	glPopMatrix();
}
 // Ftree end

// river start
void water()
{
    glColor3f(0.0,0.0,1);
    glTranslatef(-40,-40,0.0);
    glTranslatef(0,0.0,0.0);
    //glColor3f(0.0,0.0,1);
    glLineWidth(1.5);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(1.5);
    glRotatef(0,0,0,0);
	glBegin(GL_LINE_STRIP);
    for(int i=-50;i<=10;i++){
        for(int j=-100;j<=100;j+=3){
            glVertex2d(j,i);
            glVertex2d(j+1,i);
        }
    }

    glEnd();
}

// river end

//Code for Boat
void ship(GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B){
    glPushMatrix();
    {

    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    glVertex2f(-12+x,y+0);
    glVertex2f(20+x,y+0);
    glVertex2f(15+x,y-10);

    glVertex2f(x-8,y-10);
    glEnd();
    }glPopMatrix();

    //Man code
    glColor3f(0.0, 0.0, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(-12+x, y+0);
    glVertex2i(-12+x+2,y+0);
    glVertex2i(-12+x+2, y+1);
    glVertex2i(-12+x, y+1);
    glEnd();

    for(i=0;i<1;i++)
        {
            glColor3f(0.0,0.0,0.0);
            draw_circle(-12+x-i,y+2,0);
        }

}
//boat end




// cloud start
void cloud()
{

glPushMatrix(); // 1st cloud start
glTranslatef(-40,40,0);
glScalef(0.95,0.75,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-40,30,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-44,44,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-44,39,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();  // 1st cloud end


glPushMatrix(); //2nd cloud start
glTranslatef(-29,40,0);
glScalef(0.95,0.75,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-29,44,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-32,44,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-26,44,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-24,40,0);
glScalef(0.45,0.65,0);
drawCircle(5.5);
glPopMatrix(); //2nd cloud end
}

// cloud end

// sun start
void sun()
{
	glPushMatrix();
drawCircle(4.5);

	glPopMatrix();

}
// sun end

// house start
void house()
{

	glColor3f (1.0, 0.6, 0.2);



	glBegin(GL_POLYGON); //house
      glVertex3f (-8, 4, 0);
      glVertex3f (-14, 6, 0);
      glVertex3f (-14, 12, 0);
      glVertex3f (-12, 22, 0);
	  glVertex3f (-8, 12, 0);

	glEnd();
	glColor3f (0.4, 0.4, 0.4);



	glBegin(GL_POLYGON);
      glVertex3f (-8, 4, 0);
      glVertex3f (-14, 6, 0);
      glVertex3f (-15.5, 4.93, 0);
      glVertex3f (-8, 2, 0);

	glEnd();

		glColor3f (0.4, 0, 0.0);



	glBegin(GL_POLYGON);
      glVertex3f (-14, 12, 0);
      glVertex3f (-12, 22, 0);
	   glVertex3f (-13, 24, 0);
	    glVertex3f (-16, 12, 0);

	glEnd();

		glColor3f (0.6, 0, 0.0);



	glBegin(GL_POLYGON);
	   glVertex3f (-13, 24, 0);
	    glVertex3f (-8, 12, 0);
		glVertex3f (2, 12, 0);
		glVertex3f (-3, 24, 0);

	glEnd();

glColor3f (1.0, 0.8, 0.2);



	glBegin(GL_POLYGON);
	    glVertex3f (-8, 12, 0);
		glVertex3f (2, 12, 0);
		glVertex3f (2, 8, 0);
		glVertex3f (-8, 4, 0);

	glEnd();

	glColor3f (0.4, 0.4, 0.0);



	glBegin(GL_POLYGON);
		glVertex3f (2, 8, 0);
		glVertex3f (-8, 4, 0);
	    glVertex3f (-8, 2, 0);
	    glVertex3f (3, 7.4, 0);

	glEnd();

	glColor3f (1.0, 1, 1.0);



	glBegin(GL_POLYGON);
		glVertex3f (-12, 12, 0);
		glVertex3f (-10, 12, 0);
	    glVertex3f (-10, 4.5, 0);
	    glVertex3f (-12, 5, 0);

	glEnd();


}
//house end

// tree start

void head2()
{

glColor3f(0, 0, 0.0);

	glPushMatrix();



drawCircle(4.5);

	glPopMatrix();

}

void leaf()
{
	glColor3f(0.2, 0.6, 0.0);

glPushMatrix(); //movement
glTranslatef(-40,40,0);
glScalef(2.35,1.65,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-37,34,0);
glScalef(0.45,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-33,36,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-30,38,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-30,44,0);
glScalef(0.65,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-33,50,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-38,50,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-43.1,51,0);
glScalef(0.45,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-48,48,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glPushMatrix();
glTranslatef(-52,49,0);
glScalef(0.55,0.95,0);
drawCircle(5.5);
glPopMatrix();

glTranslatef(-52,42,0);
glScalef(1.05,0.95,0);
drawCircle(5.5);
glPopMatrix();


}
void polygon()
{

	//front door
		glColor3f(1,1,.7);
		glBegin(GL_POLYGON);

       glVertex3f(6,0,0);
	   glVertex3f(40,0,0);
	   glVertex3f(40,-30,0);
	   glColor3f(0,1,.7);
	   glVertex3f(5,-30,0);

	   	glEnd();
}

void tree()
{

}



void head()
{
glColor3f(0.1,0.0,0.1);
glPushMatrix();
glTranslatef(14,-4.5,0);
drawCircle(1.8);
glPopMatrix();

}
// tree end
// grass start
void grass()
{




}
// grass end

	void stick()
{



}

	void box()
{
	}
	void rope2()
{

	glColor3f(0.4, 0.2, 0.2);

	glBegin(GL_POLYGON);

      glVertex3f (1.4 , 4, 0.0);
	  glVertex3f (1.1 , 0, 0.0);
	  glVertex3f (1, 0, 0.0);
	  glVertex3f (0.8, 4, 0.0);

glEnd();

glBegin(GL_LINES);
      glVertex3f (1 , 2, 0.0);
      glVertex3f (6, 3, 0.0);
	glEnd();
	}

	//bird start

	void bird()
{

	glColor3f(0.6, 0.2, 0.0);

	glBegin(GL_POLYGON);

      glVertex3f (0 , 0, 0.0);
	  glVertex3f (2.5 , 0, 0.0);
	  glVertex3f (5.2, 4.2, 0.0);
	  glVertex3f (1, 2, 0.0);

	glEnd();

glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex3f (4 , 0, 0.0);
	  glVertex3f (2.4 , 0, 0.0);
	  glVertex3f (3.4, 1.5, 0.0);
	  glVertex3f (6.8, 1.5, 0.0);

	glEnd();


glColor3f(0.2, 0.2, 0.0);
	glBegin(GL_POLYGON);

      glVertex3f (4 , 0, 0.0);
	  glVertex3f (5.5 , -1, 0.0);
	  glVertex3f (-0.2, -0.8, 0.0);
	  glVertex3f (0, 0, 0.0);

	glEnd();


glColor3f(0.8, 0.4, 0.0);
	glBegin(GL_POLYGON);
	  glVertex3f (-0.2, -0.8, 0.0);
	  glVertex3f (0, 0, 0.0);
	   glVertex3f (-1 , 1, 0.0);
	  glVertex3f (-2 , 0, 0.0);
	glEnd();


}  //bird end

GLfloat shipX = -35;
GLfloat shipx = -35;
GLfloat shipZ = -35;
GLfloat shipY = 0;

void display(void)
{

glClear(GL_COLOR_BUFFER_BIT);

glPushMatrix();              // sky start
glRotated(rotAngle, 0, 1, 0);
if (reverseColors)

   glColor3f(0.2, 0.0, 0.6);

else

   glColor3f(0.2, 0.4, 1.0);


sky();


glPopMatrix();               // sky end

	glPushMatrix();         //dview start
  glTranslatef(74,-29.5,0);

  glScalef(0.65,0.95,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(86,-35,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(69,-35,0);
  glScalef(0.65,0.95,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(67,-36,0);
  glScalef(0.65,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(78,-34,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(61,-35.5,0);
  glScalef(0.65,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(70,-26,0);
  glScalef(0.95,0.80,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(92,-22,0);
  glScalef(1.65,0.70,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(50,-34,0);
  glScalef(0.60,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(58,-26,0);
  glScalef(0.95,0.80,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(43,-34,0);
  glScalef(0.65,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(44,-36,0);
  glScalef(0.75,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(44,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(42,-38,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(39,-35,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(36,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(34,-38,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(32,-37,0);
  glScalef(0.81,1.00,0);
  dview();

  glPopMatrix();
  glPushMatrix();
  glTranslatef(29,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(22,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(20,-38,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(6,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-8,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-10.2,-38,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-15,-37,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-17,-38,0);
  glScalef(0.81,1.00,0);
  dview();
  glPopMatrix();          // dview end

 glPushMatrix();          // ground start
glRotated(rotAngle, 1, 1, 0);
if (reverseColors)

   glColor3f(0.0, 0.2, 0.0);

else

  glColor3f(0.2, 0.6, 0.0);


ground();
  glPopMatrix();        // ground end

glPushMatrix();       // river start
glRotated(rotAngle, 0, 1, 0);
if (reverseColors)

   glColor3f(0.0, 0.0, 1);

else

   glColor3f(0.01, 0.15, 1.0);

    water();
  glPopMatrix();         //  river end

  glPushMatrix();	     // h.b start
  glTranslatef(-6,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  glPushMatrix();	     // ati start
  glTranslatef(-3,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  glPushMatrix();	     // ati start
  glTranslatef(-12,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  glPushMatrix();	     // ati start
  glTranslatef(-23,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  glPushMatrix();	     // ati start
  glTranslatef(-26,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  glPushMatrix();	     // ati start
  glTranslatef(-36,10,0);
  glScalef(0.33,.55,0);
  ati();
  glPopMatrix();

  // h.b end

 glPushMatrix();       // btree start
  glScalef(0.80,1.05,0);
  glTranslatef(-9.5,25,0);
  glRotatef(m4, 0, m4, 0);
  tree2();
  glPopMatrix();

 glPushMatrix();       // btree start
  glScalef(0.80,1.05,0);
  glTranslatef(7.5,44,0);
  glRotatef(m4, 0, m4, 0);
  tree2();
  glPopMatrix();

   glPushMatrix();       // btree start
  glScalef(0.80,1.05,0);
  glTranslatef(-47.5,15,0);
  glRotatef(m4, 0, m4, 0);
  tree2();
  glPopMatrix();


  glPushMatrix();     // house start
  glTranslatef(-34,6,0);
  glScalef(.3,.5,0);
  house();

  glPopMatrix();        // house end
glPushMatrix();     // house start
  glTranslatef(-30,6,0);
  glScalef(.3,.5,0);
  house();
glPopMatrix();
  glPushMatrix();     // house start
  glTranslatef(-10,6,0);
  glScalef(.3,.5,0);
  house();

  glPopMatrix();

  glPushMatrix();     // house start
  glTranslatef(-15,6,0);
  glScalef(.3,.5,0);
  house();

  glPopMatrix();

  glPushMatrix();     // house start
  glTranslatef(-20,6,0);
  glScalef(.3,.5,0);
  house();

  glPopMatrix();

  // house end

  glPopMatrix();        // house end

  glPushMatrix();       // sun start
  glRotated(rotAngle, 0, 1, 0);
if (reverseColors)

   glColor3f(1.0, 1.0, 1.0);

else

   glColor3f(1, 1, 0.0);
  glTranslatef(2,37,0);
  glScalef(0.55,1.05,0);
  sun();
  glPopMatrix();        // sun end

  glPushMatrix();       // cloud start
  glRotated(rotAngle, 0, 1, 0);
if (reverseColors)

   glColor3f(0.8, 0.8, 1.0);

else

   glColor3f(1.0, 1.0, 1.0);
  glTranslatef(m1,0,0);
  cloud();
  glPopMatrix();

    glPushMatrix();       // cloud start
  glRotated(rotAngle, 0, 1, 0);
if (reverseColors)

   glColor3f(0.8, 0.8, 1.0);

else

   glColor3f(1.0, 1.0, 1.0);
  glTranslatef(-m1,0,0);
  cloud();
  glPopMatrix();

//cloud end

	glPushMatrix(); //tree start
	glTranslatef(5, 0, 0);
	glScalef(0.55,0.65,0);
	tree();
    glPopMatrix();     //tree end

    glPushMatrix();
    glTranslatef(40, 35, 0);
    glScalef(0.5, 0.5, 0);
    man();
    glPopMatrix();

	glPushMatrix();            //grass start
    glTranslatef(2.2, 2.7, 0);
    grass();
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-0.4, -3.2, 0);
	glScalef(0.75,0.75,0);
    grass();
    glPopMatrix();

  //grass end

glPushMatrix();   // stick start
   glTranslatef(-40,-30.5,0);
  stick();
  glPopMatrix();     // stick end

  glPushMatrix(); //box start
glTranslatef(-44,-34,0);
box();
glPopMatrix();   //box end




glPushMatrix();   // bird start
glScalef(0.50, 0.75, 0.0);
glTranslatef(105.0,a,0);
if (birdfly)
glTranslatef(k6,0.0,0);
else
glTranslatef(0.0,0,0);
bird();
glPopMatrix();   // bird end

glPushMatrix();   // bird2 start
glScalef(0.50, 0.75, 0.0);
glTranslatef(110.0,b,0);
if (birdfly)
glTranslatef(k6,0.0,0);
else
glTranslatef(0.0,0,0);
bird();
glPopMatrix();   // bird2 end

glPushMatrix();   // bird3 start
glScalef(0.50, 0.75, 0.0);
glTranslatef(115.0,c,0);
if (birdfly)
glTranslatef(k6,0.0,0);
else
glTranslatef(0.0,0,0);
bird();
glPopMatrix(); // bird3 end

//scarecrow start from here

glPushMatrix();
glScalef(0.05, 0.1, 0.0);
glTranslatef(-1300,-300,0);
man();
glPopMatrix();

 //river and boat
	glFlush();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(dx,0.0,0.0);
	water();
	glPopMatrix();

    glFlush();
    ship(shipX, -20, 1, 0, 1);
    ship(shipx, -24, 0, 1, 1);
    ship(shipZ, -28, 1, 1, 0);

glutSwapBuffers();
}

void spinDisplay(void)
{

		m1 += 0.0070;  //sky
	if(m1 >= 97.0)
		m1 = -29.0;



 m4 += 15.0250;   // btree
	if(m4 >= 25.0)
	  m4 = 0;
	glutPostRedisplay();
/*
	m5 += 0.1050;   // man head
	if(m5 >= 45.0)
	  m5 = 0;*/
	glutPostRedisplay();

}

void spinDisplay2(void)
{


		m1 += 0.0070;  //sky
	if(m1 >= 97.0)
		m1 = -29.0;

	/*m2 += 0.0150;   //fish start
	if(m2 >= 90.0)
		m2 = -29.0;
	m3 += 0.0250;
	if(m3 >= 400.0)
		m3 = -0.0;
	m0 += 0.0250;
	if(m0 >= 190.0)
		m0 = -29.0;  //fish end*/

 m4 += 0.0250;   // btree
	if(m4 >= 25.0)
	  m4 = 0;
	glutPostRedisplay();

	m5 += 0.1050;   // man head
	if(m5 >= 45.0)
	  m5 = 0;

		k6 -= .1;  //bird
	if(k6 <= -230.0)
		k6 = 0.0;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
   switch (button)
   {
      case GLUT_LEFT_BUTTON:

         if (state == GLUT_DOWN)
			 glutIdleFunc(spinDisplay);
         break;

      case GLUT_MIDDLE_BUTTON:

      case GLUT_RIGHT_BUTTON:

         if (state == GLUT_DOWN)
			 glutIdleFunc(NULL);
         break;

      default:

         break;
   }
}




void keyboard(unsigned char k, int x, int y)

{
	switch (k)

  {

  case 'u':

        a++,b++,c++;

        break;

    case 'd':

        a--,b--,c--;

        break;

  case 'n':

        reverseColors = !reverseColors;

        break;

   case 'q':

        exit(0);

		case 'b':

        birdfly = !birdfly;
			 glutIdleFunc(spinDisplay2);

        break;


   case 's':

		glutIdleFunc(NULL);
			 glutIdleFunc(NULL);
			 break;

			  default:
break;

}


glutPostRedisplay();

}



void init(void)
{

	glClearColor (1.0, 1.0, 1.0, 1.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void timer(int){
    glutPostRedisplay();

    cx = cx - .05;
    if(cx<-10)
    {
        cx = 0;
    }

    /// Ship Animation Logic
    if(shipX<18){
        shipX+=0.05;
        shipx+=0.07;
        shipZ+=0.09;
    }
    glutTimerFunc(25, timer, 0);
}

int main()

{

printf("\n\t\tPress mouse right button to rotate and left button to stop.\n\t\t Press n : for night/ day\n\t\t press q : for quit.\n\t\t press b : for bird fly\n\t\t press u for birds up and press d for birds down\n");
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

glutInitWindowSize (1396, 768);
  glutInitWindowPosition (0, 0);

  glutCreateWindow(" SCARECROW ");
  glutTimerFunc(100, timer, 0);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();

  return 0;

}
