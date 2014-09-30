class myNode{
	
	int data;
	myNode next;
	
	myNode(int d){
		data=d;
		next=null;
	}
}

public class myStack{
	myNode top;

	myStack(){
		top=null;
	}

	Object pop(){
		
		if(!isEmpty()){
			Object item = top.data;	
			top = top.next;
			return item;
		}
		return null;
	}
	
	public void push(int d){
		myNode n = new myNode(d);
		n.next = top;
		top = n;
	}

	private boolean isEmpty(){
		return (top == null) ? true : false;
	}
}