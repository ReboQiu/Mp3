#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QList>
#include <QLabel>
#include <QString>
#include <QToolButton>
#include <QListView>
#include <QDebug>
#include <QProcess>
#include <QtGui>

void readSong(QListView* listView);
void setLayout2p1(QGridLayout * layout2p1, QListView * listview,QWidget * testWidget);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,480);

   layout2p1 = new QGridLayout(this);
   listview = new QListView();

    readSong(listview);                            //读取指定目录下的mp3目录
    setLayout2p1(layout2p1 ,listview, this);        //布局界面并把mp3目录显示到listview

}



void setLayout2p1(QGridLayout * layout2p1, QListView * listview,QWidget * testWidget)
{


    QToolButton *start = new QToolButton();
    QObject::connect(start,SIGNAL(clicked()),
            testWidget,SLOT(showStart()));
    QPixmap pixmap(":/image/start.png");
    start->setStyleSheet("QToolButton{border:0px;}");  //用于隐藏toolbutton的边框
    start->resize(pixmap.size());                      //调整按钮大小以适应图片的尺寸
    start->setIconSize(pixmap.size());
    start->setIcon(QIcon(pixmap));


    QToolButton *pause = new QToolButton();
    QPixmap pixmap1(":/image/pause.png");
    pause->setStyleSheet("QToolButton{border:0px;}");
    pause->resize(pixmap1.size());
    pause->setIconSize(pixmap1.size());
    pause->setIcon(QIcon(pixmap1));

    QToolButton *stop = new QToolButton();
    QPixmap pixmap2(":/image/stop.png");
    stop->setStyleSheet("QToolButton{border:0px;}");
    stop->resize(pixmap2.size());
    stop->setIconSize(pixmap2.size());
    stop->setIcon(QIcon(pixmap2));

    QToolButton *last = new QToolButton();
    QPixmap pixmap3(":/image/last.png");
    last->setStyleSheet("QToolButton{border:0px;}");
    last->resize(pixmap3.size());
    last->setIconSize(pixmap3.size());
    last->setIcon(QIcon(pixmap3));


    QToolButton *next = new QToolButton();
    QPixmap pixmap4(":/image/next.png");
    next->setStyleSheet("QToolButton{border:0px;}");
    next->resize(pixmap4.size());
    next->setIconSize(pixmap4.size());
    next->setIcon(QIcon(pixmap4));

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(last);
    bottomLayout->addWidget(stop);
    bottomLayout->addWidget(start);
    bottomLayout->addWidget(pause);
    bottomLayout->addWidget(next);
    bottomLayout->setSpacing(20);  //控件间距为20像素


    QGridLayout * toplayout = new QGridLayout;
    //QListView *listview = new QListView();
   // listview->setFixedSize(150,200);
    toplayout -> setMargin(15);
    toplayout -> setColumnStretch(0, 1);
    toplayout -> setColumnStretch(1, 1);
    toplayout -> setColumnStretch(2, 1);
    toplayout ->addWidget(listview,0,1);


    QSlider * middle = new QSlider(Qt::Horizontal);

    // 放置窗口，设置窗口布局
    testWidget-> setLayout(layout2p1);
    layout2p1 -> addLayout(bottomLayout, 3, 0);
    layout2p1 -> addLayout(toplayout,0,0);
    layout2p1 -> addWidget(middle,2,0);

    layout2p1 -> setRowStretch(0, 10);
    layout2p1 -> setRowStretch(1, 1);
    layout2p1 -> setRowStretch(2, 1);



    return;
}

void readSong(QListView* listView)
{

    /*-----------读取指定目录下的文件----------------------*/
        QStringList filelist;
        QFileInfo fileInfo;
        QDir dir("/mnt/Mp3/sound");
        //if(!dir.exists()) return filelist;
        dir.setFilter(QDir::Dirs|QDir::Files);
        dir.setSorting(QDir::Time|QDir::Reversed);
        QFileInfoList list=dir.entryInfoList();
        int i=0,filecount=0;
        for(i;i<(list.size());i++)
        {
            fileInfo=list.at(i);
            QString currenFileName=fileInfo.fileName();
            filelist<<currenFileName;
            //qDebug()<<"filelist sort"<<currenFileName;
            //filecount++;
            //i++;

           }

    /*--------------------把读取的文件显示到开发板上------------------*/
        QHBoxLayout* layout = new QHBoxLayout;
        QStringListModel* listModel = new QStringListModel;
        listModel->setStringList(filelist);
        listView->setModel(listModel);
        layout->addWidget(listView);



}

void Widget::showStart()
{
    int pid = fork();//创建子进程；
    if(pid == 0)//如果创建成功
    {
        /*execl("/","madplay","/nfsroot/Mp3/sound/1.mp3",NULL);
                /*execl是系统命令将当前的进程替换为新的进程（madplay）
                “/usr/bin/madplay”madplay进程的路径*/
        QProcess::execute("madplay /mnt/Mp3/sound/1.mp3");
        qDebug("test");
    }
}


Widget::~Widget()
{
    delete ui;
}
