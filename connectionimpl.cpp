#include "connectionimpl.h"
#include <qdebug.h>
#include <QTextStream>

//const QString FLAG_MSG = "::"

ConnectionImpl::ConnectionImpl(QString _name)
{
    try {
        name = _name;
        qDebug(("Creating socket by name \"" + _name + "\"...").toLatin1());
        socket.connectToHost(QHostAddress(name), PORT);
        connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        qDebug("Socket created!");
    }
    catch (QException e) {
        e.what();
    }
}

//ConnectionImpl::~ConnectionImpl(){
//    qDebug("~ConnectionImpl()");
    //destroyConnection();
//}

void ConnectionImpl::destroyConnection() {
    try {
        QString msg = ":dst:";
        QTextStream os(&socket);
        qDebug("Trying to send data to server: " + msg.toUtf8());
        os << QByteArray(msg.toUtf8());
    }
    catch (QException e)
    {
        e.what();
    }
}

void ConnectionImpl::sendData(QString msg) {
    try {
        msg = (QString)":msg:" + msg;
        QTextStream os(&socket);
        //qDebug("Trying to send data to server: " + msg.toUtf8());
        os << QByteArray(msg.toUtf8());
    }
    catch (QException e)
    {
        e.what();
    }
}

void ConnectionImpl::close() {
    needToRun = false;
}

void ConnectionImpl::onReadyRead() {
    //qDebug("emit onReadyRead()");
    try {
        if (socket.isReadable())
        {
            while (socket.bytesAvailable())
            {
                QByteArray datas = socket.readLine();
                QString msg = QString::fromUtf8(datas);
                emit ReadMe(msg);
                //qDebug(("Server says: " + msg).toLatin1());
                //connectionListener->recievedContent(msg);
            }
        }
    }
    catch (QException e) {
        e.what();
    }
}
