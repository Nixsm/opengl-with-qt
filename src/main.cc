#include <QApplication>
#include <cmath>
#include "include/gl_widget.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    GLWidget widget;
    widget.resize(640,480);
    widget.show();
    return app.exec();
}