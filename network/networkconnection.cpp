
#include "networkconnection.h"
#include <qdebug.h>

#define PORT (51515)

NetworkConnection::NetworkConnection(QObject* parent) : QObject(parent)
{
    initSocket();
}

void NetworkConnection::initSocket()
{
    // create a QUDP socket
    _socket = new QUdpSocket(this);

    // The most common way to use QUdpSocket class is
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address,
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    //_socket->bind(QHostAddress::Broadcast, 45454);
    if(_socket->bind(QHostAddress::LocalHost, PORT))
    {
        qDebug() << "Connected to local host at port number " << PORT;
    }
    else
    {
        qDebug() << "Unable to connect.";
    }
    _socket->connectToHost(QHostAddress::LocalHost, PORT);

    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

//    switch(_connectionType)
//    {
//        case ConnectionType::UDP:
//        {
//            _socket = new QUdpSocket();
//            _portNo = 51515;
//            break;
//        }
//        case ConnectionType::TCP:
//        {
//            break;
//        }
//    default:
//        break;
//    }

}

void NetworkConnection::tagPos(quint64 tagId, double x, double y, double z)
{
    //qDebug() << "Send Tag Pos \n";
    int name = tagId;
    int nameSize = sizeof(int);
    int doubleSize = sizeof(double);

    char *nameByteArray = (char*)&name;
    char *xByteArray = (char*)&x;
    char *yByteArray = (char*)&y;
    char *zByteArray = (char*)&z;

   QByteArray ba;

   for(int c = 0; c < nameSize; c++)
   {
       ba.append(nameByteArray[c]);
   }
//    ba.append(" ");
   for(int c = 0; c < doubleSize; c++)
   {
       ba.append(xByteArray[c]);
   }
//    ba.append(" ");
   for(int c = 0; c < doubleSize; c++)
   {
       ba.append(yByteArray[c]);
   }
//    ba.append(" ");
   for(int c = 0; c < doubleSize; c++)
   {
       ba.append(zByteArray[c]);
   }

//    ba.append("T");
//    ba.append(" ");
//    ba.append(QByteArray::number(tagId));
//    ba.append(" ");
//    ba.append(QByteArray::number(x));
//    ba.append(" ");
//    ba.append(QByteArray::number(y));
//    ba.append(" ");
//    ba.append(QByteArray::number(z));
   // ba.append(" ");
   // ba.append(QByteArray::number(sqrt(x*x + y*y + z*z)));

    _socket->write(ba);
}

void NetworkConnection::anchPos(quint64 anchId, double x, double y, double z, bool show, bool updatetable)
{
    //qDebug() << "Send Anchor Pos\n";
    int name = anchId;
    int nameSize = sizeof(int);
    int doubleSize = sizeof(double);

    char *nameByteArray = (char*)&name;
    char *xByteArray = (char*)&x;
    char *yByteArray = (char*)&y;
    char *zByteArray = (char*)&z;

    QByteArray ba;

    for(int c = 0; c < nameSize; c++)
    {
        ba.append(nameByteArray[c]);
    }
//    ba.append(" ");
    for(int c = 0; c < doubleSize; c++)
    {
        ba.append(xByteArray[c]);
    }
//    ba.append(" ");
    for(int c = 0; c < doubleSize; c++)
    {
        ba.append(yByteArray[c]);
    }
//    ba.append(" ");
    for(int c = 0; c < doubleSize; c++)
    {
        ba.append(zByteArray[c]);
    }

//    ba.append("A");
//    ba.append(" ");
//    ba.append(" ");
//    ba.append(QByteArray::number(anchId));
//    ba.append(" ");
//    ba.append(QByteArray::number(x));
//    ba.append(" ");
//    ba.append(QByteArray::number(y));
//    ba.append(" ");
//    ba.append(QByteArray::number(z));
   // ba.append(" ");
   // ba.append(QByteArray::number(sqrt(x*x + y*y + z*z)));
   // _socket->writeDatagram(ba,QHostAddress::LocalHost,PORT);
    _socket->write(ba);
    //qDebug() << "ba" << ba;


}

void NetworkConnection::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(_socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    _socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

//    int num = int(buffer[0]);
//    double x = double(buffer[4]);
//    double y = double(buffer[12]);
//    double z = double(buffer[20]);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
