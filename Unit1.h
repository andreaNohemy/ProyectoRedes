//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
<<<<<<< HEAD
	TOpenDialog *OpenDialog1;
	TLabel *labelLinea;
	TLabel *labelMACOrigen;
	TLabel *labelMACDestino;
	TLabel *labelOrigenIP;
	TLabel *labelDestinoIP;
	TLabel *labelTipo;
	TLabel *txtLinea;
	TLabel *txtMacOrigen;
	TLabel *txtMacDestino;
	TLabel *txtOrigenIP;
	TLabel *txtDestinoIP;
	TLabel *txtTipo;
	void __fastcall Button1Click(TObject *Sender);
=======
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	//void __fastcall Label1Click(TObject *Sender);
>>>>>>> 97cac1e62d22bcee7c9a319f4ca64ad2ce031b3c
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
