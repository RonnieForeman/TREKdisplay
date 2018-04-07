
#include "networkconnection.h"

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
    //_socket->bind(QHostAddress::Broadcast, 51515);
    _socket->bind(QHostAddress::LocalHost, 51515);

    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

//    switch(_connectionType)
//    {
//        case ConnectionType::UDP:
//        {
//            _socket = new QUdpSocket();
//            _portNo = 45454;
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

   QByteArray ba;
    ba.append("T");
    ba.append(" ");
    ba.append(QByteArray::number(tagId));
    ba.append(" ");
    ba.append(QByteArray::number(x));
    ba.append(" ");
    ba.append(QByteArray::number(y));
    ba.append(" ");
    ba.append(QByteArray::number(z));
   // ba.append(" ");
   // ba.append(QByteArray::number(sqrt(x*x + y*y + z*z)));

    _socket->writeDatagram(ba,QHostAddress::LocalHost, 51515);
}

void NetworkConnection::anchPos(quint64 anchId, double x, double y, double z, bool show, bool updatetable)
{
   // qDebug() << "Send Anchor Pos\n";


    QByteArray ba;
    ba.append("A");
    ba.append(" ");
    ba.append(QByteArray::number(anchId));
    ba.append(" ");
    ba.append(QByteArray::number(x));
    ba.append(" ");
    ba.append(QByteArray::number(y));
    ba.append(" ");
    ba.append(QByteArray::number(z));
   // ba.append(" ");
   // ba.append(QByteArray::number(sqrt(x*x + y*y + z*z)));
    _socket->writeDatagram(ba,QHostAddress::LocalHost,51515);

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

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}
