#pragma once
#include "MySQLExport.h"
#include "MySQLConnection.h"
#include "StringTool.h"

typedef std::vector<std::vector<TString>> MySQLData;

class MYSQL_API UserInfo
{
public:

	TString strID;
	TString strName;
	TString strAddress;
};

class MYSQL_API CMySQLHelp
{
public:
	CMySQLHelp();
	~CMySQLHelp();

public:
	// �û���Ϣ;
	bool InsertUserInfo(IN UserInfo& userInfo);
	bool SelectUserInfo(IN std::vector<UserInfo>& vecUserInfo, 
		IN TString strID = L"",
		IN TString strName = L"" );
	bool UpdateUserInfo(IN UserInfo& userInfo);
	bool DeleteUserInfo(IN TString strID);

public:
	// ִ��;
	void Commit();
	// ����;
	void Rollback();

protected:
	// ִ�в���SQL�����ӡ��޸ġ�ɾ��;
	bool Execute(const std::string  &strSQL);

	// ִ�в�ѯSQL����ѯ�����������vecResult��;
	bool ExecuteQuery(const std::string  &strSQL, MySQLData &vecResult);

	// ��ȡ������Ϣ;
	TString GetLastError();

private:

	CMySQLConnection m_myConnect;
};

