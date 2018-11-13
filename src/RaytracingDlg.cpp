
// RaytracingDlg.cpp : implementation file
//


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "stdafx.h"
#include "Raytracing.h"
#include "RaytracingDlg.h"
#include "cScene.h"
#include "cSphere.h"
#include "cMaterial.h"
#include "cPonctual.h"

// CRaytracingDlg dialog box
//*
BEGIN_DHTML_EVENT_MAP(CRaytracingDlg)
//	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
//	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()//*/


CRaytracingDlg::CRaytracingDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CRaytracingDlg::IDD, CRaytracingDlg::IDH, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_image = NULL;

	//cVector vector;
	cCamera *camera = new cCamera();			// define 1 camera
	cSphere *sphere = new cSphere();			// define 1st sphere
	cSphere *sphere2 = new cSphere();			// define 2nd sphere
	cPonctual *lampe1 = new cPonctual();		// define 1st light source
	cPonctual *lampe2 = new cPonctual();		// define 2nd light source

	// initialisation of the camera position
	cVector vector1(0.0f,0.0f,0.6f);
	camera->setPosition(vector1);

	// initialisation of camera directionnal vector
	cVector vector2(0.0f,0.0f,-1.0f);
	camera->set_directionnal_vector(vector2);

	// initialisation of camera focal
	camera->setFocal(50.0);

	// initialisation of camera width
	camera->setWidth(800);

	// initialisation of camera height
	camera->setHeight(800);

	// initialisation of center sphere
	cVector vector3(1.0f,1.0f,-2.0f);
	sphere->setPosition(vector3);

	// initialisation of sphere radius
	sphere->setRadius(1.0);

	// initialisation of material color
	sphere->setColorMaterial(0.7, 0.0, 0.0);

	// initialisation of material coefficient
	sphere->setCoefficientMaterial(0.2, 0.15, 0.002, 0.15);
	
	// initialisation of center sphere2
	cVector vector4(-1.2f,1.0f,-1.0f);
	sphere2->setPosition(vector4);

	// initialisation of sphere2 radius
	sphere2->setRadius(0.7);

	// initialisation of material color
	sphere2->setColorMaterial(0.0, 0.8, 0.0);
	
	// initialisation of material coefficient
	sphere2->setCoefficientMaterial(0.2, 0.15, 0.002, 0.15);

	// initialisation of lamp1
	cVector vector5(2.0, -1.3, 3.0);
	lampe1->setPos(vector5);
	lampe1->setColorLight(1.0, 1.0, 1.0);

	// initialisation of lamp2
	cVector vector6(2.0, -1.0, 3.0);
	lampe1->setPos(vector5);
	lampe1->setColorLight(0.4, 0.4, 0.4);

	// initialisation of the scene
	scene.scene_cameras.push_back(camera);
	scene.scene_objects.push_back(sphere);
	scene.scene_objects.push_back(sphere2);
	scene.scene_lightsources.push_back(lampe1);
	scene.scene_lightsources.push_back(lampe2);
}

void CRaytracingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRaytracingDlg, CDHtmlDialog)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CRaytracingDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CRaytracingDlg::OnBnClickedButtonCancel)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CRaytracingDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// message handlers for CRaytracingDlg

BOOL CRaytracingDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// Set the icon for this dialog box. The infrastructure does this automatically
  // when the main window of the application is not a dialog box
	SetIcon(m_hIcon, TRUE);			// Set a big icon
	SetIcon(m_hIcon, FALSE);		// Set a small icon

	ShowWindow(SW_MINIMIZE);

	// TODO: add an additional initialization here

	return TRUE;  // returns TRUE unless you have set the focus to a control
}

// If you add a Minimize button to your dialog box, you must use the code below
// to draw the icon. For MFC applications using the Document / View template,
// this is done automatically by the infrastructure.

void CRaytracingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);  // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center the icon in the client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to get the cursor to display when the user is dragging
// the reduced window.
HCURSOR CRaytracingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRaytracingDlg::OnBnClickedButtonCalculate()
{
	if(m_image)
	{
		FreeImage_Unload(m_image);
		m_image = NULL;
	}

	m_image = scene.getImage(0); 

	FreeImage_Save(FIF_PNG,m_image,"test.png",0);
	FreeImage_DeInitialise();	
}


void CRaytracingDlg::OnBnClickedButtonCancel()
{
	CDHtmlDialog::OnDestroy();
	OnCancel();

}


void CRaytracingDlg::OnDestroy()
{
	CDHtmlDialog::OnDestroy();

	// TODO: add here the code of the message manager
}


void CRaytracingDlg::OnBnClickedSave()
{
	// TODO: add here the code of your control notification manager
}
