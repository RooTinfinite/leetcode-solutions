class Solution {
public:

int minFlips(int a, int b, int c)
{
    int nChanges = 0;
    int nMask = 1;
    for (int i = 0; i < sizeof(int) * 8; i++, nMask <<= 1)
    {
        int nARes = a & nMask;
        int nBRes = b & nMask;
        int nCRes = c & nMask;

        if (nCRes == 0)
        {
            nChanges += (nARes != 0) + (nBRes != 0);
        }
        else // '1'
        {
            nChanges += (nARes + nBRes == 0) ? 1 : 0;
        }
        
    }
    return nChanges;
}




};