var successfulPairs = function(spells, potions, success) {
    let arr = [];
    for(let potion of potions) {
        arr.push(Math.ceil(success / potion));
    }
    arr.sort((a,b) => a-b);
    const n = arr.length;
    console.log(arr);

    const res = [];
    for(let spell of spells) {
        let l=0, r=n-1, M=0;
        while(l<=r) {
            let m = Math.floor((l+r)/2);
            if(arr[m] <= spell) {
                l = m+1;
                M = l;
            } else {
                r = m-1;
            }
        }
        res.push(M);
    }  
    return res;
};