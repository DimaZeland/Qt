// ======================================================================
//  main.cpp
// ======================================================================
//                   This file is a part of the book
//             "Qt 5.10 Professional programming with C++"
//                       http://qt-book.com
// ======================================================================
//  Copyright (c) 2017 by Max Schlee
// ======================================================================

#include <QtWidgets>

// ----------------------------------------------------------------------
int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget  wgt;
    QSlider* psld = new QSlider(Qt::Horizontal);
    QLabel*  plbl = new QLabel("5");

    psld->setRange(0, 10);
    psld->setPageStep(0);
    psld->setValue(5);
    psld->setTickInterval(1);
    psld->setTickPosition(QSlider::TicksBelow);
    QObject::connect(psld, SIGNAL(valueChanged(int)),
                     plbl, SLOT(setNum(int))
                    );

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(psld);
    phbxLayout->addWidget(plbl);
    wgt.setLayout(phbxLayout);

    wgt.show();

    return app.exec();
}
