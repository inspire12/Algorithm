package QuickSort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.StringTokenizer;

public class Main {
		private static BufferedReader br;
		private static int size;
		public static void main(String[] args) throws IOException {
			
			int[] data = fileInput();
			
			long startTime,endTime; 
			//인서트 솔트
			int[] quickSortingData = data;
			startTime = System.nanoTime();
			quickSortingData = quickSort_withRandom(quickSortingData,0,quickSortingData.length-1);
			
			endTime = System.nanoTime();
			System.out.printf("quick sort 정렬의 시간은 %d입니다. \n", endTime-startTime);
			System.out.println("졍렬된 값은 ");
			
			System.out.println();
			fileOutput(quickSortingData);
			
		}
		static int[] quickSort(int[] data,int p, int r){
			if(p<r){
				int q = partition(data, p, r);
				quickSort(data, p, q-1);
				quickSort(data, q+1, r);
			}
			return data;
		}
		
		static int partition(int[] data, int p, int r){
			int x = data[r];
			int i = p-1;
			for(int j=p; j<r-1; j++){
				if(data[j]<=x){
					i++; 
					swap(data,i,j);
				}
			}
			i++; swap(data,i,r);
			
			return i;
		}
		
		
		static void swap(int data[],int i, int j){
			int tmp = data[i];
			data[i] = data[j];
			data[j 	] = tmp;
		}
		
		static int randomizedPartition(int[] data, int p, int r){
			Random random = new Random();
			int range = r-p;
			int randomIndex = random.nextInt(range)+p;
			int x = data[randomIndex];
			int i = p-1;
			for(int j=p; j<r-1; j++){
				if(data[j]<=x){
					i++; 
					swap(data,i,j);
				}
			}
			i++; swap(data,i,r);
			
			return i;
			
		}
		
		static int[] quickSort_withRandom(int[] data, int p, int r){
			if(p<r){
				int q = partition(data, p, r);
				quickSort(data, p, q-1);
				quickSort(data, q+1, r);
			}
			return data;
		}
		
		static int[] fileInput() throws IOException{
			br = new BufferedReader(new FileReader("data04.txt"));
			String input = br.readLine();
			StringTokenizer st = new StringTokenizer(input, ",");
			int[] v = new int[1000001];
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
			FileWriter fw = new FileWriter("hw03_01_201203431_quick.txt");
//			FileWriter fw = new FileWriter("hw03_01_201203431_quickRnadom.txt");
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

