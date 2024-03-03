#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
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

vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "") {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }
    if (S1 != "") {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

vector <string> LoadDataFromFileToVector(string FileName)
{
    fstream MyFile;
    vector <string> vFileContent;
    MyFile.open(FileName, ios::in); //read Mode

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }

    return vFileContent;
}

stClientBankData ConvertLineToRecord(string ClientData, string Separator = "#//#") {

    stClientBankData Client;

    vector<string> VSplitedData = SplitString(ClientData, Separator);

    Client.AccountNumber = VSplitedData[0];
    Client.PinCode = VSplitedData[1];
    Client.Name = VSplitedData[2];
    Client.Phone = VSplitedData[3];
    Client.AccountBalance = stod(VSplitedData[4]);

    return Client;
}

vector <stClientBankData> CreateClientDataList(vector <string> vClientsData)
{
    vector<stClientBankData> vClientBankData;

    for (string& ClientData : vClientsData)
    {
        vClientBankData.push_back(ConvertLineToRecord(ClientData));
    }
    return vClientBankData;
}

void PrintClientRecord(stClientBankData Client) {
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector<stClientBankData> vClients) {
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________________________________________________________________________\n" << endl;

    for (stClientBankData Client : vClients) {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n_______________________________________________________________________________________________________________________\n" << endl;
}

int main()
{
    vector<stClientBankData> vClientData;

    vClientData = CreateClientDataList(LoadDataFromFileToVector("../Problem #47 - Add Record to File/MyFile.txt"));

    PrintAllClientsData(vClientData);

    system("pause>0");
    return 0;

}
