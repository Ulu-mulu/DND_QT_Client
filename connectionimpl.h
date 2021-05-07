#ifndef CONNECTIONIMPL_H
#define CONNECTIONIMPL_H
#include "connection.h"
#include <QString>
#include <QException>
#include <QByteArray>

class ConnectionImpl : public Connection
{
    Q_OBJECT
private:
    QString name;
    QTcpSocket socket;
    bool needToRun = true;

public:
    ConnectionImpl(QString _name);
    //virtual ~ConnectionImpl();
    virtual void destroyConnection();
    virtual void sendData(QString msg);
    void close();
public slots:
    void onReadyRead();
signals:
    void ReadMe(QString str);
};

#endif // CONNECTIONIMPL_H
