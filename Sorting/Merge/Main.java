package Merge;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
	private static  int totalSize;
	private static BufferedReader br;
	public static void main(String args[]) throws IOException {
		int[] data = fileInput();
		
		long startTime,endTime; 
		//�μ�Ʈ ��Ʈ
		int[] mergeSortingData = data;
		
		startTime = System.nanoTime();
		mergeSort(mergeSortingData);
		endTime = System.nanoTime();
		System.out.printf("�պ� ������ �ð��� %d�Դϴ�. \n", endTime-startTime);
		System.out.println("���ĵ� ���� ");
		for(int i=0; i< totalSize; i++){
			System.out.printf("%d ",mergeSortingData[i]);
		}
		System.out.println();
		fileOutput(mergeSortingData);
		
	} 

	public static int getElement(int array[], int index) {
		if (index < array.length)
			return array[index];
		else
			return Integer.MAX_VALUE;   
	 } 

	private static void merge(int[] subList1, int[] subList2, int[] mergeList) {
		int subElement[] = {0,0};
		subElement[0] = getElement(subList1, 0);
		subElement[1] = getElement(subList2, 0);
		
		int srcIndex[] = {0,0};
		int mergeIndex = 0;
		while(mergeIndex < mergeList.length) {
			if(subElement[0] <= subElement[1]) {
				mergeList[mergeIndex] = subElement[0];  
				srcIndex[0]++;
				subElement[0] = getElement(subList1, srcIndex[0]);
			}
			else{
				mergeList[mergeIndex] = subElement[1];  
				srcIndex[1]++;
				subElement[1] = getElement(subList2, srcIndex[1]);
			} 
			mergeIndex++;
		} 
	} 
	   
	static void mergeSort(int data[]) {
		if(data.length <= 1)return;      
		
		int subSize, remainderSize; 
		
		
		subSize = data.length / 2; 
		remainderSize = data.length - subSize; 
		
		int subList1[] = new int[subSize];
		int subList2[] = new int[remainderSize];
		for (int i = 0; i < subSize; i++)
			subList1[i] = data[i];
		for (int i = 0; i < remainderSize; i++)
			subList2[i] = data[subSize+i];
	      
		mergeSort(subList1);
		mergeSort(subList2);

		merge(subList1, subList2, data);		
	}
	 static int[] fileInput() throws IOException{
		 br = new BufferedReader(new FileReader("data02.txt"));
		 String input = br.readLine();
		 StringTokenizer st = new StringTokenizer(input, ",");
		 int[] v = new int[1000000]; int i=0;
		 while(st.hasMoreTokens()){
			 v[i] = Integer.parseInt(st.nextToken());
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
		 FileWriter fw = new FileWriter("hw01_01_201203431_merge.txt");
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
