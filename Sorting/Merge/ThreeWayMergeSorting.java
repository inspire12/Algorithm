package Merge;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class ThreeWayMergeSorting {
	private static  int totalSize;
	private static BufferedReader br;
	public static void main(String args[]) throws IOException {
		int[] data = fileInput();
		
		long startTime,endTime; 
		//인서트 솔트
		int[] mergeSortingData = data;
		
		for (int i = 0; mergeSortingData[i]!=1012; i++){
			System.out.print(mergeSortingData[i]+" " );
			
		}
		
		startTime = System.nanoTime();
		mergeSort(mergeSortingData);
		endTime = System.nanoTime();
		System.out.printf("3way 합병 정렬의 시간은 %d입니다. \n", endTime-startTime);
		System.out.println("졍렬된 값은 ");
		for(int i=0; i< totalSize; i++){
			System.out.printf("%d ",mergeSortingData[i]);
		}
		System.out.println();
		fileOutput(mergeSortingData);
		
	} 

	public static int getElement(int array[], int index) {
	
		if (index < array.length){
			return array[index];
		}
		else
			return Integer.MAX_VALUE;   
	 } 

	private static void merge(int[] subList1, int[] subList2, int[] subList3, int[] mergeList) {
		int subElement[] = {0,0,0};
		subElement[0] = getElement(subList1, 0);
		subElement[1] = getElement(subList2, 0);
		subElement[2] = getElement(subList3, 0);
		
		int srcIndex[] = {0,0,0};
		int mergeIndex = 0;
		while(mergeIndex < mergeList.length) {			
			if(subElement[0] <= subElement[1]) {
				if(subElement[2] <= subElement[0]) { 
					mergeList[mergeIndex] = subElement[2];
					srcIndex[2]++;
					subElement[2] = getElement(subList3, srcIndex[2]);               
	           	}
				else{
					mergeList[mergeIndex] = subElement[0];
					srcIndex[0]++;
					subElement[0] = getElement(subList1, srcIndex[0]);                  
				}
			}
			else{
				if (subElement[2] <= subElement[1]) {
					mergeList[mergeIndex] = subElement[2];
					srcIndex[2]++;
					subElement[2] = getElement(subList3, srcIndex[2]);               
				}
				else {
					mergeList[mergeIndex] = subElement[1];
					srcIndex[1]++;
					subElement[1] = getElement(subList2, srcIndex[1]);                  
				}       
			} 
			mergeIndex++;
		} 
	} 
	   
	static void mergeSort(int data[]) {
		if(data.length <= 1)return;      
		
		int subSize, remainderSize; 
		
		if(data.length == 2){
			subSize = 1;
			remainderSize = 0;
		}
		else{
		// 3의 배수가 아닐 경우 제대로 짤리지 않은 경우가 있어서 
			subSize = data.length / 3; 
			remainderSize = data.length - 2* subSize; 
		}
		int subList1[] = new int[subSize];
		int subList2[] = new int[subSize];
		int subList3[] = new int[remainderSize];
		for (int i = 0; i < subSize; i++){
			subList1[i] = data[i];
			if(data[i]==1012){
				System.out.println();
			}
		}
		for (int i = 0; i < subSize; i++){
			subList2[i] = data[subSize+i];
			if(data[subSize+i]==1012){
				System.out.println();
			}
		}
		for (int i = 0; i < remainderSize; i++){
			subList3[i] = data[2*subSize + i];
			if(data[2*subSize+i]==1012){
				System.out.println();
			}
		}
	      
		mergeSort(subList1);
		mergeSort(subList2);
		mergeSort(subList3);

		merge(subList1, subList2, subList3, data);		
	}
	 static int[] fileInput() throws IOException{
		 br = new BufferedReader(new FileReader("data02.txt"));
		 String input = br.readLine();
		 StringTokenizer st = new StringTokenizer(input);
		 int[] v = new int[1000000]; int i=0;
		 while(st.hasMoreTokens()){
			 v[i] = Integer.parseInt(st.nextToken(","));
			 i++;
		 }
		 totalSize = i;
		 int[] arr = new int[totalSize];
		 for(i=0; i<totalSize; i++){
			 arr[i] = v[i];
		 }
		 return arr;
	 }
	 static void fileOutput(int[] v) throws IOException{
		 FileWriter fw = new FileWriter("hw01_01_201203431_3way_merge.txt");
		 StringBuffer outputData = new StringBuffer();
		 for(int i=0; i<totalSize; i++){
			 outputData.append(v[i]);
			 if(i!=totalSize-1) outputData.append(",");
		 }	
		 String output = outputData.toString();
		 fw.write(output);
		 fw.close();
	 }
} 
