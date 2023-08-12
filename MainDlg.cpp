// MainDlg.cpp : implementation file
//

#include "pch.h"
#include "StudyMate.h"
#include "afxdialogex.h"
#include "MainDlg.h"

#include <afxdb.h>


// MainDlg dialog

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::OnCancel()
{
    CDialogEx::OnCancel();
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)

    ON_BN_CLICKED(IDC_BTN_FRIENDS, &MainDlg::OnBnClickedBtnFriends)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 데이터베이스 접근 및 이름 가져오기
    CString userName; // 가져온 사용자 이름을 저장할 변수
    CDatabase db;
    if (db.OpenEx(_T("DSN=StudyMateDSN"))) // 데이터베이스 연결 정보 설정
    {
        CString sqlQuery;
        sqlQuery.Format(_T("SELECT [name] FROM [TEST].[dbo].[Users] WHERE [id]='%s'"), m_loggedInID);
        CRecordset recordSet(&db);
        recordSet.Open(CRecordset::forwardOnly, sqlQuery);
        if (!recordSet.IsEOF())
        {
            recordSet.GetFieldValue(L"name", userName);
        }
        recordSet.Close();
        db.Close();
    }

    // 이름을 텍스트 컨트롤에 표시
    SetDlgItemText(IDC_STATIC_NAME_DISPLAY, userName);
    return TRUE; // TRUE를 반환하여 포커스를 컨트롤에 설정합니다.
}




void MainDlg::OnBnClickedBtnFriends()
{
    /*
    CString message;
    message.Format(_T("%s"), m_loggedInID);
    AfxMessageBox(message);
    */
}
