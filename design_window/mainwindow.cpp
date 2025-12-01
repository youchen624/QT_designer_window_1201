#include "mainwindow.h"
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    // Connect the new actions to slots
    connect(actionShowTime, &QAction::triggered, this, &MainWindow::showCurrentTime);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
}

MainWindow::~MainWindow() {}

void MainWindow::showCurrentTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeString = currentTime.toString("yyyy-MM-dd hh:mm:ss");
    QMessageBox::information(this, "目前時間", "現在時間是：\n" + timeString);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, "關於",
        "這是一個 Qt Designer 示範程式\n\n"
        "版本：1.0\n"
        "特色：Dark 暗色主題風格");
}
