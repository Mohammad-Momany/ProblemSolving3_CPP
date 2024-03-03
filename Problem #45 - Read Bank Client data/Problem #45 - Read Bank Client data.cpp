#include <iostream>
#include <string>

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

void FillClientData(stClientBankData& clientBankData) {

    cout << "Enter Account Number? ";     
    getline(cin, clientBankData.AccountNumber);
    cout << "Enter PinCode? ";
    getline(cin, clientBankData.PinCode);
    cout << "Enter Name? ";
    getline(cin, clientBankData.Name);
    cout << "Enter Phone? ";
    getline(cin, clientBankData.Phone);
    cout << "Enter AccountBalance? ";
    cin >> clientBankData.AccountBalance;

};

string ConvertRecordToLine(stClientBankData &Client, string Separator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}
int main()
{
    stClientBankData ClientBankData;

    FillClientData(ClientBankData);
    cout << ConvertRecordToLine(ClientBankData);

    return 0;

}
