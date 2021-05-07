#ifndef CONNECTION_H
#define CONNECTION_H
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>

class Connection : public QObject
{
    Q_OBJECT
public:
    //virtual ~Connection();
    const quint16 PORT = 9090;
    virtual void destroyConnection() = 0;
    virtual void sendData(QString msg) = 0;
    virtual void close() = 0;
};

#endif // CONNECTION_H
