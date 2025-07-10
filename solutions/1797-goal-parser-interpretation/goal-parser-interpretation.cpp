class Solution {
public:
    string interpret(string command) {
        string answer;
        for(int i=0;i<command.size();i++){
            if(command[i]=='G')
                answer.push_back('G');
            else if(command[i]=='('){
                if(command[i+1]==')'){
                    answer.push_back('o');
                }
                else{
                    answer.push_back('a');
                    answer.push_back('l');
                }
            }
        }
        return answer;
    }
};