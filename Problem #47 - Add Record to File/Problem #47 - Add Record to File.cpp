#include <iostream>
#include <string>
#include<fstream>
#include <vector>

using namespace std;

struct stClientBankData
{
    string AccountNumber;
    string Name;
    string Phone;
    string PinCode;
    double AccountBalance;
};

stClientBankData FillClientData() {

    stClientBankData clientBankData;
    cout << "Enter Account Number? ";
    getline(cin >> ws,clientBankData.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, clientBankData.PinCode);
    cout << "Enter Name? ";
    getline(cin, clientBankData.Name);
    cout << "Enter Phone? ";
    getline(cin, clientBankData.Phone);
    cout << "Enter AccountBalance? ";
    cin >> clientBankData.AccountBalance;

    return clientBankData;
};

string ConvertRecordToLine(stClientBankData& Client, string Separator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

bool RepeatProgrom(string message) {

    char EnteredValue = ' ';

    cout << message << endl;
    cin >> EnteredValue;

    return EnteredValue == 'Y' || EnteredValue == 'y';

}

string AddNewClient() {
    stClientBankData ClientData;

    ClientData = FillClientData();

    return ConvertRecordToLine(ClientData) + '\n';
}

void AddClients(string FilePath) {

    fstream myFile;
    myFile.open( FilePath, ios::out | ios::app);

    if (myFile.is_open())
    {
       do
       {
           myFile << AddNewClient();

       } while (RepeatProgrom("\nClient Added Successfully, do you want to add more clients? Y/N? "));
       
       myFile.close();
    }
}



int main()
{

    AddClients("MyFile.txt");
    return 0;

}
