package java_class;

class A {
	private int f1; //비공개 
	protected int f2;//한정 공개
	public int f3;//공개
	
	static final int S1 = 0;
	
	public A() {//생성자 
		f1 = f2 = f3 = 0;
	}
	
	public A(int f1, int f2, int f3) {//생성자  
		this.f1 = f1;
		this.f2 = f2;
		this.f3 = f3;
	}
	
	public void setF1(int f) { //F1 의 Setter 
		f1 = f;
	}
	public int getF1() { //F1 의 getter 
		return f1;
	}
}


public class arange {

	public static void main(String[] args) {
//		A.f1 = 3; //비공개
//		A.f2= 4;
		A instance1 = new A();
		instance1.f3=4;
		instance1.f2=5;
		instance1.setF1(6);
		System.out.println(instance1.getF1()+"||" + instance1.f2+ "||" + instance1.f3);
	}

}
