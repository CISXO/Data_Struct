package java_class;

import java.util.Scanner;


public class java_class {
	static final int VMax = 21;
	
	static class PhysicData {
		String name;
		int height;
		double vision;
		
		PhysicData(String name, int height, double vision) {
			this.name = name;
			this.height = height;
			this.vision = vision;
		}
}
	static double aveHeight(PhysicData[] dat)  {
		double sum =0;
		
		for (int i=0; i<dat.length; i++) {
			sum+= dat[i].height;
				
		}
		return sum/dat.length;
			}
	
	static void distVision(PhysicData[] dat, int[] dist) {
		int i=0;
		dist[i] =0;
		for(i=0; i<dat.length;i++){
			if(dat[i].vision>=0.0 && dat[i].vision <= VMax / 10.0) {
				dist[(int)(dat[i].vision*10)]++;
			}
		}
	}

	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PhysicData[] x = {
				new PhysicData("park",162,0.3),
				new PhysicData("Jo",152,0.3),
		};
		
		for(int i=0; i<x.length; i++) {
			
		}
		
		
	}

	
}

