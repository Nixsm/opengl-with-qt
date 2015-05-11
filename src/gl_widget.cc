#include "include/gl_widget.h"
#include <cmath>

    void GLWidget::initializeGL(){
    	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glShadeModel(GL_SMOOTH);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    }
    
    void GLWidget::qgluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar){
        const GLdouble ymax = zNear * tan(fovy * M_PI / 360.0);
        const GLdouble ymin = -ymax;
        const GLdouble xmin = ymin * aspect;
        const GLdouble xmax = ymax * aspect;
        glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
    }
    
    void GLWidget::resizeGL(int width, int height){
    	if (height==0) height=1;
    	glViewport(0,0,width,height);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	qgluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
     }
    
    void GLWidget::paintGL(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glTranslatef(0.0f, 0.0f, -10.0f);

        glBegin(GL_POLYGON); 
            glVertex3f(-3.0f, -3.0f, 0.0f); 
            glVertex3f(-3.0f,  3.0f, 0.0f);
            glVertex3f( 3.0f,  3.0f, 0.0f); 
            glVertex3f( 3.0f, -3.0f, 0.0f); 
        glEnd();
    }