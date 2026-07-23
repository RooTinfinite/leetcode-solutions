function finishTime(n: number, edges: number[][], baseTime: number[]): number {
    if (n === 1) return baseTime[0];
    const adj: number[][] = Array.from({length:n}, ()=>[]);
    for (const [u,v] of edges){ adj[u].push(v); adj[v].push(u); }
    const parent = new Int32Array(n).fill(-1);
    const order: number[] = [];
    const visited = new Uint8Array(n);
    const stack=[0]; visited[0]=1; parent[0]=-1;
    while(stack.length){
        const v=stack.pop()!; order.push(v);
        for(const u of adj[v]) if(!visited[u]){visited[u]=1;parent[u]=v;stack.push(u);}
    }
    const down = new Float64Array(n);
    for(let i=order.length-1;i>=0;i--){
        const v=order[i];
        let mn=Infinity, mx=-Infinity, cnt=0;
        for(const u of adj[v]) if(u!==parent[v]){
            const val=down[u]; cnt++;
            if(val<mn)mn=val; if(val>mx)mx=val;
        }
        down[v] = cnt===0 ? baseTime[v] : 2*mx - mn + baseTime[v];
    }
    const up = new Float64Array(n);
    let res=Infinity;
    for(const v of order){
        const neigh=adj[v];
        const m=neigh.length;
        const vals:number[]=[];
        for(const u of neigh) vals.push(u===parent[v]?up[v]:down[u]);
        if(m===0) res=Math.min(res,baseTime[v]);
        else {
            let mn=Infinity,mx=-Infinity;
            for(const c of vals){if(c<mn)mn=c;if(c>mx)mx=c;}
            res=Math.min(res,2*mx-mn+baseTime[v]);
        }
        const preMin=new Float64Array(m+1).fill(Infinity);
        const preMax=new Float64Array(m+1).fill(-Infinity);
        const sufMin=new Float64Array(m+1).fill(Infinity);
        const sufMax=new Float64Array(m+1).fill(-Infinity);
        for(let i=0;i<m;i++){
            preMin[i+1]=Math.min(preMin[i],vals[i]);
            preMax[i+1]=Math.max(preMax[i],vals[i]);
        }
        for(let i=m-1;i>=0;i--){
            sufMin[i]=Math.min(sufMin[i+1],vals[i]);
            sufMax[i]=Math.max(sufMax[i+1],vals[i]);
        }
        for(let i=0;i<m;i++){
            const u=neigh[i];
            if(u===parent[v])continue;
            const mn=Math.min(preMin[i],sufMin[i+1]);
            const mx=Math.max(preMax[i],sufMax[i+1]);
            up[u] = (mn===Infinity)?baseTime[v]:2*mx-mn+baseTime[v];
        }
    }
    return res;
}