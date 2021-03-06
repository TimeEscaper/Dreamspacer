#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "sec.h"
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

void MainWindow::InterfaceVisibility(bool visible)
{
    if(visible)
    {
        ui->webView->setVisible(false);
        ui->listWidget->setVisible(true);
        ui->listView->setVisible(true);
        ui->pushButton->setVisible(true);
    }
    else
    {
        ui->webView->setVisible(true);
        ui->listWidget->setVisible(false);
        ui->listView->setVisible(false);
        ui->pushButton->setVisible(false);
    }
}

void MainWindow::Vk_DialogDownloadFinished(QString res)
{
    QMessageBox msg;
    msg.setText(res);
    msg.exec();
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

        bool success = Core::Sec::SaveSession(Core::Global::token,Core::Global::masterId);
        if(!success)
        {
            QMessageBox msg;
            msg.setText("Saving session error!");
            msg.exec();
        }
        InterfaceVisibility(true);
    }
}
