#include <QtGui/QApplication>
#include "widget.h"
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QToolButton>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;


/*

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 4);
    gridLayout->setColumnStretch(2, 1);
    gridLayout->setColumnStretch(3, 1);
    gridLayout->setColumnStretch(4, 4);

    gridLayout->setMargin(15);
    gridLayout->setColumnMinimumWidth(2, 15);


    //QToolButton * toolBtn = new QToolButton();
   // QPixmap pixmap(":/image/pause.png");
    /*用于隐藏toolbutton的边框*/
    //toolBtn->setStyleSheet("QToolButton{border:0px;}");
    /*调整按钮大小以适应图片的尺寸*/
    //toolBtn->resize(pixmap.size());
    //toolBtn->setIconSize(pixmap.size());
    //toolBtn->setIcon(QIcon(pixmap));
/*
    QListView *listvi = new QListView(&w);
    QToolButton *start = new QToolButton();
    QLabel *lbl1 = new QLabel(QWidget::tr("First Name:"));
    QLineEdit *edit1 = new QLineEdit;
    QLabel *lbl2 = new QLabel(QWidget::tr("Last Name:"));
    QLineEdit *edit2 = new QLineEdit;
    QLabel *lbl3 = new QLabel(QWidget::tr("Sex:"));
    QLineEdit *edit3 = new QLineEdit;
    QLabel *lbl4 = new QLabel(QWidget::tr("Birthday:"));
    QLineEdit *edit4 = new QLineEdit;
    QLabel *lbl5 = new QLabel(QWidget::tr("Address:"));
    QTextEdit *textEdt = new QTextEdit;



    gridLayout->addWidget(lbl1, 0, 0);
    gridLayout->addWidget(edit1, 0, 1);
    gridLayout->addWidget(lbl2, 0, 3);
    gridLayout->addWidget(edit2, 0, 4);
    gridLayout->addWidget(lbl3, 1, 0);
    gridLayout->addWidget(edit3, 1, 1);
    gridLayout->addWidget(lbl4, 1, 3);
    gridLayout->addWidget(edit4, 1, 4);
    gridLayout->addWidget(lbl5, 2, 0);
    gridLayout->addWidget(listvi, 3, 0, 1, 2);

    w.setLayout(gridLayout);

    w.resize(400, 150);
    w.setWindowTitle(QWidget::tr("Qt Test"));


*/

    w.show();
    return a.exec();
}
