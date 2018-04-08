#ifndef NETWORKCONNECTION_H
#define NETWORKCONNECTION_H

#include <QObject>
#include <QAbstractSocket>
#include <QUdpSocket>

class NetworkType;

class NetworkConnection : public QObject
{
    Q_OBJECT

public:
    explicit NetworkConnection(QObject* parent = 0);

    enum ConnectionType
    {
        UDP, TCP
    };

    void setConnectionType(ConnectionType);

public slots:
    void tagPos(quint64 tagId, double x, double y, double z);
    void anchPos(quint64 anchId, double x, double y, double z, bool show, bool updatetable);
    void readyRead();

private:
    void initSocket();
    QUdpSocket* _socket;
//    ConnectionType _connectionType;
//    quint16 _portNo;
    char buffer[128];
};

#endif // NETWORKCONNECTION_H
