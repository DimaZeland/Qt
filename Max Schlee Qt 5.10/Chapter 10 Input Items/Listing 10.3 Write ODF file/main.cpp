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
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTextEdit* ptxt = new QTextEdit("This is а <b>TEST</b>");
    QTextDocumentWriter writer;
    writer.setFormat("odf");
    writer. setFileName ( "output. odf") ;
    writer.write(ptxt->document());


    return app.exec();
}
