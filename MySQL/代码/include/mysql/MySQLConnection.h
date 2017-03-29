#pragma once

#include<mysql_connection.h>
#include<mysql_driver.h>
#include<cppconn/exception.h>
#include<cppconn/driver.h>
#include<cppconn/connection.h>
#include<cppconn/resultset.h>
#include<cppconn/prepared_statement.h>
#include<cppconn/statement.h>

#include <vector>
#include <string>
#include <codecvt>
#include "StringHeader.h"
#include "StringTool.hpp"

#pragma comment(lib,"mysqlcppconn.lib")



//������UTF-8��������ݿ�,�ֶ��ύģʽ
class CMySQLConnection
{
public:
	CMySQLConnection(void);
	~CMySQLConnection(void);
private:
	sql::Connection *m_pConn;
	std::string          m_strError;

public:
	/*
	 Method:    GetErrorMessage
	 FullName:  CMySQLConnection::GetErrorMessage ��ȡMYSQL ִ�д��� ��Ϣ
	 Access:    public 
	 Returns:   sql::SQLString ���� ��Ϣ
	*/
	TString GetErrorMessage()
	{
		std::string strErr = m_strError;
		m_strError.clear();

		TString str;
#ifdef UNICODE
		TCHAR buf[512] = {0};
		StringTool::MByteToWChar(strErr.c_str(),buf,512);
		str = buf;
#else
		str = strErr;
#endif
		return str;
	}

	/*
	 Method:    Connecte
	 FullName:  CMySQLConnection::Connecte
	 Access:    public 
	 Returns:   bool ���ӳɹ�����ture
	 Parameter: sql::SQLString strUrl MYSQL��ַ
	 Parameter: sql::SQLString strUserName �û���
	 Parameter: sql::SQLString strPwd ����
	*/
	bool Connecte(std::string strUrl,std::string  DBName,std::string  strUserName,std::string  strPwd);

	/*
	 Method:    Execute
	 FullName:  CMySQLConnection::Execute ִ������ɾ���Ĳ���
	 Access:    public 
	 Returns:   bool ִ�гɹ�����ture
	 Parameter: const sql::SQLString & strSQL SQL�������
	*/
	bool Execute(const std::string  &strSQL);

    /*
     Method:    ExecuteQuery
     FullName:  CMySQLConnection::ExecuteQuery,ִ�в�ѯ����
     Access:    public 
     Returns:   bool ��ѯ�ɹ�����true
     Qualifier:
     Parameter: const sql::SQLString & strSQL ,��ѯ���
     Parameter: vector<string> & vecResult  ��ѯ�������������
    */
    bool ExecuteQuery(const std::string  &strSQL,std::vector<std::vector<std::wstring>> &vecResult);

	/*
     Method:    ExecuteQuery
     FullName:  CMySQLConnection::ExecuteQuery,ִ�в�ѯ����
     Access:    public 
     Returns:   std::shared_ptr<sql::ResultSet> 
     Qualifier:
     Parameter: const sql::SQLString & strSQL ,��ѯ���
     Parameter: vector<string> & vecResult  ��ѯ�����ָ��
    */
    boost::shared_ptr<sql::ResultSet> ExecuteQuery(const std::string  &strSQL);


	/*
     Method:    GetConnection
     FullName:  CMySQLConnection::GetConnection,��ȡMySQL Connector/C++����ԭʼָ��
     Access:    public 
     Returns:   sql::Connection * 
    */
	sql::Connection *GetConnection()
	{
		return m_pConn;
	}

	void Commit()
	{
		m_pConn->commit();
	}
	void Rollback()
	{
		m_pConn->rollback();
	}
};

