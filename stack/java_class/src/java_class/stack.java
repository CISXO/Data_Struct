package java_class;

public class stack {
	private int max; //stack capacity
	private int ptr; //stack pointer
	private int[] stck; // stack
	//실행시 예외 스택이 비어있을때 
	
	public class EmptyIntStackException extends RuntimeException {
		public EmptyIntStackException() {}
	}
	
	
	public class Overstack extends RuntimeException{
		public Overstack() {}
	}
	
	
	public stack(int capacity) {
		ptr = 0;
		max = capacity;
		try {
			stck = new int[max];
		} catch (OutOfMemoryError e) {
			max = 0;
		}
	}
	
	
	public int push(int x) throws Overstack {
		if( ptr>= max) {
			throw new Overstack();
		}
		return stck[ptr++] = x;
	}
	
	
	public int pop() throws EmptyIntStackException {
		if(ptr<=0) {
			throw new EmptyIntStackException();
		}
		return stck[--ptr];
	}
	
	
	public int peek() throws EmptyIntStackException {
		if(ptr <=0) {
			throw new EmptyIntStackException();
		}
		return stck[ptr-1];
	}
	
	
	public int indexOf(int x) {
		for(int i = ptr - 1; i >=0; i--) {
			if(stck[i]==x)
				return i;
		}
		return -1;
	}
	
	
	public void clear() {
		ptr = 0;
	}
	
	
	public int capacity() {
		return max;
	}
	
	
	public int size() {
		return ptr;
	}
	
	
	public boolean isEmpty() {
		return ptr <=0;
	}
	
	
	
	public boolean isFull() {
		return ptr >= max;
	}
	
	
	public void dump() {
		if(ptr <=0) {
			System.out.println("stack is empty");
		} else {
			for(int i=0; i<ptr; i++) {
				System.out.print(stck[i]+" ");
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		
	}

}
