class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        for(char i:word1){
            m1[i]++;
        }
        for(char i:word2){
            m2[i]++;
        }
        bool flag =false;
        for(auto& [key1,val1]:m1){
            for(auto& [key2,val2]:m2){
                
                m1[key2]++;
                m2[key1]++;
                int count1=m1.size();
                int count2=m2.size();
                if(val1==1)count1--;
                if(val2==1)count2--;
                if(count1==count2)flag=true;
                m1[key2]--;
                if(m1[key2]==0)m1.erase(key2);
                m2[key1]--;
                if(m2[key1]==0)m2.erase(key1);
            }
            if(flag)break;
        }
        return flag;
    }
};