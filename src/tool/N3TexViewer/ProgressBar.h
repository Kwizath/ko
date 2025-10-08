﻿#pragma once

// ProgressBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProgressBar window

class CProgressBar : public CProgressCtrl {
    // Construction
  public:
    CProgressBar();

    // Attributes
  public:
  protected:
    CString m_strMessage;
    int     m_nSize;
    CRect   m_Rect;

    // Operations
  public:
    BOOL         Create(LPCTSTR strMessage, int nSize, int MaxValue);
    CStatusBar * GetStatusBar();
    void         Resize();
    void         Clear();

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CProgressBar)
    //}}AFX_VIRTUAL

    // Implementation
  public:
    virtual ~CProgressBar();

    // Generated message map functions
  protected:
    //{{AFX_MSG(CProgressBar)
    afx_msg BOOL OnEraseBkgnd(CDC * pDC);
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
