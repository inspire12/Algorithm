package Insertion;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
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
		System.out.printf("삽입 정렬의 시간은 %d입니다. \n", endTime-startTime);
		System.out.println("졍렬된 값은 ");
		
		System.out.println();
		fileOutput(insertionSortingData);
		
	}
	
	static int[] insertionSort(int[] data){	
		
		for(int i = 0; i<size; i++){
			int cur = data[i];
			int index = i-1;
			while((index>=0)&&(data[index]>cur)){
				data[index+1] = data[index];
				index--;
			}
			data[index+1] = cur;
		} 
		return data;
	}
	
	static int[] fileInput() throws IOException{
		br = new BufferedReader(new FileReader("hw02_1000man.txt"));
		String input = br.readLine();
		StringTokenizer st = new StringTokenizer(input, ",");
		int[] v = new int[1000000];
		int i=0;
		while(st.hasMoreTokens()){
			v[i] = Integer.parseInt(st.nextToken());
			i++;
		}
		size = i;
		return v;
	}
	static void fileOutput(int[] v) throws IOException{
		FileWriter fw = new FileWriter("hw01_01_201203431_insertion.txt");
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