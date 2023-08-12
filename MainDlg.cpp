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

    // �����ͺ��̽� ���� �� �̸� ��������
    CString userName; // ������ ����� �̸��� ������ ����
    CDatabase db;
    if (db.OpenEx(_T("DSN=StudyMateDSN"))) // �����ͺ��̽� ���� ���� ����
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

    // �̸��� �ؽ�Ʈ ��Ʈ�ѿ� ǥ��
    SetDlgItemText(IDC_STATIC_NAME_DISPLAY, userName);
    return TRUE; // TRUE�� ��ȯ�Ͽ� ��Ŀ���� ��Ʈ�ѿ� �����մϴ�.
}




void MainDlg::OnBnClickedBtnFriends()
{
    /*
    CString message;
    message.Format(_T("%s"), m_loggedInID);
    AfxMessageBox(message);
    */
}
