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

string ReadClientAccountNumber() {
    string AccountNumber = "";
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;
    return AccountNumber;
}

void PrintClientRecord(stClientBankData Client) {
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
}

vector<stClientBankData> SaveClientsDataToFile(string FileName, vector<stClientBankData> vClients, string accountNumber) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); //overwrite
    string DataLine;

    if (MyFile.is_open()) {
        for (stClientBankData C : vClients) {
            if (C.AccountNumber != accountNumber) {
                // Only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClientBankData>& vClients) {
    stClientBankData Client;

    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientRecord(Client);

        do
        {
            SaveClientsDataToFile(ClientsFileName, vClients, Client.AccountNumber); // Refresh Clients
            vClients = CreateClientDataList(LoadClientsDataFromFile(ClientsFileName));
            cout << "\n\nClient Deleted Successfully.";
            return true;

        } while (RepeatProgrom("\nClient Added Successfully, do you want to add more clients? Y/N? "));


        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

int main() {

    vector<stClientBankData> vClients = CreateClientDataList(LoadClientsDataFromFile(ClientsFileName));;
    string AccountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");
    return 0;
}