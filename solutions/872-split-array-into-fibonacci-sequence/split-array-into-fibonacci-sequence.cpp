class Solution {
    bool prgm(string& num,vector<int>&vec,int t){
        long n=0;
        for(int i=t;i<num.size();i++){
            if(i>t && num[t]=='0')break;
            n=n*10+num[i]-'0';
            if(n>INT_MAX)break;
            vec.push_back((int)n);
            if(vec.size()>=2){
                if(check(num,vec,i+1))return true;
            }else{
                if(prgm(num,vec,i+1))return true;
            }   
            vec.pop_back();

        }
        return false;
    }
    bool check(string& num,vector<int>& vec,int i){
        if(i==num.size())return vec.size()>=3;
        int n2=vec[vec.size()-1];
        int n1=vec[vec.size()-2];
        long sum=(long)n1+(long)n2;
        if(sum>INT_MAX)return false;
        string n3=to_string(sum);
        if (i + n3.size() > num.size() || num.substr(i, n3.size()) != n3)
            return false;

        vec.push_back((int)sum);

        if (i + n3.size() == num.size()) return true;

        if(check(num, vec, i + n3.size()))return true;
        vec.pop_back();
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int>vec;
        bool res=prgm(num,vec,0);
        if(res)return vec;
        return {};
    }
};