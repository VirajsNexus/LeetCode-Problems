class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        // case 1- after concatemation of both strings str1+str2 != str2+str1
        // hence no common divisor pattern found
        if(str1 + str2 != str2 + str1 )
        {
            return "";      // no common divisor
        }    

        // case 2- concatenated strings shows greatest common divisor pattern
        // length of gcd (gratest common divisor) is->

        int GCD_length = __gcd(str1.size(), str2.size());

        // return GCD string
        // logic : - GCD is present in the str1, which is substring of str1 string, we have GCD_ length so we can cut it down 

        return str1.substr(0,GCD_length);
    }
};