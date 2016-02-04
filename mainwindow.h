#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *ui;
    void InterfaceVisibility(bool visible);
    ~MainWindow();

public slots:
    void Vk_DialogDownloadFinished(QString res);

private slots:
    void on_webView_loadFinished(bool arg1);
    void on_webView_urlChanged(const QUrl &arg1);
};

#endif // MAINWINDOW_H
