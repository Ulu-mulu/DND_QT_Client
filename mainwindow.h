#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "connection.h"
#include "connectionimpl.h"
#include <QMainWindow>
#include <QPushButton>
#include <QException>
#include <QDebug>
#include <QObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    virtual void connectionCreated(Connection *c);
    virtual void connectionClosed(Connection *c);
    virtual void connectionException(Connection *c, QException *ex);
    virtual void recievedContent(QString msg);

private slots:
    void on_buttonConnect_clicked();
    void on_buttonSend_clicked();

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    Connection *c;
    void setState(bool isConnected);
};

#endif // MAINWINDOW_H
