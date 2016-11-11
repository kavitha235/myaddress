
//#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection()){

        qDebug() << "Not connected!";
        return 1;
    }
    else{

        qDebug() << "Connected!";

        QSqlQuery query;
        query.exec("SELECT * FROM contacts");

        while (query.next()) {
            QString id = query.value(0).toString();
            QString firstname = query.value(1).toString();
            QString lastname = query.value(2).toString();
            QString phonenumber = query.value(3).toString();
            QString address = query.value(4).toString();
            QString email = query.value(5).toString();
            QString bloodgroup = query.value(6).toString();
            qDebug() << "id" << id;
            qDebug() << "firstname:" << firstname;
            qDebug() << "lastname:" << lastname;
            qDebug() << "phonenumber:" << phonenumber;
            qDebug() << "address:" << address;
            qDebug() << "email:" << email;
            qDebug() << "bloodgroup:" << bloodgroup;
            //qDebug() << "firstname:" << firstname;
        }

        return 0;
    }

    return app.exec();
}

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("address_book");
    db.setUserName("root");
    db.setPassword("root");
    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
    return true;
}
