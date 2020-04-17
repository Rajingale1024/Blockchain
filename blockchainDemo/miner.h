///************************************THIS IS MINER.H************************************************************************
#ifndef miner
#define miner
#include"pow.h"
#include"select.h"
#include"user_1.h"
#include"user_2.h"
#include"user_3.h"
#include"user_4.h"
#include<ctime>             ///FOR GETTING CURRENT TIME
#include<fstream>
#include<string>
using namespace std;
class Mine_the_Block
{
private:
    user_1_data obj_user_1;
    user_2_data obj_user_2;                             ///OBJECTS OF USER'S
    user_3_data obj_user_3;
    user_4_data obj_user_4;
    Select obj_s;
    Proof_of_Work pow;
    string getBalance;
    int long Nonce;
    int check,flag;
    string combine_string,timestamp,mine_hash;
    string file_name,get_b;
    ifstream read;
public:
    Mine_the_Block(string sender,string reci,int amt)
    {
        get_b=get_user_balance(sender);
        cout<<"\n\t ***************************************THIS IS MINER**********************************************";
        cout<<"\n\t Sender:="<<sender;
        cout<<"\n\t Reciever:="<<reci;
        cout<<"\n\t Amount:="<<amt;
        cout<<"\n\t Sender's Balance:="<<get_b;
        cout<<"\n\t DO YOU WANT TO MINE THE BLOCK[1/0]:=";
        cin>>check;
        if (check==0)
        {
            cout<<"\n\t Transaction not verified..";
        }
        else
        {
            timestamp=getTime();        ///GET CURRENT TIME
            mine_hash=pow.mineBlock(sender+reci+to_string(amt)+timestamp+get_b);            ///PROOF OF WORK i.e. MINE THE BLOCK.
            cout<<"\n\t DONE MINING......";
            system("pause");
            system("cls");
            Nonce=pow.get_nonce();
            flag=obj_s.select_to_operate(sender,reci,amt,mine_hash,Nonce);      ///TO SELECT.H TO BROADCAST THE LEDGER
            system("cls");
            if(flag==1)
            {
                obj_s.process_Balance(sender,reci,amt);            ///PROCESSING FUNDS
            }

        }
    }
    string getTime()
    {
        while(true)
        {
            time_t current_time=time(0);     ///RETURN THE CURRENT TIME(CHANGING)
            return(ctime(&current_time));
        }
    }
    string get_user_balance(string sen)
    {
            file_name=sen+"_data.txt";
            read.open(file_name);               ///RETURN THEE CURRENT BALANCE OF SENDER
            getline(read,getBalance);
            read.close();

        return getBalance;
    }
};

#endif // miner
