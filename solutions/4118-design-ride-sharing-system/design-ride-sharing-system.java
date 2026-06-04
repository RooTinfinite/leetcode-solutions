class RideSharingSystem {
    Queue<Integer> r,d;
    boolean b[];
    public RideSharingSystem() {
        r=new LinkedList<>();
        d=new LinkedList<>();
        b=new boolean[1001];
    }
    
    public void addRider(int riderId) {
        r.offer(riderId);
        b[riderId]=false;
    }
    
    public void addDriver(int driverId) {
        d.offer(driverId);
    }
    
    public int[] matchDriverWithRider() {
        while(!r.isEmpty()&&b[r.peek()])
            r.poll();
        if(r.isEmpty()||d.isEmpty())
            return new int[]{-1,-1};
        return new int[]{d.poll(),r.poll()};
    }
    
    public void cancelRider(int riderId) {
        b[riderId]=true;
    }
}