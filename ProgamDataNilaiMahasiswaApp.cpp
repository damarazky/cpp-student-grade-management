/***************************************************************
 * Name:      ProgamDataNilaiMahasiswaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Damar Azky Nazari Putra (202553027@std.umk.ac.id)
 * Created:   2026-06-10
 * Copyright: Damar Azky Nazari Putra ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ProgamDataNilaiMahasiswaApp.h"

//(*AppHeaders
#include "ProgamDataNilaiMahasiswaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(ProgamDataNilaiMahasiswaApp);

bool ProgamDataNilaiMahasiswaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        ProgamDataNilaiMahasiswaFrame* Frame = new ProgamDataNilaiMahasiswaFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
