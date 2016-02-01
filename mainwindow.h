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
    ~MainWindow();

private slots:
    void on_webView_loadFinished(bool arg1);
    void on_webView_urlChanged(const QUrl &arg1);
};

#endif // MAINWINDOW_H
