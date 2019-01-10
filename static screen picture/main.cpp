// ======================================================================
//  Copyright (c) 2019 by Dima Zeland
// ======================================================================
#include <QtWidgets>

class MouseObserver : public QLabel {
public:
    MouseObserver(QWidget* pwgt = 0);
protected:
    virtual void mouseMoveEvent   (QMouseEvent* pe);
    void    dumpEvent     (QMouseEvent* pe, const QString& strMessage);
};

// ----------------------------------------------------------------------
MouseObserver::MouseObserver(QWidget* pwgt /*= 0*/) : QLabel(pwgt){
    setAlignment(Qt::AlignRight);
}

/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent* pe){
    if(pe->modifiers() & Qt::AltModifier)
    this->move(pe->globalX(), pe->globalY());
    /*dumpEvent(pe, "Mouse Is Moving");*/
}

// ----------------------------------------------------------------------
void MouseObserver::dumpEvent(QMouseEvent* pe, const QString& strMsg){
    setText(strMsg
            + "\n globalX()=" + QString::number(pe->globalX())
            + "\n globalY()=" + QString::number(pe->globalY())
           );
}

// ----------------------------------------------------------------------
int main(int argc, char** argv){
    QApplication app(argc, argv);
    QPixmap pix;
    pix.load("D:\\2.jpg");
    MouseObserver wgt;
    wgt.resize(pix.size());
    wgt.setPixmap(pix);
    wgt.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    wgt.show();
    wgt.move(1442, 585);
    return app.exec();
}
