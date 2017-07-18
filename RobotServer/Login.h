#pragma once

#include <QWidget>
#include "ui_Login.h"
#include <QtSql>
#include <qmessagebox.h>
#include <RobotServer.h>

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();

signals:
	//void transmitdb(QSqlDatabase db);

private slots:
	void login_Clicked();   //高级用户登录
//	void register_Clicked();    //注册按键槽函数
	void vistor_Login();  //普通模式

	void getUserInfo();
private:
	void db_Connect();

private:
	Ui::Login ui;

	QSqlDatabase database;
	bool tableFlag;
	int usr_id;
	QString usr_passwd;
	QString usr_name;
	QString usr_email;
	int usr_history;
	bool matchFlag;

	QString select_table = "select tbl_name name from sqlite_master where type = 'table'";
	QString create_sql = "create table user (chatid int primary key, passwd varchar(30), name varchar(30), email varchar(30), history int)";
	QString select_max_sql = "select max(chatid) from user";
	QString insert_sql = "insert into user values (?, ?, ?, ? ?)";
	QString select_sql = "select name from user";

	QString select_nameInfo = "selcet * from user wher name=";

	RobotServer *mainWindow;
};
