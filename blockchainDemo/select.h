#ifndef select
#define select
#include"block.cpp"
#include"user_1.h"
#include"user_2.h"
#include"user_3.h"
#include"user_4.h"
class Select
{
public:
        user_1_data obj_user_1;
        user_2_data obj_user_2;
        user_3_data obj_user_3;
        user_4_data obj_user_4;
        int validate_1,validate_2;
        int val;
    int select_to_operate(std::string sen_name,std::string reci_name,int amt_to_transfer,std::string h_ash,int long n)
    {
        ///SELECTING MINERS AND TRANSFER DATA FOR VALIDATION.///
        if((sen_name=="user_1"&&reci_name=="user_2")|(sen_name=="user_2"&&reci_name=="user_1"))
        {
            validate_1=obj_user_3.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);       ///SENDING TO VERIFY
            validate_2=obj_user_4.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);   ///ADDING TO BLOCK
                mb.addTochain();        ///ADDING TO CHAIN.
                return (1);
            }
        }
        else if((sen_name=="user_1"&&reci_name=="user_3")|(sen_name=="user_3"&&reci_name=="user_1"))
        {
            validate_1=obj_user_2.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            validate_2=obj_user_4.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                    MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);
                    mb.addTochain();
                    return (1);
            }
        }

        else if((sen_name=="user_1"&&reci_name=="user_4")|(sen_name=="user_4"&&reci_name=="user_1"))
        {
            validate_1=obj_user_2.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            validate_2=obj_user_3.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                    MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);
                    mb.addTochain();
                    return (1);
            }
        }

        else if((sen_name=="user_2"&&reci_name=="user_3")|(sen_name=="user_3"&&reci_name=="user_2"))
        {
            validate_1=obj_user_1.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            validate_2=obj_user_4.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                    MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);
                    mb.addTochain();
                    return (1);
            }
        }

        else if((sen_name=="user_2"&&reci_name=="user_4")|(sen_name=="user_4"&&reci_name=="user_2"))
        {
            validate_1=obj_user_1.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            validate_2=obj_user_3.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                    MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);
                    mb.addTochain();
                    return (1);
            }
        }

        else if((sen_name=="user_3"&&reci_name=="user_4")|(sen_name=="user_4"&&reci_name=="user_3"))
        {
            validate_1=obj_user_1.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            validate_2=obj_user_2.verify_transaction(sen_name,reci_name,amt_to_transfer,h_ash,n);
            val=validate_1|validate_2;
            if(val==0)
            {
                cout<<"\n\t Transaction not verified!!!! ";
                return (0);
            }
            else{
                    MakeBlock mb(sen_name,reci_name,amt_to_transfer,h_ash,n);
                    mb.addTochain();
                    return (1);
            }
        }
    }

    ///DEDUCTION AND RECIEVING BALANCE///
    void process_Balance(std::string sen_name,std::string reci_name,int amt_to_transfer)
    {
        user_1_data obj_1;
        user_2_data obj_2;
        user_3_data obj_3;
        user_4_data obj_4;

        if(sen_name=="user_1")
            obj_1.deduct_balance(amt_to_transfer);
        else if(sen_name=="user_2")
            obj_2.deduct_balance(amt_to_transfer);              ///GO TO USER INFO FILE
        else if(sen_name=="user_3")
            obj_3.deduct_balance(amt_to_transfer);
        else if(sen_name=="user_4")
            obj_4.deduct_balance(amt_to_transfer);

        if(reci_name=="user_1")
            obj_1.recieve_balance(amt_to_transfer);
        else if(reci_name=="user_2")
            obj_2.recieve_balance(amt_to_transfer);
        else if(reci_name=="user_3")
            obj_3.recieve_balance(amt_to_transfer);
        else if(reci_name=="user_4")
            obj_4.recieve_balance(amt_to_transfer);

    }
};

#endif



