#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtPromise>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QtPromise::QPromise<QByteArray> download(const QUrl& url)
{
    return QtPromise::QPromise<QByteArray>{[&](
        const QtPromise::QPromiseResolve<QByteArray>& resolve,
        const QtPromise::QPromiseReject<QByteArray>& reject) {

            QNetworkAccessManager *manager = new QNetworkAccessManager();
            QNetworkReply* reply = manager->get(QNetworkRequest{url});
            QObject::connect(reply, &QNetworkReply::finished, [=]() {
                if (reply->error() == QNetworkReply::NoError) {
                    resolve(reply->readAll());
                } else {
                    reject(reply->error());
                }

                reply->deleteLater();
            });
    }};
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    QString content = "{\"from\":\"zh\",\"to\":\"en\",\"trans_result\":[{\"src\":\"\\u4f60\\u597d\",\"dst\":\"Hello\"}]}";
//    QtJsonSerializer::JsonSerializer serializer;
//    QtJsonSerializer::JsonSerializer::registerListConverters<ResultItem>();
//    TranslationResult result = serializer.deserializeFrom<TranslationResult>(content.toUtf8(), nullptr);
//    qDebug() << "result: " << result;

//    download(QUrl("https://www.baidu.com")).then([](QByteArray res) {
//            qDebug().noquote() << res;
//            return 0;
//        });

    return a.exec();
}
