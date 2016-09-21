package Insertion;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class BinarySearch {
	private static BufferedReader br;
	private static int size;
	public static void main(String[] args) throws IOException {
		
		int[] data = fileInput();
		
		long startTime,endTime; 
		//인서트 솔트
		int[] insertionSortingData = new int[size];
		startTime = System.nanoTime();
		insertionSortingData = insertionSort(data);
		endTime = System.nanoTime();
		System.out.printf("Binary 삽입 정렬의 시간은 %d입니다. \n", endTime-startTime);
		System.out.println("졍렬된 값은 ");
		
		System.out.println();
		fileOutput(insertionSortingData);
		
	}
	static int[] insertionSort(int[] data){
		for(int i=1; i<size; ++i){
			int j=i-1;   
			int cur = data[i];
			int index = binarySearch(data, cur, 0, j);
			while(j>=index){
				data[j+1] = data[j];
				j--;
			}
			data[j+1] = cur;
		}
		return data;
	}

	static int binarySearch(int data[],int value, int left,int right){
		if(left>=right)return (value>data[right])?left+1 : left;
		int mid = (left+right)/2;
		if(value == data[mid])return mid;
		
		if(value > data[mid]) 
			return binarySearch(data, value, mid+1, right);
		else 
			return binarySearch(data, value, left, mid);
		
	}	
	static int[] fileInput() throws IOException{
		br = new BufferedReader(new FileReader("hw02_100man.txt"));
		String input = br.readLine();
		StringTokenizer st = new StringTokenizer(input, ",");
		int[] v = new int[1000000];
		int i=0;
		while(st.hasMoreTokens()){
			v[i] = Integer.parseInt(st.nextToken());
			i++;
		}
		size = i;
		int[] arr = new int[size];
		 for(i=0; i<size; i++){
			 arr[i] = v[i];
		 }
		 return arr;
	}
	static void fileOutput(int[] v) throws IOException{
		FileWriter fw = new FileWriter("hw01_01_201203431_binary_insertion.txt");
		StringBuffer outputData = new StringBuffer();
		for(int i=0; i<size; i++){
			outputData.append(v[i]);
			if(i!=size-1) outputData.append(",");
		}
		String output = outputData.toString();
		fw.write(output);
		fw.close();
	}
}