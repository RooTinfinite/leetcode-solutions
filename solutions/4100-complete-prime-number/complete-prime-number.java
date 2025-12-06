import java.math.BigInteger;
class Solution {
    public boolean completePrime(int num) {
        var x = String.valueOf(num);
        var y = 0;
        var z = x.length();
        while(y < z)
            if(!new BigInteger(x.substring(0, ++y)).isProbablePrime(3))
                return false;
        while(y --> 0)
            if(!new BigInteger(x.substring(y, z)).isProbablePrime(3))
                return false;
        return true;
    }
}