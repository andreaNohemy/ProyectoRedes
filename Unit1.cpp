//---------------------------------------------------------------------------

#include <fmx.h>
#include <stdio.h>     // for FILE
#include <string>
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
	char txtHex[102];
	string hexString[34];
	string ipString[8];
	string macO;
	string macD;
	string etherType;

	OpenDialog1->Filter = "Text files (*.txt)|*.txt";
	if (OpenDialog1->Execute())
	{
		for (int I = 0; I < OpenDialog1->Files->Count; I ++)
		{
		  stream = fopen(AnsiString(OpenDialog1->Files->Strings[I]).c_str(), "r");
		  if (stream)
		  {
			// read the first line from the file
			fgets(txtHex, sizeof(txtHex), stream);
			txtLinea->Text=txtHex;
			fclose(stream);
			int prueba = 0xa8; // c0 a8 00 0f
			txtDestinoIP->Text=prueba;
			string tmp;
			int count = 0;
			//extraer los bytes
			for(int i = 0; i < sizeof(txtHex); i++){
				if(isspace(txtHex[i])){ //en cada espacio en blanco
					hexString[count]=tmp;
					tmp = "";
					count++;
				}else if(i == sizeof(txtHex)-1){ //al final
					tmp += txtHex[i];
					hexString[count] = tmp;
				}
				else{
					tmp += txtHex[i];
				}
			}

			for(int i = 0; i < 12; i++){

				if(i < 5){
					macD += hexString[i] + ":";
				}
				else if(i == 5){
					macD += hexString[i];
					txtMacOrigen->Text= macD.c_str();
				}
				else if(i == 11){
					macO += hexString[i];
//
					txtMacDestino->Text= macO.c_str();
				}
				else if(i > 5){
					macO += hexString[i] + ":";
				}
			}
//			txtMacDestino->Text=(hexString[0]+":"+hexString[1]+":"+hexString[2]+":"+hexString[3]+":"+hexString[4]+":"+hexString[5]).c_str();
//			txtMacDestino->Text=(hexString[6]+":"+hexString[7]+":"+hexString[8]+":"+hexString[9]+":"+hexString[10]+":"+hexString[11]).c_str();

			//procesar el etherType
			//posicion 12 y 13
			string tipo = (hexString[12] + hexString[13]);
			string type;
			if(tipo == "0806"){
				type = "ARP";
			}else if(tipo == "0800"){
				type = "IPv4";
			}else if(tipo == "8100"){
				type = "VLAN";
			}else if(tipo == "8035"){
				type = "RARP";
			}else if(tipo == "86dd" || tipo == "86DD"){
				type = "IPv6";
			}
//			empezar en el byte de Ip dest.
//          posicion 26-29 y 30-33
			int ipO[4];
			int ipD[4];
			string hexOP = "0x";
			ipO[0] = stoi(hexOP + hexString[26], nullptr, 16);
			ipO[1] = stoi(hexOP + hexString[27], nullptr, 16);
			ipO[2] = stoi(hexOP + hexString[28], nullptr, 16);
			ipO[3] = stoi(hexOP + hexString[29], nullptr, 16);

			ipD[0] = stoi(hexOP + hexString[30], nullptr, 16);
			ipD[1] = stoi(hexOP + hexString[31], nullptr, 16);
			ipD[2] = stoi(hexOP + hexString[32], nullptr, 16);
			ipD[3] = stoi(hexOP + hexString[33], nullptr, 16);

			txtOrigenIP-> Text= (std::to_string(ipO[0]) + "." + std::to_string(ipO[1]) + "." + std::to_string(ipO[2]) + "." + std::to_string(ipO[3])).c_str();
			txtDestinoIP-> Text= (std::to_string(ipD[0]) + "." + std::to_string(ipD[1]) + "." + std::to_string(ipD[2]) + "." + std::to_string(ipD[3])).c_str();
			txtTipo->Text= (type + " 0x" + tipo).c_str();

		  }
		}
	}
}
//---------------------------------------------------------------------------

