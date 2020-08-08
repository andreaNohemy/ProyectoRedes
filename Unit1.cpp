//---------------------------------------------------------------------------

#include <fmx.h>
#include <stdio.h>     // for FILE
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

using namespace std;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	cout << "hola" << endl;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	FILE *stream;
	char firstLine[512];

//  OpenDialog1->Options.Clear();
//  OpenDialog1->Options << ofAllowMultiSelect << ofFileMustExist;
	OpenDialog1->Filter = "Text files (*.txt)|*.txt";
	OpenDialog1->FilterIndex = 2; // start the dialog showing all files
	if (OpenDialog1->Execute())
	{
		for (int I = 0; I < OpenDialog1->Files->Count; I ++)
		{
		  stream = fopen(AnsiString(OpenDialog1->Files->Strings[I]).c_str(), "r");
		  if (stream)
		  {
          //cambio
			// read the first line from the file
			fgets(firstLine, sizeof(firstLine), stream);
			txtLinea->Text=firstLine;
			  fclose(stream);
		  }
		}
	}
}
//---------------------------------------------------------------------------

