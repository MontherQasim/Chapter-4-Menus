
// MenusView.cpp : implementation of the CMenusView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Menus.h"
#endif

#include "MenusDoc.h"
#include "MenusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenusView

IMPLEMENT_DYNCREATE(CMenusView, CView)

BEGIN_MESSAGE_MAP(CMenusView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMenusView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMenusView construction/destruction

CMenusView::CMenusView() noexcept
{
	// TODO: add construction code here

}

CMenusView::~CMenusView()
{
}

BOOL CMenusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMenusView drawing

void CMenusView::OnDraw(CDC* /*pDC*/)
{
	CMenusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMenusView printing


void CMenusView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMenusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMenusView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMenusView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMenusView diagnostics

#ifdef _DEBUG
void CMenusView::AssertValid() const
{
	CView::AssertValid();
}

void CMenusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenusDoc* CMenusView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenusDoc)));
	return (CMenusDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenusView message handlers
