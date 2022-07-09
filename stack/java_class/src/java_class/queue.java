package java_class;

class queue {
	private int max;
	private int front;
	private int rear;
	private int num;
	private int[] que;
	
	
	public class EmptyIntqueueException extends RuntimeException{
		public EmptyIntqueueException() {}
	}
	
	
	public class OverflowIntQueueException extends RuntimeException{
		public OverflowIntQueueException() {}
	}
	
	
	public queue(int capacity) {
		num = front = rear = 0;
		max = capacity;
		try {
		que = new int[max];
	} catch(OutOfMemoryError e) {
		max = 0;
	}
	}
	
	
	public int enque(int x) throws OverflowIntQueueException {
		if(num>=max)
			throw new OverflowIntQueueException();
		que[rear++] = x;
		num++;
		if(rear==max)
			rear = 0;
		return x;
	}
	
	public int deque() throws EmptyIntqueueException {
		if(num<=0) 
			throw new EmptyIntqueueException();
		
		int x = que[front++];
		num--;
		if(front == max)
			front = 0;
		return x;
	}
	
	
	public int peex() throws EmptyIntqueueException{
		if(num<=0)
			throw new EmptyIntqueueException();
		return que[front];
	}
	
	public int indexOf(int x) {
		for(int i=0; i<num; i++) {
			int idx = (i + front) % max;
			if(que[idx]==x)
				return idx;
		}
		return -1;
	}

	

	public void clear() {
		num = front = rear = 0;
	}
	
	public int capacity() {
		return max;
	}
	
	
	public int size() {
		return num;
	}
	
	public boolean isEmpty() {
		return num<=0;
	}
	
	public boolean isFull() {
		return num>=max;
	}
	
	public void dump() {
		if(num<=0) {
			System.out.println("queue is empyu");
		} else {
			for(int i=0; i<num; i++) {
				System.out.print(que[(i+front)%max] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
	}
}
