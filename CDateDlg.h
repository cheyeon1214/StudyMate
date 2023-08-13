#pragma once
#include "afxdialogex.h"


// CDateDlg dialog

class CDateDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDateDlg)

public:
	CDateDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDateDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	void SetDateInfo(const COleDateTime& date);
};
