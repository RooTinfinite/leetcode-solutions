
const minLengthAfterRemovals=t=>{let o=t.length,e=0,r=0,l=Math.floor((o+1)/2);for(;r<Math.floor(o/2)&&l<o;)t[r]<t[l]&&(e+=2),r++,l++;return o-e};