//Describe how you could use a single array to implement three stacks

class myArrayStack{
	
	int [] elements;
	int top, size, bottom;
	
	myArrayStack(int [] array, int size, int bottom){
		this.elements=array;		
		this.bottom=bottom;
		this.size=size;
		top=bottom;
	}
	
	int pop(){
		if(top==bottom)
			return -1;
		int r = elements[top];
		top--;
		return r;
	}
	
	void push(int n){
		if(top!=bottom+size){
			elements[top]=n;
			top++;
		}		
	}
	
	void print(){
		for(int i=top-1; i>=bottom; i--){
			System.out.print(elements[i]+" ");
		}
		System.out.println("\n");
	}
	
}


public class Exercise01 {
	public static void main(String[] args){
		int totalSize = 15;
		int [] array = new int[totalSize];
		int nStacks = 3;
		int stackSize=(totalSize/nStacks);
		int i=0;
		
		myArrayStack stack1= new myArrayStack(array, stackSize,stackSize*i);
		myArrayStack stack2= new myArrayStack(array, stackSize,stackSize*(i+1));
		myArrayStack stack3= new myArrayStack(array, stackSize,stackSize*(i+2));
		stack1.push(1);
		stack1.push(2);
		stack1.print();
		stack1.pop();
		stack1.print();
		stack1.pop();
		
		for(i=0; i<stackSize;i++){
			stack1.push(i);
			stack2.push(15-i);
			stack3.push(i*2);
		}
		
		for(int j=0;j<totalSize;j++)
			System.out.print(array[j]+" ");
	}
}
