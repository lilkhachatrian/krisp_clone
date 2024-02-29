#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class hello_world; }
QT_END_NAMESPACE

class hello_world : public QMainWindow
{
    Q_OBJECT

public:
    hello_world(QWidget *parent = nullptr);
    ~hello_world();

private:
    Ui::hello_world *ui;
};
#endif // HELLO_WORLD_H
