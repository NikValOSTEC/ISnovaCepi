#include "NewWhire.h"
#include"pin.h"
#include"chain.h"
#include"Dot.h"
#include"AddWhireCommand.h"
#include"port.h"
#include"proxyrectport.h"
#include "MessageHandler.h"
NewWhire::NewWhire(Pin* pp1, Pin* pp2, AddWhireCommand* comm):
	CustomColliderLineRecoursive(true,pp1->dot(), pp2->dot())
{
    p1 = pp1;
    p2 = pp2;
    this->command = comm;
    _exception exp;
    exp.type = 9999;
    if (p1->chain == nullptr && p2->chain == nullptr)
    {
        chain = new Chain();
        int x = (p1->coredot()->pos().x() + p2->coredot()->pos().x()) / 2;
        int y = (p1->coredot()->pos().y() + p2->coredot()->pos().y()) / 2;
        p1->dot()->setX(x);
        p2->dot()->setX(x);
    }
    else if (p1->chain == p2->chain)
    {
        throw exp;
        return;
    }
    else if (p2->chain != nullptr && p1->chain != nullptr)
    {
        p1->chain->moveToChain(p2->chain);
        chain = p1->chain;
        p2->dot()->setPos(p1->dot()->pos());
        throw exp;
        return;
    }
    else if (p1->chain != nullptr)
    {
        chain = p1->chain;
        p2->dot()->setPos(p1->dot()->pos());
    }
    else if (p2->chain != nullptr)
    {
        chain = p2->chain;
        p1->dot()->setPos(p2->dot()->pos());
    }
    p1->pinWhire();
    p2->pinWhire();
    p1->dot()->whires.append(this);
    p2->dot()->whires.append(this);
    p1->parCon->graphicsProxyWidget()->scene()->addItem(this);
    chain->AddPin(p1);
    chain->AddPin(p2); 
    const void* address = static_cast<const void*>(this);
    QString addressString;
    QTextStream addressStream(&addressString);
    addressStream << "Addwhire   " << address;
    std::string str = addressString.toStdString();
    const char* p = str.c_str();
    myMessageHandler(p, QtWarningMsg);
    const void* addressp1 = static_cast<const void*>(p1);
    const void* addressp2 = static_cast<const void*>(p2);
    QString addressString2;
    QTextStream addressStream2(&addressString2);
    addressStream2 << "Pins    " << addressp1 << "      " << addressp2;
    std::string str2 = addressString2.toStdString();
    p = str2.c_str();
    myMessageHandler(p, QtWarningMsg);

}

NewWhire::~NewWhire()
{

    myMessageHandler( "~NewWhire");
    p1->dot()->whires.removeAll(this);
    p2->dot()->whires.removeAll(this);
}

void NewWhire::AddComandW(Pin *p1, Pin *p2)
{

    myMessageHandler( "NewWhireAddCom");
    new AddWhireCommand(p1->command,p2->command);

}

QColor NewWhire::color()
{
    return chain->color;
}


