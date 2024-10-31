func minimumTotalDistance(robot []int, factory [][]int) int64 {
        m,n:=len(robot),len(factory)
        inf:=int(1e13)
        sort.Ints(robot)
        sort.Slice(factory, func(i,j int)bool{return factory[i][0]<factory[j][0]})
        memo:=make([][]int,m)
        for i:=range memo{
            memo[i] = make([]int,n)
        }
        var dfs func(i,j int) int
        dfs = func(i,j int) int{
            if i==m{
                return 0
            }
            if j==n{
                return inf
            }
            if memo[i][j]>0{
                return memo[i][j]-1
            }
            res:=dfs(i,j+1)
            var sum int
            for k:=i;k<m&&k-i+1<=factory[j][1];k++{
                sum+=abs(robot[k]-factory[j][0])
                res = min(res, dfs(k+1,j+1)+sum)
            }
            memo[i][j] = res+1
            return res
        }
        return int64(dfs(0,0))
}

func abs(x int) int{if x<0{return -x};return x}