#include "client.h"

Client::Client(QObject *parent)
{

}

void Client::clientConnect(QString address)
{
    init();
    this->connectToHost(address, PORT);
    _data = "Connecting to host at " + address;
    emit newData();
}

void Client::init()
{
    // signals and slots c onnected
    connect( this, SIGNAL(readyRead()), SLOT(readClient()) );
    
    // error reporting signal and slot connection
    connect(this, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
        [=](QAbstractSocket::SocketError socketError){ _data = this->errorString(); emit newData();});
    
    connect( this, SIGNAL(connected()), SLOT(connected()));
}

QString Client::getData()
{
    return _data;
}

void Client::clientDisconnect()
{
    this->disconnectFromHost();
}

void Client::clientWrite(QString text)
{
    QByteArray t;
    t.append(text);
    this->write(t);
    waitForBytesWritten();
}

void Client::readClient(){
    _data = readAll();
    emit newData();
    }

void Client::connected()
{
    _data += " Connected... ";
}
