#pragma once
#include "afxdialogex.h"


// MainDlg dialog

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~MainDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_loggedInID; // 로그인한 사용자의 ID 정보
	afx_msg void OnCancel();
	afx_msg void OnBnClickedBtnFriends();

protected:
	virtual BOOL OnInitDialog(); // OnInitDialog 함수 선언
	
public:
	afx_msg void OnSelchangeMonthcalendar(NMHDR* pNMHDR, LRESULT* pResult);
};
