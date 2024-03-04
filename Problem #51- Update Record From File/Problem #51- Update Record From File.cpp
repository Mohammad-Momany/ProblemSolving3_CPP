#include <iostream>
#include<fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const string ClientsFileName = "../Problem #47 - Add Record to File/MyFile.txt";

struct stClientBankData
{
    string AccountNumber;
    string Name;
    string Phone;
    string PinCode;
    double AccountBalance;
};

enum ActionType
{
    Get,
    Update,
    Delete
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

bool RepeatProgrom(string message) {

    char EnteredValue = ' ';

    cout << message << endl;
    cin >> EnteredValue;

    return EnteredValue == 'Y' || EnteredValue == 'y';

}

vector <string> LoadClientsDataFromFile(string FileName)
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

string ConvertRecordToLine(stClientBankData& Client, string Separator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Separator;
    stClientRecord += Client.PinCode + Separator;
    stClientRecord += Client.Name + Separator;
    stClientRecord += Client.Phone + Separator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
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

bool FindClientByAccountNumber(string AccountNumber, stClientBankData& Client) {

    vector<stClientBankData> vClients = CreateClientDataList(LoadClientsDataFromFile(ClientsFileName));

    for (stClientBankData C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

stClientBankData ChangeClientRecord(string AccountNumber) {
    stClientBankData Client;
    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}


void PrintClientRecord(stClientBankData Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

vector<stClientBankData> SaveClientsDataToFile(string FileName, vector<stClientBankData> vClients, string accountNumber, ActionType actionType) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); //overwrite
    string DataLine;

    if (MyFile.is_open()) {
        for (stClientBankData C : vClients) {
            if (C.AccountNumber != accountNumber) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
            else
            {
                if (actionType == ActionType::Update)
                {
                    C = ChangeClientRecord(accountNumber);

                    DataLine = ConvertRecordToLine(C);
                }
                else if (actionType == ActionType::Delete) {
                    DataLine = "";
                }
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClientBankData>& vClients) {
    stClientBankData Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientRecord(Client);
        bool Answer = RepeatProgrom("\n\nAre you sure you want to update this client? y/n ? ");

        if (Answer) {
            SaveClientsDataToFile(ClientsFileName, vClients, AccountNumber);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}


    string ReadClientAccountNumber() {
        string AccountNumber = "";
        cout << "\nPlease enter Account Number: ";
        cin >> AccountNumber;
        return AccountNumber;
    }
int main() {

    vector<stClientBankData> vClients = CreateClientDataList(LoadClientsDataFromFile(ClientsFileName));;
    string AccountNumber = ReadClientAccountNumber();

    UpdateClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}