// CDateDlg.cpp : implementation file
//

#include "pch.h"
#include "StudyMate.h"
#include "afxdialogex.h"
#include "CDateDlg.h"
#include "MainDlg.h"

#include <afxdb.h>


// CDateDlg dialog

IMPLEMENT_DYNAMIC(CDateDlg, CDialogEx)

CDateDlg::CDateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATE_DIALOG, pParent)
{

}

CDateDlg::~CDateDlg()
{
}

void CDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDateDlg, CDialogEx)
END_MESSAGE_MAP()

void CDateDlg::SetDateInfo(const COleDateTime& date)
{

}

// CDateDlg message handlers
