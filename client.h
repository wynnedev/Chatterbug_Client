#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QGuiApplication>
#include <QQmlApplicationEngine>


class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Qstring text NOTIFY textChanged)

public:
    explicit Client(QObject *parent = nullptr);
    Q_INVOKABLE void clientConnect(QString address);

    void init();


signals:


public slots:
    void readClient();
    void testSlot();


private:
    QTcpSocket* socket;

};

#endif // CLIENT_H
