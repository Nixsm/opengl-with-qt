#ifndef GL_WIDGET_H
#define GL_WIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget{
    void initializeGL();
    
    void qgluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
    
    void resizeGL(int width, int height);
    
    void paintGL();
};

#endif//GL_WIDGET_H