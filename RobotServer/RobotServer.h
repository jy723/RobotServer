#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RobotServer.h"

#include <QLibrary>
#include <QWidget>

#include <qmessagebox.h>
#include <QDebug.h>

#include <DitServer.h>

class RobotServer : public QMainWindow
{
	Q_OBJECT

public:
	RobotServer(QWidget *parent = Q_NULLPTR);

	void andvanceMode(bool flag);

private slots:

	void logShow();
private:
	Ui::RobotServerClass ui;

	DitServer *m_Server;
};
