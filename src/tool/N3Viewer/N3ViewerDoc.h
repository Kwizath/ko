﻿// N3ViewerDoc.h : interface of the CN3ViewerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "N3Base/N3Scene.h"

class CN3ViewerDoc : public CDocument {
  public:
    CN3Scene  m_Scene;
    CN3Base * m_pSelectedObj;

  protected: // create from serialization only
    CN3ViewerDoc();
    DECLARE_DYNCREATE(CN3ViewerDoc)

    // Attributes
  public:
    // Operations
  public:
    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CN3ViewerDoc)
  public:
    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive & ar);
    virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
    virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
    virtual void OnCloseDocument();
    //}}AFX_VIRTUAL

    // Implementation
  public:
    virtual ~CN3ViewerDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext & dc) const;
#endif

  protected:
    // Generated message map functions
  protected:
    //{{AFX_MSG(CN3ViewerDoc)
    afx_msg void OnEditInsertCamera();
    afx_msg void OnEditInsertLight();
    afx_msg void OnEditInsertShape();
    afx_msg void OnEditInsertCharacter();
    afx_msg void OnEditDeleteFromScene();
    afx_msg void OnFileImport();
    afx_msg void OnFileExport();
    afx_msg void OnFileSaveToSameFolder();
    afx_msg void OnViewAmbientLight();
    afx_msg void OnViewDisableDefaultLight();
    afx_msg void OnUpdateViewDisableDefaultLight(CCmdUI * pCmdUI);
    afx_msg void OnFileSaveToIndoor();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
