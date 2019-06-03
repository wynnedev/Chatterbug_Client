#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include <QTCPSocket>
#include <QDebug>
#include <QList>

static QList<QTcpSocket*> sockets;  //list all connected sockets

class ThreadManager : public QThread
{
    Q_OBJECT
public:

// constructor
    ThreadManager(int ID, QObject *parent);
    
    // Start thread
    void run();

signals:

//emit on error
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;  // communication socket
    int socketID;        // socket ID

};

#endif // THREADMANAGER_H
