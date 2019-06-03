#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <string>
#include <iostream>

#define PORT 8888

class Client : public QTcpSocket
{
    Q_OBJECT
    Q_PROPERTY(QString data READ getData NOTIFY newData)

public:
    explicit Client(QObject *parent = nullptr);
    
    // Connect client to host at specified address
    Q_INVOKABLE void clientConnect(QString address);
    
    // return _data
    Q_INVOKABLE QString getData();
    
    // Disconnect client from host
    Q_INVOKABLE void clientDisconnect();
    
    // Write to port
    Q_INVOKABLE void clientWrite(QString);
    
    // not needed delete
    void init();

signals:

// emit signal when new data is ready
   void newData();

public slots:

// Read socket
    void readClient();
    
    // response to established connection
    void connected();

private:
    QString _data;

};

#endif // CLIENT_H
