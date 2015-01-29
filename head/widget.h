#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QListView>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    QGridLayout * layout2p1;
    QListView * listview;

private:
    Ui::Widget *ui;
public slots:
    void showStart();
};

#endif // WIDGET_H
