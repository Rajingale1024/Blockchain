#ifndef P_O_W
#define P_O_W
#include "ToCalhash.h"
#include<string.h>
using namespace std;
int long nonce=-1;      ///NONCE IS NUMBER OF TIME MINER  PROCESS HASH
class Proof_of_Work
{
public:
    string  mineBlock(string ID)
    {

        string hass;
        do {
            nonce++;
            hass = picosha2::hash256_hex_string(ID+to_string(nonce));
            cout<<"\n\tHash:="<<hass;
        } while (hass.substr(0, 4) != "0000");          /// DIFFICULTY TARGET = NO.OF ZEROS AT BEGINING OF HASH .IT IS  PROOF OF WORK
        return hass;                                    /// RETURN  HASH OF BLOCK
    }
    int long get_nonce()
    {
        return nonce;
    }
};

#endif // P_O_W



