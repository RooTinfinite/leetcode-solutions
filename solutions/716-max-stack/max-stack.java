class Node{
    int id;
    int val;
    Node next, prev;
    public Node(int id, int val){
        this.id=id;
        this.val=val;
    }
    public String toString(){
        return "id "+ id+",val "+val;
    }
}
class DLL {
    Node head, tail;
    public DLL(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head.next=tail;
        tail.prev=head;
    }
    public boolean isEmpty(){
        return head.next==tail && tail.prev==head;
    }
    public void add(Node n){
        n.next=head.next;
        head.next.prev=n;
        n.prev=head;
        head.next=n;
    }
    public Node poll(){
        if(isEmpty()){
            return null;
        }
        Node n = head.next;
        head.next = n.next;
        n.next.prev=head;
        return n;
    }
    public void remove(Node n){
        if(isEmpty()){
            return;
        }
        n.prev.next=n.next;
        n.next.prev=n.prev;
    }
}
class MaxStack {

    DLL dll = new DLL();
    int id = 0;
    int top = 0;
    PriorityQueue<Node> pq;
    Set<Node> deleted = new HashSet<>();
    public MaxStack() {
        pq = new PriorityQueue<>((eleInd1,eleInd2)->{
            int c = Integer.compare(eleInd2.val, eleInd1.val);
            if(c==0){
                return Integer.compare(eleInd2.id, eleInd1.id);
            }   
            return c;
        });
    }
    
    public void push(int x) {
        Node n = new Node(id,x);
        dll.add(n);
        pq.add(n);
        id++;
    }
    
    public int pop() {
        Node n = dll.poll();
        deleted.add(n);
        return n.val;
    }
    
    public int top() {
        return dll.head.next.val;
    }
    
    public int peekMax() {
        
        while(!pq.isEmpty()){
            Node n = pq.peek();
            if(deleted.contains(n)){
                pq.poll();
                deleted.remove(n);
            } else {
                return n.val;
            }
        }
        return -1;
        
    }
    
    public int popMax() {
        
        while(!pq.isEmpty()){
            Node n = pq.peek();
            if(deleted.contains(n)){
                pq.poll();
                deleted.remove(n);
            } else {
                n = pq.poll();
                dll.remove(n);
                return n.val;
            }
        }
        return -1;
    }
}

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */