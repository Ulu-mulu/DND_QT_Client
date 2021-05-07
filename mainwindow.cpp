#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //delete c;
    delete ui;
}

void MainWindow::on_buttonConnect_clicked()
{
    try {
        QString host = ui->inputConnect->text().trimmed();
        c = new ConnectionImpl(host);
        connectionCreated(c);
        setState(true);
        connect(c, SIGNAL(ReadMe(QString)), this, SLOT(recievedContent(QString)));
    } catch (QException ex) {
        ex.what();
    }
}

void MainWindow::on_buttonSend_clicked()
{
    QString text = ui->inputSend->text().trimmed().toUtf8();
    c->sendData(text);
    ui->inputSend->setText("");
}

void MainWindow::connectionCreated(Connection *c) {
    qDebug("Connection created!");
    setState(true);
    //this->c = c;
    return;
}

void MainWindow::connectionClosed(Connection *c) {
    qDebug("Connection closed");
    return;
}

void MainWindow::connectionException(Connection *c, QException *ex) {
    return;
}

void MainWindow::recievedContent(QString msg) {
    //qDebug("MainWindow::recievedContent()");
    ui->output->setText(ui->output->toPlainText()+msg);
}

void MainWindow::setState(bool isConnected)
{
    ui->buttonSend->setEnabled(isConnected);
    ui->inputSend->setEnabled(isConnected);
    ui->output->setText("");
}

void MainWindow::on_MainWindow_destroyed()
{
    qDebug("MainWindow::on_MainWindow_destroyed()");
    //c->destroyConnection();
}
