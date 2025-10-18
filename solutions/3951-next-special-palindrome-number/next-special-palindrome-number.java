class Solution {
    private static Set <Long> res = new TreeSet<>();
    private static List <Long> values = new ArrayList<>();

    static {
        generateAll();
    }

    private static boolean validate(int[] freq) {
        for(int i=1; i<10; i++) {
            if(freq[i]!=i && freq[i]>0) return false; 
        }
        return true;
    }

    private static Long calculate(int[] arr) {
        Long res=(long)0;
        for(int i=0; i<arr.length; i++) res = res * 10 + arr[i];
        return res;
    }

    private static void construct(Set <Long> res, int digit_count, int[] freq, int[] arr, int index) {
        if(index==digit_count/2) {
            if(validate(freq)) res.add(calculate(arr));
            return;
        }

        int rem = (digit_count-2*index)- ((digit_count%2==1)? 1: 0);

        for(int i=1; i<10; i++) {
            arr[index]=i;
            arr[digit_count-index-1]=i;
            freq[i]+=2;
            if(freq[i]<=i && rem-(i-freq[i]) > 0) construct(res, digit_count, freq, arr, index+1);
            freq[i]-=2;
        }
    }

    private long search(long n) {
        int l=0, r=values.size()-1;
        long res=0;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(values.get(mid)>n) {
                res = values.get(mid);
                r = mid-1;
            } else l = mid + 1;
        }

        return res;
    }

    private static void generateAll() {
        for(int i=2; i<=16; i+=2) {
            construct(res, i, new int[10], new int[i], 0);
        }

        for(int i=1; i<=15; i+=2) {
            for(int j=1; j<=9; j+=2) {
                if(i<j) continue;
                int[] arr=new int[i];
                int[] freq = new int[10];
                arr[i/2]=j;
                freq[j]=1;
                construct(res, i, freq, arr, 0);
            }
        }

        for(long x: res) values.add(x);
    }

    public long specialPalindrome(long n) {
        return search(n);
    }
}