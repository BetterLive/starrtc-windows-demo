// CShowLiveDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "starrtcdemo.h"
#include "CShowLiveDlg.h"
#include "afxdialogex.h"


// CShowLiveDlg 对话框

IMPLEMENT_DYNAMIC(CShowLiveDlg, CDialogEx)

CShowLiveDlg::CShowLiveDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SHOW_LIVE, pParent)
{
	m_pDataShowView = new CDataShowView();
	m_pPicControlCallback = NULL;
	m_bAudio = false;
	m_strAimID = "";
}

CShowLiveDlg::~CShowLiveDlg()
{
	if (m_pDataShowView != NULL)
	{
		m_pDataShowView->removeAllUser();
		delete m_pDataShowView;
		m_pDataShowView = NULL;
	}
}

void CShowLiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC1, m_Pic1);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC2, m_Pic2);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC3, m_Pic3);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC4, m_Pic4);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC5, m_Pic5);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC6, m_Pic6);
	DDX_Control(pDX, IDC_STATIC_SHOW_LIVE_PIC7, m_Pic7);
	DDX_Control(pDX, IDC_STATIC_VOIP_AUDIO_AIM_ID, m_AimId);
}


BEGIN_MESSAGE_MAP(CShowLiveDlg, CDialogEx)
	ON_WM_MOVE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_HANGUP, &CShowLiveDlg::OnBnClickedButtonHangup)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CShowLiveDlg 消息处理程序


BOOL CShowLiveDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	::GetClientRect(this->m_hWnd, rect);
	m_pDataShowView->setDrawRect(rect);

	CPicControl *pPicControl = new CPicControl();
	pPicControl->Create(_T(""), WS_CHILD | WS_VISIBLE | SS_BITMAP, rect, this, WM_USER + 100);
	//mShowPicControlVector[i] = pPicControl;
	pPicControl->ShowWindow(SW_SHOW);
	DWORD dwStyle = ::GetWindowLong(pPicControl->GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(pPicControl->GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);
	pPicControl->setInfo(m_pPicControlCallback);
	m_pDataShowView->m_pPictureControlArr.push_back(pPicControl);

	CPicControl *pPicControl1 = new CPicControl();
	pPicControl1->Create(_T(""), WS_CHILD | WS_VISIBLE | SS_BITMAP, rect, this, WM_USER + 100);
	//mShowPicControlVector[i] = pPicControl;
	pPicControl1->ShowWindow(SW_SHOW);
	dwStyle = ::GetWindowLong(pPicControl1->GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(pPicControl1->GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);
	pPicControl1->setInfo(m_pPicControlCallback);
	m_pDataShowView->m_pPictureControlArr.push_back(pPicControl1);
	
	
	/*DWORD dwStyle = ::GetWindowLong(m_Pic1.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic1.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic2.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic2.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic3.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic3.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic4.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic4.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic5.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic5.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic6.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic6.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);

	dwStyle = ::GetWindowLong(m_Pic7.GetSafeHwnd(), GWL_STYLE);
	::SetWindowLong(m_Pic7.GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);


	m_pDataShowView->m_pPictureControlArr.push_back(&m_Pic1);
	m_Pic1.setInfo(m_pPicControlCallback);

	m_pDataShowView->m_pPictureControlArr.push_back(&m_Pic2);
	m_Pic2.setInfo(m_pPicControlCallback);

	m_pDataShowView->m_pPictureControlArr.push_back(&m_Pic3);
	m_Pic3.setInfo(m_pPicControlCallback);

	m_pShowLiveControl->m_pPictureControlArr[3] = &m_Pic4;
	m_Pic4.setInfo(m_pPicControlCallback);

	m_pShowLiveControl->m_pPictureControlArr[4] = &m_Pic5;
	m_Pic5.setInfo(m_pPicControlCallback);

	m_pShowLiveControl->m_pPictureControlArr[5] = &m_Pic6;
	m_Pic6.setInfo(m_pPicControlCallback);

	m_pShowLiveControl->m_pPictureControlArr[6] = &m_Pic7;
	m_Pic7.setInfo(m_pPicControlCallback);

	m_pShowLiveControl->resetPicControlPos();*/

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CShowLiveDlg::addPictureControlListener(CPicControlCallback* pPicControlCallback)
{
	m_pPicControlCallback = pPicControlCallback;
}

void CShowLiveDlg::addShowLiveListener(IShowLiveCallback* pShowLiveCallback)
{
	m_pShowLiveCallback = pShowLiveCallback;
}


void CShowLiveDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
	CRect rect;
	::GetClientRect(this->m_hWnd, rect);
	m_pDataShowView->setDrawRect(rect);	
}


void CShowLiveDlg::OnClose()
{
	if (IDYES == AfxMessageBox("是否要关闭视频通话", MB_YESNO))
	{
		if (m_pShowLiveCallback != NULL)
		{
			m_pShowLiveCallback->stopLive();
		}
		CDialogEx::OnClose();
	}
	m_bAudio = false;
}


void CShowLiveDlg::OnBnClickedButtonHangup()
{
	if (IDYES == AfxMessageBox("是否要关闭语音通话", MB_YESNO))
	{
		if (m_pShowLiveCallback != NULL)
		{
			m_pShowLiveCallback->stopLive();
		}
		CDialogEx::OnClose();
	}
	m_bAudio = false;
}


void CShowLiveDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	if (m_bAudio)
	{
		CRect rect;
		::GetClientRect(this->m_hWnd, rect);

		CRect rect1;
		::GetClientRect(GetDlgItem(IDC_BUTTON_HANGUP)->m_hWnd, rect1);

		GetDlgItem(IDC_BUTTON_HANGUP)->MoveWindow(rect.left + rect.Width() / 2 - rect1.Width() / 2, rect.top + (int)(rect.Height()*0.75), rect1.Width(), rect1.Height());
		GetDlgItem(IDC_BUTTON_HANGUP)->ShowWindow(SW_SHOW);
		m_AimId.SetWindowText(m_strAimID.c_str());
		m_AimId.MoveWindow(rect.left + rect.Width() / 2 - rect1.Width() / 2, rect.top + (int)(rect.Height()*0.3), rect1.Width(), rect1.Height());
		m_AimId.ShowWindow(SW_SHOW);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_HANGUP)->ShowWindow(SW_HIDE);
		m_AimId.ShowWindow(SW_HIDE);
	}
}
