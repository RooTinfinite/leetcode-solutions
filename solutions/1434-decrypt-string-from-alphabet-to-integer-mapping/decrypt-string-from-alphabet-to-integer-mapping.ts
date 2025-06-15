function freqAlphabets(s: string): string {
    let ans = ""
    for(let i = s.length - 1; i>=0; i--){
        let code = s.charAt(i)
        if(code === "#"){
            code = s.charAt(i - 2) + s.charAt(i - 1) 
            i-=2
        }
        const num = parseInt(code);
        const val = String.fromCharCode(num + 96)
        ans = val + ans;

    }
    return ans

};