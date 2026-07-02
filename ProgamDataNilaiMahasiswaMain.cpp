/***************************************************************
 * Name:      ProgamDataNilaiMahasiswaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Damar Azky Nazari Putra (202553027@std.umk.ac.id)
 * Created:   2026-06-10
 * Copyright: Damar Azky Nazari Putra ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "ProgamDataNilaiMahasiswaMain.h"
#include <wx/msgdlg.h>
#include "ProgamDataNilaiMahasiswaMain.h"
#include <wx/listctrl.h>
#include <fstream>
#include <sstream>
#include <algorithm>

//(*InternalHeaders(ProgamDataNilaiMahasiswaFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(ProgamDataNilaiMahasiswaFrame)
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT1 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT2 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT3 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT4 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT5 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT6 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATICTEXT7 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL1 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL2 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL3 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL4 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL5 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_TEXTCTRL6 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON1 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON2 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON4 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON5 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON6 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON7 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON8 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON9 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON10 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON11 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON12 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON13 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_BUTTON3 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_LISTCTRL1 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_MENUITEM1 = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::idMenuAbout = wxNewId();
const wxWindowID ProgamDataNilaiMahasiswaFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ProgamDataNilaiMahasiswaFrame,wxFrame)
    //(*EventTable(ProgamDataNilaiMahasiswaFrame)
    //*)
END_EVENT_TABLE()

ProgamDataNilaiMahasiswaFrame::ProgamDataNilaiMahasiswaFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(ProgamDataNilaiMahasiswaFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Program Data Nilai Mahasiswa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(950,750));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    Ib1Judul = new wxStaticText(this, ID_STATICTEXT1, _("PROGRAM DATA NILAI MAHASISWA"), wxPoint(256,40), wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
    wxFont Ib1JudulFont(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Ib1Judul->SetFont(Ib1JudulFont);
    LabelNIM = new wxStaticText(this, ID_STATICTEXT2, _("NIM"), wxPoint(56,104), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    LabelNama = new wxStaticText(this, ID_STATICTEXT3, _("Nama"), wxPoint(56,144), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    LabelNilaiTugas = new wxStaticText(this, ID_STATICTEXT4, _("Nilai Tugas"), wxPoint(56,184), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    LabelNilaiUTS = new wxStaticText(this, ID_STATICTEXT5, _("Nilai UTS"), wxPoint(56,224), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    LabelNilaiUAS = new wxStaticText(this, ID_STATICTEXT6, _("Nilai UAS"), wxPoint(56,264), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    LabelCariNIMNama = new wxStaticText(this, ID_STATICTEXT7, _("Cari NIM / Nama"), wxPoint(56,456), wxSize(113,29), wxALIGN_CENTRE, _T("ID_STATICTEXT7"));
    txtNim = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(160,104), wxSize(728,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    txtNama = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(160,144), wxSize(728,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    txtTugas = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(160,184), wxSize(728,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    txtUts = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(160,224), wxSize(728,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    txtUas = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(160,264), wxSize(728,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    txtSearch = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(184,456), wxSize(600,28), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    btnTambah = new wxButton(this, ID_BUTTON1, _("Tambah Data"), wxPoint(56,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnReset = new wxButton(this, ID_BUTTON2, _("Reset Tampilan"), wxPoint(192,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    btnHapus = new wxButton(this, ID_BUTTON4, _("Hapus Data"), wxPoint(344,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnEdit = new wxButton(this, ID_BUTTON5, _("Edit Data"), wxPoint(472,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    btnTxt = new wxButton(this, ID_BUTTON6, _("Simpan di Txt"), wxPoint(584,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    btnExcel = new wxButton(this, ID_BUTTON7, _("Simpan di Excel"), wxPoint(720,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    btnAmbil = new wxButton(this, ID_BUTTON8, _("Ambil dari File"), wxPoint(56,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    btnLulus = new wxButton(this, ID_BUTTON9, _("Cek Lulus"), wxPoint(192,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    btnTidak = new wxButton(this, ID_BUTTON10, _("Cek Tidak Lulus"), wxPoint(304,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
    btnTertinggi = new wxButton(this, ID_BUTTON11, _("Cek Nilai Tertinggi"), wxPoint(448,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON11"));
    btnTerendah = new wxButton(this, ID_BUTTON12, _("Cek Nilai Terendah"), wxPoint(616,360), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON12"));
    btnRataRata = new wxButton(this, ID_BUTTON13, _("Cek Rata - Rata Nilai"), wxPoint(56,408), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
    btnCari = new wxButton(this, ID_BUTTON3, _("Cari"), wxPoint(792,456), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    listData = new wxListCtrl(this, ID_LISTCTRL1, wxPoint(56,504), wxSize(832,216), wxLC_REPORT|wxLC_SINGLE_SEL, wxDefaultValidator, _T("ID_LISTCTRL1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnHapusData);
    Connect(ID_BUTTON5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnEditData);
    Connect(ID_BUTTON6, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnSimpanTXT);
    Connect(ID_BUTTON7, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnSimpanExcel);
    Connect(ID_BUTTON8, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnAmbilFile);
    Connect(ID_BUTTON9, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnLulus);
    Connect(ID_BUTTON10, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnTidakLulus);
    Connect(ID_BUTTON11, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnNilaiTertinggi);
    Connect(ID_BUTTON12, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnNilaiTerendah);
    Connect(ID_BUTTON13, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnNilaiRataRata);
    Connect(ID_MENUITEM1, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnQuit);
    Connect(idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, (wxObjectEventFunction)&ProgamDataNilaiMahasiswaFrame::OnAbout);
    //*)

    AturKolomTabel();
    btnTambah->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnTambahData, this);
    btnCari->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnCariData, this);
    btnReset->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnResetTampilan, this);

    btnEdit->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnEditData, this);
    btnHapus->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnHapusData, this);
    btnTxt->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnSimpanTXT, this);
    btnExcel->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnSimpanExcel, this);
    btnAmbil->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnAmbilFile, this);
    btnLulus->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnLulus, this);
    btnTidak->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnTidakLulus, this);
    btnTertinggi->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnNilaiTertinggi, this);
    btnTerendah->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnNilaiTerendah, this);
    btnRataRata->Bind(wxEVT_BUTTON, &ProgamDataNilaiMahasiswaFrame::OnNilaiRataRata, this);
}

ProgamDataNilaiMahasiswaFrame::~ProgamDataNilaiMahasiswaFrame()
{
    //(*Destroy(ProgamDataNilaiMahasiswaFrame)
    //*)
}

void ProgamDataNilaiMahasiswaFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void ProgamDataNilaiMahasiswaFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ProgamDataNilaiMahasiswaFrame::AturKolomTabel()
{
    listData->InsertColumn(0, "No", wxLIST_FORMAT_CENTER, 50);
    listData->InsertColumn(1, "NIM", wxLIST_FORMAT_LEFT, 100);
    listData->InsertColumn(2, "Nama", wxLIST_FORMAT_LEFT, 180);
    listData->InsertColumn(3, "Tugas", wxLIST_FORMAT_CENTER, 80);
    listData->InsertColumn(4, "UTS", wxLIST_FORMAT_CENTER, 80);
    listData->InsertColumn(5, "UAS", wxLIST_FORMAT_CENTER, 80);
    listData->InsertColumn(6, "Rata-rata", wxLIST_FORMAT_CENTER, 100);
    listData->InsertColumn(7, "Grade", wxLIST_FORMAT_CENTER, 80);
    listData->InsertColumn(8, "Keterangan", wxLIST_FORMAT_CENTER, 120);
}

wxString ProgamDataNilaiMahasiswaFrame::BersihkanInput(wxTextCtrl* input)
{
    wxString teks = input->GetValue();
    teks.Trim(true);
    teks.Trim(false);
    return teks;
}

bool ProgamDataNilaiMahasiswaFrame::CekNilai(long nilai)
{
    return nilai >= 0 && nilai <= 100;
}

wxString ProgamDataNilaiMahasiswaFrame::TentukanGrade(double rata)
{
    if (rata >= 85)
        return "A";
    else if (rata >= 75)
        return "B";
    else if (rata >= 65)
        return "C";
    else if (rata >= 50)
        return "D";
    else
        return "E";
}

wxString ProgamDataNilaiMahasiswaFrame::TentukanKeterangan(double rata)
{
    if (rata >= 65)
        return "Lulus";
    else
        return "Tidak Lulus";
}

bool ProgamDataNilaiMahasiswaFrame::NimSudahAda(const wxString& nim)
{
    for (size_t i = 0; i < dataMahasiswa.size(); i++)
    {
        if (dataMahasiswa[i].nim == nim)
        {
            return true;
        }
    }
    return false;
}

bool ProgamDataNilaiMahasiswaFrame::NimSudahAdaSelain(const wxString& nim, int index)
{
    for (size_t i = 0; i < dataMahasiswa.size(); i++)
    {
        if ((int)i != index && dataMahasiswa[i].nim == nim)
        {
            return true;
        }
    }

    return false;
}

void ProgamDataNilaiMahasiswaFrame::KosongkanInput()
{
    txtNim->Clear();
    txtNama->Clear();
    txtTugas->Clear();
    txtUts->Clear();
    txtUas->Clear();
    txtNim->SetFocus();
}

void ProgamDataNilaiMahasiswaFrame::TampilkanData(const std::vector<Mahasiswa>& data)
{
    listData->DeleteAllItems();

    for (size_t i = 0; i < data.size(); i++)
    {
        long index = listData->InsertItem(i, wxString::Format("%d", (int)i + 1));

        listData->SetItem(index, 1, data[i].nim);
        listData->SetItem(index, 2, data[i].nama);
        listData->SetItem(index, 3, wxString::Format("%d", data[i].tugas));
        listData->SetItem(index, 4, wxString::Format("%d", data[i].uts));
        listData->SetItem(index, 5, wxString::Format("%d", data[i].uas));
        listData->SetItem(index, 6, wxString::Format("%.2f", data[i].rataRata));
        listData->SetItem(index, 7, data[i].grade);
        listData->SetItem(index, 8, data[i].keterangan);
    }
}

void ProgamDataNilaiMahasiswaFrame::OnTambahData(wxCommandEvent& event)
{
    wxString nim = BersihkanInput(txtNim);
    wxString nama = BersihkanInput(txtNama);

    long tugas, uts, uas;

    if (nim.empty() || nama.empty() || txtTugas->GetValue().empty()
        || txtUas->GetValue().empty() || txtUts->GetValue().empty())
    {
        wxMessageBox("Semua harus diisi",
                     "Validasi Input",
                     wxOK | wxICON_WARNING
                     );
        return;
    }

    if (NimSudahAda(nim))
    {
        wxMessageBox("NIM sudah terdaftar. Gunakan NIM yang berbeda.", "Validasi NIM", wxOK | wxICON_WARNING);
        return;
    }

    if (!txtTugas->GetValue().ToLong(&tugas) ||
        !txtUts->GetValue().ToLong(&uts) ||
        !txtUas->GetValue().ToLong(&uas))
    {
        wxMessageBox("Nilai tugas, UTS, dan UAS harus berupa angka.", "Validasi Nilai", wxOK | wxICON_WARNING);
        return;
    }

    if (!CekNilai(tugas) || !CekNilai(uts) || !CekNilai(uas))
    {
        wxMessageBox("Nilai harus berada dalam rentang 0 sampai 100.", "Validasi Nilai", wxOK | wxICON_WARNING);
        return;
    }

    Mahasiswa mhs;

    mhs.nim = nim;
    mhs.nama = nama;
    mhs.tugas = tugas;
    mhs.uts = uts;
    mhs.uas = uas;

    mhs.rataRata = (mhs.tugas + mhs.uts + mhs.uas) / 3.0;
    mhs.grade = TentukanGrade(mhs.rataRata);
    mhs.keterangan = TentukanKeterangan(mhs.rataRata);

    dataMahasiswa.push_back(mhs);

    TampilkanData(dataMahasiswa);
    KosongkanInput();

    wxMessageBox("Data berhasil ditambahkan.", "Informasi", wxOK | wxICON_INFORMATION);
}


void ProgamDataNilaiMahasiswaFrame::OnCariData(wxCommandEvent& event)
{
    wxString keyword = BersihkanInput(txtSearch);

    if (keyword.IsEmpty())
    {
        TampilkanData(dataMahasiswa);
        return;
    }

    std::vector<Mahasiswa> hasilPencarian;
    wxString keywordLower = keyword.Lower();

    for (size_t i = 0; i < dataMahasiswa.size(); i++)
    {
        wxString nimLower = dataMahasiswa[i].nim.Lower();
        wxString namaLower = dataMahasiswa[i].nama.Lower();

        if (nimLower.Contains(keywordLower) || namaLower.Contains(keywordLower))
        {
            hasilPencarian.push_back(dataMahasiswa[i]);
        }
    }

    TampilkanData(hasilPencarian);

    if (hasilPencarian.empty())
    {
        wxMessageBox("Data tidak ditemukan.", "Hasil Pencarian", wxOK | wxICON_INFORMATION);
    }
}

void ProgamDataNilaiMahasiswaFrame::OnResetTampilan(wxCommandEvent& event)
{
    txtSearch->Clear();
    TampilkanData(dataMahasiswa);
}

void ProgamDataNilaiMahasiswaFrame::OnEditData(wxCommandEvent& event)
{
    long selected = listData->GetNextItem(
                        -1,
                        wxLIST_NEXT_ALL,
                        wxLIST_STATE_SELECTED);

    if (selected == -1)
    {
        wxMessageBox("Pilih data yang akan diedit!",
                     "Edit Data",
                     wxOK | wxICON_WARNING);
        return;
    }

    wxString nim = BersihkanInput(txtNim);
    wxString nama = BersihkanInput(txtNama);

    long tugas, uts, uas;

    // Validasi input kosong
    if (nim.empty() || nama.empty() ||
        txtTugas->GetValue().empty() ||
        txtUts->GetValue().empty() ||
        txtUas->GetValue().empty())
    {
        wxMessageBox("Semua data harus diisi.",
                     "Validasi Input",
                     wxOK | wxICON_WARNING);
        return;
    }

    // Validasi NIM (kecuali data yang sedang diedit)
    if (NimSudahAdaSelain(nim, selected))
    {
        wxMessageBox("NIM sudah digunakan oleh mahasiswa lain.",
                     "Validasi NIM",
                     wxOK | wxICON_WARNING);
        return;
    }

    // Validasi angka
    if (!txtTugas->GetValue().ToLong(&tugas) ||
        !txtUts->GetValue().ToLong(&uts) ||
        !txtUas->GetValue().ToLong(&uas))
    {
        wxMessageBox("Nilai Tugas, UTS, dan UAS harus berupa angka.",
                     "Validasi Nilai",
                     wxOK | wxICON_WARNING);
        return;
    }

    // Validasi rentang nilai
    if (!CekNilai(tugas) ||
        !CekNilai(uts) ||
        !CekNilai(uas))
    {
        wxMessageBox("Nilai harus berada pada rentang 0 sampai 100.",
                     "Validasi Nilai",
                     wxOK | wxICON_WARNING);
        return;
    }

    // Update data
    dataMahasiswa[selected].nim = nim;
    dataMahasiswa[selected].nama = nama;
    dataMahasiswa[selected].tugas = tugas;
    dataMahasiswa[selected].uts = uts;
    dataMahasiswa[selected].uas = uas;

    dataMahasiswa[selected].rataRata =
        (tugas + uts + uas) / 3.0;

    dataMahasiswa[selected].grade =
        TentukanGrade(dataMahasiswa[selected].rataRata);

    dataMahasiswa[selected].keterangan =
        TentukanKeterangan(dataMahasiswa[selected].rataRata);

    TampilkanData(dataMahasiswa);
    KosongkanInput();

    wxMessageBox("Data berhasil diubah.",
                 "Informasi",
                 wxOK | wxICON_INFORMATION);
}

void ProgamDataNilaiMahasiswaFrame::OnHapusData(wxCommandEvent& event)
{
    long selected = listData->GetNextItem(-1,
                                          wxLIST_NEXT_ALL,
                                          wxLIST_STATE_SELECTED);

    if(selected == -1)
    {
        wxMessageBox("Pilih data yang akan dihapus!");
        return;
    }

    dataMahasiswa.erase(dataMahasiswa.begin() + selected);

    TampilkanData(dataMahasiswa);

    wxMessageBox("Data berhasil dihapus.");
}

void ProgamDataNilaiMahasiswaFrame::OnSimpanTXT(wxCommandEvent& event)
{
    std::ofstream file("DataMahasiswa.txt");

    for(const auto& m : dataMahasiswa)
    {
        file
            << m.nim << ";"
            << m.nama << ";"
            << m.tugas << ";"
            << m.uts << ";"
            << m.uas << ";"
            << m.rataRata << ";"
            << m.grade << ";"
            << m.keterangan
            << std::endl;
    }

    file.close();

    wxMessageBox("Data berhasil disimpan ke TXT");
}

void ProgamDataNilaiMahasiswaFrame::OnSimpanExcel(wxCommandEvent& event)
{
    std::ofstream file("DataMahasiswa.csv");

    file << "NIM,Nama,Tugas,UTS,UAS,Rata-rata,Grade,Keterangan\n";

    for(const auto& m : dataMahasiswa)
    {
        file
            << m.nim << ","
            << m.nama << ","
            << m.tugas << ","
            << m.uts << ","
            << m.uas << ","
            << m.rataRata << ","
            << m.grade << ","
            << m.keterangan
            << "\n";
    }

    file.close();

    wxMessageBox("File CSV berhasil dibuat.");
}

void ProgamDataNilaiMahasiswaFrame::OnAmbilFile(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(
        this,
        "Pilih File",
        "",
        "",
        "Text File (*.txt)|*.txt|CSV File (*.csv)|*.csv",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    std::ifstream file(openFileDialog.GetPath().ToStdString());

    if (!file.is_open())
    {
        wxMessageBox("File tidak dapat dibuka!",
                     "Error",
                     wxOK | wxICON_ERROR);
        return;
    }

    dataMahasiswa.clear();

    std::string line;
    bool csv = openFileDialog.GetFilename().AfterLast('.').Lower() == "csv";

    // Lewati header CSV
    if (csv)
        std::getline(file, line);

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        Mahasiswa m;

        std::stringstream ss(line);
        std::string item;

        char delimiter = csv ? ',' : ';';

        std::getline(ss, item, delimiter);
        m.nim = item;

        std::getline(ss, item, delimiter);
        m.nama = item;

        std::getline(ss, item, delimiter);
        m.tugas = std::stoi(item);

        std::getline(ss, item, delimiter);
        m.uts = std::stoi(item);

        std::getline(ss, item, delimiter);
        m.uas = std::stoi(item);

        std::getline(ss, item, delimiter);
        m.rataRata = std::stod(item);

        std::getline(ss, item, delimiter);
        m.grade = item;

        std::getline(ss, item);
        m.keterangan = item;

        dataMahasiswa.push_back(m);
    }

    file.close();

    TampilkanData(dataMahasiswa);

    wxMessageBox("Data berhasil diimport.",
                 "Informasi",
                 wxOK | wxICON_INFORMATION);
}

void ProgamDataNilaiMahasiswaFrame::OnLulus(wxCommandEvent& event)
{
    int jumlah = 0;

    for (const auto& m : dataMahasiswa)
    {
        if (m.rataRata >= 60)
        {
            jumlah++;
        }
    }

    wxMessageBox(
        wxString::Format(
            "Jumlah mahasiswa lulus : %d",
            jumlah),
        "Data Kelulusan",
        wxOK | wxICON_INFORMATION);
}

void ProgamDataNilaiMahasiswaFrame::OnTidakLulus(wxCommandEvent& event)
{
    int jumlah = 0;

    for (const auto& m : dataMahasiswa)
    {
        if (m.rataRata <= 60)
        {
            jumlah++;
        }
    }

    wxMessageBox(
        wxString::Format(
            "Jumlah mahasiswa tidak lulus : %d",
            jumlah),
        "Data Kelulusan",
        wxOK | wxICON_INFORMATION);
}

void ProgamDataNilaiMahasiswaFrame::OnNilaiTertinggi(wxCommandEvent& event)
{
    if(dataMahasiswa.empty())
    {
        wxMessageBox("Belum ada data.");
        return;
    }

    Mahasiswa terbaik = dataMahasiswa[0];

    for(const auto& m : dataMahasiswa)
    {
        if(m.rataRata > terbaik.rataRata)
            terbaik = m;
    }

    wxMessageBox(
        "Nilai Tertinggi\n\n" +
        terbaik.nama +
        "\nRata-rata : " +
        wxString::Format("%.2f", terbaik.rataRata)
    );
}

void ProgamDataNilaiMahasiswaFrame::OnNilaiTerendah(wxCommandEvent& event)
{
    if(dataMahasiswa.empty())
    {
        wxMessageBox("Belum ada data.");
        return;
    }

    Mahasiswa terendah = dataMahasiswa[0];

    for(const auto& m : dataMahasiswa)
    {
        if(m.rataRata < terendah.rataRata)
            terendah = m;
    }

    wxMessageBox(
        "Nilai Terendah\n\n" +
        terendah.nama +
        "\nRata-rata : " +
        wxString::Format("%.2f", terendah.rataRata)
    );
}

void ProgamDataNilaiMahasiswaFrame::OnNilaiRataRata(wxCommandEvent& event)
{
    std::sort(
        dataMahasiswa.begin(),
        dataMahasiswa.end(),
        [](const Mahasiswa& a,
           const Mahasiswa& b)
        {
            return a.rataRata > b.rataRata;
        }
    );

    TampilkanData(dataMahasiswa);

    wxMessageBox(
        "Data berhasil diurutkan berdasarkan rata-rata tertinggi."
    );
}
