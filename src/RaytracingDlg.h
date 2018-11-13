
// RaytracingDlg.h : header file
//

#pragma once

#include "FreeImage\FreeImage.h"
#include "cScene.h"
#include "Resource.h"

// CRaytracingDlg dialog box
class CRaytracingDlg : public CDHtmlDialog
{
// Construction
public:
	CRaytracingDlg(CWnd* pParent = NULL);	// standard constructor

	cScene scene;
// Dialog box data
	enum { IDD = IDD_RAYTRACING_DIALOG, IDH = IDR_HTML_RAYTRACING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX / DDV support

// Implementation
protected:
	HICON m_hIcon;
	FIBITMAP * m_image;
	
	// Generated functions of the message table
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonCancel();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedSave();
};
