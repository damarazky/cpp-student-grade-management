/***************************************************************
 * Name:      ProgamDataNilaiMahasiswaMain.h
 * Purpose:   Defines Application Frame
 * Author:    Damar Azky Nazari Putra (202553027@std.umk.ac.id)
 * Created:   2026-06-10
 * Copyright: Damar Azky Nazari Putra ()
 * License:
 **************************************************************/

#ifndef PROGAMDATANILAIMAHASISWAMAIN_H
#define PROGAMDATANILAIMAHASISWAMAIN_H
#include <vector>
#include <wx/string.h>

//(*Headers(ProgamDataNilaiMahasiswaFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

struct Mahasiswa
{
    wxString nim;
    wxString nama;
    int tugas;
    int uts;
    int uas;
    double rataRata;
    wxString grade;
    wxString keterangan;
};

class ProgamDataNilaiMahasiswaFrame: public wxFrame
{
    public:

        ProgamDataNilaiMahasiswaFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~ProgamDataNilaiMahasiswaFrame();

    private:

        std::vector<Mahasiswa> dataMahasiswa;

        wxString BersihkanInput(wxTextCtrl* input);
        bool CekNilai(long nilai);
        wxString TentukanGrade(double rata);
        wxString TentukanKeterangan(double rata);
        bool NimSudahAda(const wxString& nim);
        bool NimSudahAdaSelain(const wxString& nim, int index);
        void TampilkanData(const std::vector<Mahasiswa>& data);
        void KosongkanInput();
        void AturKolomTabel();

        void OnTambahData(wxCommandEvent& event);
        void OnCariData(wxCommandEvent& event);
        void OnResetTampilan(wxCommandEvent& event);

        //(*Handlers(ProgamDataNilaiMahasiswaFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnEditData(wxCommandEvent& event);
        void OnHapusData(wxCommandEvent& event);
        void OnSimpanTXT(wxCommandEvent& event);
        void OnSimpanExcel(wxCommandEvent& event);
        void OnAmbilFile(wxCommandEvent& event);
        void OnLulus(wxCommandEvent& event);
        void OnTidakLulus(wxCommandEvent& event);
        void OnNilaiTertinggi(wxCommandEvent& event);
        void OnNilaiTerendah(wxCommandEvent& event);
        void OnNilaiRataRata(wxCommandEvent& event);
        //*)

        //(*Identifiers(ProgamDataNilaiMahasiswaFrame)
        static const wxWindowID ID_STATICTEXT1;
        static const wxWindowID ID_STATICTEXT2;
        static const wxWindowID ID_STATICTEXT3;
        static const wxWindowID ID_STATICTEXT4;
        static const wxWindowID ID_STATICTEXT5;
        static const wxWindowID ID_STATICTEXT6;
        static const wxWindowID ID_STATICTEXT7;
        static const wxWindowID ID_TEXTCTRL1;
        static const wxWindowID ID_TEXTCTRL2;
        static const wxWindowID ID_TEXTCTRL3;
        static const wxWindowID ID_TEXTCTRL4;
        static const wxWindowID ID_TEXTCTRL5;
        static const wxWindowID ID_TEXTCTRL6;
        static const wxWindowID ID_BUTTON1;
        static const wxWindowID ID_BUTTON2;
        static const wxWindowID ID_BUTTON4;
        static const wxWindowID ID_BUTTON5;
        static const wxWindowID ID_BUTTON6;
        static const wxWindowID ID_BUTTON7;
        static const wxWindowID ID_BUTTON8;
        static const wxWindowID ID_BUTTON9;
        static const wxWindowID ID_BUTTON10;
        static const wxWindowID ID_BUTTON11;
        static const wxWindowID ID_BUTTON12;
        static const wxWindowID ID_BUTTON13;
        static const wxWindowID ID_BUTTON3;
        static const wxWindowID ID_LISTCTRL1;
        static const wxWindowID ID_MENUITEM1;
        static const wxWindowID idMenuAbout;
        static const wxWindowID ID_STATUSBAR1;
        //*)

        //(*Declarations(ProgamDataNilaiMahasiswaFrame)
        wxButton* btnAmbil;
        wxButton* btnCari;
        wxButton* btnEdit;
        wxButton* btnExcel;
        wxButton* btnHapus;
        wxButton* btnLulus;
        wxButton* btnRataRata;
        wxButton* btnReset;
        wxButton* btnTambah;
        wxButton* btnTerendah;
        wxButton* btnTertinggi;
        wxButton* btnTidak;
        wxButton* btnTxt;
        wxListCtrl* listData;
        wxStaticText* Ib1Judul;
        wxStaticText* LabelCariNIMNama;
        wxStaticText* LabelNIM;
        wxStaticText* LabelNama;
        wxStaticText* LabelNilaiTugas;
        wxStaticText* LabelNilaiUAS;
        wxStaticText* LabelNilaiUTS;
        wxStatusBar* StatusBar1;
        wxTextCtrl* txtNama;
        wxTextCtrl* txtNim;
        wxTextCtrl* txtSearch;
        wxTextCtrl* txtTugas;
        wxTextCtrl* txtUas;
        wxTextCtrl* txtUts;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROGAMDATANILAIMAHASISWAMAIN_H
