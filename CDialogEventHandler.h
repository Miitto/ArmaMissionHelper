#pragma once

#include <Windows.h>
#include <shlobj.h>
#include <objbase.h>
#include <shobjidl.h>
#include <shlwapi.h>
#include <propvarutil.h>
#include <propsys.h>
#include <new>

#define INDEX_WORDDOC 1
#define INDEX_WEBPAGE 2
#define INDEX_TEXTDOC 3

#define CONTROL_GROUP           2000
#define CONTROL_RADIOBUTTONLIST 2
#define CONTROL_RADIOBUTTON1    1
#define CONTROL_RADIOBUTTON2    2

class CDialogEventHandler : public IFileDialogEvents,
    public IFileDialogControlEvents
{
public:
    // IUnknown methods
    IFACEMETHODIMP QueryInterface(REFIID riid, void** ppv)
    {
        static const QITAB qit[] = {
            QITABENT(CDialogEventHandler, IFileDialogEvents),
            QITABENT(CDialogEventHandler, IFileDialogControlEvents),
            { 0 },
#pragma warning(suppress:4838)
        };
        return QISearch(this, qit, riid, ppv);
    }

    IFACEMETHODIMP_(ULONG) AddRef()
    {
        return InterlockedIncrement(&_cRef);
    }

    IFACEMETHODIMP_(ULONG) Release()
    {
        long cRef = InterlockedDecrement(&_cRef);
        if (!cRef)
            delete this;
        return cRef;
    }

    // IFileDialogEvents methods
    IFACEMETHODIMP OnFileOk(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnFolderChange(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnFolderChanging(IFileDialog*, IShellItem*) { return S_OK; };
    IFACEMETHODIMP OnHelp(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnSelectionChange(IFileDialog*) { return S_OK; };
    IFACEMETHODIMP OnShareViolation(IFileDialog*, IShellItem*, FDE_SHAREVIOLATION_RESPONSE*) { return S_OK; };
    IFACEMETHODIMP OnTypeChange(IFileDialog* pfd);
    IFACEMETHODIMP OnOverwrite(IFileDialog*, IShellItem*, FDE_OVERWRITE_RESPONSE*) { return S_OK; };

    // IFileDialogControlEvents methods
    IFACEMETHODIMP OnItemSelected(IFileDialogCustomize* pfdc, DWORD dwIDCtl, DWORD dwIDItem);
    IFACEMETHODIMP OnButtonClicked(IFileDialogCustomize*, DWORD) { return S_OK; };
    IFACEMETHODIMP OnCheckButtonToggled(IFileDialogCustomize*, DWORD, BOOL) { return S_OK; };
    IFACEMETHODIMP OnControlActivating(IFileDialogCustomize*, DWORD) { return S_OK; };

    static HRESULT CreateInstance(REFIID riid, void** ppv);

    CDialogEventHandler() : _cRef(1) { };
private:
    ~CDialogEventHandler() { };
    long _cRef;
};