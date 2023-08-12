// SignUpDlg.cpp : implementation file
//

#include "pch.h"
#include "StudyMate.h"
#include "afxdialogex.h"
#include "SignUpDlg.h"


#include <afxdb.h>


// SignUpDlg dialog

IMPLEMENT_DYNAMIC(SignUpDlg, CDialogEx)

SignUpDlg::SignUpDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGNUP_DIALOG, pParent)
{

}

SignUpDlg::~SignUpDlg()
{
}

void SignUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SignUpDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_CREATE, &SignUpDlg::OnBnClickedBtnCreate)
END_MESSAGE_MAP()


// SignUpDlg message handlers


void SignUpDlg::OnBnClickedBtnCreate()
{
	// TODO: Add your control notification handler code here
    CDatabase db;
    if (db.OpenEx(_T("DSN=StudyMateDSN"))) {
        CRecordset recset(&db);
        CString strSQL;


        CString id, pw, pw_check, name;
        GetDlgItemText(IDC_SET_ID, id);
        GetDlgItemText(IDC_SET_PW, pw);
        GetDlgItemText(IDC_CHECK_PW, pw_check);
        GetDlgItemText(IDC_SET_NAME, name);

        if (pw != pw_check) {
            AfxMessageBox(_T("비밀번호가 일치하지 않습니다."));
        }

        strSQL.Format(_T("INSERT INTO [TEST].[dbo].[Users]([Id], [pw], [name]) VALUES('%s', '%s', '%s')"), id, pw, name);
        db.ExecuteSQL(strSQL);
        AfxMessageBox(_T("완료."));
        db.Close();
    }

}
