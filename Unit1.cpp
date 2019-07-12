//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <Windows.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
system("chcp 1251");
system("cls");
HKEY Key;
HKEY fkey;
DWORD txData=255;
DWORD divData=255;
char* tData = new char [txData];
char* key = new char [50];
char* dData = new char [divData];
char* divis = new char [50];
string substr;


cout<<"Введите дескриптор ключа "<<endl;
cin>>key;

cout<<"Введите раздел "<<endl;
cin>>divis;
if(RegOpenKeyEx(key,divis,0,KEY_QUERY_VALUE+KEY_EXECUTE,&fkey)==ERROR_SUCCESS) //открываем раздел
{ if (RegQueryValueEx(fkey,REG_SZ,NULL, NULL, (LPBYTE)dData,&divData)==ERROR_SUCCESS)// ищем параметр REG_SZ
   cout<<"Введите подстроку: "<<endl;
    cin>>substr;
     int num=KEY_EXECUTE.find(substr);
     {if (num!=0)
     cout<<KEY_EXECUTE<<endl;
     else cout<<"Заданных значений нет"<<endl; }
    cout<<"Нет данного параметра"<<endl;
    RegCloseKey(fkey);
    }
  system ("pause");
        return 0;
}
//---------------------------------------------------------------------------

