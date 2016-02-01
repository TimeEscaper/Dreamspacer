#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
//#include "debug.h"
#include <QString>
#include <QUrlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_webView_loadFinished(bool arg1)
{
}

void MainWindow::on_webView_urlChanged(const QUrl &arg1)
{
    QString loadedUrlStr = ui->webView->url().toString();
    loadedUrlStr.replace("#","?");
    QUrl loadedUrl = QUrl(loadedUrlStr);
    QUrlQuery loadedUrlQuery = QUrlQuery(loadedUrl);

    if(loadedUrlQuery.hasQueryItem("access_token"))
    {
        Core::Global::token = loadedUrlQuery.queryItemValue("access_token");
        Core::Global::masterId = loadedUrlQuery.queryItemValue("user_id").toLong();

        ui->label->setText(Core::Global::token+"\n"+QString::number(Core::Global::masterId));
    }
}
