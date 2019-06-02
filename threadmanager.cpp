#include "threadmanager.h"


ThreadManager::ThreadManager(int ID, QObject *parent) : QThread(parent), socketID(ID)
{

}

void ThreadManager::run()
{
    //start new thread
    qDebug() << "Starting Thread...";
    socket = new QTcpSocket();
    sockets.push_back(socket);

    if(!socket->setSocketDescriptor(this->socketID))
    {
        emit error(socket->error());
    }

    //add direction connection flag to avoid cross thread errors
    connect(socket, SIGNAL(readyRead()), this,SLOT(readyRead()), Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    exec();
}

void ThreadManager::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << socketID << "Data in: " << data;

    for(QTcpSocket *s : sockets){
        qDebug() << s->write(data);

    }
}

void ThreadManager::disconnected()
{
    socket->deleteLater();
    qDebug() << socketID << " disconected ";
    exit(0);
}
