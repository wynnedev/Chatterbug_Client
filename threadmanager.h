#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include <QTCPSocket>
#include <QDebug>
#include <QList>

static QList<QTcpSocket*> sockets;

class ThreadManager : public QThread
{
    Q_OBJECT
public:
    ThreadManager(int ID, QObject *parent);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketID;

};

#endif // THREADMANAGER_H
