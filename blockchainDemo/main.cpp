#include <iostream>
#include<string>
#include"user_1.h"
#include"user_2.h"
#include"user_3.h"
#include"user_4.h"
#include"miner.h"
#include<fstream>
using namespace std;
ifstream display_chain;
int main()
{
    int choice,in_switch,fund;
    user_1_data user_1_obj;
    user_2_data user_2_obj;                     ///objects of user_1_data,user_2_data,user_3_data,user_4_data,
    user_3_data user_3_obj;
    user_4_data user_4_obj;
    string user_name,s_name,r_name,getdata;
    do{
        cout<<"\n\t1.USER INFORMATION.";
        cout<<"\n\t2.TRANSACTION.";
        cout<<"\n\t3.BLOCKCHAIN.";          /// Main Menu
        cout<<"\n\t4.EXIT.";
        cout<<"\n\tSELECT THE OPERATION:=";
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            cout<<"\n\tENTER THE USERNAME:=";
            cin>>user_name;
            do{
                cout<<"\n\t1.GET INFORMATION.";
                cout<<"\n\t2.ADD BALANCE.";                         ///UserInfo Menu
                cout<<"\n\t3.EXIT.";
                cout<<"\n\tSELECT THE OPERATION:=";
                cin>>in_switch;
                system("cls");
                switch(in_switch)
                {
                  case 1:
                    if(user_name=="user_1")
                    user_1_obj.get_info();
                    else if(user_name=="user_2")
                    user_2_obj.get_info();                                              ///GET THE USER'S INFO
                    else if(user_name=="user_3")
                    user_3_obj.get_info();
                    else if(user_name=="user_4")
                    user_4_obj.get_info();
                    break;

                  case 2:
                    cout<<"\n\t ENTER THE AMOUNT:=";
                    cin>>fund;
                    if(user_name=="user_1")
                    user_1_obj.add_balance(fund);
                    else if(user_name=="user_2")              ///ADD FUND IN USER'S ACCOUNT.
                    user_2_obj.add_balance(fund);
                    else if(user_name=="user_3")
                    user_3_obj.add_balance(fund);
                    else if(user_name=="user_4")
                    user_4_obj.add_balance(fund);
                    break;
            }
            cout<<"\n\tPRESS KEY TO GO BACK...";
            system("pause");
            system("cls");              ///CLEAR SCREEN
            }while(in_switch!=3);
            break;

        case 2:
            {
                cout<<"\n\tENTER SENDER'S NAME:=";
                cin>>s_name;
                cout<<"\n\tENTER RECIEVER'S NAME:=";                        /// TRANSACTION  MENU
                cin>>r_name;
                cout<<"\n\tENTER AMOUNT TO TRANSFER:=";
                cin>>fund;
                system("cls");
                Mine_the_Block mtb(s_name,r_name,fund);                     ///TO MINER.H
                system("pause");
                system("cls");
            }
            break;

        case 3:
            display_chain.open("ChainFile.txt",ios::app);
            while(getline(display_chain,getdata))
            {
                cout<<getdata<<endl;
            }                                                                                                                            ///READ DATA FROM FILE i.e. SHOW BLOCKCHAIN.
            display_chain.close();
            cout<<"********************************************************************************"<<endl;
            cout<<"Press a key to go to menu:"<<endl;

            system("pause");
            system("cls");
        }
    }while(choice!=4);
    return 0;
}
