class Solution {
    static int  calcScale( char c , char a1 , char a2 ) {
        return (c == a1 || c == a2) ? -1 : +1;
    }
public:
    int romanToInt(string s) {
        int     result = 0;

        for( size_t n = 0 ; n < s.size() ; ++n )
        {
            switch( s[n] )
            {
            case 'M':   result += 1000; break;
            case 'D':   result +=  500; break;
            case 'C':   result +=  100 * calcScale( s[n+1] , 'M' , 'D' ); break;
            case 'L':   result +=   50; break;
            case 'X':   result +=   10 * calcScale( s[n+1] , 'C' , 'L' ); break;
            case 'V':   result +=    5; break;
            case 'I':   result +=    1 * calcScale( s[n+1] , 'X' , 'V' ); break;
            }
        }
        return result;
    }
};