/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    let ans=""
    let prev=word[0]
    let count=1
    for(let i=1;i<word.length;i++){
        if(prev!==word[i]){
            ans+=String(count)
            ans+=prev
            count=1
            prev=word[i]
        }
        else{
            if(count===9){
                ans+=String(count)
                ans+=prev
                count=1
            }
            else{
                count+=1
            }
        }
    }
    ans+=String(count)
    ans+=prev
    return ans
    
};