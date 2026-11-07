class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n>=1)
        {
            for(unsigned int i=1;i<=n;i*=2)
            {
                if(i==n)
                {
                    return true;
                }
            }

        }
        return false;
    }
};