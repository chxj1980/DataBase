#pragma once
#include "MySQLExport.h"
#include <WinSock2.h>
#include <vector>
#include "mysql.h"

#pragma comment(lib,"libmysql.lib")

#ifndef BUF_SIZE
#define BUF_SIZE	(1024*8)
#endif

// ������UTF-8��������ݿ�,�ֶ��ύģʽ;
class MYSQL_API CMySQLConnection
{
public:
	CMySQLConnection();
	~CMySQLConnection();

public:

	/*--------------------------------------------------------------------
	 Method:    Connecte
	 FullName:  CMySQLConnection::Connecte
	 Access:    public 
	 Returns:   bool ���ӳɹ�����ture;
	 Parameter: string strUrl MYSQL��ַ
	 Parameter: string strUserName �û���;
	 Parameter: string strPwd ����;
	---------------------------------------------------------------------*/
	bool Connecte(std::string strUrl,std::string  DBName,std::string  strUserName,std::string  strPwd);

	/*--------------------------------------------------------------------
	 Method:    Execute
	 FullName:  CMySQLConnection::Execute ִ������ɾ���Ĳ���;
	 Access:    public 
	 Returns:   bool ִ�гɹ�����ture;
	 Parameter: const string & strSQL SQL�������;
	---------------------------------------------------------------------*/
	bool Execute(const std::string  &strSQL);

	/*--------------------------------------------------------------------
	Method:    ExecuteQuery
	FullName:  CMySQLConnection::ExecuteQuery,ִ�в�ѯ����
	Access:    public 
	Returns:   bool ��ѯ�ɹ�����true;
	Qualifier:
	Parameter: const sql::SQLString & strSQL ,��ѯ���
	Parameter: vector<string> & vecResult  ��ѯ�������������;
	---------------------------------------------------------------------*/
	bool ExecuteQuery(const std::string  &strSQL,std::vector<std::vector<std::wstring>> &vecResult);

	// �����ƶ�д;
	void ExecuteBlod(std::string fileName);
	void Blod2(char *file);

	/*--------------------------------------------------------------------
	 Method:	GetErrorMessage
	 FullName:	CMySQLConnection::GetErrorMessage ��ȡMYSQL ִ�д��� ��Ϣ
	 Access:	public 
	 Returns:	string������Ϣ;
	--------------------------------------------------------------------*/
	std::wstring GetErrorMessage();

	/*--------------------------------------------------------------------
	 Method:    GetErrorCode
	 FullName:  CMySQLConnection::GetErrorCode ��ȡMYSQL ִ�д������
	 Access:    public 
	 Returns:   string �������;
	--------------------------------------------------------------------*/
	int GetErrorCode();

	/*--------------------------------------------------------------------
	Method:    GetConnection
	FullName:  CMySQLConnection::GetConnection,��ȡMySQL Connector/C++����ԭʼָ��
	Access:    public 
	Returns:   sql::Connection
	---------------------------------------------------------------------*/
	MYSQL *GetConnection();

	// ִ��;
	void Commit();
	// ����;
	void Rollback();

private:
	MYSQL			m_conn;
	bool			m_bConn;
	std::string		m_strError;
	int				m_nErrorNo;
	// dll����ģ��ʱ�����棬��ʱ����;
};