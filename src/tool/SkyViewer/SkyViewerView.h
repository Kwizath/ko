﻿// SkyViewerView.h : interface of the CSkyViewerView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CSkyViewerView : public CView {
  protected: // create from serialization only
    CSkyViewerView();
    DECLARE_DYNCREATE(CSkyViewerView)

    // Attributes
  public:
    class CSkyViewerDoc * GetDocument();

    // Operations
  public:
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSkyViewerView)
  public:
    virtual void OnDraw(CDC * pDC); // overridden to draw this view
    virtual BOOL PreCreateWindow(CREATESTRUCT & cs);

  protected:
    virtual BOOL    OnPreparePrinting(CPrintInfo * pInfo);
    virtual void    OnBeginPrinting(CDC * pDC, CPrintInfo * pInfo);
    virtual void    OnEndPrinting(CDC * pDC, CPrintInfo * pInfo);
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    //}}AFX_VIRTUAL

    // Implementation
  public:
    virtual ~CSkyViewerView();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext & dc) const;
#endif

  protected:
    // Generated message map functions
  protected:
    //{{AFX_MSG(CSkyViewerView)
    afx_msg BOOL OnEraseBkgnd(CDC * pDC);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG // debug version in SkyViewerView.cpp
inline CSkyViewerDoc * CSkyViewerView::GetDocument() {
    return (CSkyViewerDoc *)m_pDocument;
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
