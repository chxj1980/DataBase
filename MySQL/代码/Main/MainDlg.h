
// MainDlg.h : ͷ�ļ�
//

#pragma once


// CMainDlg �Ի���
class CMainDlg : public CDialogEx
{
// ����
public:
	CMainDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMainInsert();
	afx_msg void OnBnClickedMainSelect();
	afx_msg void OnBnClickedMainUpdate();
	afx_msg void OnBnClickedMainDelete();
};
