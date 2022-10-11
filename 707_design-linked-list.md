# tips
add a dummy head node in my linked list  

# code
```java

public class ListNode {
	public int val;
	public ListNode next;
	public ListNode() {
		
	}
	public ListNode(int val) {
		this.val = val;
	}
	public ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}

class MyLinkedList {
    ListNode head;
    int size;
    public MyLinkedList() {
        this.size = 0;
        this.head = new ListNode();
    }
    
    public ListNode getNode(int index){
        ListNode cur = head;
        while((cur.next != null) && (index>=0)){
            cur = cur.next;
            index--;
        }
        return cur;
    }
    public int get(int index) {
        if(index<0 || index >=this.size){
            return -1;
        }
        ListNode cur = head;
        while((cur.next != null) && (index>=0)){
            cur = cur.next;
            index--;
        }
        return cur.val;
    }
    
    public void addAtHead(int val) {
        ListNode node = new ListNode(val);
        node.next = this.head.next;
        this.head.next = node;
        this.size++;
    }
    
    public void addAtTail(int val) {
        addAtIndex(this.size, val);
        
    }
    
    public void addAtIndex(int index, int val) {
        if(index <= 0){
            addAtHead(val);
            return;
        }
        if(index>this.size){
            return;
        }
        ListNode node = new ListNode(val);
        ListNode cur = getNode(index-1);
        node.next = cur.next;
        cur.next = node;
        this.size++;
    }
    
    public void deleteAtIndex(int index) {
        if(index<0 || index>=this.size){
            return;
        }
        ListNode pre = getNode(index -1);
        pre.next = pre.next.next;
        this.size--;
    }
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
public class Main {
	
	public static void main(String[] args) {
		System.out.println("Hello Java!");
		MyLinkedList list1 = new MyLinkedList();
		list1.addAtHead(1);
		list1.addAtTail(3);
		list1.addAtIndex(1, 2);
		for(int i=0;i<3;i++) {
			System.out.printf("%d, ", list1.get(i));
		}
		
		System.out.println();
	}
}
```
