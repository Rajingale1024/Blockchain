#ifndef user_2
#define user_2
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class user_2_data
{
    public:
    ofstream write_user_2;
    ifstream read_user_2;
    int validate_of_user_2;
    void get_info()
    {
        string user_2_name="MadhavPathak.";
        int balance=get_current_balance();                  ///GETTING INFO
        cout<<"\n\tName:="<<user_2_name;
        cout<<"\n\tCurrent Balance:="<<balance;
    }
    int get_current_balance()
    {
        string get_data;
        int balance_user_2;                                                         ///GET CURRENT INFO
        read_user_2.open("user_2_data.txt");
        getline(read_user_2,get_data);
        read_user_2.close();
        if(get_data.empty())
        {
            return (0);
        }
        else
        {
            stringstream convert(get_data);
            convert>>balance_user_2;
            return balance_user_2;
        }
    }
    void add_balance(int fund_to_add)
    {
        int current_balance=get_current_balance();
        int updated_balance_user_2=current_balance+fund_to_add;
        write_user_2.open("user_2_data.txt");                                                                                ///ADD BALANCE
        write_user_2<<updated_balance_user_2;
        write_user_2.close();
        cout<<"\n\tYour Balance Updated Successfully......";
        cout<<"\n\tYour Current Balance is:="<<updated_balance_user_2;
    }
    int verify_transaction(string send_name,string recieve_name,int amount_to_transfer,string hash_block,int long nonce)
    {

        cout<<"\n\tThis is Node 2.";
        string get_balance;
        int balance_verify;
        string file_name=send_name+"_data.txt";
        read_user_2.open(file_name);
        getline(read_user_2,get_balance);
        read_user_2.close();
        stringstream string_to_int(get_balance);
        string_to_int>>balance_verify;
        cout<<"\n\tSender's name:="<<send_name;
        cout<<"\n\tReciever's name:="<<recieve_name;                                        /// VERIFY  THE TRANSACTION MINED BY MINER.
        cout<<"\n\tAmount to transfer:="<<amount_to_transfer;
        cout<<"\n\tSender's Balance:="<<balance_verify;
        cout<<"\n\tHash:="<<hash_block;
        cout<<"\n\tNonce:="<<nonce;
        cout<<"\n\tDo you want to Validate the transaction[1/0]:=";
        cin>>validate_of_user_2;
        return validate_of_user_2;
    }
    void recieve_balance(int fund_to_add)
    {
        int current_balance=get_current_balance();
        int new_balance_after_transaction_user_2=current_balance+fund_to_add;
        write_user_2.open("user_2_data.txt");                                                                           ///RECIEVE AMOUNT OF TRANSACTION (IF USER_2 IS RECIEVER)
        write_user_2<<new_balance_after_transaction_user_2;
        write_user_2.close();
        cout<<"\n\tUser2 recieved Rs."<<fund_to_add;
        cout<<"\n\tUser2 Total Balance is:="<<new_balance_after_transaction_user_2;
    }
    void deduct_balance(int amount_to_deduct)
    {
        int c_balance=get_current_balance();
        int new_balance_after_deduction_user_2=c_balance-amount_to_deduct;          ///DEDUCT AMOUNT OF TRANSACTION(IF USER_2 IS SENDER)
        write_user_2.open("user_2_data.txt");
        write_user_2<<new_balance_after_deduction_user_2;
        write_user_2.close();
    }
};


#endif // user_2
