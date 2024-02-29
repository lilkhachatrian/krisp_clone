#include "hello_world.h"
#include "ui_hello_world.h"

hello_world::hello_world(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::hello_world)
{
    ui->setupUi(this);
}

hello_world::~hello_world()
{
    delete ui;
}

