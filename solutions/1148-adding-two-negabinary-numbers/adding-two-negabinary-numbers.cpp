class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) { 
    vector<int> result; 
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1; 
    while (i >= 0 || j >= 0 || carry != 0) { 
        int bitSum = carry;
        if (i >= 0) bitSum += arr1[i--];
        if (j >= 0) bitSum += arr2[j--]; 
        result.insert(result.begin(), bitSum & 1); 
        carry = -(bitSum >> 1);
    } 
    while (result.size() > 1 && result[0] == 0) {
        result.erase(result.begin());
    } 
    return result;
}
};