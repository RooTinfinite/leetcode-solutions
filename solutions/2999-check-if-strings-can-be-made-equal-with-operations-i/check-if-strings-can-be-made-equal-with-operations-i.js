/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var canBeEqual = function(s1, s2) {
    let ch1 = [...s1];
    let ch2 = [...s2];
    let i=0;
    while(i < s1.length){
        if(ch1[i] === ch2[i]){
            i++;
        }
        else{
            if(i+2 < s1.length){
                let temp = ch1[i];
                ch1[i] = ch1[i+2];
                ch1[i+2] = temp;
            }
            i++;
        }
    }
    for(let j=0;j<s1.length;j++){
        if(ch1[j] !== ch2[j]) return false;
    }
    return true;
};