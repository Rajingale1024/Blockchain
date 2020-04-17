#include<iostream>
#include"ToCalhash.h"
#include<string>
#include<ctime>
#include<fstream>
#include<sstream>
using namespace std;
class MakeBlock
{
    public:
    string prev_Hashof_block;
    string curr_hashof_block;
    int amount;
    string sender_name;         ///attributes in the block.
    string receiver_name;
    string timestamp;
    string hashfor;
    int block_no;
    string getinfo;
    int long nonce;
    ofstream ins;
    ifstream out;

    //TocalHash tch;

    MakeBlock(string s,string r,int amt,string hass,int long non)
    {
        sender_name=s;
        receiver_name=r;
        amount=amt;
        nonce=non;
        timestamp=getTime();  ///call to getTime
        block_no=getindex();///get the latest block number.

        hashfor=hass;
        if(block_no==1)
          {
            prev_Hashof_block="0000000000000000000000000000000000000000000000000000000000000000";       ///Genesis block
            curr_hashof_block=hashfor;

            ins.open("BlockInfo.txt");
            ins<<block_no<<endl;            ///stores block_no,prevhash,currhash in
            ins<<prev_Hashof_block<<endl;   /// "BLOCKINFO.txt"
            ins<<curr_hashof_block<<endl;
            ins.close();

          }
          else
          {
            getline(out,prev_Hashof_block);
            getline(out,curr_hashof_block);
            out.close();
            prev_Hashof_block=curr_hashof_block;    ///In block previous hash of current
            curr_hashof_block=hashfor;             ///block is equal to current hash of previous block.
            ins.open("BlockInfo.txt");
            ins<<block_no<<endl;
            ins<<prev_Hashof_block<<endl;
            ins<<curr_hashof_block<<endl;
            ins.close();
          }

    }

    ///get current time
    string getTime()
    {
        while(true)
        {
            time_t current_time=time(0);     ///returns the current time(changing)
            return(ctime(&current_time));
        }
    }
    ///return block number
    int getindex()
    {
        //string check;
        out.open("BlockInfo.txt");
        getline(out,getinfo);
        out.close();
        if(getinfo=="")
        {
            return 1;
        }
                               ///if BPC.txt is empty(for genesis block)
        else
        {
            //cout<<"\n\t block number....2.................";
           // system("pause");
            out.open("BlockInfo.txt");
            getline(out,getinfo);
            stringstream doit(getinfo);
            doit>>block_no;        ///convert the string into int.
            block_no++;
            return block_no;
        }
    }
    void addTochain()
    {
        ofstream save;
        save.open("ChainFile.txt",ios::app);
        save<<"********************************************************************************"<<endl;
        save<<"BLOCK NUMBER:="<<block_no<<endl;
        save<<"PREVIOUS HASH:="<<prev_Hashof_block<<endl;
        save<<"SENDER NAME:="<<sender_name<<endl;                   ///ADDING TO CHAIN.
        save<<"RECEIVER NAME:="<<receiver_name<<endl;
        save<<"AMOUNT:="<<amount<<endl;
        save<<"TIMESTAMP:="<<timestamp;
        save<<"NONCE:="<<nonce<<endl;
        save<<"DIFFICULTY TARGET:=4"<<endl;
        save<<"CURRENT HASH:="<<curr_hashof_block<<endl;
        save<<endl;
        save.close();
    }

};

